#include "price_limit.h"
#include <Preferences.h>
#include "ui/ui.h"
#include <Arduino.h>

extern Preferences prefs;

static lv_obj_t *active_spinbox = nullptr;

// updates the lowest price limit value
void change_lowest_price(lv_event_t *e)
{
    int value = lv_spinbox_get_value(objects.lowest_price);

    prefs.putInt("low_limit", value);

    Serial.printf("Low limit: %d\n", value);
}

// updates the highest price limit value
void change_highest_price(lv_event_t *e)
{
    int value = lv_spinbox_get_value(objects.highest_price);

    prefs.putInt("high_limit",value);

    Serial.printf("High limit: %d\n", value);
}

// updates the price limit value at start up
void active_limits_init()
{
    Serial.println("limits_init");

    int low = prefs.getInt("low_limit", 500);

    int high = prefs.getInt("high_limit", 2000);

    lv_spinbox_set_value(objects.lowest_price, low);

    lv_spinbox_set_value(objects.highest_price, high);

    active_spinbox = objects.lowest_price;
}

// activates the lowest price limit plus button
void lowest_plus(lv_event_t *e)
{
    active_spinbox = objects.lowest_price;

    lv_spinbox_increment(objects.lowest_price);

    lv_event_send(objects.lowest_price, LV_EVENT_VALUE_CHANGED, NULL);
}

// activates the lowest price limit minus button
void lowest_minus(lv_event_t *e)
{
    active_spinbox = objects.lowest_price;

    lv_spinbox_decrement(objects.lowest_price);

    lv_event_send(objects.lowest_price, LV_EVENT_VALUE_CHANGED, NULL);
}

// activates the highest price limit plus button
void highest_plus(lv_event_t *e)
{
    active_spinbox = objects.highest_price;

    lv_spinbox_increment(objects.highest_price);

    lv_event_send(objects.highest_price, LV_EVENT_VALUE_CHANGED, NULL);
}

// activates the highest price limit minus button
void highest_minus(lv_event_t *e)
{
    active_spinbox = objects.highest_price;

    lv_spinbox_decrement(objects.highest_price);

    lv_event_send(objects.highest_price, LV_EVENT_VALUE_CHANGED, NULL);
}

// activates the knob to the left
void limit_knob_left()
{
    if(active_spinbox == nullptr)
        return;

    lv_spinbox_decrement(active_spinbox);

    lv_event_send(active_spinbox, LV_EVENT_VALUE_CHANGED, NULL);
}

// activates the knob to the right
void limit_knob_right()
{
    if(active_spinbox == nullptr)
        return;

    lv_spinbox_increment(active_spinbox);

    lv_event_send(active_spinbox, LV_EVENT_VALUE_CHANGED, NULL);
}