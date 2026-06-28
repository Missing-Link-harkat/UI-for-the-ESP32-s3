#include "nav.h"
#include "ui/ui.h"
#include "lvgl.h"
#include <Arduino.h>
#include <esp_heap_caps.h>

static bool startup_finished = false;

static void startup_timer_cb(lv_timer_t *timer)
{
    if (!startup_finished)
    {
        startup_finished = true;
        
        // Show main screen
        lv_scr_load(objects.main_screen);
    }
    // delete the timer
    lv_timer_del(timer);
}

// Initialize navigation
void navigation_init()
{
    // Show startup screen
    lv_scr_load(objects.startup_screen);

    // Start boot timer
    lv_timer_create(startup_timer_cb, 2000, NULL);
}

// shows the brightness container
void open_brightness(lv_event_t * e)
{
    lv_obj_add_flag(objects.settings_main,LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.brightness,LV_OBJ_FLAG_HIDDEN);
}

// shows the wifi container
void open_wifi(lv_event_t * e)
{
    lv_obj_add_flag(objects.settings_main,LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.wifi,LV_OBJ_FLAG_HIDDEN);
}

// shows the price limit container
void open_limit(lv_event_t * e)
{
    lv_obj_add_flag(objects.settings_main,LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.limit,LV_OBJ_FLAG_HIDDEN);
}

// shows the factory reset container
void open_reset_settings(lv_event_t * e)
{
    lv_obj_add_flag(objects.settings_main,LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.reset_settings,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.factory_reset, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.settings_reset, LV_OBJ_FLAG_HIDDEN);
}

// hides all containers in the settings
void hide_all_settings()
{
    lv_obj_add_flag(objects.brightness, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.wifi, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.limit, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.reset_settings, LV_OBJ_FLAG_HIDDEN);
}

// goes back to the main settings container
void back_settings(lv_event_t *e)
{
    hide_all_settings();

    lv_obj_clear_flag(objects.settings_main,LV_OBJ_FLAG_HIDDEN);
}