#include "reset.h"
#include "ui/ui.h"
#include "Arduino.h"
#include "brightness.h"
#include <Preferences.h>

extern Preferences prefs;

//extern void set_brightness(uint8_t bri);
static lv_timer_t *factory_timer = nullptr;

// wifi returns to the settings main screen
void wifi_reset(lv_event_t *e)
{
    LV_UNUSED(e);

    // reset wifi code here

    lv_obj_add_flag(objects.reset_settings, LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.settings_main, LV_OBJ_FLAG_HIDDEN);
}

// when timer runs out it hides all factor settings conainers and returns to main screen
static void factory_reset_timer_cb(lv_timer_t *timer)
{
    factory_timer = nullptr;

    lv_obj_add_flag(objects.factory_reset, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(objects.reset_settings,LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.reset_main, LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.settings_main, LV_OBJ_FLAG_HIDDEN);

    // Return to Main Screen
    lv_scr_load(objects.main_screen);

    lv_obj_set_tile_id(objects.tileview_main, 0, 0, LV_ANIM_OFF);

    lv_timer_del(timer);
}

// when timer starts it hides all factor settings conainers and returns to main screen
static void settings_reset_timer_cb(lv_timer_t *timer)
{
    lv_obj_add_flag(objects.settings_reset, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(objects.reset_settings, LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.reset_main, LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.settings_main, LV_OBJ_FLAG_HIDDEN);

    // Return to Main Screen
    lv_scr_load(objects.main_screen);
    
    lv_obj_set_tile_id(objects.tileview_main, 0, 0, LV_ANIM_OFF);

    lv_timer_del(timer);
}

// deletes all saved settings and returns them to default
void restore_default_settings()
{
    // Remove all saved settings
    prefs.clear();

    // Brightness default
    brightness_set_percent(70);

    // Price limits
    lv_spinbox_set_value(objects.lowest_price, 500);
    lv_spinbox_set_value(objects.highest_price, 2000);

    Serial.println("Settings restored");
}

// shows settings reset for 3s then returns to main screen
void open_settings_reset(lv_event_t * e)
{
    LV_UNUSED(e);

    restore_default_settings();

    lv_obj_add_flag(objects.reset_main,LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.settings_reset,LV_OBJ_FLAG_HIDDEN);

    lv_timer_create(settings_reset_timer_cb, 3000, NULL);

}

// shows factory reset container
void open_factory_reset(lv_event_t * e)
{
    lv_obj_add_flag(objects.reset_main,LV_OBJ_FLAG_HIDDEN);

    lv_obj_clear_flag(objects.factory_reset,LV_OBJ_FLAG_HIDDEN);
}

// starts the timer for 5s when pressing the "kyllä" button
void factory_reset_start(lv_event_t * e)
{
    LV_UNUSED(e);

    if(factory_timer == nullptr)
    {
        factory_timer = lv_timer_create(factory_reset_timer_cb, 5000, NULL);
    }
}

// cancels the timer if user stops pressing the "kyllä" button
void factory_reset_cancel(lv_event_t * e)
{
    LV_UNUSED(e);

    if(factory_timer != nullptr)
    {
        lv_timer_del(factory_timer);
        factory_timer = nullptr;
    }
}

// goes back to factory reset settings container
void back_reset_settings(lv_event_t * e)
{
    lv_obj_clear_flag(objects.reset_main,LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(objects.settings_reset, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.factory_reset, LV_OBJ_FLAG_HIDDEN);
}