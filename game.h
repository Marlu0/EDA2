#include "common.h"
#include "common.c"

#define MAX_SKILLS 4
#define MAX_MODIFIERS 4
#define MAX_STRING_LEN 50
#define MAX_DESCRIPTION_LEN 100

/* MODIFIER: 
    This will help us with combat calculations like:
    damage = atk + tempatk 
*/
typedef struct{
    int tempatk, tempdef, templuc;
}Modifier;

/* SKILL:
    Has name, description and a modifier, this affects the 
    combat outcome by adding a modifier to stats when fighting.
    Example:
        - name = "Rampage"
        - description = "You shoot twice in the same turn"
        - skill_modifier = {atk, 0, 0} (This will make damage = atk + tempatk = 2*atk)
*/
typedef struct{
    char name[MAX_STRING_LEN];                  
    char description[MAX_STRING_LEN];           
    Modifier skill_modifier;
}Skill;

/* STATS: Health, maná, attack, defense, luck*/
typedef struct{
    int hp, mp, atk, def, luc;
}Stats;

/* CHARACTER:
    Has name, reputation, Stats, an array of skills and an array of active modifiers
    Example:
        - name = "Lizzy"
        - reputation = -1
        - stats = {100,50,10,20,5}
        - skills = [Rampage, Time Strike]
        - active_modifier = []
*/
typedef struct{
    char name[MAX_STRING_LEN];
    int reputation;
    int health;
    int mana;
    Stats stats;
    Skill skills[MAX_SKILLS];
    Modifier active_modifier[MAX_MODIFIERS];
}Character;

/* ENEMY:
    Has name, stats and an array of skills
    Example:
        - name = "Sheriff Roach"
        - stats = {90, 60, 5, 15, 25}
        - skills = [Shell armor, Intimidate, Play Dead]
*/
typedef struct{
    char name[MAX_STRING_LEN];
    Stats stats;      // Health, maná, attack, defense, luck
    Skill skills[MAX_SKILLS];                // 4 slots for skills
}Enemy;

typedef struct{
    char choice[20];            // Spit on his boot
    char outcome[30];           // Example: "I ain't gonna let you cheat on my casino!"
    int reputation;             // Maybe we can create a function that changes CPU's atk and def depending on your reputation
}Option;

typedef struct{
    Option option[2];
    char description[30];
}Decision;

/* SCENARIO:
    Has title, description and an array of decisions
*/
typedef struct{
    char title[MAX_STRING_LEN];                 // Name of the scenario
    char description[MAX_DESCRIPTION_LEN];           // Self explanatory
    Decision decision[];           // Decision list
}Scenario;

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