#ifndef GAME_H
#define GAME_H

#include "global.h"

/* Functions for character creation */

void name_character(Character *character);

void reset_character_stats(Character *character);

void assign_points(int *stat, int *statpts, const char *stat_name);

Character create_character();

#endif // GAME H