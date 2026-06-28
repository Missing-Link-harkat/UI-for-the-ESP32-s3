#include <Arduino.h>
#include "scr_st77916.h"
#include "pincfg.h"
#include <lvgl.h>
#include "nav.h"
#include "brightness.h"
#include "price_limit.h"
#include "battery_status.h"
#include "ui/ui.h"
#include "knob.h"
#include "sleep.h"
#include <esp_heap_caps.h>
#include <Preferences.h>
Preferences prefs;

void setup()
{
    Serial.begin(115200);
    delay(500);

    // screen, touch and knob config
    scr_lvgl_init();

    // ui
    ui_init();

    // battery percentage
    battery_init();
  
    prefs.begin("settings", false);

    // brightness
    brightness_init();

    // price limits
    active_limits_init();

    // sleeping timer
    sleep_init();

    // loads the startup screen
    navigation_init();
}


void loop()
{
  // LVGL tasks
  lv_timer_handler();
  ui_tick();

  vTaskDelay(5);
}