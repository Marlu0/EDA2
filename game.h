#ifndef GAME_H
#define GAME_H

#include "common.h"

/* MODIFIER: This will help us with combat calculations like: damage = atk + tempatk */
typedef struct{
    float tempatk, tempdef, templuc;
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
    int bulletcost;
    char name[MAX_STRING_LEN];                  
    char description[MAX_STRING_LEN];           
    Modifier skill_modifier;
    int healing; /*where do we put this in the skills?*///ill add it in later
}Skill;

typedef struct{
    char name[MAX_STRING_LEN];
    char description[MAX_STRING_LEN];
    Skill **skills; //Size of the array = NUM_SKILLS
}Weapon;

typedef struct{
    /*weapons array it includes the sixe of the array so that
    you don't have to pass it in seperatly in fucntions*/
    Weapon weapons_in_inventory[INVENTORY_SIZE];
    int fill; //init_character sets the fill equal to 1.
}Inventory;

Weapon *init_weapons(Skill skills[]){}; // It has to be in a function so that the array gets created in runtime.
// if it is created in compilation it doesnt know what to do.

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
        - active_modifiers = []
*/
typedef struct{
    char name[MAX_STRING_LEN];
    int health;
    int bullets;
    int balance; //money
    Stats stats;
    Inventory inventory;
    Modifier active_modifiers[MAX_MODIFIERS];
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
    int health;
    Stats stats;
    Skill skill1,skill2;
    Modifier modifier;
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

/*we will need to make a fucntion that inits the linked list of all scenaraios. and then a function that iters
over them so that the load function can put you back in the correct section.*/

/* FUNCTION DECLARATIONS */

void name_character(Character *character);

void reset_character_stats(Character *character);

void assign_points(int *stat, int *statpts, const char *stat_name);

Character create_character();

Character customize_character();

void do_combat(Character *character, Enemy *enemies, int number_of_enemies);

void attack_player(Character *character, Enemy *enemies, int dead_enemies);

#endif /* COMMON_H */
