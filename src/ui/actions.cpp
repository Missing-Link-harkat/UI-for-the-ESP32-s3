#include "actions.h"
#include "nav.h"
#include "price_limit.h"
#include "brightness.h"
#include "reset.h"
#include "settings.h"
#include <stdio.h>

void action_settings_button(lv_event_t * e)
{
    settings_button(e);
}

void action_back_main(lv_event_t * e)
{
    lv_scr_load(objects.main_screen);
}

void action_open_brightness(lv_event_t *e)
{
    open_brightness(e);
}


void action_open_wifi(lv_event_t * e)
{
    open_wifi(e);
}

void action_open_limit(lv_event_t * e)
{
    open_limit(e);
}

void action_open_reset_settings(lv_event_t * e)
{
    open_reset_settings(e);
}

void action_open_factory_reset(lv_event_t * e)
{
    open_factory_reset(e);
}

void action_open_settings_reset(lv_event_t * e)
{
    open_settings_reset(e);
}

void action_back_reset_settings(lv_event_t * e)
{
    back_reset_settings(e);
}

void action_back_settings(lv_event_t *e)
{
    back_settings(e);
}

void action_change_brightness(lv_event_t * e)
{
    change_brightness(e);
}

void action_change_lowest_price(lv_event_t *e)
{
    change_lowest_price(e);
}

void action_change_highest_price(lv_event_t *e)
{
    change_highest_price(e);
}

void action_lowest_plus(lv_event_t *e)
{
    lowest_plus(e);
}

void action_lowest_minus(lv_event_t *e)
{
    lowest_minus(e);
}

void action_highest_plus(lv_event_t *e)
{
    highest_plus(e);
}

void action_highest_minus(lv_event_t *e)
{
    highest_minus(e);
}

void action_factory_reset_start(lv_event_t * e)
{
    factory_reset_start(e);
}

void action_factory_reset_cancel(lv_event_t * e)
{
    factory_reset_cancel(e);
}

void action_wifi_reset(lv_event_t * e)
{
    wifi_reset(e);
}