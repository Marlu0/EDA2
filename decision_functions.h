#ifndef DECISION_FUNCTIONS_H
#define DECISION_FUNCTIONS_H

#include "global.h"

void health_gain(Character *character);

void health_loss(Character *character);

void attack_gain(Character *character);

void attack_loss_booze(Character *Character);
                            
void defense_gain(Character *character);
                            
void defense_loss(Character *character);
                            
void luck_gain_ciggarette(Character *character);

void defense_gain_clothes(Character *character);

void luck_loss(Character *character);

void health_loss_saloon(Character *character);

void defense_loss_well(Character *character);

void luck_loss_coffin(Character *character);

void attack_gain_turtle(Character *character);



void nothing();
#endif //DECISION_FUNCTIONS_H