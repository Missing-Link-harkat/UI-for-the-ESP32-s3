#include <Preferences.h>
#include "ui/ui.h"
#include "brightness.h"
#include "lvgl.h"
#include <Arduino.h>
#include "brightness.h"
#include "knob.h"
#include "sleep.h"

extern Preferences prefs;

extern void set_brightness(uint8_t bri);

void brightness_set_percent(uint8_t value)
{
    if (value > 100)
    {
        value = 100;
    }

    // Update arc
    lv_arc_set_value(objects.brightness_arc, value);

    // Map 0-100 -> 10-100
    uint8_t brightness = map(value, 0, 100, 10, 100);

    // Set display brightness
    set_brightness(brightness);
    screen_set_active_brightness(brightness);

    // Save user value
    prefs.putUChar("brightness", value);

    // Update label
    char txt[8];

    snprintf(txt,sizeof(txt),"%u %%",value);
    lv_label_set_text(objects.brightness_label, txt);
}

void brightness_init()
{
    uint8_t value = prefs.getUChar("brightness", 70);

    brightness_set_percent(value);
}

void change_brightness(lv_event_t *e)
{
    LV_UNUSED(e);

    uint8_t value = lv_arc_get_value(objects.brightness_arc);

    brightness_set_percent(value);
}

void knob_change_brightness(int step)
{
    int value = lv_arc_get_value(objects.brightness_arc);

    value += step;

    if (value < 0)
    {
        value = 0;
    }

    if (value > 100)
    {
        value = 100;
    }

    brightness_set_percent((uint8_t)value);
}