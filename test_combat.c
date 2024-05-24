#include "global.h"
#include "combat.h"

int main(){
    Character jose = create_character();
    Enemy paco = {"Paco", 50, {2, 2, 2, 2, 2}};
    Enemy manolo = {"Manolo", 50, {2, 2, 2, 2, 2}};
    Enemy enemies[2];
    int number_of_enemies = 2;
    enemies[0] = paco;
    enemies[1] = manolo;
    int game_over = 0;
    do_combat(&jose, enemies, number_of_enemies, &game_over);
}

//C:\msys64\ucrt64\bin\gcc.exe -fdiagnostics-color=always -Wall -g test_combat.c game.c global.c combat.c -o test_combat.exe