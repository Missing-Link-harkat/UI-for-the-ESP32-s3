#pragma once

#include <lvgl.h>

void wifi_reset(lv_event_t *e);
void open_factory_reset(lv_event_t * e);
void open_settings_reset(lv_event_t * e);

void back_reset_settings(lv_event_t * e);

void restore_default_settings();

void factory_reset_start(lv_event_t * e);
void factory_reset_cancel(lv_event_t * e);