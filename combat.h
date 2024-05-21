#ifndef COMBAT_H
#define COMBAT_H

#include "common.h"
#include "game.h"

int select_skill(Character *character, int attacks_done);

int select_enemy(Enemy *enemies, int number_of_enemies);

void turn_player(Character *character, Enemy *enemies, Stack* attack_stack, int number_of_enemies, int attacks_done, bool time_strike_done);

void turn_enemy(Character *character, Enemy *enemy);

void do_combat(Character *character, Enemy *enemies, int number_of_enemies);



#endif /* COMBAT_H */