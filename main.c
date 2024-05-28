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
void save_game(Game *game, Scenario *first_scenario){ //you will need to fix this like hell
    if(game->character == NULL || game->current_scenario == first_scenario){
        printf("Error, there is nothing to save\n\n");
        return;
    }
    printf("Enter a filename: ");
    char filename[MAX_STRING_LEN];

    int count; //checking for valid name
    do{
         count = scanf("%s", filename);
    }while(count != 1);
    
    printf("\n");

    FILE *file_p = fopen(filename, "w");
    if(file_p == NULL){
        printf("Failed to open file\n");
        return;
    }

    Character *character = game->character;
    Scenario *scenario = game->current_scenario;

    //SAVING CHARACTER INFO
    fprintf(file_p, "%s\n", character->name);
    fprintf(file_p, "%d\n", character->health);
    fprintf(file_p, "%d\n", character->bullets);

    //printing stats
    fprintf(file_p, "%d\n", character->stats.hp);
    fprintf(file_p, "%d\n", character->stats.bp);
    fprintf(file_p, "%d\n", character->stats.atk);
    fprintf(file_p, "%d\n", character->stats.def);
    fprintf(file_p, "%d\n", character->stats.luc);

    //printing modifier
    fprintf(file_p, "%f\n", character->active_modifiers.tempatk);
    fprintf(file_p, "%f\n", character->active_modifiers.tempdef);
    fprintf(file_p, "%f\n", character->active_modifiers.templuc);

    //SAVING SCENARIO INFO
    fprintf(file_p, "%s", scenario->name); //we will load the scenario from the name
}
/*LOAD GAME
this function receives:
    -   charcater and scenario
use:
    - loads a pervious save froma  text file.
returns:
    nothing.*/
int load_game(Game *game){
    printf("Enter a filename: ");
    char filename[MAX_STRING_LEN];

    int count; //checking for valid name (again)
    do{
         count = scanf("%s", filename);
    }while(count != 1);
    
    printf("\n");

    FILE *file_p = fopen(filename, "r");
    if(file_p == NULL){
        printf("Failed to open file\n");
        return -1;
    }
    // make the game->current_session real 
    Character *character = game->character;
    Scenario *scenario = game->current_scenario;

    char read_name[MAX_STRING_LEN];
    fscanf(file_p, "%s\n", read_name);
    strcpy(character->name, read_name);

    fscanf(file_p, "%d\n", &(character->health));
    fscanf(file_p, "%d\n", &(character->bullets));

    //scaning stats
    fscanf(file_p, "%d\n", &(character->stats.hp));
    fscanf(file_p, "%d\n", &(character->stats.bp));
    fscanf(file_p, "%d\n", &(character->stats.atk));
    fscanf(file_p, "%d\n", &(character->stats.def));
    fscanf(file_p, "%d\n", &(character->stats.luc));

    //scaning modifiers
    fscanf(file_p, "%f\n", &(character->active_modifiers.tempatk));
    fscanf(file_p, "%f\n", &(character->active_modifiers.tempdef));
    fscanf(file_p, "%f\n", &(character->active_modifiers.templuc));

    //do an init_scneario thing and then try match the name to the index and then str_copy everything fro taht index.
    Decision *decision_list = init_decision_list(game->character);
    Scenario *scenario_list = init_scenario_list(decision_list, (game->character));

    char scenario_name[MAX_STRING_LEN];
    fscanf(file_p, "%s\n", scenario_name); //check whether you can scanf strings. maybe not.
    //ok your name can only be one word long now
    //and you have to add the nulll terminator at the end.

    for(int i = 0; i < NUM_SCENARIOS; i++){
        if(strcmp(scenario_list[i].name, scenario_name) == 0){
            *scenario = scenario_list[i];
            break;
        }
    }

    free(decision_list);
    free(scenario_list);

    return 0;
}

void play_scenario_completed(Game *game){ //update this
    printf("%s\n\n", game->current_scenario->name);
    printf("%s\n--------------------\n", game->current_scenario->completed_decription);
}

void play_scenario_uncompleted(Game *game) {
    printf("%s\n\n", game->current_scenario->name);
    (game->current_scenario->print_decription)(game->character);
    printf("\n--------------------\n");
    
    do_combat(game);

    if(game->character->health > 0){
        printf("%s\n\n", game->current_scenario->decision.chapa_del_NPC);

        for(int i = 1; i <= MAX_CHOICES; i++){
            printf("%d. %s\n", i, game->current_scenario->decision.choices[i-1].response);
        }
        int option = 0;

        while(true){
            printf("Your Response: ");
            scanf("%d", &option);
            if(option == 1 || option == 2 || option == 3 || option == 4) {
                break;
            } else {
                printf("Please Enter A Valid number.\n");
            }        
        }

    printf("%s\n", game->current_scenario->decision.choices[option - 1].response);

    (game->current_scenario->decision.choices[option - 1].outcome_on_character)(game->character);
    } else{
        game->state = DEAD;
    }
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
        Character character;
        character = create_character(); //WORKS
        game->character = &character;
    }

    printf("LETS GO!\n\n");

    while(game->state == PLAYING){ //game continues while its state is in "PLAYING"

        //title and description print of new scenario
        if (game->current_scenario->completed == true) {
            play_scenario_completed(game);
        } else{
            play_scenario_uncompleted(game);
        }
        
        if(game->state == DEAD){
            printf("\n\n\n\n\nYOU LOSE!!\n\n\n\n\n");
            return game;
        }

        //checking possible movement directions and playing scenarios of said directions.
        if (game->current_scenario->next == NULL && game->current_scenario->completed == true) {
        } else {
            printf("Which direction do you want to go?\n"); 
        } //it seperates here

        if(game->current_scenario->other_direction == NULL){

            if(game->current_scenario->next == NULL && game->current_scenario->completed == true){ // it is becuase you have won the game
                game->state = WIN;
            } else if(game->current_scenario->prev == NULL){ // up untill here is chill

                int option;

                do {
                    printf("1. Forwards\n"); // it lets you go forewrds its so silly. but its becuase the prev thing is not loading.
                    scanf("Select direction: %d", &option);

                    switch (option) {
                        case 1:
                            game->current_scenario = game->current_scenario->next;
                            printf("Moving forward!\n");
                            break;

                        case 2:
                            printf("Can't go backwards!\n");

                        default:
                            printf("Select a valid option\n");
                    }
                } while (option != 1);
            } else {
                printf("1. Forwards\n");
                printf("2. Backwards\n"); //you need the triple here?

                int option;

                do {
                    scanf("Select direction: %d", &option);

                    switch (option) {
                        case 1:
                            game->current_scenario = game->current_scenario->next;
                            printf("Moving forwards!\n");
                            break;

                        case 2:
                            game->current_scenario = game->current_scenario->prev;
                            printf("Moving back!\n");
                            break;
                        
                        default:
                            printf("Select a valid option\n");
                            break;
                    }
                } while ((option != 1) && (option != 2));
            }
        }
        else {
            printf("1. Left\n");
            printf("2. Right\n");
            printf("3. Backwards\n");
                
		    int option;

            do {
                scanf("Select direction: %d", &option);

                switch (option) {
                    case 1:
                        game->current_scenario = game->current_scenario->next;
                        printf("Moving left!\n");
                        break;

                    case 2:
                        game->current_scenario = game->current_scenario->other_direction;
                        printf("Moving right!\n");
                        break;

                    case 3:
                        game->current_scenario = game->current_scenario->prev;
                        printf("Moving back!\n");
                        break;
                            
                    default:
                        printf("Select a valid option\n");
                        break;
                }
            } while ((option != 1) && (option != 2) && (option != 3));
        }
    }
    printf("\n\n\n\n\n\nYOU WIN!!!\n\n\n\n\n");
    return game;

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

    Scenario *first_scenario = (Scenario *)malloc(sizeof(Scenario));
    Decision *decision_list = init_decision_list(game->character);
    Scenario *scenario_list = init_scenario_list(decision_list, (game->character));
    int option = 0;

    while(option != 5){

        const char *strings[] = {"New Game", "Save Game", "Load Game", "Print Credits", "Exit", NULL};
        option = get_selection(strings);

        switch (option){
            case 1:
                init_scenario_graph(first_scenario, scenario_list);

                game->current_scenario = first_scenario;

                play_game(game);

                free_scenario_graph(first_scenario);
                break;

            case 2:
                save_game(game, first_scenario);
                break;

            case 3:
                init_scenario_graph(first_scenario, scenario_list);
      
                int correctly_loaded = load_game(game);
                if (correctly_loaded == -1){
                    printf("Error: File not found\n\n");
                    break;
                }
                else{
                    play_game(game);

                    free_scenario_graph(first_scenario);
                    break;
                }
                
            case 4:
                print_credits();
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                perror("Error finding game option\n");
                break;
        }
    }
    free(first_scenario);
    free(scenario_list);
    free(decision_list);
}

/*main*/
int main() {
    srand(time(NULL));
    print_main_title();

    Game *game = (Game *)malloc(sizeof(Game)); //you released it 
    if(game == NULL){
        perror("Failed to create game\n");
        return -1;
    }

    game->character = NULL;
    game->current_scenario = NULL;
    game->state = PLAYING;
    Scenario *scenario = (Scenario *)malloc(sizeof(Scenario)); //does it explode?
    free(scenario);
    
    main_menu_selection(game);

    free(game);
    // i am sure that there are memory leaks in places. so i will need to check that later.

    printf("Thanks for playing!\n");
    return 0;
}

//confirming character name does not have proper user defense.
//you need to actually confirm that you can save in some place
//update the save and load functions
//make sure that the play_completed function thing makes sense
//only bother that if you are sure that you can fix the going backwards thing.
//update the print scenarios in the decision_functions.h