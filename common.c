/* common.c contains the most used functions to optimise their use in other files */

#include "common.h"

/*  
This function recieves: 
    - An array of strings, the last element MUST be NULL. 
It does:
    - Prints the strings as enumerated options and correctly scans the selection
Returns:
    - The selection (int)
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

/*
This function recieves: 
    - Nothing. 
It does:
    - Prints the main title
Returns:
    - Nothing
*/
void print_main_title() {
    printf("_____________________________________________________________________________________\n");
    printf("    _        _     _      _       _                 _                  \n");
    printf("   / \\   ___(_) __| |    / \\   __| |_   _____ _ __ | |_ _   _ _ __ ___ \n");
    printf("  / _ \\ / __| |/ _` |   / _ \\ / _` \\ \\ / / _ \\ '_ \\| __| | | | '__/ _ \\\n");
    printf(" / ___ \\ (__| | (_| |  / ___ \\ (_| |\\ V /  __/ | | | |_| |_| | | |  __/\n");
    printf("/_/   \\_\\___|_|\\__,_| /_/   \\_\\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___|\n");
    printf("(_)_ __   | |_| |__   ___                                             \n");
    printf("| | '_ \\  | __| '_ \\ / _ \\   ▄▄▌ ▐ ▄▌▪  ▄▄▌  ·▄▄▄▄      ▄▄▌ ▐ ▄▌▄▄▄ ..▄▄ · ▄▄▄▄▄                                        \n");
    printf("| | | | | | |_| | | |  __/   ██· █▌▐███ ██•  ██▪ ██     ██· █▌▐█▀▄.▀·▐█ ▀. •██                                          \n");
    printf("|_|_| |_|  \\__|_| |_|\\___|   ██▪▐█▐▐▌▐█·██▪  ▐█· ▐█▌    ██▪▐█▐▐▌▐▀▀▪▄▄▀▀▀█▄ ▐█.▪                                        \n");
    printf("                             ▐█▌██▐█▌▐█▌▐█▌▐▌██. ██     ▐█▌██▐█▌▐█▄▄▌▐█▄▪▐█ ▐█▌·\n");
    printf("                              ▀▀▀▀ ▀▪▀▀▀.▀▀▀ ▀▀▀▀▀•      ▀▀▀▀ ▀▪ ▀▀▀  ▀▀▀▀  ▀▀▀ \n");
    printf("_____________________________________________________________________________________\n\n");
}
