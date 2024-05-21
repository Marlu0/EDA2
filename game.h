#ifndef GAME_H
#define GAME_H

#include "global.h"

/*SCENARIO STRUCTURES.*/

/*ITS ME POL, ALL OF THESE WAS A SHITFUCK OF ERRORS, IT CANNOT COMPILE IF YOU USE IT BEFORE 
DECLARING IT os amo*/

//typedef struct{
    //char response[MAX_DESCRIPTION_LEN];
   // Scenario *outcome_on_senario;
   // Character *(*outcome_on_character)(Character *);
    /*this is a function pointer that points to a function describing what happened to your character.*/
//}Response_Outcome;

//typedef struct{
  //  char chapa_del_NPC[MAX_DESCRIPTION_LEN];
    //Response_Outcome choices[MAX_CHOICES]; /*in hex becuase its fun and silly lol*/

//}Decision;
//you will need apointer to indicate where you are.


// you need a meta function that asks where the player wants to go and then loads that scenario and then moves the current pointer over there.
// with this current scenario pointer you can pass it in the ply scenario function to play it out.once the scenario has played out it will then ask you where you want to go.
// you need to change how we are storing the scenarios becasue as it is they have no indication of what next is and we are just going to have to magic number the shit out of it.
//but that is an issue for you once you are done with the EDA coruse.
// htings you need to implement is the meta functions above and you need to change the load Scenarios list function to include some sort of pointer to the next one.













//typedef struct scenario{
  //  char name[MAX_DESCRIPTION_LEN];
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