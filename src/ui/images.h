#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_asetukset;
extern const lv_img_dsc_t img_clound;
extern const lv_img_dsc_t img_cloud_big;
extern const lv_img_dsc_t img_location;
extern const lv_img_dsc_t img_brightness;
extern const lv_img_dsc_t img_wifi;
extern const lv_img_dsc_t img_relay;
extern const lv_img_dsc_t img_reset;
extern const lv_img_dsc_t img_limit;
extern const lv_img_dsc_t img_back;
extern const lv_img_dsc_t img_offline;
extern const lv_img_dsc_t img_online;
extern const lv_img_dsc_t img_wifi_off;
extern const lv_img_dsc_t img_wifi_on;
extern const lv_img_dsc_t img_arrow;
extern const lv_img_dsc_t img_battery_full;
extern const lv_img_dsc_t img_battery_low;
extern const lv_img_dsc_t img_battery_half;
extern const lv_img_dsc_t img_battery_charging;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[19];

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/