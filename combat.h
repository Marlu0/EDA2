#ifndef COMBAT_H
#define COMBAT_H

#include "global.h"
#include "game.h"

/* Functions for turn-based combat */

void init_fight_characters(Character *character, Enemy *enemies, int number_of_enemies);

int select_enemy(Enemy *enemies, int number_of_enemies);

int calculate_damage_player(Character *character, Enemy enemy);

void turn_player(Character *character, Enemy *enemies, Stack* attack_stack, int number_of_enemies, int *attacks_done, int *time_strike_done, int *dead_enemies);

void turn_enemy(Character *character, Enemy *enemy);

void do_combat(Game *game_state);

#endif /* COMBAT_H */