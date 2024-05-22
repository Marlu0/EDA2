#include "global.h"
#include "game.h"
#include "combat.h"


#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4
#define BACKWARDS 5
// its arranged in that if you do backwards - direction you get the other direction

#define NUM_SKILLS 2
#define NUM_MODIFIERS 4
#define MAX_CHOICES 4
#define MAX_STRING_LEN 100
#define NUM_OPTIONS 2
#define NUM_DECISIONS 2
#define INVENTORY_SIZE 8
#define AGGRESSIVE_MODE_ACTIVATOR 2.5



int main(){






    Character jose;
    bool boolean = false;
    jose = create_character();

    Enemy paco = {"Paco", 100, {10, 10, 10}};
    Enemy manolo = {"Manolo", 100, {10, 10, 10}};
    Enemy enemies[2];
    enemies[0] = paco;
    enemies[1] = manolo;

    do_combat(&jose, enemies, 2);
}