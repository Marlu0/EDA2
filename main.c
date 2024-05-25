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
//void save_game(Character *character, Scenario *scenario/*figure this out*/) {
//
//    /*||PRINTING CHARACTER INFROMATION||*/
//
//    /*checks that the cahracter has been initilized*/
//    if (character->name[0] == NULL) {
//        /*at least like this we know a name exists so the character prob inited.*/
//        printf("Character Does not exist"); /*in order for this to exist we need to have error handling on charcter creation*/
//        return;
//    }
//    printf("Enter save filename: ");
//    char filename[MAX_STRING_LEN]; /*error proof this later*/
//
//    FILE *file_pointer = fopen(filename, "w");
//    if (file_pointer == NULL) {
//        printf("Couldn't open file");
//        return;
//    }
//
//    /*here is where you need to do the actual writing.*/
//    fprintf(file_pointer, "%s\n", character->name); //this is the save game shit gets weird.
//
//    fprintf(file_pointer, "%d\n", character->health); // goes without saying that these should be less than 4 million
//    fprintf(file_pointer, "%d\n", character->bullets);
//    fprintf(file_pointer, "%d\n", character->balance);
//
//
//    fprintf(file_pointer, "%d\n", character->stats.hp);
//    fprintf(file_pointer, "%d\n", character->stats.bp);
//    fprintf(file_pointer, "%d\n", character->stats.atk);
//    fprintf(file_pointer, "%d\n", character->stats.def);
//    fprintf(file_pointer, "%d\n", character->stats.luc);
//
//    fprintf(file_pointer, "%s\n", character->active_weapon.name);
//
//    fprint(file_pointer, "%d\n", character->inventory.fill);
//
//    int temp_fill = character->inventory.fill;
//    fprintf(file_pointer, "%d\n", temp_fill);
//    for (int i = 0; i < temp_fill; i++) {
//        fprintf(file_pointer, "%s\n", character->inventory.weapons_in_inventory[i].name);
//    } //here you are just printing the names of all the weapons you have
//
//    for (int i = 0; i < NUM_MODIFIERS; i++) { /*will this not print all the modifiers tahta re active.*/
//        fprintf(file_pointer, "%d\n", character->active_modifiers[i].tempatk);
//        fprintf(file_pointer, "%d\n", character->active_modifiers[i].tempdef);
//        fprintf(file_pointer, "%d\n", character->active_modifiers[i].templuc);
//        fpirntf(file_pointer, "\n");
//    }
//    fprintf(file_pointer, "%s\n", "END_OF_CHARACTER");
//
//    /*||PRINING SCENARIO INFO||*/
//
//
//
//    // you still need to do this 
//
//
//
//
//    /*we can say that when you are printing the scenario that you have passed the scenarios before.*/
//    //i think it might be better to orgaise the scenarios as a linked list.
//    fclose(file_pointer);
//}
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

void play_scenario_completed(Game *game){
    printf("%s\n\n", game->current_scenario->name);
    printf("%s\n--------------------\n", game->current_scenario->completed_decription);
}

void play_scenario_uncompleted(Game *game) {
    printf("%s\n\n", game->current_scenario->name);
    printf("%s\n--------------------\n", game->current_scenario->description);
    //fight can go here maybe
    printf("%s\n\n", game->current_scenario->decision.chapa_del_NPC);

    for(int i = 1; i <= MAX_CHOICES; i++){
        printf("%d. %s\n", i, game->current_scenario->decision.choices->response);
    }
    int option = 0;
    scanf("%d", &option);

    game->current_scenario->decision.choices[option].response;
    

}
/*PLAY GAME
This function receives:
    - game pointer
Does:
    - plays the game
Returns:
    - game pointer (incase you want to go to the menu and play again)
*/
Game *play_game(Game *game){
    
    // create character if there is none
    if(game->character == NULL){
        *game->character = create_character();
    }

    while(game->state == PLAYING){ //game continues while its state is in "PLAYING"

        //title and description print of new scenario
        if (game->current_scenario->completed == true) {
            play_scenario_completed(game);
        } else{
            play_scenario_uncompleted(game);
        //DO FIGHT GOES OVER HERE
        }


        if(game->state == WIN){
            printf("\n\n\n\n\n\nYOU WIN!!!\n\n\n\n\n");
            return game;
        } else if(game->state == DEAD){
            printf("\n\n\n\n\nyou died :(\n");
            printf("YOU LOSE!!\n\n\n\n\n");
            return game;
        } else {
            perror("the game is still in a playing state but somehow you are out of the game loop?\n good job you broke it. wuaw >:(\n");
            exit(-1);
        }

        //checking possible movement directions and playing scenarios of said directions.
        if (game->current_scenario->next == NULL && game->current_scenario->completed == true) {
        } else {
            printf("which direction do you want to go?\n"); 
        }
        if(game->current_scenario->other_direction != NULL){

            if(game->current_scenario->next == NULL && game->current_scenario->completed == true){ // it is becuase you have won the game
                game->state == WIN;
            } else if(game->current_scenario->prev == NULL){
                    printf("1. forwards\n");

                    int option;

                    do {
                    scanf("%d", &option);

                    switch (option) {
                        case 1:
                            game->current_scenario = game->current_scenario->next;
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
                            game->current_scenario = game->current_scenario->next;
                            printf("moving left!\n");
                            break;

                        case 2:
                            game->current_scenario = game->current_scenario->other_direction;
                            printf("moving right!\n");

                        case 3:
                            game->current_scenario = game->current_scenario->prev;
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
                        game->current_scenario = game->current_scenario->next;
                        printf("moving left!\n");
                        break;

                    case 2:
                        game->current_scenario = game->current_scenario->prev;
                        printf("moving right!\n");
                        
                    default:
                        printf("select a valid option\n");
                        break;
                }
            } while ((option != 1) || (option != 2));
        }
    }
}



/*MAIN_MENU_SELECTION
This function receives:
    - game pointer
Does:
    - prints the starting menu and does your option
returns:
    - nothing
*/
void main_menu_selection(Game *game) {

    //flags and initializations
    bool first_game = true;
    bool game_saved = false;

    Scenario *first_scenario;
    Decision *decision_list = init_decision_list();
    Scenario *scenario_list = init_scenario_list(decision_list);
    int option = 0;

    while(option != 4){

        char strings[5][15] = {"new game", "load game", "print credits", "exit", NULL};
        if(first_game == false){
            strcpy(strings[0], "play again");
        }
        option = get_selection(strings);

        switch (option){
            case 1:
                /*game_over*/ //put this in a loop in this function
                /*game_win as well*/
                init_scenario_graph(first_scenario, scenario_list);

                game->current_scenario = first_scenario;

                play_game(game);
                first_game = false;
                break;

            //case 2:
            //    /*do the filename things here.*/
            //    Decision *decision_list = init_decision_list();
            //    Scenario *scenario_list = init_scenario_list(decision_list);
            //    init_scenario_graph(first_scenario, scenario_list);
            //
            //    /*load_game(game //filename is found in here );*/
            //    play_game(game);
            //    break;
        
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
    free(scenario_list);
    free(decision_list);
}

/*main*/
int main() {
    srand(time(NULL));
    print_main_title();

    Game *game = init_game_state();
    
    main_menu_selection(game);

    /*free the array function*/
    /*free the decisions function*/

    //you still need to free everything and do the fights
    free(game);
    print_credits();
    return 0;
}