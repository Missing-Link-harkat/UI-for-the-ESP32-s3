#include "knob.h"
#include "brightness.h"
#include "price_limit.h"
#include "sleep.h"
#include "nav.h"
#include "ui/ui.h"

static int knob_cont = 0;
static int knob_conts = 0;
static int current_tile = 0;

// calculates the current position of the tile
void tile_knob_change(knob_event_t k)
{
    lv_obj_t *tile = lv_tileview_get_tile_act(objects.tileview_main);

    if (tile == objects.tile_clock)
    {
        current_tile = 0;
    }
    else if (tile == objects.tile_price)
    {
        current_tile = 1;
    }
    else if (tile == objects.tile_weather)
    {
        current_tile = 2;
    }
    else if (tile == objects.tile_relays)
    {
        current_tile = 3;
    }

    if (k == KNOB_LEFT)
    {
        if (current_tile > 0)
        {
            current_tile--;
        }
    }
    else if (k == KNOB_RIGHT)
    {
        if (current_tile < 3)
        {
            current_tile++;
        }
    }

    lv_obj_set_tile_id(objects.tileview_main, current_tile, 0, LV_ANIM_ON);
}

void knob_change(knob_event_t k, int cont)
{
    screen_activity();

    // main screen
    if (lv_scr_act() == objects.main_screen)
    {
        tile_knob_change(k);
        return;
    }

    // Brightness page
    if (!lv_obj_has_flag(objects.brightness,LV_OBJ_FLAG_HIDDEN))
    {
        if (k == KNOB_LEFT)
        {
            knob_change_brightness(-5);
        }
        else if (k == KNOB_RIGHT)
        {
            knob_change_brightness(+5);
        }
        return;
    }

    // Price limit page
    if (!lv_obj_has_flag(objects.limit, LV_OBJ_FLAG_HIDDEN))
    {
    if (k == KNOB_LEFT)
    {
        limit_knob_left();
    }
    else if (k == KNOB_RIGHT)
    {
        limit_knob_right();
    }

    return;
    }
}
