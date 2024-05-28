
#include "global.h"

void health_gain(Character *character){
    printf("HEALTH POTION! health maxed\n");
    character->health = 100+(20*(character->stats.hp-1));
}
void health_loss(Character *character){
    printf("ACK! POISONED! health loss\n");
    character->health*= 0.9; //will this cast it to a double?
}


void attack_gain(Character *character){
    printf("NEW GUN! attack boost!\n");
    character->active_modifiers.tempatk *= 2;
}
void attack_loss(Character *character){
    printf("YOU LOST YOUR BULLETS! attack loss\n");
    character->active_modifiers.tempatk *= 0.5;
}


void defense_gain(Character *character){
    printf("NEW HAT!! defense boost\n");
    character->active_modifiers.tempdef *= 2;
}
void defense_loss(Character *character){
    printf("CAT SCRATCHED YOUR COAT! defense loss\n");
    character->active_modifiers.tempatk *= 0.5;
}


void luck_gain(Character *character){
    printf("FOUND A WILD CLOVER!! luck boost!\n");
    character->active_modifiers.templuc *= 2;
}
void luck_loss(Character *character){
    printf("BROKE A MIRROR!! luck loss!\n");
    character->active_modifiers.templuc *= 0.5;
}
