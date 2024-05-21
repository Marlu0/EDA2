/* common.c contains the most used functions to optimise their use in other files */

#include "common.h"

/* GET SELECTION (Important: This function returns index+1 of the array entered)
This function recieves: 
    - An array of strings, the last element MUST be NULL. 
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
int get_selection(const char *strings[]) {
    int selection;
    int n = 0;

    /* Count the number of strings until NULL terminator */
    while (strings[n] != NULL) {
        n++;
    }
    /* Create a flag to track validity of input */
    bool valid_input = false;
    
    while (!valid_input) {

        /* Printing the possible selections */
        for (int i = 0; i < n; i++) {
            printf("%d. %s\n", i + 1, strings[i]);
        }

        /* Getting the selection */
        printf("Enter your selection (1-%d): ", n);
        
        if (scanf(" %d", &selection) != 1) {
            printf("Invalid input. Please enter a number.\n");
            /* Flush the input buffer to clear all characters but the first */
            while (getchar() != '\n');
        } 
        else {
            valid_input = true;
        }

        if (valid_input && (selection < 1 || selection > n)) {
            printf("Invalid selection. Please try again.\n");
            valid_input = false;
        }
    };
    
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
    printf(" _   _                                                                \n");
    printf("| |_| |__   ___                                                     \n");
    printf("| __| '_ \\ / _ \\   ▄▄▌ ▐ ▄▌▪  ▄▄▌  ·▄▄▄▄      ▄▄▌ ▐ ▄▌▄▄▄ ..▄▄ · ▄▄▄▄▄ \n");
    printf("| |_| | | |  __/   ██· █▌▐███ ██•  ██▪ ██     ██· █▌▐█▀▄.▀·▐█ ▀. •██   \n");
    printf(" \\__|_| |_|\\___|   ██▪▐█▐▐▌▐█·██▪  ▐█· ▐█▌    ██▪▐█▐▐▌▐▀▀▪▄▄▀▀▀█▄ ▐█.▪ \n");
    printf("                   ▐█▌██▐█▌▐█▌▐█▌▐▌██. ██     ▐█▌██▐█▌▐█▄▄▌▐█▄▪▐█ ▐█▌· \n");
    printf("                    ▀▀▀▀ ▀▪▀▀▀.▀▀▀ ▀▀▀▀▀•      ▀▀▀▀ ▀▪ ▀▀▀  ▀▀▀▀  ▀▀▀   \n");
}

/* FUNCTIONS FOR STACK */

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

/* FUNCTIONS FOR QUEUE */

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

int main(){
    printf("hOLA");
}