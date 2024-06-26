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
void save_game(Game *game){ //you will need to fix this like hell
    printf("Enter a filename: ");
    char filename[MAX_NAME_LEN];

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

    // no need to save health or bullets as they can be found with hp and bp. reduce file size.

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
    fprintf(file_p, "%s\n", scenario->name); //we will load the scenario from the name
    fclose(file_p);
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

    char name[MAX_NAME_LEN];
    char *read_character_name = fgets(name, MAX_NAME_LEN, file_p);

    if(read_character_name == NULL){
        printf("Error finding character name");
        return -1;
    }
    int length1 = strlen(name);
    name[length1] = '\0';
    strcpy(character->name, name);

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
    char *read_scenario_name = fgets(scenario_name, MAX_STRING_LEN, file_p);

    if(read_scenario_name == NULL){
        printf("Error Loading File\n");
        return -1;
    }
    int length2 = strlen(scenario_name);
    
    scenario_name[length2] = '\0';


    
    for(int i = 0; i < NUM_SCENARIOS; i++){
        if(strcmp(scenario_list[i].name, scenario_name) == 0){
            *scenario = scenario_list[i];
            break;
        }
    }

    free(decision_list);
    free(scenario_list);

    fclose(file_p);

    return 0;
}
/*PLAY_SCENARIO_COMPLETED
this function takes in:
    - game pointer
it does:
    - plays out the scenario you are in and gives a little scenario. (as you've already completed the scenario.)
it returns:
    - nothing*/
void play_scenario_completed(Game *game){ //you need to make it so that the completed counter goes up when you are done
    printf("%s (again)\n", game->current_scenario->name);
    (game->current_scenario->print_decription2)(game->character);
    printf("\n--------------------\n");

    //im not sure if we want anything else happen here really
}
/*PLAY_SCENARIO_UNCOMPLETED
this function takes in:
    - game pointer
it does:
    - plays out the current scenario that you are in
it returns:
    - nothing*/
void play_scenario_uncompleted(Game *game) {
    printf("%s\n\n", game->current_scenario->name);
    (game->current_scenario->print_decription)(game->character);
    printf("\n--------------------\n");
    
    if(strcmp(game->current_scenario->name, "CASINO")){
        do_combat(game);
    };
    if(game->character->health > 0){
        printf("%s\n\n", game->current_scenario->decision.chapa_del_NPC);

        for(int i = 1; i <= MAX_CHOICES; i++){
            printf("%d. %s\n", i, game->current_scenario->decision.choices[i-1].response);
        }
        int option;
        bool valid = false;
        while(!valid){

            printf("Enter your selection\n");

            if (scanf(" %d", &option) != 1) {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n'); // Flush the input buffer
                continue;
            }

            int extra;
            while ((extra = getchar()) != '\n' && extra != EOF);

            // Validating input
            if (option < 1 || option > 4) {
                printf("Invalid selection. Please try again.\n");
                continue;
            }

            valid = true;
        }

        printf("%s\n", game->current_scenario->decision.choices[option - 1].response);

        (game->current_scenario->decision.choices[option - 1].outcome_on_character)(game->character);
        

        if(!strcmp(game->current_scenario->name, "CASINO")){
            (game->current_scenario->print_decription2)(game->character);
            do_combat(game);
        };
        game->current_scenario->completed = true;
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
            if(game->state == PLAYING){
                printf("Save?\n1. Yes\n2. No\n");
                bool valid = false;
                int option = 0;
                while(!valid){
                    printf("Enter your selection\n");

                    if (scanf(" %d", &option) != 1) {
                        printf("Invalid input. Please enter a number.\n");
                        while (getchar() != '\n'); // Flush the input buffer
                        continue;
                    }

                    int extra;
                    while ((extra = getchar()) != '\n' && extra != EOF);

                    // Validating input
                    if (option == 1 || option == 2) {
                        valid = true;
                    } else{
                        printf("Invalid selection. Please try again.\n");
                        continue;
                    }
                }
                if(option == 1){
                    save_game(game);
                    printf("back to the game!\n");
                }
            }
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

                const char *options[] = {"Forwards", NULL};
                get_selection(options);
                game->current_scenario = game->current_scenario->next;
                printf("Moving forwards!\n");

            } else {
                int option;
                const char *options[] = {"Forwards", "Backwards", NULL};
                option = get_selection(options);

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
                        break;
                }
            }
        }
        else {
                
		    int option;
            const char *options[] = {"Left", "Right", "Backwards", NULL};
            option = get_selection(options);
            char name[MAX_STRING_LEN];
                
            switch (option) {
                case 1:
                    strcpy(game->character->name, name);
                    game->current_scenario = game->current_scenario->next;
                    printf("Moving right!\n");
                    strcpy(name, game->character->name);                    
                    break;

                case 2:
                    strcpy(game->character->name, name);
                    game->current_scenario = game->current_scenario->other_direction;
                    printf("Moving right!\n");
                    strcpy(name, game->character->name);                    
                    break;

                case 3:
                    strcpy(game->character->name, name);
                    game->current_scenario = game->current_scenario->prev;
                    printf("Moving back!\n");
                    strcpy(name, game->character->name);
                    break;
                            
                default:
                    printf("Select a valid option\n");
                    break;
            }
        }
    }
    printf("\n\n\nYou've successfully recovered the water! You're saved! You win!!\n\n\n\n");
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
    bool first_game = true;

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
                if(first_game){
                    printf("You have no game to save");
                } else {
                    save_game(game);
                }
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

                    break;
                }
                free_scenario_graph(first_scenario);
                
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

    Game *game = (Game *)malloc(sizeof(Game));
    if(game == NULL){
        perror("Failed to create game\n");
        return -1;
    }

    game->character = NULL;
    game->current_scenario = NULL;
    game->state = PLAYING;
    
    main_menu_selection(game);

    free(game);

    printf("Thanks for playing!\n");
    return 0;
} 