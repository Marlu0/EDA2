#include "global.h"
#include "combat.h"

int main(){
    Character jose = create_character();
    Enemy paco = {"Paco", 100, {10, 10, 10, 10, 10}};
    Enemy manolo = {"Manolo", 100, {10, 10, 10, 10, 10}};
    Enemy enemies[2];
    int number_of_enemies = 2;
    enemies[0] = paco;
    enemies[1] = manolo;
    int game_over = 0;
    do_combat(&jose, enemies, number_of_enemies, &game_over);
}