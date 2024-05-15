#include "common.h"
#include "game.h"
#include "combat.h"


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
        {100, "Time Strike", "Repeat a random previous attack and double its damage", {1,1,1}, 0}
    };


    Weapon weapons_dictionar[7] = {
        {"Fists", "Ol' reliable bare knuckles", {&skills_dictionar[4], &skills_dictionar[10]}},
        {"Rusty Revolver", "Older than the mountains", {&skills_dictionar[0], &skills_dictionar[4]}},
        {"Linda", "Sweetest kisses in the wild west", {&skills_dictionary[2], &skills_dictionar[0]}},
        {"GOAT", "Gun Of Antilope Trilobites", {&skills_dictionary[5]}, {&skills_dictionary[3]}},
        {"Gun & Barrel", "A gun in a barrel", {&skills_dictionary[1]}, {&skills_dictionary[2]}},
        {"Cactus Thrower", "Ouch..", {&skills_dictionary[7]}, {&skills_dictionary[8]},},
        {"Gatling Gun", "RATATATTATATA", {&skills_dictionary[6]}, {&skills_dictionary[5]}}
    };




    Character jose;
    bool boolean = false;
    jose = create_character(weapons_dictionar, boolean);

    Enemy paco = {"Paco", 100, {10, 10, 10}, weapons_dictionar[0], };
}