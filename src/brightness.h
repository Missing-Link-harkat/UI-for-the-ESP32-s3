#pragma once
#include "ui/ui.h"

void brightness_init();
void change_brightness(lv_event_t * e);


void knob_change_brightness(int step);
void brightness_set_percent(uint8_t value);