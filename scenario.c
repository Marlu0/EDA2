#include "scenario.h"

Enemy enemies[10]={
    {"Cockroach Henchman", 100, {100,50,10,20,5}},
    {"Sheriff Bull", 100, {100,50,10,20,5}},
    {"The Turtle", 100, {100,50,10,20,5}},
    {"Fish", 100, {100,50,10,20,5}},
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
Scenario *init_scenario_list(Decision decision_list[], Character *character){ //does not have enemies

    Scenario *scenario_list = (Scenario *)calloc(8, sizeof(Scenario));

    Scenario *temp = scenario_list;
    char story[2048];
    snprintf(story, sizeof(story),
             "The story begins with our protagonist, %s, waking up in his house to the sound of a noise coming from outside.\n"
             "He jumps out of bed and rushes to the door, alarmed.\n\n"
             "%s: (muttering) What the heck is going on?\n\n"
             "%s opens the door and runs outside. In the desert, he sees the fish's henchman cockroaches fleeing in a hurry.\n\n"
             "%s: (surprised) Those cockroaches! They're the fish's henchmen! \n\n"
             "The cockroaches run faster, but one of them, the hatless and weaker one, stops, blocking %s's path.\n\n"
             "Bandit Cockroach: Well, well, look who we have here. The famous %s, searching for his lost water, huh? FISHY told me you'd be coming. Too bad you won't get far. \n\n"
             "%s: Let me tell you something, stinky cockroach. Nobody, and I mean nobody, steals from me and gets away with it\n\n"
             "Bandit Cockroach: Ha! your adventure ends right here in this desert.", character->name, character->name, character->name, character->name, character->name, character->name, character->name);

    *temp++ = (Scenario){"DESERT", story, character->name, .decision = decision_list[0], .completed = false, .enemies = &enemies[0], .numEnemies = 1};

    snprintf(story, sizeof(story),
             "%s enters the town, his eyes scanning the surroundings as he takes in the unfamiliar sights and sounds.\n\n"
             "%s: (thinking to himself) Alright, %s, time to gather some intel. I need to find out where that slippery fish is hiding.\n"
             "Looks like I'll need more information if I'm going to track down that slippery fish. Lucky for me, there are a couple of places around here where we might find some leads. \n\n"
             "He gestures towards two buildings on either side of the street - a funeral home and a police station. \n\n"
             "%s: Now, where should I start? The funeral home might have some... unconventional sources of information, while the police station could have more... official records. Decisions, decisions.",
             character->name, character->name, character->name, character->name);

    *temp++ = (Scenario){"LOCAL TOWN", story, "description completed1", .decision = decision_list[1], .completed = false, .enemies = &enemies[1], .numEnemies = 0};

    snprintf(story, sizeof(story),
             "%s approaches the funeral home, a somber wooden structure with faded paint and a weathered sign. The door creaks open as he steps inside.\n"
             "%s:\n"
             "(noting the atmosphere) \"This place gives off a different vibe...\"\n"
             "He proceeds cautiously into the dimly lit interior.\n"
             "%s:\n"
             "(to himself) \"Shelly must be around here somewhere...\"\n"
             "%s heads towards the main office, ready to confront the mafia turtle and get the information he needs.\n\n"
             "At the Funeral Home:\n"
             "%s approaches the door of the main office, a solid wooden door with a brass plaque that reads \"Shelly - Manager.\" He takes a deep breath before knocking.\n"
             "%s:\n"
             "(firmly) \"Shelly, we need to talk.\"\n"
             "The door creaks open, revealing a dimly lit room filled with shelves of urns and other funeral paraphernalia. Shelly, a large turtle with a cigar in her mouth, sits behind a cluttered desk.\n"
             "Shelly:\n"
             "(gruffly) \"Well, well, well, what do we have here? Another lost soul looking for answers?\"\n"
             "%s:\n"
             "(determined) \"I'm not lost, Shelly. I'm here for information. About the carapez.\"\n"
             "Shelly's eyes narrow as she considers %s's request.\n"
             "Shelly:\n"
             "(shrewdly) \"Information isn't free, sweetheart. What's in it for me?\"\n"
             "%s:\n"
             "(thoughtfully) \"I have something that might interest you. My will.\"\n"
             "Shelly ponders for a moment before nodding slowly.\n"
             "Shelly:\n"
             "(finally) \"Alright. Knowing this, Mr. Scaled, the only way to get the information is for a big guy with two horns to speak through his mouth. You'll have to get past him to know Fishy's whereabouts, and that's enough for me.\"",
             character->name, character->name, character->name, character->name, character->name, character->name, character->name, character->name, character->name);

    *temp++ = (Scenario){"TURTLE'S TOMBSTONES", story, "description completed2", .decision = decision_list[2], .completed = false, .numEnemies = 0};
    
    snprintf(story, sizeof(story),
             "At the Sheriff's Station:\n"
             "%s approaches the sheriff's station, a sturdy-looking building with the sheriff's emblem hung over the main door. The wood creaks under his feet as he steps inside.\n"
             "%s:\n"
             "(surveying the interior cautiously) \"This is where I'm supposed to find Sheriff Bull...\"\n"
             "He walks down the main hallway, passing by empty jail cells and a cluttered reception desk.\n"
             "%s:\n"
             "(muttering to himself) \"The bull must be around here somewhere...\"\n"
             "He stops in front of a closed door with a sign that reads \"Sheriff's Office.\"\n"
             "%s:\n"
             "(determined) \"This is where I'll find him.\"\n"
             "He opens the door and steps into the sheriff's office, ready to confront the bull and get the information he needs.\n\n"
             "Toro, Chief of Police:\n"
             "The Toro, with his imposing figure, greets you at the police station, his gaze firm and authoritative.\n"
             "\"So, you're the one they sent to take me down. You must be more foolish than you look.\"\n"
             "%s:\n"
             "Stands firm in front of the Toro, his determination palpable.\n"
             "\"I'm not here for pleasantries. I'm here to find FISHY and stop any obstacle in my way, even if it includes the law.\"\n"
             "Toro, Chief of Police:\n"
             "He looks at you with disdain, preparing for the showdown.\n"
             "\"Ha! You're in way over your head, cowboy. Prepare to face the full force of the law!\"",
             character->name, character->name, character->name, character->name, character->name);
    
    *temp++ = (Scenario){"SHERIFF BULL'S STATION", story, "description_completed3", .decision = decision_list[2], .completed = false, .enemies = &enemies[1], .numEnemies = 1};
    
    snprintf(story, sizeof(story),
             "%s enters the sheriff's station, the door squeaking as it opens. The interior is illuminated by fluorescent lights, and there are several agents busy at their desks.\n\n"
             "%s: (murmuring) Let's see what we can find here. \n\n"
             "He approaches the counter where the sheriff is, an imposing bull wearing a cowboy hat. \n\n"
             "Sheriff Bull: (looking up) Good afternoon, how can I help you? \n\n"
             "%s: (determined) Hello, sheriff. I'm looking for information about a fish that's been causing trouble in the area. Have you heard anything about it?\n\n"
             "Sheriff Bull: (frowning) Hmm, that darn Fishy... Yes, we've had some reports about him. But he moves in the shadows, it won't be easy to get that information. \n\n"
             "%s: (nodding) I see. How do I get it then? \n\n"
             "Sheriff Bull: In this town, evil has a single headquarters and hides under a single shell. Defeat the queen of the dead, Shelly the turtle, and you'll get what you crave so much.\n\n"
             "%s: (frowning) The funeral home? There's no time to waste, let's see what that shell with legs has for me. \n\n"
             "%s thanks the sheriff and heads towards the back alley, ready to confront the turtle and get the information he needs.",
             character->name, character->name, character->name, character->name, character->name, character->name);

    *temp++ = (Scenario){"SHERIFF BULL'S STATION", story, "description_completed4", .decision = decision_list[4], .completed = false, .numEnemies = 0};

     snprintf(story, sizeof(story),
             "%s arrives at the funeral home, a gloomy wooden structure with a rusty sign creaking in the wind. The door opens with an ominous squeak as %s steps inside.\n\n"
             "%s: (surveying the interior cautiously) This place gives me the creeps...\n\n"
             "He walks down the main hallway, passing rows of empty chairs and framed photos of the deceased on the walls. \n\n"
             "%s: (muttering to himself) Alright, Shelly must be around here somewhere... \n\n"
             "He stops in front of a closed door with a sign that reads Main Office.\n\n"
             "%s: (determined) This is where I'll find Shelly. \n\n"
             "%s opens the door and steps into the main office, ready to confront the mafia turtle and get the information he needs. \n\n"
             "The mafia turtle greets you in her funeral parlor, a defiant look in her eyes as she prepares for the showdown.\n\n"
             "Shelly: Well, well, well... What do we have here? The Toro's pawn come to do his dirty work? \n\n"
             "%s: He takes a combat stance, his gaze determined as he prepares for battle. I'm not here for chit-chat. Toro wants me to stop you, and I'm not going to let you stand in my way. \n\n"
             "Tortuga Mafiosa: Oh, how brave! But Toro doesn't know who he's messing with. Get ready to face the true might of this city's mafia.",
             character->name, character->name, character->name, character->name, character->name, character->name, character->name);

    *temp++ = (Scenario){"TURTLE'S TOMBSTONES", story, "description_completed5", .decision = decision_list[5], .completed = false, .enemies = &enemies[2]};
    
    snprintf(story, sizeof(story),
             "%s approaches the casino, an ostentatious building with flashing neon lights and lively music resonating from within. The entrance is guarded by two burly gorillas.\n"
             "%s:\n"
             "(surveying the scene) \"This looks like a lively place...\"\n"
             "He strides purposefully towards the casino entrance.\n"
             "%s:\n"
             "(addressing the gorillas) \"Allow me to pass, I have important matters to attend to inside.\"\n"
             "The gorillas regard him with seriousness, evaluating him.\n"
             "Gorilla 1:\n"
             "(furrowing his brow) \"I'm sorry, buddy. We can't just let anyone in.\"\n"
             "%s:\n"
             "(insistent) \"I'm not just anyone. I just need a few minutes with the boss of this place.\"\n"
             "The gorillas exchange glances before reluctantly allowing him entry, albeit with some reluctance.\n"
             "%s:\n"
             "(grateful) \"Thank you, I won't disappoint.\"\n"
             "%s steps through the casino entrance, ready to confront the fish and resolve his quest once and for all.",
             character->name, character->name, character->name, character->name, character->name, character->name);

    *temp++ = (Scenario){"CASINO1", story, "description_completed6", .decision = decision_list[6], .completed = false};

    snprintf(story, sizeof(story),
             "%s approaches the casino, an ostentatious building with flashing neon lights and lively music resonating from within. The entrance is guarded by two burly gorillas.\n"
             "%s:\n"
             "(surveying the scene) \"This looks like a lively place...\"\n"
             "He strides purposefully towards the casino entrance.\n"
             "%s:\n"
             "(addressing the gorillas) \"Allow me to pass, I have important matters to attend to inside.\"\n"
             "The gorillas regard him with seriousness, evaluating him.\n"
             "Gorilla 1:\n"
             "(furrowing his brow) \"I'm sorry, buddy. We can't just let anyone in.\"\n"
             "%s:\n"
             "(insistent) \"I'm not just anyone. I just need a few minutes with the boss of this place.\"\n"
             "The gorillas exchange glances before reluctantly allowing him entry, albeit with some reluctance.\n"
             "%s:\n"
             "(grateful) \"Thank you, I won't disappoint.\"\n"
             "%s steps through the casino entrance, ready to confront the fish and resolve his quest once and for all.",
             character->name, character->name, character->name, character->name, character->name, character->name);

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