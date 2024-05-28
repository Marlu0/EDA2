#include "global.h"
#include "combat.h"

/* This is where we tested the combat functions before completely implementing scenarios and changing 
the do_combat function to receiving game_state */

int main(){
    Character Jose = create_character();
    Enemy Paco = {"Paco", 50, {2, 2, 2, 2, 2}};
    Enemy Manolo = {"Manolo", 50, {2, 2, 2, 2, 2}};
    Enemy enemies[2];
    int number_of_enemies = 2;
    enemies[0] = Paco;
    enemies[1] = Manolo;
    int game_over = 0;
    //do_combat(&Jose, enemies, number_of_enemies, &game_over); do_combat() used to take these variables
}

// Command to create .exe of test_combat
//C:\msys64\ucrt64\bin\gcc.exe -fdiagnostics-color=always -Wall -g test_combat.c game.c global.c combat.c -o test_combat.exe