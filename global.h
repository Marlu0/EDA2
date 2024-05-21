#ifndef GLOBAL_H
#define GLOBAL_H

/* global.h contains the macros and the most used libraries and functions */

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
#define MAX_STRING_LEN 100

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
    Skill skill_1;
    Skill skill_2;
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