#include "common.h"

#define MAX_SKILLS 4
#define MAX_MODIFIERS 4
#define MAX_STRING_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_OPTIONS 2
#define MAX_DECISIONS 2

/* MODIFIER: This will help us with combat calculations like: damage = atk + tempatk */
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
    int health;
    int bullets;
    int balance; //money
    Stats stats;
    Skill skills[MAX_SKILLS];
    Modifier active_modifier[MAX_MODIFIERS];
}Character;

/* ENEMY:
    Has name, stats and an array of skills
    Example:
        - name = "Sheriff Roach"
        - stats = {2, 1, 5, 5, 2}
        - skills = [Shell armor, Intimidate, Play Dead]
*/
typedef struct{
    char name[MAX_STRING_LEN];
    Stats stats;
    Skill skills[MAX_SKILLS];
}Enemy;

/* OPTION:
    Has choice string which displays the choice, its outcome and the change in reputation
    Example:
        - choice = "Spit on his boot"
        - outcome = "Don't you disrespect me young lad!"
        - reputation = -1
*/
typedef struct{
    char choice[MAX_STRING_LEN];
    char outcome[MAX_STRING_LEN];
    int reputation;
}Option;

/* DECISION:
    Has a description of the decision to make and MAX_OPTIONS options
    Example:
        - "You find a snake, it is looking at you in a menacing way, what do you do?"
        - ["Fight", "Flee"]
*/
typedef struct{
    char description[MAX_DESCRIPTION_LEN];
    Option option[MAX_OPTIONS];
}Decision;

/* SCENARIO:
    Has title, description and an array of decisions
    Example:
        - title = "Casino"
        - description = "A place to unleash yourself"
        - decision = [play_blackjack, play_shot-roulette]
*/
typedef struct{
    char title[MAX_STRING_LEN];
    char description[MAX_DESCRIPTION_LEN];
    Decision decision[MAX_DECISIONS];
}Scenario;

/* FUNCTION DECLARATIONS */

void name_character(Character *character);

void reset_character_stats(Character *character);

void assign_points(int *stat, int *statpts, const char *stat_name);

Character create_character();
