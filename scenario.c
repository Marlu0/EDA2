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
        {"desert interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}}}, //i need to story board this
        {"town interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}, {"REPUESTA 1.2"}, {"RESPUESTA 1.3"}}}, // we need to find a file format that works.
        {"talking to turtle", {{"REPUESTA 1"}, {"RESPUESTA 2"}}},
        {"talking to bull", {{"REPUESTA 1"}, {"RESPUESTA 2"}}},
        {"talking to the bull after turtle interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}}},
        {"talking to turtle after bull interaction", {{"repuesta 2"}, {"respueta 2"}}},
        {"final interation", {{"REPUESTA 1"}, {"RESPUESTA 2"}}},
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
        {"DESERT", "description0", /*we need to put the other things here*/ .decision = decision_list[0]},
        {"LOCAL TOWN", "description1", .decision = decision_list[1]},
        {"TURTLE'S TOMBSTONES", "description2", .decision = decision_list[2]},
        {"SHERIFF BULL'S STATION", "description3", .decision = decision_list[3]},
        {"SHERIFF BULL'S STATION", "description4", .decision = decision_list[4]},
        {"TURTLE'S TOMBSTONES", "description5", .decision = decision_list[5]},
        {"CASINO", "description 6", .decision = decision_list[6]},
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
Scenario *init_first_scenario(Scenario scenario_list[]){ // I DONT THINK WE NEED THIS
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
Scenario *init_next_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario){ // I DONT THINK WE NEED THIS EITHER
    Scenario next_scenario = scenario_list[index];

    /*setting the doubly linked list.*/
    prev_scenario->next = &next_scenario;
    next_scenario.prev = prev_scenario;
}
/*INIT_SCENARIO_GRAPH
this function takes in:
    - the first scenario
it inits:
    - the scenario graph
it returns:
    - nothing
*/
void init_scenario_graph(Scenario *first_scenario){
    //you need to do a unit test on this. so far it should be easy as hell just export it out into a testing folder.
    Decision *decision_list = init_decision_list();
    Scenario *scenario_list = init_scenario_list(decision_list);

    Scenario *temp_scenario = first_scenario;
    Scenario *split_temp_scenario;

    int i;
    for(i = 0; i < 2; i++)
    {
        *temp_scenario = scenario_list[i];
        temp_scenario = temp_scenario->next;
    }
    //this is where the first split is
    *temp_scenario->next = scenario_list[i++];
    *temp_scenario->other_direction = scenario_list[i++];
    temp_scenario = temp_scenario->next;
    split_temp_scenario = temp_scenario->other_direction;

    //first branch.
    *temp_scenario = scenario_list[i++];
    temp_scenario = temp_scenario->next;


    //second branch.
    *split_temp_scenario = scenario_list[i++];
    split_temp_scenario = split_temp_scenario->next;

    //final node.
    *temp_scenario = scenario_list[i];
    *split_temp_scenario = scenario_list[i];
}

Scenario *init_other_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario){
    Scenario other_scenario = scenario_list[index];

    prev_scenario->other_direction = &other_scenario;
    other_scenario.prev = prev_scenario;
}
void play_scenario(Scenario *scenario, Character *character){
    printf("%s\n\n", scenario->name);
    printf("%s\n\n", scenario->description);
    
    printf("%s\n\n", scenario->decision.chapa_del_NPC);

    int option = get_selection(scenario->decision.choices[0].response, scenario->decision.choices[1].response, scenario->decision.choices[2].response, scenario->decision.choices[3].response, NULL);

    scenario = scenario->decision.choices[option - 1].outcome_on_senario;
    // make sure that the option -1 thing works and figure out the function implementation.

}

void change_scenario(Scenario *scenario){
    printf("where do you want to go?\n");
    int option = get_selection("", "Right", "Back", NULL);

    switch (option)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
}

void delete_scenarios(Scenario *scenario){
    // while there are valid directions to go you should delete them all this is done when you die and want to restart so that memory is not building up forever.
}

void play_scenario(Scenario *cuurent_scenario){ /*this is where you have the fight and everything*/}
//im etting distracted so im puttin all the scenario implementation in here.
