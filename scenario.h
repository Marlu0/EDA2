#ifndef SCENARIO_H
#define SCENARIO_H

#include "game.h"

//SCENARIO STRUCTS ARE DEFINED IN GLOBAL

Decision *init_decision_list();

Scenario *init_scenario_list(Decision decision_list[], Character *character);

void create_next_node(Scenario **pointer);

void create_branch(Scenario **pointer, Scenario **split_pointer);

void init_scenario_graph(Scenario *first_scenario, Scenario *scenario_list);

void free_node(Scenario **pointer);

void free_branched_node(Scenario **pointer, Scenario **branch_pointer);

void free_scenario_graph(Scenario *first_scenario);


//you will need apointer to indicate where you are.


// you need a meta function that asks where the player wants to go and then loads that scenario and then moves the current pointer over there.
// with this current scenario pointer you can pass it in the ply scenario function to play it out.once the scenario has played out it will then ask you where you want to go.
// you need to change how we are storing the scenarios becasue as it is they have no indication of what next is and we are just going to have to magic number the shit out of it.
//but that is an issue for you once you are done with the EDA coruse.
// htings you need to implement is the meta functions above and you need to change the load Scenarios list function to include some sort of pointer to the next on

#endif //SCENARIO_H