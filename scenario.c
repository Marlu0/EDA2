#include "scenario.h"

Decision *init_decision_list(){ // silly list like last time you can make a file implementation another time.
    Decision *decision_list = (Decision *)calloc(8, sizeof(Decision));
    Decision * temp = decision_list;

    *temp++ = {"desert interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = {"town interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = {"talking to turtle", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = {"talking to bull", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = {"talking to the bull after turtle interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = {"talking to turtle after bull interaction", {{"repuesta 2"}, {"respueta 2"}}};

    *temp++ = {"final interation1", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = {"final interation2", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    return decision_list;
}

Scenario *init_scenario_list(Decision decision_list[]){

    Scenario *scenario_list = (Scenario *)calloc(8, sizeof(Scenario));

    Scenario *temp = scenario_list;

    *temp++ = (Scenario){"DESERT", "description0", "description completed0", .decision = decision_list[0]};

    *temp++ = (Scenario){"LOCAL TOWN", "description1", "description completed1", .decision = decision_list[1]};

    *temp++ = (Scenario){"TURTLE'S TOMBSTONES", "description2", "description completed2", .decision = decision_list[2]};
    
    *temp++ = (Scenario){"SHERIFF BULL'S STATION", "description3", "description_completed3", .decision = decision_list[3]};
    
    *temp++ = (Scenario){"SHERIFF BULL'S STATION", "description4", "description_completed4", .decision = decision_list[4]};
    
    *temp++ = (Scenario){"TURTLE'S TOMBSTONES", "description5", "description_completed5", .decision = decision_list[5]};
    
    *temp++ = (Scenario){"CASINO1", "description 6", "description_completed6", .decision = decision_list[6]};

    *temp++ = (Scenario){"CASINO2", "description 6", "description_completed7", .decision = decision_list[6]};

    return scenario_list;
}

void create_next_node(Scenario **pointer){ //pass the address of the scenario
    (*pointer)->next = (Scenario *)malloc(sizeof(Scenario));
    (*pointer)->next->prev = *pointer;
    (*pointer) = (*pointer)->next;
}

void create_branch(Scenario **pointer, Scenario **split_pointer){

    (*pointer)->next = (Scenario *)malloc(sizeof(Scenario));
    (*pointer)->next->prev = *pointer; // i think this might be because it goes into the prev of the split_pointer
    (*pointer) = (*pointer)->next;

    (*split_pointer)->other_direction = (Scenario *)malloc(sizeof(Scenario));
    (*split_pointer)->other_direction->prev = (*split_pointer);
    (*split_pointer) = (*split_pointer)->other_direction;
}

void init_scenario_graph(Scenario *first_scenario, Scenario *scenario_list){ // this function is borken as hell raise it frome the ground up

    Scenario *temp_scenario = first_scenario;

    int i = 0;

    //first node
    *temp_scenario = scenario_list[i++];

    //second node
    create_next_node(&temp_scenario); //ok the pointer does not. update after the funcion
    *temp_scenario = scenario_list[i++];

    //branch
    Scenario *split_scenario = temp_scenario;
    create_branch(&temp_scenario, &split_scenario);

    *temp_scenario = scenario_list[i++];
    *split_scenario = scenario_list[i++];

    //upper route
    create_next_node(&temp_scenario);
    *temp_scenario = scenario_list[i++];

    //lower route
    create_next_node(&split_scenario);
    *split_scenario = scenario_list[i++];

    //last node up
    create_next_node(&temp_scenario);
    *temp_scenario = scenario_list[i++];

    //last node down
    create_next_node(&split_scenario);
    *split_scenario = scenario_list[i];
}

void free_node(Scenario **pointer){ //first_scneario did not update
    Scenario *temp_pointer = *pointer;
    if((*pointer)->next != NULL){
        *pointer = (*pointer)->next;
    }
    free(temp_pointer);
    pointer == NULL;
}

void free_branched_node(Scenario **pointer, Scenario **branch_pointer){
    (*branch_pointer) = (*pointer)->other_direction;
    free_node(pointer);
}

void working_free_scenario_graph(Scenario *first_scenario){

    free_node(&first_scenario);

    Scenario *branched_scneario = first_scenario;

    free_branched_node(&first_scenario, &branched_scneario);

    while(first_scenario->next != NULL){
        free_node(&first_scenario);
    }
    while(branched_scneario->next != NULL){
        free_node(&branched_scneario);
    }
}

void free_scenario_graph_if_prev_works(Scenario *current_scenario){
    while(current_scenario->prev != NULL){
        current_scenario = current_scenario->prev;
    }
    free_node(&current_scenario);

    Scenario *branched_scneario = current_scenario;

    free_branched_node(&current_scenario, &branched_scneario);

    while(current_scenario != NULL){
        free_node(&current_scenario);
    }
    while(branched_scneario != NULL){
        free_node(&branched_scneario);
    }
}

void play_scenario(Scenario *scenario, Character *character){
    printf("%s\n\n", scenario->name);
    printf("%s\n\n", scenario->description);
    
    printf("%s\n\n", scenario->decision.chapa_del_NPC);

    // GET SELECTION WONT WORK FOR VARIABLES, THEY HAVE TO BE CONSTANT STRINGS. MAYBE CREATE ANOTHER FUNCTION THAT PRINTS VARIABLE STRINGS
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

void play_scenario(Scenario *cuurent_scenario){ /*this is where you have the fight and everything*/}
//im etting distracted so im puttin all the scenario implementation in here.
