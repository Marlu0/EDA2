#include <common.h>

Skill skills[10]{
    /*0*/("The Hermit", "Increases defense a 15%", (1, 1.15, 1)),
    /*1*/("The Chariot", "Increases defence a 30%", (1, 1.3, 1)),
    /*2*/("The Tower", "Increases attack a 15%", (1.15 , 1, 1)),
    /*3*/("The Devil", "Increases attack a 30%", (1.3,1,1)),
    /*4*/("The Hangman", "Eliminates luck", (1,1,0)),
    /*5*/("Weel Of Fortune", "Duplicates luck", (1,1,2)),
    /*6*/("Death of Theo", "Death is the only way", (0.5, 2, 1)),
    /*7*/("The Armadillo", "Nothing like home", (2, 0.5, 1)),
    /*8*/("The Fool", "Decreases defense a 10%, and increase luck a 30%", (1, 0.9, 1.3)),
    /*9*/("Justice", "Faith will guide you", (1.1,1.1,1.1))
};

Weapon weapons[6] = {
    ("Rusty Revolver", "Older that the mountains", skills[0], skills[4]),
    ("Linda", "Sweetest kisses in the wild west", skills[2], skills[0]),
    ("GOAT", "Gun Of Antilope Trilobites ", skills[5], skills[3]),
    ("Gun & Barrel", "A gun in a barrel", skills[1], skills[2]),
    ("Cactus Thrower", "Ouch..", skills[7], skills[8]),
    ("Gatling Gun", "RATATATTATATA", skills[6], skills[5]) 
};