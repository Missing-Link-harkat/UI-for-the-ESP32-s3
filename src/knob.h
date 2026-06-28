#ifndef _KNOB_H
#define _KNOB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
#include "bidi_switch_knob.h"

void tile_knob_change(knob_event_t k);
void knob_change(knob_event_t k,int cont);



#ifdef __cplusplus
}
#endif

#endif