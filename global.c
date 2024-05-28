/* global.c contains functions commonly used across the code to optimise the other files */

#include "global.h"

/* GENERAL FUNCTION DECLARATIONS */

/* GET SELECTION (Important: This function returns index+1 of the array entered)
This function recieves: 
    - An array of constant strings, the last element MUST be NULL. 
It does:
    - Prints the strings as enumerated options and correctly scans the selection
Returns:
    - The selection (int)

Example of definition of array:
const char *array[] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Option 4",
        NULL // NULL terminator to indicate end of array
    };
*/
int get_selection(const char *strings[]) { //const?
    int selection;
    int n = 0;

    // Count the number of strings until NULL terminator
    while (strings[n] != NULL /*prob need to change NULL*/) {
        n++;
    }
    
    bool valid_input = false;

    while (!valid_input) {
        // Printing the possible selections
        for (int i = 0; i < n; i++) {
            printf("%d. %s\n", i + 1, strings[i]);
        }

        // Getting the selection
        printf("Enter your selection (1-%d): ", n);
        
        // Read the input as an integer followed by any characters until a newline
        if (scanf(" %d", &selection) != 1) {
            // Handle error or end of file
            // For simplicity, let's assume no error handling is needed here
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Flush the input buffer
            continue;
        }

        // Check if there are any characters left in the input buffer
        int extra;
        while ((extra = getchar()) != '\n' && extra != EOF);

        // Validating input
        if (selection < 1 || selection > n) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        valid_input = true;
    }
    
    return selection;
}

/* PRINT MAIN TITLE
This function recieves: 
    - Nothing. 
It does:
    - Prints the main title
Returns:
    - Nothing
*/
void print_main_title() {
    printf(" ____                  _          ____                   _             \n");
    printf("| __ ) _   _  __ _ ___( )_ __    / ___|_   _ _ __  ___  (_)_ __        \n");
    printf("|  _ \\| | | |/ _` / __|/| '_ \\  | |  _| | | | '_ \\/ __| | | '_ \\       \n");
    printf("| |_) | |_| | (_| \\__ \\ | | | | | |_| | |_| | | | \\__ \\ | | | | |      \n");
    printf("|____/ \\__,_|\\__, |___/ |_| |_|  \\____|\\__,_|_| |_|___/ |_|_| |_|      \n");
    printf(" _   _        \\___/                                                  \n");
    printf("| |_| |__   ___                                                     \n");
    printf("| __| '_ \\ / _ \\   ▄▄▌ ▐ ▄▌▪  ▄▄▌  ·▄▄▄▄      ▄▄▌ ▐ ▄▌▄▄▄ ..▄▄ · ▄▄▄▄▄ \n");
    printf("| |_| | | |  __/   ██· █▌▐███ ██•  ██▪ ██     ██· █▌▐█▀▄.▀·▐█ ▀. •██   \n");
    printf(" \\__|_| |_|\\___|   ██▪▐█▐▐▌▐█·██▪  ▐█· ▐█▌    ██▪▐█▐▐▌▐▀▀▪▄▄▀▀▀█▄ ▐█.▪ \n");
    printf("                   ▐█▌██▐█▌▐█▌▐█▌▐▌██. ██     ▐█▌██▐█▌▐█▄▄▌▐█▄▪▐█ ▐█▌· \n");
    printf("                    ▀▀▀▀ ▀▪▀▀▀.▀▀▀ ▀▀▀▀▀•      ▀▀▀▀ ▀▪ ▀▀▀  ▀▀▀▀  ▀▀▀   \n");
    printf("\n");
}

/* PRINT CREDITS
This function recieves:
    - Nothing
It does:
    - Print Credits
Returns:
    - Nothing
*/
void print_credits(){
    printf("\nGame Producers:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");

    printf("\nGame Directors:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");
    
    printf("\nSenior programmers:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");
    
    printf("\nJunior programmers:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");

    printf("\nGraphic Designers:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");

    printf("\nStory Boarders:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");

    printf("\nEverything Else:\n");
    printf("Darcy Thomas Robertson\nMarcel Manzano\nPol Obrador\nRicardo Ortega\n\n");
}

/* STACK FUNCTIONS */

// Function to create a new stack
Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1; // Initialize top to -1 (empty stack)
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int is_empty_stack(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int is_full_stack(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push_stack(Stack* stack, int item) {
    if (is_full_stack(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop_stack(Stack* stack) {
    if (is_empty_stack(stack)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 to indicate stack underflow
    }
    return stack->arr[stack->top--];
}

// Function to get the top element of the stack without removing it
int peek_stack(Stack* stack) {
    if (is_empty_stack(stack)) {
        printf("Stack is empty\n");
        return -1; // Return -1 to indicate empty stack
    }
    return stack->arr[stack->top];
}

// Function to print the elements of the stack
void print_stack(Stack* stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Function to free the memory allocated for the stack
void free_stack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

/* QUEUE FUNCTIONS */

// Function to create a new queue with given maximum size
Queue* create_queue(int maxSize) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->maxSize = maxSize;
    queue->items = (int*)malloc(maxSize * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int is_empty_queue(Queue* queue) {
    return (queue->rear == -1);
}

// Function to check if the queue is full
int is_full_queue(Queue* queue) {
    return ((queue->rear + 1) % queue->maxSize == queue->front);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int value) {
    if (is_full_queue(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (is_empty_queue(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->maxSize;
    }
    queue->items[queue->rear] = value;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    if (is_empty_queue(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int removedItem = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->maxSize;
    }
    return removedItem;
}

// Function to display the elements in the queue
void display_queue(Queue* queue) {
    if (is_empty_queue(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue->front;
    printf("Queue elements: ");
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % queue->maxSize;
    }
    printf("%d\n", queue->items[i]);
}

/* DICTIONARY FUNCTIONS */

// Function to create a hash table
HashTable* create_table() {
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->table = malloc(sizeof(Node*) * TABLE_SIZE);

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }

    return hashTable;
}

// Hash function
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % TABLE_SIZE;
}

// Function to insert element in a hash table
void insert(HashTable *hashTable, const char *key, void *value) {
    unsigned int index = hash(key);
    Node *newNode = malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

// Function to look up an element in a hash table
void* lookup(HashTable *hashTable, const char *key) {
    unsigned int index = hash(key);
    Node *node = hashTable->table[index];

    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }

    return NULL;
}
