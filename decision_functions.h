#ifndef DECISION_FUNCTIONS_H
#define DECISION_FUNCTIONS_H

#include "global.h"

void health_gain(Character *Character);

void health_loss(Character *character);

void attack_gain(Character *character);

void attack_loss(Character *Character);
                            
void defense_gain(Character *character);
                            
void defense_loss(Character *character);
                            
void luck_gain(Character *character);

void luck_loss(Character *character);

void print_description1(Game *game);

void print_description2(Game *game);

void print_description3(Game *game);

void print_description4(Game *game);

void print_description5(Game *game);

void print_description6(Game *game);

void print_description7(Game *game);

void print_description8(Game *game);

#endif //DECISION_FUNCTIONS_H