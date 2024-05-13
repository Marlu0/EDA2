/* common.h contains the most used libraries to reduce #includes in other files */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/* Global variables */

#define NUM_SKILLS 2
#define MAX_MODIFIERS 4
#define MAX_STRING_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_OPTIONS 2
#define MAX_DECISIONS 2
#define MAX_ENEMIES 3
#define INVENTORY_SIZE 7 /*this is the number of weapons including fists.*/

/* FUNCTION DECLARATIONS */

void print_credits();

int get_selection(const char *strings[]);

void print_main_title();

/* Stack definitions */

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity);

int isEmptyStack(Stack* stack);

int isFullStack(Stack* stack);

void pushStack(Stack* stack, int item);

int popStack(Stack* stack);

int peekStack(Stack* stack);

void printStack(Stack* stack);

void freeStack(Stack* stack);

/* Queue definitions */

typedef struct {
    int *items; 
    int front;
    int rear;
    int maxSize;
} Queue;

Queue* createQueue(int maxSize);

int isEmpty(Queue* queue);

int isFull(Queue* queue);

void enqueue(Queue* queue, int value);

int dequeue(Queue* queue);

void display(Queue* queue);
