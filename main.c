/* Main code */

#include "common.h"
#include "game.h"
/*
this fucntion receives:
    - character and scenario.
it:
    - saves the game data in a text file.
returns:
    -nothing
    */
void save_game(Character *character, Scenario *scenario/*figure this out*/){
    /*checks that the cahracter has been initilized*/
    if (character->name[0] == NULL){
        /*at least like this we know a name exists so the character prob inited.*/
        printf("Character Does not exist"); /*in order for this to exist we need to have error handling on charcter creation*/
        return;
    }
    printf("Enter save filename: ");
    char filename[MAX_STRING_LEN]; /*error proof this later*/

    FILE *file_pointer = fopen(filename, "w");
    if(file_pointer == NULL){
        printf("Couldn't open file");
        return;
    }

    /*here is where you need to do the actual writing.*/
    for(int i = 0; character->name[i] != NULL; i++){
        fprintf(file_pointer, "%c", character->name);
    } fprint(file_pointer, "\n");

    fprintf(file_pointer, "%d\n", character->health); // goes without saying that these should be less than 4 million
    fprintf(file_pointer, "%d\n", character->bullets);
    fprintf(file_pointer, "%d\n", character->balance);


    fprintf(file_pointer, "%d\n", character->stats.hp);
    fprintf(file_pointer, "%d\n", character->stats.bp);
    fprintf(file_pointer, "%d\n", character->stats.atk);
    fprintf(file_pointer, "%d\n", character->stats.def);
    fprintf(file_pointer, "%d\n", character->stats.luc);

    fprintf(file_pointer, "%d\n", character->skills); /*NOT COMPLETE*/

    for(int i = 0; i < MAX_MODIFIERS; i++){
        fprintf(file_pointer, "%d\n", character->active_modifiers[i].tempatk);
        fprintf(file_pointer, "%d\n", character->active_modifiers[i].tempdef);
        fprintf(file_pointer, "%d\n", character->active_modifiers[i].templuc);
        fpirntf(file_pointer, "\n");
    }
    
    /*still need weapon inventory and active modifier. they should be passed by referce or maybe not as the acdress of object might change between saves. you also need to work on the report.*/

}
/*
this function receives:
    -   charcater and scenario
use:
    - loads a pervious save froma  text file.
returns:
    nothing.*/
void load_game(Characater *character, Scenario *scenario){

}
/*
This function recieves:
    - Nothing
It does:
    - Print Credits
Returns:
    - Nothing
*/


void print_credits(){
    printf("\nGame Producers:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");

    printf("\nGame Directors:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");
    
    printf("\nSenior programmers:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");
    
    printf("\nJunior programmers:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");

    printf("\nGraphic Designers:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");

    printf("\nStory Boarders:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");

    printf("\nEverything Else:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");
}


/*
this function receives:
    -nothing
Does:
    -calls print_main_meu and does the opening menu
Returns:
    - the selection of the user.
*/
int start_menu(bool first_game){
    print_main_title();
    printf("\n"); //It looks nicer with an extra line
    clock_t start_time = clock();
    int delay = 2;
    

    while(clock() < start_time + CLOCKS_PER_SEC * delay){}
    printf("JUEGAZO DEL GRUPO 4!\n\n");
    start_time = clock();

    while(clock() < start_time + CLOCKS_PER_SEC * delay){}
    printf("VAMOS YA!!\n\n");
    start_time = clock();

    while(clock() < start_time + CLOCKS_PER_SEC * delay){}

    int option;
    const char *options[] = {"New Game", "Load game", "Credits", "Exit", NULL};
    return option = get_selection(options); // this is just the first menu later menus will have the save game and the customize character.
}
/*
this funtion receives:
    -nothing
it does: 
    -calls start_menu and uses the option with a switch to direct the user option
it returns:
    -nothing
*/
void init_game(bool first_game){
    int option = start_menu(first_game);

    switch (option)
    {
    case 1:
        first_game = false;
        start_game();
        break;

    case 2:
        load_game(filename);
        break;

    case 4:
        print_credits();
        break;

    case 5:
        exit(0);

    default:
        printf("Error");
        break;
    }

}
/*main*/
int main(){
    bool first_game = true;
    init_game(first_game);

    return 0;
}