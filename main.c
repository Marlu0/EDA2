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
void save_game(Game *game, Scenario *first_scenario){
    if(game->character == NULL || game->current_scenario == first_scenario){
        printf("Error, there is nothing to save");
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
void load_game(Game *game){
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
        return;
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
    Decision *decision_list = init_decision_list();
    Scenario *scenario_list = init_scenario_list(decision_list);

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

}

void play_scenario_completed(Game *game){
    printf("%s\n\n", game->current_scenario->name);
    printf("%s\n--------------------\n", game->current_scenario->completed_decription);
}

void play_scenario_uncompleted(Game *game) {
    printf("%s\n\n", game->current_scenario->name);
    printf("%s\n--------------------\n", game->current_scenario->description);
    
    do_combat(game);

    printf("%s\n\n", game->current_scenario->decision.chapa_del_NPC);

    for(int i = 1; i <= MAX_CHOICES; i++){
        printf("%d. %s\n", i, game->current_scenario->decision.choices->response);
    }
    int option = 0;
    scanf(">%d", &option);

    game->current_scenario->decision.choices[option].response;

    game->current_scenario->decision.choices[option].outcome_on_character(game->character);
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
        
        if(game->state == DEAD){
            printf("\n\n\n\n\nyou died :(\n");
            printf("YOU LOSE!!\n\n\n\n\n");
            return game;
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
                            printf("moving foreward!\n");

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

    //flags and initializations
    bool first_game = true;
    bool game_saved = false;

    Scenario *first_scenario;
    Decision *decision_list = init_decision_list();
    Scenario *scenario_list = init_scenario_list(decision_list);
    int option = 0;

    while(option != 5){

        const char *strings[] = {"new game", "load game", "print credits", "exit", NULL};
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

            case 2:
                save_game(game, first_scenario); //code this.
                break;

            case 3:
                /*do the filename things here.*/
                init_scenario_graph(first_scenario, scenario_list);
      
                load_game(game); //this loads the game current scenario to whatever it has to be
                //after that its chill.
                play_game(game);
                first_game = false;
                break;
        
            /*case 3:
                save_game(character, current_scenario);
                game_saved = true;
                break;*/

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
    free(scenario_list);
    free(decision_list);
}

/*main*/
int main() {
    srand(time(NULL));
    print_main_title();

    Game *game = (Game *)malloc(sizeof(Game));
    if(game == NULL){
        perror("Failed to malloc");
        return -1;
    }
    game->character = NULL;
    game->current_scenario = NULL;
    game->state = PLAYING;
    
    main_menu_selection(game);

    /*free the array function*/
    /*free the decisions function*/

    //you still need to free everything and do the fights
    free(game);
    print_credits();
    return 0;
}