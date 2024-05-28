#include "scenario.h"

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
Decision *init_decision_list(){
    Decision *decision_list = (Decision *)calloc(8, sizeof(Decision));
    Decision * temp = decision_list;

    *temp++ = (Decision){"desert interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = (Decision){"town interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = (Decision){"talking to turtle", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = (Decision){"talking to bull", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = (Decision){"talking to the bull after turtle interaction", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = (Decision){"talking to turtle after bull interaction", {{"repuesta 2"}, {"respueta 2"}}};

    *temp++ = (Decision){"final interation1", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

    *temp++ = (Decision){"final interation2", {{"REPUESTA 1"}, {"RESPUESTA 2"}}};

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
Scenario *init_scenario_list(Decision decision_list[]){ //does not have enemies

    Scenario *scenario_list = (Scenario *)calloc(8, sizeof(Scenario));

    Scenario *temp = scenario_list;

    *temp++ = (Scenario){"DESERT", "The story begins with our protagonist, Camo Joe, waking up in his house to the sound of a noise coming from outside.\n He jumps out of bed and rushes to the door, alarmed.\n\n Camo Joe: (muttering) What the heck is going on?\n\n Camo Joe opens the door and runs outside. In the desert, he sees the fish's henchman cockroaches fleeing in a hurry.\n\n Camo Joe: (surprised) Those cockroaches! They're the fish's henchmen! \n\n The cockroaches run faster, but one of them, the hatless and weaker one, stops, blocking Camo Joe's path.\n\n Bandit Cockroach: Well, well, look who we have here. The famous Camo Joe, searching for his lost water, huh? FISHY  told me you'd be coming. Too bad you won't get far. \n\n Camo Joe: Let me tell you something, stinky cockroach. Nobody, and I mean nobody, steals from me and gets away with it\n\n Bandit Cockroach: Ha! your adventure ends right here in this desert.", "Just a barren wasteland, looks like a fight just took place here", .decision = decision_list[0], .completed = false, .enemies = &enemies[0], .numEnemies = 1};

    *temp++ = (Scenario){"LOCAL TOWN", "Camo Joe enters the town, his eyes scanning the surroundings as he takes in the unfamiliar sights and sounds.\n\n Camo Joe: (thinking to himself) Alright, Camo Joe, time to gather some intel. I need to find out where that slippery fish is hiding.\n Looks like I'll need more information if I'm going to track down that slippery fish. Lucky for me, there are a couple of places around here where we might find some leads. \n\n He gestures towards two buildings on either side of the street - a funeral home and a police station. \n\n Camo Joe: Now, where should I start? The funeral home might have some... unconventional sources of information, while the police station could have more... official records. Decisions, decisions.", "description completed1", .decision = decision_list[1], .completed = false, .enemies = &enemies[1], .numEnemies = 0};

    *temp++ = (Scenario){"TURTLE'S TOMBSTONES", "description2", "description completed2", .decision = decision_list[2], .completed = false, .numEnemies = 0};
    
    *temp++ = (Scenario){"SHERIFF BULL'S STATION", "description3", "description_completed3", .decision = decision_list[2], .completed = false, .enemies = &enemies[1], .numEnemies = 1};
    
    *temp++ = (Scenario){"SHERIFF BULL'S STATION", "Camo Joe enters the sheriff's station, the door squeaking as it opens. The interior is illuminated by fluorescent lights, and there are several agents busy at their desks.\n\n Camo Joe: (murmuring) Let's see what we can find here. \n\n He approaches the counter where the sheriff is, an imposing bull wearing a cowboy hat. \n\n Sheriff Bull: (looking up) Good afternoon, how can I help you? \n\n Camo Joe: (determined) Hello, sheriff. I'm looking for information about a fish that's been causing trouble in the area. Have you heard anything about it?\n\n Sheriff Bull: (frowning) Hmm, that darn Fishy... Yes, we've had some reports about him. But he moves in the shadows, it won't be easy to get that information. \n\n Camo Joe: (nodding) I see. How do I get it then? \n\n Sheriff Bull: In this town, evil has a single headquarters and hides under a single shell. Defeat the queen of the dead, Shelly the turtle, and you'll get what you crave so much.\n\n Camo Joe: (frowning) The funeral home? There's no time to waste, let's see what that shell with legs has for me. \n\n Camo Joe thanks the sheriff and heads towards the back alley, ready to confront the turtle and get the information he needs.", "description_completed4", .decision = decision_list[4], .completed = false, .numEnemies = 0};
    
    *temp++ = (Scenario){"TURTLE'S TOMBSTONES", "Camo Joe arrives at the funeral home, a gloomy wooden structure with a rusty sign creaking in the wind. The door opens with an ominous squeak as Camo Joe steps inside.\n\n Camo Joe: (surveying the interior cautiously) This place gives me the creeps...\n\n He walks down the main hallway, passing rows of empty chairs and framed photos of the deceased on the walls. \n\n Camo Joe: (muttering to himself) Alright, Shelly must be around here somewhere... \n\n He stops in front of a closed door with a sign that reads Main Office.\n\n Camo Joe: (determined) This is where I'll find Shelly. \n\n Camo Joe opens the door and steps into the main office, ready to confront the mafia turtle and get the information he needs. \n\n The mafia turtle greets you in her funeral parlor, a defiant look in her eyes as she prepares for the showdown.\n\n Shelly: Well, well, well... What do we have here? The Toro's pawn come to do his dirty work? \n\n Camo Joe: He takes a combat stance, his gaze determined as he prepares for battle. I'm not here for chit-chat. Toro wants me to stop you, and I'm not going to let you stand in my way. \n\n Tortuga Mafiosa:  Oh, how brave! But Toro doesn't know who he's messing with. Get ready to face the true might of this city's mafia.", "description_completed5", .decision = decision_list[5], .completed = false, .enemies = &enemies[2]};
    
    *temp++ = (Scenario){"CASINO1", "Camo Joe approaches the casino, an ostentatious building with flashing neon lights and lively music resonating from within. The entrance is guarded by two burly gorillas. \n\n ", "description_completed6", .decision = decision_list[6], .completed = false};

    *temp++ = (Scenario){"CASINO2", "description 6", "description_completed7", .decision = decision_list[6], .completed = false};

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