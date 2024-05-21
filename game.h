#ifndef GAME_H
#define GAME_H

#include "common.h"

#define NUM_SKILLS 2
#define NUM_MODIFIERS 4
#define MAX_CHOICES 4
#define MAX_STRING_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define NUM_OPTIONS 2
#define NUM_DECISIONS 2
#define INVENTORY_SIZE 8
#define AGGRESSIVE_MODE_ACTIVATOR 2.5
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
    char name[MAX_STRING_LEN]; //I HAVE NO IDEA WHY THIS IS RED LIKE WHAT!
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
    Skill *skills[NUM_SKILLS];
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

/*SCENARIO STRUCTURES.*/

/*ITS ME POL, ALL OF THESE WAS A SHITFUCK OF ERRORS, IT CANNOT COMPILE IF YOU USE IT BEFORE 
DECLARING IT os amo*/

//typedef struct{
    //char response[MAX_STRING_LEN];
   // Scenario *outcome_on_senario;
   // Character *(*outcome_on_character)(Character *);
    /*this is a function pointer that points to a function describing what happened to your character.*/
//}Response_Outcome;

//typedef struct{
  //  char chapa_del_NPC[MAX_STRING_LEN];
    //Response_Outcome choices[MAX_CHOICES]; /*in hex becuase its fun and silly lol*/

}Decision;
//you will need apointer to indicate where you are.


// you need a meta function that asks where the player wants to go and then loads that scenario and then moves the current pointer over there.
// with this current scenario pointer you can pass it in the ply scenario function to play it out.once the scenario has played out it will then ask you where you want to go.
// you need to change how we are storing the scenarios becasue as it is they have no indication of what next is and we are just going to have to magic number the shit out of it.
//but that is an issue for you once you are done with the EDA coruse.
// htings you need to implement is the meta functions above and you need to change the load Scenarios list function to include some sort of pointer to the next one.













//typedef struct scenario{
  //  char name[MAX_STRING_LEN];
    //char description[MAX_DESCRIPTION_LEN]; //description of the scenario.
    //struct scenario *next;
    //struct scenario *prev;
   // struct scenario *other_direction; //there is going to be max  3 direction on any node.
  //  Decision decision; //this is the thing that you will need to have a library for
  //  bool completed;
//}Scenario;


/*  WE NEED HAVE AN INIT_sCENARIO FUNCTION THAT TAKES IN */

/*we will need to make a fucntion that inits the linked list of all scenaraios. and then a function that iters
over them so that the load function can put you back in the correct section.*/

/* FUNCTION DECLARATIONS */

/* Functions for character creation */

void name_character(Character *character);

void reset_character_stats(Character *character);

void assign_points(int *stat, int *statpts, const char *stat_name);

Character create_character(Weapon weapon_dictionary[], bool first_game); //it doesnt take in the list here what?

/* Functions for inventory */

void obtain_weapon(Character *character, Weapon weapon);

void change_weapon(Character *character);

Skill *init_skill_list();

Weapon *init_weapons_dictionary(Skill skills_dictionary[]);

#endif // GAME H