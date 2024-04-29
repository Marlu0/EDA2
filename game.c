// Here we implement the functions required to play the game, including scenario navigation and turn based combat

#include <stdio.h>

int selection(char *strings[]){

    int n = sizeof(strings) / sizeof(strings[0]);
    int selection = 0;

    /* While loop to handle if selection is invalid */
    while (selection < 1 || selection > n) {

        /* Printing the possible selections */
        for (int i = 0; i < n; i++) {
            printf("%d. %s\n", i + 1, strings[i]);
        }

        /* Getting the selection */
        printf("Enter your selection (1-%d): ", n);
        scanf("%d", &selection);

        /* Flush the input buffer to clear any remaining characters */
        while (getchar() != '\n');

        /* Print invalid selection if input doesn't belong to [1, n] */
        if (selection < 1 || selection > n) {
            printf("Invalid selection. Please try again.\n");
        }
    };  
    return selection;
}

int main() {
    char *strings[] = {"Hello", "World", "How", "Are", "You"};
    selection(strings);
    printf("You selected: %d\n", selection);
    return 0;
}