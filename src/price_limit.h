#pragma once

#include <lvgl.h>

void active_limits_init();

void change_lowest_price(lv_event_t *e);
void change_highest_price(lv_event_t *e);

void lowest_plus(lv_event_t *e);
void lowest_minus(lv_event_t *e);

void highest_plus(lv_event_t *e);
void highest_minus(lv_event_t *e);

void limit_knob_left();
void limit_knob_right();