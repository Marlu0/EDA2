#ifndef GAME_H
#define GAME_H

#include "common.h"

/* TYPE DEFINITIONS */

/* STATS: 
Health, maná, attack, defense, luck*/
typedef struct{
    int hp, bp, atk, def, luc;
}Stats;

/* MODIFIER: 
This will help us with combat calculations like: damage = atk + tempatk */
typedef struct{
    float tempatk, tempdef, templuc;
}Modifier;

/* SKILL:
    Has name, description and a modifier, this affects the 
    combat outcome by adding a modifier to stats when fighting.
    Example:
        - name = "Rampage"
        - description = "You double the damage"
        - skill_modifier = {atk, 0, 0} (This will make damage = atk + tempatk = 2*atk)
*/
typedef struct{
    int bulletcost;
    char name[MAX_STRING_LEN];                  
    char description[MAX_STRING_LEN];           
    Modifier skill_modifier;
    int healing; /*where do we put this in the skills?*///ill add it in later
}Skill;

/* WEAPON:
    Has name, description and an array of skill structs.
    Will affect available skills.
    Example:
        - name = "Rusty Revolver"
        - description = "Older than the mountains"
        - skills[] = skills[0], skills[4]
*/
typedef struct{
    char name[MAX_STRING_LEN];
    char description[MAX_STRING_LEN];
    Skill *skills; //Size of the array = NUM_SKILLS
}Weapon;

/* INVENTORY:
    Has:
    - A weapons array of size INVENTORY_SIZE, a macro defined to not have to pass the size on all functions
    - An int fill to track empty slots when adding new weapons
*/
typedef struct{
    Weapon weapons_in_inventory[INVENTORY_SIZE];
    int fill; //create_character sets the fill equal to 1.
}Inventory;

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
    Modifier active_modifiers[NUM_MODIFIERS];
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
    Weapon weapon;
    Modifier active_modifiers[NUM_MODIFIERS];
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
    Has a description of the decision to make and NUM_OPTIONS options
    Example:
        - "You find a snake, it is looking at you in a menacing way, what do you do?"
        - ["Fight", "Flee"]
*/
typedef struct{
    char description[MAX_DESCRIPTION_LEN];
    Option option[NUM_OPTIONS];
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
    Decision decision[NUM_DECISIONS];
}Scenario;

/*we will need to make a fucntion that inits the linked list of all scenaraios. and then a function that iters
over them so that the load function can put you back in the correct section.*/

/* FUNCTION DECLARATIONS */

/* Functions for character creation */

void name_character(Character *character);

void reset_character_stats(Character *character);

void assign_points(int *stat, int *statpts, const char *stat_name);

Character create_character();

/* Functions for inventory */

void obtain_weapon(Character *character, Weapon weapon);

void change_weapon(Character *character);

/* Functions for combat */

int select_skill(Character *character, int attacks_done);

int select_enemy(Enemy *enemies, int number_of_enemies);

void turn_player(Character *character, Enemy *enemies, Stack* attack_stack, int number_of_enemies, int attacks_done);

void do_combat(Character *character, Enemy *enemies, int number_of_enemies);

#endif /* COMMON_H */