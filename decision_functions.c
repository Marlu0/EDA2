/*
#include "global.h"

void health_potion(Character *character){
    character->health = 100;
}

void poisoned(Character *character){
    (int)(character->health*= 0.9); //will this cast it to a double?
    13;
}

void secretWeapon(Character *character, Skill skills_list[]){
    character->inventory.weapons_in_inventory[character->inventory.fill] = character->active_weapon;
    character->inventory.fill++;

    Weapon secret_weapon = {"legendary sword",
    "Singing iron blade,\nfeinds no more than memeories\nA debt to be paid\n",
    {&skills_list[11], skills_list[12]}};

    character->active_weapon = secret_weapon;
}

/*example of what the character function pointer can do it lets us be a lot more creative with what happens at decisions.*/

/*
Decision *init_decision_list(){ //i have not implemented most of this its just a framework
    Decision decision_list[] = {
        {"CHAPA NUMERO 0", {{"REPUESTA 0.0"}, {"RESPUESTA 0.1"}, {"REPUESTA 0.2"}, {"RESPUESTA 0.3"}}},
        {"CHAPA NUMERO 1", {{"REPUESTA 1.0"}, {"RESPUESTA 1.1"}, {"REPUESTA 1.2"}, {"RESPUESTA 1.3"}}},
        {"CHAPA NUMERO 2", {{"REPUESTA 2.0"}, {"RESPUESTA 2.1"}, {"REPUESTA 2.2"}, {"RESPUESTA 2.3"}}},
        {"CHAPA NUMERO 3", {{"REPUESTA 3.0"}, {"RESPUESTA 3.1"}, {"REPUESTA 3.2"}, {"RESPUESTA 3.3"}}},
        {"CHAPA NUMERO 4", {{"REPUESTA 4.0"}, {"RESPUESTA 4.1"}, {"REPUESTA 4.2"}, {"RESPUESTA 4.3"}}},
        {"CHAPA NUMERO 5", {{"REPUESTA 5.0"}, {"RESPUESTA 5.1"}, {"REPUESTA 5.2"}, {"RESPUESTA 5.3"}}},
    };

    return decision_list;
}
/*
Scenario *init_scenario_list(Decision decision_list[]){

    Scenario scenario_list[] = {
        {"name0", "description0", /*we need to put the other things here .decision = decision_list[0]},
        {"name1", "description1", .decision = decision_list[1]},
        {"name2", "description2", .decision = decision_list[2]},
        {"name3", "description3", .decision = decision_list[3]},
        {"name4", "description4", .decision = decision_list[4]},
        {"name5", "description5", .decision = decision_list[5]},
    };

    return scenario_list;
}

Scenario *init_first_scenario(Scenario scenario_list[], int index){
    Scenario first_scenario = scenario_list[0]; //we just have to make sure that the first one in the list is the starting one
    return &first_scenario;
}

Scenario *init_next_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario){
    Scenario *next_scenario = (Scenario *)malloc(sizeof(Scenario));
    *next_scenario = scenario_list[index];


    /*setting the doubly linked list.
    prev_scenario->next = next_scenario;
    next_scenario->prev = prev_scenario;

}

Scenario *init_other_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario){
    Scenario *other_scenario = (Scenario *)malloc(sizeof(Scenario));
    *other_scenario = scenario_list[index];

    /*this is the same as the above function but with a other route. //it might be useful to store the direction in an arry so that we can appluy marcels function
    prev_scenario->other_direction = other_scenario;
    other_scenario->prev = prev_scenario;
}

int backwards(int direction){
    return (4 - direction);
}

void change_scenario(Scenario *scenario, int direction /*should be passed in as macro){
    int backwards_direction = backwards(direction);
    /*there will need to be error checking here
}

void delete_scenarios(Scenario *scenario){
    // while there are valid directions to go you should delete them all this is done when you die and want to restart so that memory is not building up forever.
}

void play_scenario(Scenario *cuurent_scenario){ /*this is where you have the fight and everything
*/