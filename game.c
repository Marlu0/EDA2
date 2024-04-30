#include <stdio.h>
#include <stdbool.h>

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
            // Flush the input buffer to clear any remaining characters
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

void print_main_title() {
    printf("___________________________________________________________________________\n");
    printf(" _     _                _          _        _     _                          \n");
    printf("| |   (_)_________   _ ( )___     / \\   ___(_) __| |                         \n");
    printf("| |   | |_  /_  / | | ||// __|   / _ \\ / __| |/ _` |                         \n");
    printf("| |___| |/ / / /| |_| |  \\__ \\  / ___ \\ (__| | (_| |                         \n");
    printf("|_____|_/___/___|\\__, |  |___/ /_/   \\_\\___|_|\\__,_|_         _   _          \n");
    printf("   / \\   __| |_  |___/_ _ __ | |_ _   _ _ __ ___  (_)_ __   | |_| |__   ___ \n");
    printf("  / _ \\ / _` \\ \\ / / _ \\ '_ \\| __| | | | '__/ _ \\ | | '_ \\  | __| '_ \\ / _ \\ \n");
    printf(" / ___ \\ (_| |\\ V /  __/ | | | |_| |_| | | |  __/ | | | | | | |_| | | |  __/\n");
    printf("/_/   \\_\\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___| |_|_| |_|  \\__|_| |_|\\___|\n");
    printf("▄▄▌ ▐ ▄▌▪  ▄▄▌  ·▄▄▄▄      ▄▄▌ ▐ ▄▌▄▄▄ ..▄▄ · ▄▄▄▄▄\n");
    printf("██· █▌▐███ ██•  ██▪ ██     ██· █▌▐█▀▄.▀·▐█ ▀. •██  \n");
    printf("██▪▐█▐▐▌▐█·██▪  ▐█· ▐█▌    ██▪▐█▐▐▌▐▀▀▪▄▄▀▀▀█▄ ▐█.▪\n");
    printf("▐█▌██▐█▌▐█▌▐█▌▐▌██. ██     ▐█▌██▐█▌▐█▄▄▌▐█▄▪▐█ ▐█▌·\n");
    printf(" ▀▀▀▀ ▀▪▀▀▀.▀▀▀ ▀▀▀▀▀•      ▀▀▀▀ ▀▪ ▀▀▀  ▀▀▀▀  ▀▀▀ \n");
    printf("___________________________________________________________________________\n\n");
}

int main() {
    print_main_title();
    const char *strings[] = {"New Game", "Character Creation", "Exit", "Credits", NULL}; // NULL terminator
    int user_selection = get_selection(strings);
    
    switch (user_selection) {
        case 1:
            printf("You selected: %s\n", strings[user_selection - 1]);
            break;
        case 2:
            printf("You selected: %s\n", strings[user_selection - 1]);
            break;
        case 3:
            printf("You selected: %s\n", strings[user_selection - 1]);
            break;
        case 4:
            printf("You selected: %s\n", strings[user_selection - 1]);
            break;
        default:
            printf("Invalid selection\n");
    }

    return 0;
}