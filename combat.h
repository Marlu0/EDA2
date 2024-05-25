#ifndef COMBAT_H
#define COMBAT_H

#include "global.h"
#include "game.h"

/* Macros for turn-based combat */

#define AGGRESSIVE_MODE_VALUE 2.5

/* Functions for turn-based combat */

void init_fight_characters(Character *character, Enemy *enemies, int number_of_enemies);

int select_enemy(Enemy *enemies, int number_of_enemies);

void turn_player(Character *character, Enemy *enemies, Stack* attack_stack, int number_of_enemies, int *attacks_done, int *time_strike_done, int *dead_enemies);

void turn_enemy(Character *character, Enemy *enemy);

void do_combat(Game *game_state, Enemy *enemies, int number_of_enemies);

#endif /* COMBAT_H */