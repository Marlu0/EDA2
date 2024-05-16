#include "common.h"

void health_potion(Character *character){
    character->health = 100;
}

void poisoned(Character *character){
    character->health*= 0.9;
}

void secretWeapon(Character *character, Skill skills_list[]){
    character->inventory.weapons_in_inventory[character->inventory.fill] = character->active_weapon;
    character->inventory.fill++;

    Weapon secret_weapon = {"legendary sword",
    "Singing iron blade,\nfeinds no more than memeories\nA debt to be paid\n",
    {&skills_list[11], skills_list[12]}};
    
    character->active_weapon = secret_weapon;
}

/*example of what the character function pointer can do it lets us be a lot more creative with what happens at decisions.*/