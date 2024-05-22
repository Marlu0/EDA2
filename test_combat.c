#include "global.h"
#include "combat.h"

int main(){
    Character jose = create_character();
    Enemy paco = {"Paco", 100, {10, 10, 10, 10, 10}};
    Enemy manolo = {"Manolo", 100, {10, 10, 10, 10, 10}};
    Enemy enemies[2];
    enemies[0] = paco;
    enemies[1] = manolo;

    do_combat(&jose, enemies, 2);
}