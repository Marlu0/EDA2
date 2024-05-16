#ifndef DICTIONARIES_H
#define DICTIONARIES_H

/* Here we define the skills and weapons, hard coded as a .h to make adjustments to the playability easier */

#include "common.h"
#include "game.h"

Skill skills_dictionary[11] = {
    /*1*/{10, "The Hermit", "Increases defense a 15%", {1, 1.15, 1}, 0},
    /*2*/{10, "The Chariot", "Increases defense a 30%", {1, 1.3, 1}, 0},
    /*3*/{10, "The Tower", "Increases attack a 15%", {1.15 , 1, 1}, 0},
    /*4*/{10, "The Devil", "Increases attack a 30%", {1.3, 1, 1}, 0},
    /*5*/{10, "The Hangman", "Eliminates luck", {1, 1, 0}, 10},
    /*6*/{10, "Weel Of Fortune", "Duplicates luck", {1, 1, 2}, 0},
    /*7*/{10, "Death of Theo", "Death is the only way", {0.5, 2, 1}, -5},
    /*8*/{10, "The Armadillo", "Nothing like home", {0.5, 2, 1}, 20},
    /*8*/{10, "The Fool", "Decreases defense a 10%, and increase luck a 30%", {1, 0.9, 1.3}, 0},
    /*9*/{10, "Justice", "Faith will guide you", {1.1, 1.1, 1.1}, 0},
    /*10*/{100, "Time Strike", "Repeat a random previous attack and double its damage", {1,1,1}, 0}
    /*11*/{0, "Sword Slash", "their blood, better spent in soil than veins", {100.0, 100.0, 100.0}, 100},
    /*12*/{10, "Sword Strie", "peirce the enemies' unfeeling heart", {200.0, 200.0, 200.0}, 100},

};

Weapon weapons_dictionary[7] = {
    {"Fists", "Ol' reliable bare knuckles", {&skills_dictionary[4], &skills_dictionary[10]}},
    {"Rusty Revolver", "Older than the mountains", {&skills_dictionary[0], &skills_dictionary[4]}},
    {"Linda", "Sweetest kisses in the wild west", {&skills_dictionary[2], &skills_dictionary[0]}},
    {"GOAT", "Gun Of Antilope Trilobites", {&skills_dictionary[5]}, {&skills_dictionary[3]}},
    {"Gun & Barrel", "A gun in a barrel", {&skills_dictionary[1]}, {&skills_dictionary[2]}},
    {"Cactus Thrower", "Ouch..", {&skills_dictionary[7]}, {&skills_dictionary[8]},},
    {"Gatling Gun", "RATATATTATATA", {&skills_dictionary[6]}, {&skills_dictionary[5]}}
};
/*Enemy enemies_dictionary[6] = {
    {"shelly the turtle",,,&weapons_dictionary[4],0 },
    {"bull the bully",,&weapons_dictionary[3],0},
    {"minion 1",,,&weapons_dictionary[1],0},
    {"minion 2",,,&weapons_dictionary[2],0},
    {"mr bubbles",,,&weapons_dictionary[6],0},
    
    };*/

#endif /* DICTIONARIES_H */