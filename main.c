/* Main code */

#include "common.h"
#include "game.h"

int start_menu(){
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

    const char *options[] = {"New Game", "Save game", "Load game", "Customize Character", "Credits", "Exit", NULL};
    int selection = get_selection(options);

    return selection;
    
}

void init_game(){
    int option = start_menu();

    switch (option)
    {
    case 1:
        start_game();
        break;

    case 2:
        char name[20];
        printf("max name length 20"); //find a better way to do the error check on this
        printf("name of save file?\n");
        scanf("%s", name)
        //save_game(name); //implement this later
        break;
    
    case 3:
        char name[20];
        printf("what file do you want to load?\n"); //this too
        printf("%s", name)
        load_game(name);
        break;

    case 4:
        customize_character(Character *character, game); //we need to break the character creation in 2 function. like the modifiers and such that are not part of the customization and then the things that you can customise in a fucntion called "character customization"
        break; /*you should be able to customize your character if it is the first time that you are playing. thus it also has to take in as game state function that says whether there is a game to play.*/
    
    case 5:
        print_credits();
        break;
    default:
        printf("Error");
        break;
    }

}

int main(){
    init_game();
    return 0;
}