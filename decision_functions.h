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

void bullet_gain(Character *character);
                            
void bullet_loss(Character *character);

#endif //DECISION_FUNCTIONS_H