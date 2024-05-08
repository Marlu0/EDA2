#include "common.h"

/* MODIFIER: This will help us with combat calculations like: damage = atk + tempatk */
typedef struct{
    int tempatk, tempdef, templuc;
}Modifier;

/* SKILL:
    Has name, description and a modifier, this affects the 
    combat outcome by adding a modifier to stats when fighting.
    Example:
        - name = "Rampage"
        - description = "You shoot twice in the same turn"
        - skill_modifier = {atk, 0, 0} (This will make damage = atk + tempatk = 2*atk)
*/
typedef struct{
    char name[MAX_STRING_LEN];                  
    char description[MAX_STRING_LEN];           
    Modifier skill_modifier;
}Skill;

typedef struct{
    char name[MAX_STRING_LEN];
    char description[MAX_STRING_LEN];
    Skill skill_1;
    Skill skill_2;
}Weapon;

Skill skills[10] = { /*ignora k % sea rojo esta bien*/
    /*0*/{"The Hermit", "Increases defense a 15\%", {1, 1.15, 1}},
    /*1*/{"The Chariot", "Increases defence a 30%", {1, 1.3, 1}},
    /*2*/{"The Tower", "Increases attack a 15%", {1.15 , 1, 1}},
    /*3*/{"The Devil", "Increases attack a 30%", {1.3,1,1}},
    /*4*/{"The Hangman", "Eliminates luck", {1,1,0}},
    /*5*/{"Weel Of Fortune", "Duplicates luck", {1,1,2}},
    /*6*/{"Death of Theo", "Death is the only way", {0.5, 2, 1}},
    /*7*/{"The Armadillo", "Nothing like home", {2, 0.5, 1}},
    /*8*/{"The Fool", "Decreases defense a 10%, and increase luck a 30%", {1, 0.9, 1.3}},
    /*9*/{"Justice", "Faith will guide you", {1.1,1.1,1.1}}
};

Weapon weapons[6] = {
    {"Rusty Revolver", "Older that the mountains", skills[0], skills[4]}, //this does not work because items in an arry need to be constant size and these arrays are not
    {"Linda", "Sweetest kisses in the wild west", skills[2], skills[0]},
    {"GOAT", "Gun Of Antilope Trilobites ", skills[5], skills[3]},
    {"Gun & Barrel", "A gun in a barrel", skills[1], skills[2]},
    {"Cactus Thrower", "Ouch..", skills[7], skills[8]},
    {"Gatling Gun", "RATATATTATATA", skills[6], skills[5]} 
}


/* STATS: Health, maná, attack, defense, luck*/
typedef struct{
    int hp, bp, atk, def, luc;
}Stats;

/* CHARACTER:
    Has name, reputation, Stats, an array of skills and an array of active modifiers
    Example:
        - name = "Lizzy"
        - reputation = -1
        - stats = {100,50,10,20,5}
        - skills = [Rampage, Time Strike]
        - active_modifier = []
*/
typedef struct{
    char name[MAX_STRING_LEN];
    int health;
    int bullets;
    int balance; //money
    Weapon weapon_inventory[10];
    Stats stats;
    Skill skills[MAX_SKILLS];
    Modifier active_modifier[MAX_MODIFIERS];
    Weapon active_weapon;
}Character;

/* ENEMY:
    Has name, stats and an array of skills
    Example:
        - name = "Sheriff Roach"
        - stats = {2, 1, 5, 5, 2}
        - skills = [Shell armor, Intimidate, Play Dead]
*/
typedef struct{
    char name[MAX_STRING_LEN];
    Stats stats;
    Skill skills[MAX_SKILLS];
}Enemy;

/* OPTION:
    Has choice string which displays the choice, its outcome and the change in reputation
    Example:
        - choice = "Spit on his boot"
        - outcome = "Don't you disrespect me young lad!"
        - reputation = -1
*/
typedef struct{
    char choice[MAX_STRING_LEN];
    char outcome[MAX_STRING_LEN];

}Option;

/* DECISION:
    Has a description of the decision to make and MAX_OPTIONS options
    Example:
        - "You find a snake, it is looking at you in a menacing way, what do you do?"
        - ["Fight", "Flee"]
*/
typedef struct{
    char description[MAX_DESCRIPTION_LEN];
    Option option[MAX_OPTIONS];
}Decision;

/* SCENARIO:
    Has title, description and an array of decisions
    Example:
        - title = "Casino"
        - description = "A place to unleash yourself"
        - decision = [play_blackjack, play_shot-roulette]
*/
typedef struct{
    char title[MAX_STRING_LEN];
    char description[MAX_DESCRIPTION_LEN];
    Decision decision[MAX_DECISIONS];
}Scenario;

/* FUNCTION DECLARATIONS */

void name_character(Character *character);

void reset_character_stats(Character *character);

void assign_points(int *stat, int *statpts, const char *stat_name);

Character create_character();

Character customize_character();

Character do_combat(Character *character, Enemy enemy[]);










