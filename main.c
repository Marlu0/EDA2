/* Main code */

#include "common.h"
#include "game.h"

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
    do{
        const char *options[] = {"New Game", "Save game", "Load game", "Customize Character", "Credits", "Exit", NULL};
        option = get_selection(options);
        if ((option == 2) && (first_game = true)){
            printf("You have to first play a game before you can save anything");
        };

    }while((first_game == true) && (option == 2));
    return option;
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
        save_game(character, scenario);
        break;
    
    case 3:
        load_game(filename);
        break;

    case 4:
        customize_character(Character *character) // you need to create this function
        break;    
    case 5:
        print_credits();
        break;
    case 6:
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