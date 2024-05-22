/* Main code */

#include "global.h"
#include "game.h"
#include "combat.h"
#include "global.h"
#include "scenario.h"


/*SAVE GAME
this fucntion receives:
    - character and scenario.
it:
    - saves the game data in a text file.
returns:
    -nothing
    */
void save_game(Character *character, Scenario *scenario/*figure this out*/) {

    /*||PRINTING CHARACTER INFROMATION||*/

    /*checks that the cahracter has been initilized*/
    if (character->name[0] == NULL) {
        /*at least like this we know a name exists so the character prob inited.*/
        printf("Character Does not exist"); /*in order for this to exist we need to have error handling on charcter creation*/
        return;
    }
    printf("Enter save filename: ");
    char filename[MAX_STRING_LEN]; /*error proof this later*/

    FILE *file_pointer = fopen(filename, "w");
    if (file_pointer == NULL) {
        printf("Couldn't open file");
        return;
    }

    /*here is where you need to do the actual writing.*/
    fprintf(file_pointer, "%s\n", character->name); //this is the save game shit gets weird.

    fprintf(file_pointer, "%d\n", character->health); // goes without saying that these should be less than 4 million
    fprintf(file_pointer, "%d\n", character->bullets);
    fprintf(file_pointer, "%d\n", character->balance);


    fprintf(file_pointer, "%d\n", character->stats.hp);
    fprintf(file_pointer, "%d\n", character->stats.bp);
    fprintf(file_pointer, "%d\n", character->stats.atk);
    fprintf(file_pointer, "%d\n", character->stats.def);
    fprintf(file_pointer, "%d\n", character->stats.luc);

    fprintf(file_pointer, "%s\n", character->active_weapon.name);

    fprint(file_pointer, "%d\n", character->inventory.fill);

    int temp_fill = character->inventory.fill;
    fprintf(file_pointer, "%d\n", temp_fill);
    for (int i = 0; i < temp_fill; i++) {
        fprintf(file_pointer, "%s\n", character->inventory.weapons_in_inventory[i].name);
    } //here you are just printing the names of all the weapons you have

    for (int i = 0; i < NUM_MODIFIERS; i++) { /*will this not print all the modifiers tahta re active.*/
        fprintf(file_pointer, "%d\n", character->active_modifiers[i].tempatk);
        fprintf(file_pointer, "%d\n", character->active_modifiers[i].tempdef);
        fprintf(file_pointer, "%d\n", character->active_modifiers[i].templuc);
        fpirntf(file_pointer, "\n");
    }
    fprintf(file_pointer, "%s\n", "END_OF_CHARACTER");

    /*||PRINING SCENARIO INFO||*/



    // you still need to do this 




    /*we can say that when you are printing the scenario that you have passed the scenarios before.*/
    //i think it might be better to orgaise the scenarios as a linked list.
    fclose(file_pointer);
}
/*LOAD GAME
this function receives:
    -   charcater and scenario
use:
    - loads a pervious save froma  text file.
returns:
    nothing.*/
void load_game(Character *character, Scenario *scenario) {} //figure this out.

/*START GAME
this function receives: nothing
it does:
    - stores runs all the other functions that make the game work
Returns:
    - character and scenario for possible later saves.
*/
/*init_start_scenario
this function receives: nothing
it does:
    - creates the starting scenario
it returns:
    - pointer to the start scenario.
*/
Character *start_game(Character *character, Scenario *start, int first_game){
    Skill *skills_list = init_skill_list;
    Weapon *weapons_list = init_weapons_dictionary;
    Character character = create_character(weapons_list, first_game);
    // after you create your character you go to the first scenario (load scenario function.)
    //
}
void continue_game(/*this is the thing that you should put into load file.*/){}

/*
this funtion receives:
    -nothing
it does: 
    -calls start_menu and uses the option with a switch to direct the user option
it returns:
    -nothing
*/

/*INIT_SCENARIO_GRAPH
this function take in:
    - a scneario pointer
it does:
    - initializes the scenarios.
it returns:
    - nothing
*/
void init_scenario_graph(Scenario *first_scenario){
    Decision *decision_list = init_decision_list();
    Scenario *scenario_list = init_scenario_list(decision_list);

    Scenario *temp_scenario;

    temp_scenario = first_scenario;

    for(int i = 0; i < 2)
    *first_scenario = scenario_list[0];
    first_scenario->next = SOMETHING else
    //finishthis things.
}

/* INIT UTILS
this function takes in:
    - character, current_scenario, first_scenario, decision_list, scenario_list
it:
    - inits them.
it returns:
    - nothing*/
void init_utils(Character *character, Scenario *current_scenario){
    
    character = (Character *)malloc(sizeof(Character));
    current_scenario = (Scenario *)malloc(sizeof(Scenario));
}

void main_menu(Character *character, Scenario *current_scenario) {

    bool first_game = true;
    bool game_saved = false;

    Scenario *first_scenario;

    // in the game loop
    int option = 0;
    while(option != 5){

        char strings[5][15] = {"start game", "load game", "print credits", "exit", NULL};
        option = get_selection(strings);

        switch (option){
            case 1:
                /*game_over*/ //put this in a loop in this function
                /*game_win as well*/
                init_scenario_graph(first_scenario);

                current_scenario = first_scenario;

                start_game(character, current_scenario, first_scenario); //we'll get to this eventually.
                first_game = false;
                break;

            case 2:
                /*do the filename things here.*/
                init_scenario_graph(first_scenario);
                load_game(/*filename*/); //where you pull out the current scenario
                start_game(character, current_scenario, first_scenario)
                break;

            case 3:
                save_game(character, current_scenario);
                game_saved = true;
                break;

            case 4:
                print_credits();
                break;

            case 5:
                break;

            default:
                perror("Error finding game option");
                break;
        }
    }
}
/*main*/
int main() {
    bool first_game = true;
    srand(time(NULL));
    print_main_title();

    Character *character;

    Decision *decision_list;
    Scenario *scenario_list;

    Scenario *current_scenario;

    init_untils(character, current_scenario);

    main_menu(character, current_scenario);

    /*free the array function*/
    /*free the decisions function*/
    free(character);
    return 0;
}