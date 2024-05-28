#include "scenario.h"
#include "decision_functions.h"

Enemy enemies[10]={ //fix these back when you are done.
    {"Cockroach Henchman", 1, {1,1,1,1,1}},
    {"Sheriff Bull", 1, {1,1,1,1,1}},
    {"The Turtle", 1, {1,1,1,1,1}},
    {"Fish", 1, {1,1,1,1,1}},
};


/*INIT_DECISION_LIST
this function receives:
    - nothing
it does:
    - intializes the decision list
it returns:
    -a pointer to the first Decision element
*/
Decision *init_decision_list(Character *character){
    Decision *decision_list = (Decision *)calloc(8, sizeof(Decision));
    Decision * temp = decision_list;

    *temp++ = (Decision){"desert interaction", {{"Look inside the barrel", .outcome_on_character = health_gain}, {"Look behind the wheelbarrow", .outcome_on_character = nothing}, {"Drink some booze", .outcome_on_character = attack_loss_booze}, {"Light a cigarrete (Lucky Strike)", .outcome_on_character = luck_gain_ciggarette}}};

    *temp++ = (Decision){"town interaction", {{"Upgrade your weapon", .outcome_on_character = attack_gain}, {"Go have some fun in the Saloon", .outcome_on_character = health_loss_saloon}, {"Buy new clothes", .outcome_on_character = defense_gain_clothes}, {"Throw a coin in the well", .outcome_on_character = defense_loss_well}}};

    *temp++ = (Decision){"talking to turtle", {{"Look inside a coffin", .outcome_on_character = boring_coffin}, {"Talk to Turtle again", .outcome_on_character = attack_gain_turtle}, {"Take a dead man's watch (He won't use it)", .outcome_on_character = watch_luck_loss}, {"Stare at the ceiling", .outcome_on_character = amazing_ceiling}}};

    *temp++ = (Decision){"talking to bull", {{"You see some pretty horns, grab them", .outcome_on_character = grab_horns}, {"Clean the weapon", .outcome_on_character = weapon_clean}}};

    *temp++ = (Decision){"talking to the bull after turtle interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = (Decision){"talking to turtle after bull interaction", {{"repuesta 2"}, {"respueta 2"}}};

    *temp++ = (Decision){"in the casino good route", {{"You see a group of guys gambling in the roulette, want to join them?", .outcome_on_character = luck_gain_gipsy}, {"Want to play Black Jack?", .outcome_on_character = black_jack}, {"You spit in a bucket", .outcome_on_character = bucket_spit},{"You see a blind man gambling", .outcome_on_character = bucket_spit}}};

    *temp++ = (Decision){"in the casino bad route", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    return decision_list;
}
/*INIT_SCENARIO_LIST
this function receives:
    - the decision list.
it does:
    - inits the scenario list.
it returns:
    - Scenario pointer to the first element
*/
Scenario *init_scenario_list(Decision decision_list[], Character *character){ //does not have enemies

    Scenario *scenario_list = (Scenario *)calloc(8, sizeof(Scenario));
 
    Scenario *temp = scenario_list; 
    
    *temp++ = (Scenario){"DESERT", print_description1, "description completed", .decision = decision_list[0], .enemies = &enemies[0], .numEnemies = 1, .completed = false};
    
    *temp++ = (Scenario){"LOCAL TOWN", print_description2, "description completed1", .decision = decision_list[1], .enemies = &enemies[1], .numEnemies = 0, .completed = false};

    *temp++ = (Scenario){"TURTLE'S TOMBSTONES", print_description3, "description completed2", .decision = decision_list[2], .numEnemies = 0, .completed = false,};
    
    *temp++ = (Scenario){"SHERIFF BULL'S STATION", print_description4, "description_completed3", .decision = decision_list[2], .completed = false, .enemies = &enemies[1], .numEnemies = 1};

    *temp++ = (Scenario){"SHERIFF BULL'S STATION", print_description4, "description_completed4", .decision = decision_list[4], .completed = false, .numEnemies = 0};
     
    *temp++ = (Scenario){"TURTLE'S TOMBSTONES", print_description6, "description_completed5", .decision = decision_list[5], .completed = false, .enemies = &enemies[2]};

    *temp++ = (Scenario){"CASINO1", print_description7, "description_completed6", .decision = decision_list[6], .completed = false};
    
    *temp++ = (Scenario){"CASINO2", print_description8, "description_completed7", .decision = decision_list[6], .completed = false};
    
    return scenario_list;
}
/*FREE_NODE
this function receives:
    - a scenario pointer pointer
it does:
    - creates a node
returns:
-    nothing*/
void create_next_node(Scenario **pointer){ //pass the address of the scenario
    (*pointer)->next = (Scenario *)malloc(sizeof(Scenario));
    if((*pointer)->next == NULL){
        printf("Pointer failed");
    }
    (*pointer)->next->prev = *pointer;
    (*pointer) = (*pointer)->next;
}
/*CREATE_BRANCH
this function receives:
    - a scenario pointer pointer and another scenario pointer pointer
it does:
    - takes the node and creates 2 child nodes.
returns:
-    nothing*/
void create_branch(Scenario **pointer, Scenario **split_pointer){

    (*pointer)->next = (Scenario *)malloc(sizeof(Scenario));
    (*pointer)->next->prev = *pointer; // i think this might be because it goes into the prev of the split_pointer
    (*pointer) = (*pointer)->next;

    (*split_pointer)->other_direction = (Scenario *)malloc(sizeof(Scenario));
    (*split_pointer)->other_direction->prev = (*split_pointer);
    (*split_pointer) = (*split_pointer)->other_direction;
}
/*INIT_SCENARIO_GRAPH
this function receives:
    - scenario_list and first_scenario pointer
it does:
    - inits the scenario graph
returns:
    - nothing
*/
void init_scenario_graph(Scenario *first_scenario, Scenario *scenario_list) {

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

    //it goes first node then in town
    //then up to the turtle and then down to the bull and then the turtle ending and then the bull ending.
}
/*FREE_NODE
this function receives:
    - a scenario pointer pointer
it does:
    - frees a node
returns:
-    nothing*/
void free_node(Scenario **pointer){
    Scenario *temp_pointer = *pointer;
    if((*pointer)->next != NULL){
        *pointer = (*pointer)->next;
    }
    free(temp_pointer);
    pointer = NULL;
}
/*FREE_BRANCHED_NODE
this fucntion receives:
    - scenario pointer pointer, another scenario pointer pointer
it does:
    - frees the root node of the branch
returns:
    - nothing.
*/
void free_branched_node(Scenario **pointer, Scenario **branch_pointer){
    (*branch_pointer) = (*pointer)->other_direction; // you really need to make sure that this makes sense too
    
    free_node(pointer);
}
/*FREE_SCENARIO_GRAPH
this fucntion receives:
    - nothing
it does:
    - frees the entire scenario graph
returns:
    - nothing
*/
void free_scenario_graph(Scenario *first_scenario){

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