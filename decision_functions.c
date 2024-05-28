
#include "global.h"

void health_gain(Character *character){
    printf("There was a health potion inside the barrel! health maxed\n");
    character->stats.hp++;
}
void health_loss(Character *character){
    printf("ACK! POISONED! health loss\n");
    character->health*= 0.9; //will this cast it to a double?
}

void health_loss_saloon(Character *character){
    printf("DAMN, you got in a nasty fight! Your wounds look bad.  health loss\n");
    character->stats.hp--;
}

void attack_gain(Character *character){
    printf("NEW GUN! attack boost!\n");
    character->active_modifiers.tempatk *= 2;
}

void attack_gain_turtle(Character *character){
    printf("Turtle: Huh? You again. I told you already, go kill that darn Bull and you'll get your information. You know what! You should kill him with this bad boy, sure he'll recognize it! recieved REMINGTON, attack boost\n");
    character->stats.atk += 2;
}

void attack_loss_booze(Character *character){
    printf("You're now drunk as hell! attack loss\n");
    character->stats.atk--;
}


void defense_gain_clothes(Character *character){
    printf("Lookin' good! defense boost\n");
    character->stats.def++;
}
void defense_loss_well(Character *character){
    printf("As you were throwing the coin, a naked man came out of the well and stole your hat! defense loss\n");
    character->stats.def--;
}


void luck_gain_ciggarette(Character *character){
    printf("Smoke feels good in your lungs, today is gonna' be a good one. luck boost!\n");
    character->stats.luc++;
}
void luck_loss(Character *character){
    printf("BROKE A MIRROR!! luck loss!\n");
    character->active_modifiers.templuc *= 0.5;
}

void luck_loss_coffin(Character *character){
    printf("WHAT WERE YOU THINKING OF, CREEP! luck loss!\n");
    character->stats.luc--;
}



void nothing(){
    printf("You found nothing\n");
}