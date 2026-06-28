#include "settings.h"
#include "ui/ui.h"
#include <lvgl.h>

static bool settings_armed = false;
static lv_timer_t *settings_timer = nullptr;

static void settings_timeout_cb(lv_timer_t *timer)
{
    settings_armed = false;
    settings_timer = nullptr;

    // Return button to original position
    lv_obj_set_style_x(objects.settings_btn, -30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_y(objects.settings_btn, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_timer_del(timer);
}

void settings_button(lv_event_t *e)
{
    LV_UNUSED(e);

    // First click
    if (!settings_armed)
    {
        settings_armed = true;

        // Move button more toward center
        lv_obj_set_style_x(objects.settings_btn, -70, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_y(objects.settings_btn, 35, LV_PART_MAIN | LV_STATE_DEFAULT);

        // waits for 3s
        settings_timer = lv_timer_create(settings_timeout_cb, 3000, NULL);

        return;
    }
    // Second click
    settings_armed = false;

    if (settings_timer != nullptr)
    {
        lv_timer_del(settings_timer);
        settings_timer = nullptr;
    }

    // Return button to corner
    lv_obj_set_style_x(objects.settings_btn, -30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_y(objects.settings_btn, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_scr_load(objects.settings_screen);
}