#include <lvgl.h>
#include "sleep.h"

extern void set_brightness(uint8_t bri);

static lv_timer_t *idle_timer = nullptr;

static uint8_t active_brightness = 70;
static bool dimmed = false;

// screen is sleep after 5 seconds
static void idle_timer_cb(lv_timer_t *timer)
{
    LV_UNUSED(timer);

    dimmed = true;

    set_brightness(5);
}

// set sleep timer
void sleep_init()
{
    idle_timer = lv_timer_create(idle_timer_cb, 5000, NULL);
}

// set brightness
void screen_set_active_brightness(uint8_t brightness)
{
    active_brightness = brightness;
}

// screen has been touched
void screen_activity()
{
    if(dimmed)
    {
        set_brightness(active_brightness);

        dimmed = false;
    }

    lv_timer_reset(idle_timer);
}

