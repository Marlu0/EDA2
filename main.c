// Main code

#include "common.h"
#include "common.c"

/*
This function recieves:
    - Nothing
It does:
    - Prints the main menu
Returns:
    - Integer that represents selection
*/
int main_menu(){
    
    /* First we print the main title */
    print_main_title();

    /* Then we use the get_selection function to display the options and manage the selection */
    const char *options[] = {"New Game","Create Character","Credits","Exit",NULL /* NULL terminator to mark the end of the array */};
    return get_selection(options);
}
