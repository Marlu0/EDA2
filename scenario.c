#include "scenario.h"
/* INIT_DECISION_LIST
This function receives:
    - nothing
It does:
    - inits the decision array
Returns:
    - pointer to array
*/
Decision *init_decision_list(){ // silly list like last time you can make a file implementation another time.
    Decision decision_list[] = {
        {"CHAPA NUMERO 0", {{"REPUESTA 0.0"}, {"RESPUESTA 0.1"}, {"REPUESTA 0.2"}, {"RESPUESTA 0.3"}}}, //i need to story board this
        {"CHAPA NUMERO 1", {{"REPUESTA 1.0"}, {"RESPUESTA 1.1"}, {"REPUESTA 1.2"}, {"RESPUESTA 1.3"}}}, // we need to find a file format that works.
        {"CHAPA NUMERO 2", {{"REPUESTA 2.0"}, {"RESPUESTA 2.1"}, {"REPUESTA 2.2"}, {"RESPUESTA 2.3"}}},
        {"CHAPA NUMERO 3", {{"REPUESTA 3.0"}, {"RESPUESTA 3.1"}, {"REPUESTA 3.2"}, {"RESPUESTA 3.3"}}},
        {"CHAPA NUMERO 4", {{"REPUESTA 4.0"}, {"RESPUESTA 4.1"}, {"REPUESTA 4.2"}, {"RESPUESTA 4.3"}}},
        {"CHAPA NUMERO 5", {{"REPUESTA 5.0"}, {"RESPUESTA 5.1"}, {"REPUESTA 5.2"}, {"RESPUESTA 5.3"}}},
    };

    return decision_list;
}
/*INIT_SCENARIO_LIST
this fucntion receives:
    - decision_list
it does:
    - inits the scenario list
it returns:
    - pointer to an the new list.
*/
Scenario *init_scenario_list(Decision decision_list[]){

    Scenario scenario_list[] = {
        {"name0", "description0", /*we need to put the other things here*/ .decision = decision_list[0]},
        {"name1", "description1", .decision = decision_list[1]},
        {"name2", "description2", .decision = decision_list[2]},
        {"name3", "description3", .decision = decision_list[3]},
        {"name4", "description4", .decision = decision_list[4]},
        {"name5", "description5", .decision = decision_list[5]},
    };
    return scenario_list;
}
/*INIT_FIRST_SCENARIO
this fucntion receives:
    - scenario list
it does:
    creates aninstance of the first scenario.
it returns:
    - the address to current scenario (this one)
*/
Scenario *init_first_scenario(Scenario scenario_list[]){ //first scenario is at index 0 of the list.
    Scenario first_scenario = scenario_list[0];
    return &first_scenario;
}
/*INIT_NEXT_SCENARIO
this fucntion receives:
    - scenario list, index of specific scenario to load, pointer to the previous scenario
it does:
    - loads the nex scenario and puts it in *next of the prev
it returns:
    - new current scenario
*/
Scenario *init_next_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario){
    Scenario next_scenario = scenario_list[index];

    /*setting the doubly linked list.*/
    prev_scenario->next = &next_scenario;
    next_scenario.prev = prev_scenario;
}

Scenario *init_other_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario){
    Scenario other_scenario = scenario_list[index];

    prev_scenario->other_direction = &other_scenario;
    other_scenario.prev = prev_scenario;
}

int backwards(int direction){
    return (4 - direction);
}

void change_scenario(Scenario *scenario, int direction /*should be passed in as macro*/){
    int backwards_direction = backwards(direction);
    /*there will need to be error checking here*/
}

void delete_scenarios(Scenario *scenario){
    // while there are valid directions to go you should delete them all this is done when you die and want to restart so that memory is not building up forever.
}

void play_scenario(Scenario *cuurent_scenario){ /*this is where you have the fight and everything*/}
//im etting distracted so im puttin all the scenario implementation in here.
