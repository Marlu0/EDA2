#include "game.h"

/*SCENARIO STRUCTURES.*/
typedef struct{
<<<<<<< HEAD
    char response[MAX_STRING_LEN];
    Scenario *outcome_on_senario;
=======
    char response[MAX_DESCRIPTION_LEN];
    //Scenario *outcome_on_senario; //not well defined, compiling errors
>>>>>>> 4d621e15962df87be6f4cd1dd33a34b38691e901
    Character *(*outcome_on_character)(Character *);
    /*this is a function pointer that points to a function describing what happened to your character.*/
}Response_Outcome;


typedef struct{
    char chapa_del_NPC[MAX_STRING_LEN];
    Response_Outcome choices[MAX_CHOICES]; /*in hex becuase its fun and silly lol*/

}Decision;
//you will need apointer to indicate where you are.


// you need a meta function that asks where the player wants to go and then loads that scenario and then moves the current pointer over there.
// with this current scenario pointer you can pass it in the ply scenario function to play it out.once the scenario has played out it will then ask you where you want to go.
// you need to change how we are storing the scenarios becasue as it is they have no indication of what next is and we are just going to have to magic number the shit out of it.
//but that is an issue for you once you are done with the EDA coruse.
// htings you need to implement is the meta functions above and you need to change the load Scenarios list function to include some sort of pointer to the next on


typedef struct scenario{
    char name[MAX_STRING_LEN];
    char description[MAX_STRING_LEN]; //description of the scenario.
    struct scenario *next;
    struct scenario *prev;
    struct scenario *other_direction; //there is going to be max  3 direction on any node.
    Decision decision; //this is the thing that you will need to have a library for
    bool completed;
}Scenario;

Decision *init_decision_list();

Scenario *init_scenario_list(Decision decision_list[]);

Scenario *init_first_scenario(Scenario scenario_list[]);

Scenario *init_next_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario);

Scenario *init_other_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario);

int backwards(int direction);

void change_scenario(Scenario *scenario, int direction);

void delete_scenarios(Scenario *scenario);

void play_scenario(Scenario *cuurent_scenario);
