#include "common.h"
#include "game.h"

Skill skills[10] = {
    {10, "The Hermit", "Increases defense a 15%", {1, 1.15, 1}, 0},
    {10, "The Chariot", "Increases defense a 30%", {1, 1.3, 1}, 0},
    {10, "The Tower", "Increases attack a 15%", {1.15 , 1, 1}, 0},
    {10, "The Devil", "Increases attack a 30%", {1.3, 1, 1}, 0},
    {10, "The Hangman", "Eliminates luck", {1, 1, 0}, 10},
    {10, "Weel Of Fortune", "Duplicates luck", {1, 1, 2}, 0},
    {10, "Death of Theo", "Death is the only way", {0.5, 2, 1}, -5},
    {10, "The Armadillo", "Nothing like home", {0.5, 2, 1}, 20},
    {10, "The Fool", "Decreases defense a 10%, and increase luck a 30%", {1, 0.9, 1.3}, 0},
    {10, "Justice", "Faith will guide you", {1.1, 1.1, 1.1}, 0}
};

Weapon weapons[6] = {
    {"Rusty Revolver", "Older that the mountains", &skills[0], &skills[4]},
    {"Linda", "Sweetest kisses in the wild west", &skills[2], &skills[0]},
    {"GOAT", "Gun Of Antilope Trilobites", &skills[5], &skills[3]},
    {"Gun & Barrel", "A gun in a barrel", &skills[1], &skills[2]},
    {"Cactus Thrower", "Ouch..", &skills[7], &skills[8]},
    {"Gatling Gun", "RATATATTATATA", &skills[6], &skills[5]}
};