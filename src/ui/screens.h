#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_STARTUP_SCREEN = 1,
    SCREEN_ID_MAIN_SCREEN = 2,
    SCREEN_ID_SETTINGS_SCREEN = 3,
    _SCREEN_ID_LAST = 3
};

typedef struct _objects_t {
    lv_obj_t *startup_screen;
    lv_obj_t *main_screen;
    lv_obj_t *settings_screen;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *tileview_main;
    lv_obj_t *tile_clock;
    lv_obj_t *clock;
    lv_obj_t *settings_btn;
    lv_obj_t *tile_price;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *tile_weather;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *tile_relays;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *obj23;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *settings;
    lv_obj_t *settings_main;
    lv_obj_t *obj28;
    lv_obj_t *battery_label;
    lv_obj_t *battery_full;
    lv_obj_t *battery_low;
    lv_obj_t *battery_half;
    lv_obj_t *battery_charging;
    lv_obj_t *obj29;
    lv_obj_t *obj30;
    lv_obj_t *obj31;
    lv_obj_t *obj32;
    lv_obj_t *obj33;
    lv_obj_t *obj34;
    lv_obj_t *obj35;
    lv_obj_t *obj36;
    lv_obj_t *obj37;
    lv_obj_t *obj38;
    lv_obj_t *brightness;
    lv_obj_t *brightness_arc;
    lv_obj_t *brightness_label;
    lv_obj_t *obj39;
    lv_obj_t *wifi;
    lv_obj_t *obj40;
    lv_obj_t *obj41;
    lv_obj_t *obj42;
    lv_obj_t *obj43;
    lv_obj_t *obj44;
    lv_obj_t *limit;
    lv_obj_t *obj45;
    lv_obj_t *lowest_price;
    lv_obj_t *low_minus_btn;
    lv_obj_t *low_plus_btn;
    lv_obj_t *obj46;
    lv_obj_t *highest_price;
    lv_obj_t *highest_minus_btn;
    lv_obj_t *hinghest_plus_btn;
    lv_obj_t *obj47;
    lv_obj_t *reset_settings;
    lv_obj_t *reset_main;
    lv_obj_t *obj48;
    lv_obj_t *obj49;
    lv_obj_t *obj50;
    lv_obj_t *obj51;
    lv_obj_t *settings_reset;
    lv_obj_t *obj52;
    lv_obj_t *factory_reset;
    lv_obj_t *obj53;
    lv_obj_t *obj54;
    lv_obj_t *obj55;
    lv_obj_t *obj56;
    lv_obj_t *obj57;
    lv_obj_t *obj58;
    lv_obj_t *obj59;
} objects_t;

extern objects_t objects;

typedef struct {
    lv_meter_scale_t *hour;
    lv_meter_indicator_t *hour_hand;
    lv_meter_scale_t *minute;
    lv_meter_indicator_t *minute_hand;
} screen_main_screen_state_t;

extern screen_main_screen_state_t screen_main_screen_state;

void create_screen_startup_screen();
void tick_screen_startup_screen();

void create_screen_main_screen();
void tick_screen_main_screen();

void create_screen_settings_screen();
void tick_screen_settings_screen();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/