#ifndef COMMON_H
#define COMMON_H

/* common.h contains the macros and the most used libraries and functions */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/* MACROS */

/* DIRECTIONS */
// Arranged so that if you do BACKWARDS - DIRECTION(previous) you get the opposite direction
#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4
#define BACKWARDS 5

#define TABLE_SIZE 100
#define NUM_SKILLS 2
#define NUM_MODIFIERS 4
#define MAX_CHOICES 4
#define MAX_DESCRIPTION_LEN 100
#define NUM_OPTIONS 2
#define NUM_DECISIONS 2
#define INVENTORY_SIZE 8
#define AGGRESSIVE_MODE_ACTIVATOR 2.5

/* GENERAL FUNCTION DECLARATIONS */

int get_selection(const char *strings[]);

void print_main_title();

void print_credits();

/* DEFINITIONS OF GAME STRUCTS */

/* STATS: 
Health, maná, attack, defense, luck*/
typedef struct{
    int hp, bp, atk, def, luc;
}Stats;

/* MODIFIER: 
This will help us with combat calculations like: damage = atk + tempatk */
typedef struct{
    float tempatk, tempdef, templuc;
}Modifier;

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
    char name[MAX_DESCRIPTION_LEN]; //I HAVE NO IDEA WHY THIS IS RED LIKE WHAT!
    char description[MAX_DESCRIPTION_LEN];
    Modifier skill_modifier;
    int healing; /*where do we put this in the skills?*///ill add it in later
}Skill;

/* WEAPON:
    Has name, description and an array of skill structs.
    Will affect available skills.
    Example:
        - name = "Rusty Revolver"
        - description = "Older than the mountains"
        - skills[] = skills[0], skills[4]
*/
typedef struct{
    char name[MAX_DESCRIPTION_LEN];
    char description[MAX_DESCRIPTION_LEN];
    Skill *skills[NUM_SKILLS];
}Weapon;

/* INVENTORY:
    Has:
    - A weapons array of size INVENTORY_SIZE, a macro defined to not have to pass the size on all functions
    - An int fill to track empty slots when adding new weapons
*/
typedef struct{
    Weapon weapons_in_inventory[INVENTORY_SIZE];
    int fill; //create_character sets the fill equal to 1.
}Inventory;

/* ENEMY:
    Has name, stats and an array of skills
    Example:
        - name = "Sheriff Roach"
        - stats = {2, 1, 5, 5, 2}
        - skills = [Shell armor, Intimidate, Play Dead]
*/
typedef struct{
    char name[MAX_DESCRIPTION_LEN];
    int health;
    Stats stats;
    Weapon weapon;
    Modifier active_modifiers[NUM_MODIFIERS];
}Enemy;

/* CHARACTER:
    Has name, reputation, Stats, an array of skills and an array of active modifiers
    Example:
        - name = "Lizzy"
        - reputation = -1
        - stats = {100,50,10,20,5}
        - skills = [Rampage, Time Strike]
        - active_modifiers = []
*/
typedef struct{
    char name[MAX_DESCRIPTION_LEN];
    int health;
    int bullets;
    int balance; //money
    Stats stats;
    Inventory inventory;
    Modifier active_modifiers[NUM_MODIFIERS];
    Weapon active_weapon;
}Character;

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
}Queue;

Queue* create_queue(int maxSize);

int is_empty_queue(Queue* queue);

int is_full_queue(Queue* queue);

void enqueue(Queue* queue, int value);

int dequeue(Queue* queue);

void display_queue(Queue* queue);

/* FUNCTIONS FOR DICTIONARY */

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

#endif // COMMON_H