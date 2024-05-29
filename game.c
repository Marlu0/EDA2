#include "game.h"


/*INIT GAME STATE
This function receives:
    - noting
Does:
    - inits the gamestate
Returns:
    - pointer to the gamestate
    */
//THIS IS WHERE THE INIT_GAME FUCNTION WAS
/* Functions for character creation */

/* NAME CHARACTER
This function recieves: 
    - Pointer to character of type Character 
It does:
    - Sets character.name and handles errors
Returns:
    - Nothing
*/
void name_character(Character *character) {
    // Flag to track validity of input
    bool sure = false;

    // Loop to ensure input and handle errors
    while (sure != true) {
        printf("Choose a name for your character: ");
        
        // Use fgets to read the entire line, including spaces, for the character's name
        fgets(character->name, MAX_NAME_LEN, stdin);

        // Remove the newline character from the end of the input and add the null terminator
        character->name[strcspn(character->name, "\n")] = '\0';

        printf("Are you sure you want the name '%s'? (yes/no): ", character->name);
        char answer[MAX_STRING_LEN];
        fgets(answer, MAX_STRING_LEN, stdin);
        // Remove the newline character from the end of the input
        answer[strcspn(answer, "\n")] = '\0'; 

        if (strcmp(answer, "yes") == 0) {
            sure = true;
        } else {
            printf("Invalid Character Name. Try Again\n");
        }
    }
}

/* RESET CHARACTER STATS
This function recieves: 
    - Pointer to character of type Character
It does:
    - Resets all stats in character.stats to 0
Returns:
    - Nothing
*/
void reset_character_stats(Character *character) {
    // All stats go to 1 since they're multipliers
    character->stats.hp = 1;
    character->stats.bp = 1;
    character->stats.atk = 1;
    character->stats.def = 1;
    character->stats.luc = 1;
}

/* ASSIGN POINTS
This function recieves: 
    - Pointer to stat to change, pointer to available statpts and a string containing the stat_name 
It does:
    - Adds an integer input of points (from 0 to statpts) to the stat
Returns:
    - Nothing
*/
void assign_points(int *stat, int *statpts, const char *stat_name) {
    printf("You selected: %s\n", stat_name);
    printf("How many points do you wish to assign? (0-%d): ", *statpts);
    int points;
    scanf(" %d", &points);
    getchar(); // Consume the newline character left in the input buffer

    // Validate the points
    if (points >= 0 && points <= *statpts) {
        // Assign points and update statpts
        *stat += points;
        *statpts -= points;
    } else {
        printf("Invalid number of points. Please enter a number between 0 and %d.\n", *statpts);
    }
}

/* CREATE CHARACTER
This function recieves: 
    - Nothing
It does:
    - Creates a character, initializes its values and assigns name and stats depending on input
Returns:
    - character of type Character 
*/
Character create_character() {
    printf("\nWelcome to Character Creation!\n");

    // Character initialization
    Character character;
    
    // We name our character
    name_character(&character);
    
    // We assign the skills to character

    // Flag to track validity of input
    int done = 0;
    int statpts = 15;  // Initialize stat points to 15 outside the loop
    
    // Initialize character stats to 1
    printf("Base level of all stats: 1\n");
    reset_character_stats(&character);

    // Outer loop in case of re-doing stats
    while (!done) {
        // Loop until sure is true and there are stat points remaining
        while (statpts > 0) {
            printf("Select stat to assign: (Current points: %d)\n", statpts);
            
            // List of stats
            const char *list_of_stats[] = {"HP (Health points)", "MP (Mana Points)", "ATK (Attack)", "DEF (Defense)", "LUC (Luck)", NULL};
            
            // Get user's selection
            int selected_stat = get_selection(list_of_stats);

            // Handle selected stat and assign the respective points
            switch (selected_stat) {
                case 1:
                    assign_points(&character.stats.hp, &statpts, "HP (Health points)");
                    break;
                case 2:
                    assign_points(&character.stats.bp, &statpts, "BP (Bullet Points)");
                    break;
                case 3:
                    assign_points(&character.stats.atk, &statpts, "ATK (Attack)");
                    break;
                case 4:
                    assign_points(&character.stats.def, &statpts, "DEF (Defense)");
                    break;
                case 5:
                    assign_points(&character.stats.luc, &statpts, "LUC (Luck)");
                    break;
                default:
                    printf("Invalid selection. Please try again.\n");
            }
        }
        // If all points are allocated the selection is displayed
        if (statpts == 0) {
            printf("You've spent all the stat points!\n");
            printf("This was your selection:\n");
            printf("- HP: %d\n", character.stats.hp);
            printf("- BP: %d\n", character.stats.bp);
            printf("- ATK: %d\n", character.stats.atk);
            printf("- DEF: %d\n", character.stats.def);
            printf("- LUC: %d\n", character.stats.luc);

            
            // Confirmation is asked in case the user wants to change their selection
            printf("Are you sure about your stat selection? (yes/no): ");
            bool valid = false;
            while(!valid) {
            char answer[MAX_STRING_LEN];
            fgets(answer, MAX_STRING_LEN, stdin);
            answer[strcspn(answer, "\n")] = '\0'; // Remove the newline character from the end of the input

                if (strcmp(answer, "yes") == 0) {
                    done = 1;
                    valid = true;
                } 
                else if(strcmp(answer, "no") == 0){
                    statpts = 15;
                    reset_character_stats(&character);
                    valid = true;
                } else {
                    printf("please type 'yes or 'no'\n");
                }
            }
        }
    }

    // Initialize active modifier to default values
    character.active_modifiers.tempatk = 1;
    character.active_modifiers.tempdef = 1;
    character.active_modifiers.templuc = 1;

    // We initialise health and mana in function of hp and bp stats
    character.health = 100 + (20 * (character.stats.hp - 1));

    character.bullets = 100 + (10 * (character.stats.bp - 1));

    return character;
}
