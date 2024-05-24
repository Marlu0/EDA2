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

/*PLAY GAME
this function receives: nothing
it does:
    - stores runs all the other functions that make the game work
Returns:
    - character and scenario for possible later saves.
*/
void play_scenario_completed(Character *character, Scenario *current_scenario){
    printf("%s\n\n", current_scenario->name);
    printf("%s\n", current_scenario->completed_decription);
}

void play_scenario_uncompleted(Character *character, Scenario *current_scenario) {
    printf("%s\n\n", current_scenario->name);
    printf("%s\n", current_scenario->description);
    printf("%s\n", current_scenario->decision.chapa_del_NPC);


}

Character *play_game(Character *character, Scenario *current_scenario){
    bool win = false;
    Character character = create_character();
    while(){
        if (current_scenario->completed == true) {
            play_scenario_completed(character, current_scenario);
        } else{
            play_scenario_uncompleted(character, current_scenario);
        }
        if (current_scenario->next == NULL && current_scenario->completed == true) {
        } else {
            printf("which direction do you want to go?\n"); 
        }
        if(current_scenario->other_direction != NULL){

            if(current_scenario->next == NULL && current_scenario->completed == true){ // it is becuase you have won the game
                printf("YOU WIN!!!\n\n");
                win = true;
            } else if(current_scenario->prev == NULL){
                    print("1. forwards\n");

                    int option;

                    do {
                    scanf("%d", &option);

                    switch (option) {
                        case 1:
                            current_scenario = current_scenario->next;
                            printf("moving left!\n");

                        case 2:
                            printf("can't go backwards!\n");
                            // no break so that it also does the option after.

                        default:
                            printf("select a valid option\n");
                            break;
                    }
                } while (option != 1);

            } else {
                printf("1. left\n");
                printf("2. right\n");
                printf("3. backwards\n");

                int option;

                do {
                    scanf("%d", &option);

                    switch (option) {
                        case 1:
                            current_scenario = current_scenario->next;
                            printf("moving left!\n");
                            break;

                        case 2:
                            current_scenario = current_scenario->other_direction;
                            printf("moving right!\n");

                        case 3:
                            current_scenario = current_scenario->prev;
                            printf("moving back!\n");

                        default:
                            printf("select a valid option\n");
                            break;
                    }
                } while ((option != 1) || (option != 2) || (option != 3));
            }

            

        } else {
            printf("1. forewards\n");
            printf("2. backwards\n");

            int option;

            do {
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        current_scenario = current_scenario->next;
                        printf("moving left!\n");
                        break;

                    case 2:
                        current_scenario = current_scenario->prev;
                        printf("moving right!\n");
                        
                    default:
                        printf("select a valid option\n");
                        break;
                }
            } while ((option != 1) || (option != 2));
        }
    }
    //if win is true end the game
}

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
                Decision *decision_list = init_decision_list();
                Scenario *scenario_list = init_scenario_list(decision_list);
                init_scenario_graph(first_scenario, scenario_list);

                first_scenario = current_scenario;

                play_game(character, current_scenario); //we'll get to this eventually.
                first_game = false;
                break;

            case 2:
                /*do the filename things here.*/
                Decision *decision_list = init_decision_list();
                Scenario *scenario_list = init_scenario_list(decision_list);
                init_scenario_graph(first_scenario, scenario_list);

                load_game(character, current_scenario /*filename is found in here*/);
                play_game(character, current_scenario);
                break;

            /*case 3:
                save_game(character, current_scenario);
                game_saved = true;
                break;*/

            case 3:
                print_credits();
                break;

            case 4:
                break;

            default:
                perror("Error finding game option");
                break;
        }
    }
}
/*main*/
int main() {
    srand(time(NULL));
    print_main_title();

    Character *character;

    Scenario *current_scenario;

    init_untils(character, current_scenario);

    main_menu_selection(character, current_scenario);

    /*free the array function*/
    /*free the decisions function*/
    free(character);
    free(current_scenario);
    return 0;
}