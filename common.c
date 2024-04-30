/* common.c contains the most used functions to optimise their use in other files */

#include "common.h"

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
        
        if (scanf("%d", &selection) != 1) {
            printf("Invalid input. Please enter a number.\n");
            /* Flush the input buffer to clear all characters but the first */
            while (getchar() != '\n');
        } else {
            valid_input = true;
        }

        if (valid_input && (selection < 1 || selection > n)) {
            printf("Invalid selection. Please try again.\n");
            valid_input = false;
        }
    };
    
    return selection;
}