#ifndef COMMON_H
#define COMMON_H

/* common.h contains the most used libraries to reduce #includes in other files */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/* MACROS */
#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4
#define BACKWARDS 5
// its arranged in that if you do backwards - direction you get the other direction

#define NUM_SKILLS 2
#define NUM_MODIFIERS 4
#define MAX_CHOICES 4
#define MAX_STRING_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define NUM_OPTIONS 2
#define NUM_DECISIONS 2
#define INVENTORY_SIZE 8
#define AGGRESSIVE_MODE_ACTIVATOR 2.5

/* FUNCTION DECLARATIONS */

void print_credits();

int get_selection(const char *strings[]);

void print_main_title();

/* Stack definitions */

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

/* Queue definitions */

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

#endif // COMMON_H