#pragma once
#include "ui/ui.h"

void navigation_init();

void open_brightness(lv_event_t *e);
void open_wifi(lv_event_t * e);
void open_limit(lv_event_t * e);
void open_reset_settings(lv_event_t * e);

void back_settings(lv_event_t *e);