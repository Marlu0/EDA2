#include "global.h"
#include "game.h"
#include "combat.h"


#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4
#define BACKWARDS 5
// its arranged in that if you do backwards - direction you get the other direction

#define NUM_SKILLS 2
#define NUM_MODIFIERS 4
#define MAX_CHOICES 4
#define MAX_STRING_LEN 100
#define NUM_OPTIONS 2
#define NUM_DECISIONS 2
#define INVENTORY_SIZE 8
#define AGGRESSIVE_MODE_ACTIVATOR 2.5



int main(){

    Skill skills_dictionar[11] = {
        {10, "The Hermit", "Increases defense a 15", {1, 1.15, 1}, 0},
        {10, "The Chariot", "Increases defense a 30", {1, 1.3, 1}, 0},
        {10, "The Tower", "Increases attack a 15", {1.15 , 1, 1}, 0},
        {10, "The Devil", "Increases attack a 30", {1.3, 1, 1}, 0},
        {10, "The Hangman", "Eliminates luck", {1, 1, 0}, 10},
        {10, "Weel Of Fortune", "Duplicates luck", {1, 1, 2}, 0},
        {10, "Death of Theo", "Death is the only way", {0.5, 2, 1}, -5},
        {10, "The Armadillo", "Nothing like home", {0.5, 2, 1}, 20},
        {10, "The Fool", "Decreases defense a 1, and increase luck a 30", {1, 0.9, 1.3}, 0},
        {10, "Justice", "Faith will guide you", {1.1, 1.1, 1.1}, 0},
        {100, "Time Strike", "Repeat a random ", {1,1,1}, 0} //The string was too long
    };


    Weapon weapons_dictionar[7] = {
        {"Fists", "Ol' reliable bare knuckles", {&skills_dictionar[4], &skills_dictionar[10]}},
        {"Rusty Revolver", "Older than the mountains", {&skills_dictionar[0], &skills_dictionar[4]}},
        {"Linda", "Sweetest kisses in the wild west", {&skills_dictionar[2], &skills_dictionar[0]}},
        {"GOAT", "Gun Of Antilope Trilobites", {&skills_dictionar[5], &skills_dictionar[3]}},
        {"Gun & Barrel", "A gun in a barrel", {&skills_dictionar[1], &skills_dictionar[2]}},
        {"Cactus Thrower", "Ouch..", {&skills_dictionar[7], &skills_dictionar[8]},},
        {"Gatling Gun", "RATATATTATATA", {&skills_dictionar[6], &skills_dictionar[5]}}
    };




    Character jose;
    bool boolean = false;
    jose = create_character(weapons_dictionar, boolean);

    Enemy paco = {"Paco", 100, {10, 10, 10}, weapons_dictionar[0], {1.2, 1.3, 1.5}};
    Enemy manolo = {"Manolo", 100, {10, 10, 10}, weapons_dictionar[0], {1.2, 1.3, 1.5}};
    Enemy enemies[2];
    enemies[0] = paco;
    enemies[1] = manolo;

    do_combat(&jose, enemies, 2);
}