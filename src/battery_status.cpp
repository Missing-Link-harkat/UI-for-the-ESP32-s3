#include "battery_status.h"

#include <Arduino.h>
#include <lvgl.h>

#include "ui/ui.h"
#include "pincfg.h"

static lv_timer_t *battery_timer = NULL;

// calculates the battery voltage
float battery_voltage()
{
    long sum = 0;

    for(int i = 0; i < 20; i++)
    {
        sum += analogRead(BAT_ADC_PIN);
    }

    float raw = sum / 20.0f;

    float adc = raw * 3.3f / 4095.0f;

    return adc * 2.0f;
}

// turns the voltage to percentage
int battery_percent()
{
    float battery = battery_voltage();

    int percent = (battery - 3.3f)* 100.0f/ (4.2f - 3.3f);

    if(percent < 0)
        percent = 0;

    if(percent > 100)
        percent = 100;

    return percent;
}

// updates the battery icon and procentage according to voltage and percentage state
void battery_update()
{
    float voltage = battery_voltage();

    lv_obj_add_flag(objects.battery_low, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(objects.battery_half, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(objects.battery_full, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(objects.battery_charging, LV_OBJ_FLAG_HIDDEN);

    // charging detected
    if(voltage > 4.25f)
    {
        lv_obj_clear_flag(objects.battery_charging, LV_OBJ_FLAG_HIDDEN);

        lv_obj_add_flag(objects.battery_label, LV_OBJ_FLAG_HIDDEN);

        return;
    }

    int percent = battery_percent();

    lv_obj_clear_flag(objects.battery_label, LV_OBJ_FLAG_HIDDEN);

    if(percent < 25)    // percentage is under 25
    {
        lv_obj_clear_flag(objects.battery_low, LV_OBJ_FLAG_HIDDEN);
    }
    else if(percent < 75)   // percentage is under 75
    {
        lv_obj_clear_flag(objects.battery_half, LV_OBJ_FLAG_HIDDEN);
    }
    else    // percentage is over 75
    {
        lv_obj_clear_flag(objects.battery_full, LV_OBJ_FLAG_HIDDEN);
    }

    char txt[8];

    snprintf(txt, sizeof(txt), "%d%%", percent);

    lv_label_set_text(objects.battery_label, txt);

    Serial.printf("Battery %.2fV %d%%\n", voltage, percent);
}

static void battery_timer_cb(
    lv_timer_t *timer
)
{
    LV_UNUSED(timer);

    battery_update();
}

// updates the battery every 30s
void battery_init()
{
    analogReadResolution(12);

    battery_update();

    battery_timer = lv_timer_create(battery_timer_cb, 30000, NULL);
}