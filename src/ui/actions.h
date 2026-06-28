#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_settings_button(lv_event_t * e);
extern void action_back_main(lv_event_t * e);
extern void action_back_settings(lv_event_t * e);
extern void action_open_brightness(lv_event_t * e);
extern void action_change_brightness(lv_event_t * e);
extern void action_open_wifi(lv_event_t * e);
extern void action_open_limit(lv_event_t * e);
extern void action_open_reset_settings(lv_event_t * e);
extern void action_open_factory_reset(lv_event_t * e);
extern void action_open_settings_reset(lv_event_t * e);
extern void action_back_reset_settings(lv_event_t * e);
extern void action_change_lowest_price(lv_event_t * e);
extern void action_change_highest_price(lv_event_t * e);
extern void action_lowest_minus(lv_event_t * e);
extern void action_lowest_plus(lv_event_t * e);
extern void action_highest_minus(lv_event_t * e);
extern void action_highest_plus(lv_event_t * e);
extern void action_factory_reset_start(lv_event_t * e);
extern void action_factory_reset_cancel(lv_event_t * e);
extern void action_wifi_reset(lv_event_t * e);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/