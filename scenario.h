#ifndef SCENARIO_H
#define SCENARIO_H

#include "game.h"

/*SCENARIO STRUCTURES.*/

// foreward declaration

struct Scenario;

typedef struct{
    char response[MAX_STRING_LEN];
    struct Scenario *outcome_on_senario;
    Character *(*outcome_on_character)(Character *);
}Response_Outcome;

typedef struct{
    char chapa_del_NPC[MAX_STRING_LEN];
    Response_Outcome choices[MAX_CHOICES];

}Decision;

typedef struct scenario{
    char name[MAX_STRING_LEN];
    char description[MAX_STRING_LEN];
    char completed_decription[MAX_STRING_LEN]; //most recent change it means i have to update the list
    struct scenario *next;
    struct scenario *prev; //leaving this in incase
    struct scenario *other_direction;
    Decision decision;
    bool completed;
}Scenario;

Decision *init_decision_list();

Scenario *init_scenario_list(Decision decision_list[]);

void create_next_node(Scenario **pointer);

void create_branch(Scenario **pointer, Scenario **split_pointer);

void init_scenario_graph(Scenario *first_scenario, Scenario *scenario_list);

void free_node(Scenario **pointer);

void free_branched_node(Scenario **pointer, Scenario **branch_pointer);

void working_free_scenario_graph(Scenario *first_scenario);

void free_scenario_graph_if_prev_works(Scenario *current_scenario);

void play_scenario(Scenario *scenario, Character *character);

void change_scenario(Scenario *scenario);

//you will need apointer to indicate where you are.


// you need a meta function that asks where the player wants to go and then loads that scenario and then moves the current pointer over there.
// with this current scenario pointer you can pass it in the ply scenario function to play it out.once the scenario has played out it will then ask you where you want to go.
// you need to change how we are storing the scenarios becasue as it is they have no indication of what next is and we are just going to have to magic number the shit out of it.
//but that is an issue for you once you are done with the EDA coruse.
// htings you need to implement is the meta functions above and you need to change the load Scenarios list function to include some sort of pointer to the next on

#endif //SCENARIO_H