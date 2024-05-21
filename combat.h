#ifndef COMBAT_H
#define COMBAT_H

#include "global.h"
#include "combat.h"
#include "game.h"

#define AGGRESSIVE_MODE_VALUE 2.5

int select_enemy(Enemy *enemies, int number_of_enemies);

void turn_player(Character *character, Enemy *enemies, Stack* attack_stack, int number_of_enemies, int attacks_done, bool time_strike_done);

void turn_enemy(Character *character, Enemy *enemy);

void do_combat(Character *character, Enemy *enemies, int number_of_enemies);

#endif /* COMBAT_H */