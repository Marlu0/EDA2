#include "common.h"

typedef struct{
    char name[10];                  // Ex: Rampage
    char description[20];           // Description of the skill Ex: You shoot twice
    int tempatk, tempdef, templuc;  // This will help us with combat calculations:   damage = atk + tempatk
}Skill;                             // For Rampage example: tempatk = atk, that way damage = 2*atk

typedef struct{
    char name[20];
    int graphID;                    // ID for graph
    int hp, mp, atk, def, luc;      // Health, maná, attack, defense, luck
    Skill skills[4];                // 4 slots for skills
}Character;

typedef struct{
    char name[10];
    int hp, mp, atk, def, luc;      // Health, maná, attack, defense, luck
    Skill skills[4];                // 4 slots for skills
}Enemy;

typedef struct{
    char title[10];                 // Name of the scenario
    char description[30];           // Self explanatory
    Decision decision[2];           // Decision list
}Scenario;

typedef struct{
    Option option[2];
    char description[30];
}Decision;

typedef struct{
    char choice[20];            // Spit on his boot
    char outcome[30];           // Example: "I ain't gonna let you cheat on my casino!"
    int reputation;             // Maybe we can create a function that changes CPU's atk and def depending on your reputation
}Option;

/* Maybe we can do the decisions like

print (all i in Scenario.decisions[choice].option[i])
1.option good
2.option evil
print draw weapon
3. *draw weapon*
print stay silent
4. *stay silent*

This way we don't have to print the last two options each time
*/

// Then in a fight we could access like 
/*

If option[FIGHT]
    int winner = 0
    int fight(Enemy enemy, int winner)
    if (winner==1) VICTORY else death()
*/