#ifndef GLOBAL_H
#define GLOBAL_H

/* global.h contains the macros and the most used libraries and functions */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// foreward declaration

struct Scenario;

/* MACROS */

#define TABLE_SIZE 100
#define MAX_STRING_LEN 1000
#define MAX_CHOICES 4
#define NUM_SCENARIOS 8

/* GENERAL FUNCTION DECLARATIONS */

int get_selection(const char *strings[]);

void print_main_title();

void print_credits();

/* DEFINITIONS OF GAME STRUCTS */

/* STATS: 
Health, maná, attack, defense, luck*/
typedef struct{
    int hp, bp, atk, def, luc;
} Stats;

/* MODIFIER: 
This will help us with combat calculations like: damage = atk + tempatk */
typedef struct{
    float tempatk, tempdef, templuc;
} Modifier;

/* SKILL:
    Has name, description and a modifier, this affects the 
    combat outcome by adding a modifier to stats when fighting.
    Example:
        - name = "Rampage"
        - description = "You double the damage"
        - skill_modifier = {atk, 0, 0} (This will make damage = atk + tempatk = 2*atk)
*/
typedef struct{
    int bulletcost;
    char name[MAX_STRING_LEN];
    char description[MAX_STRING_LEN];
    Modifier skill_modifier;
} Skill;

/* ENEMY:
    Example:
        - name = "Sheriff Roach"
        - stats = {2, 1, 5, 5, 2}
        - skill_1 = Shell armor
        - skill_2 = Play Dead
*/
typedef struct{
    char name[MAX_STRING_LEN];
    int health;
    Stats stats;
} Enemy;

/* CHARACTER:
    Example:
        - name = "Lizzy"
        - stats = {100,50,10,20,5}
*/
typedef struct{
    char name[MAX_STRING_LEN];
    int health;
    int bullets;
    Stats stats;
    Modifier active_modifiers;
} Character;

/* SCENARIO DEFINTINITIONS*/

typedef struct{
    char response[MAX_STRING_LEN];
    Character *(*outcome_on_character)(Character *);
}Response_Outcome;

typedef struct{
    char chapa_del_NPC[MAX_STRING_LEN];
    Response_Outcome choices[MAX_CHOICES];

}Decision;

typedef struct scenario{
    char name[MAX_STRING_LEN];
    char description[MAX_STRING_LEN];
    char completed_decription[MAX_STRING_LEN];
    struct scenario *next;
    struct scenario *prev; //INCASE
    struct scenario *other_direction;
    Decision decision;
    Enemy *enemies; // of the scneario when there is a combat
    int numEnemies;
    bool completed;
}Scenario;

/* GAME STATE DEFINITIONS*/

typedef enum {
    PLAYING,
    DEAD,
    WIN,
} State;

typedef struct{
    Character *character;
    Scenario *current_scenario;
    State state;
}Game;

/* STACK DEFINITIONS AND FUNCTIONS */

typedef struct {
    int *arr;
    int top;
    int capacity;
}Stack;

Stack* create_stack(int capacity);

int is_empty_stack(Stack* stack);

int is_full_stack(Stack* stack);

void push_stack(Stack* stack, int item);

int pop_stack(Stack* stack);

int peek_stack(Stack* stack);

void print_stack(Stack* stack);

void free_stack(Stack* stack);

/* QUEUE DEFINITIONS AND FUNCTIONS */

typedef struct {
    int *items; 
    int front;
    int rear;
    int maxSize;
} Queue;

Queue* create_queue(int maxSize);

int is_empty_queue(Queue* queue);

int is_full_queue(Queue* queue);

void enqueue(Queue* queue, int value);

int dequeue(Queue* queue);

void display_queue(Queue* queue);

/* DICTIONARY DEFINITIONS AND FUNCTIONS */

typedef struct Node {
    char *key;
    void *value;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **table;
} HashTable;

HashTable* create_table();

unsigned int hash(const char *key);

void insert(HashTable *hashTable, const char *key, void *value);

void* lookup(HashTable *hashTable, const char *key);

#endif // GLOBAL_H