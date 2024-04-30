#include "game.h"

void name_character(Character *character) {
    /* Flag to track validity of input */
    int sure = 0;

    /* Loop to ensure input and handle errors */
    while (sure != 1) {
        printf("Choose a name for your character: ");
        
        /* Use fgets to read the entire line, including spaces, for the character's name */
        fgets(character->name, MAX_STRING_LEN, stdin);

        /* Remove the newline character from the end of the input and add the null terminator */
        character->name[strcspn(character->name, "\n")] = '\0';

        printf("Are you sure you want the name '%s'? (yes/no): ", character->name);
        char answer[MAX_STRING_LEN];
        fgets(answer, MAX_STRING_LEN, stdin);
        /* Remove the newline character from the end of the input */
        answer[strcspn(answer, "\n")] = '\0';

        if (strcmp(answer, "yes") == 0) {
            sure = 1;
        } else {
            printf("Please re-enter your character's name.\n");
        }
    }
}

/* Function to reset character stats */
void reset_character_stats(Character *character) {
    character->stats.hp = 0;
    character->stats.mp = 0;
    character->stats.atk = 0;
    character->stats.def = 0;
    character->stats.luc = 0;
}

Character create_character() {
    printf("Welcome to Character Creation!\n");

    /* Character initialization */
    Character character;

    /* We name our character */
    name_character(&character);
    
    /* We assign the skills to character*/

    /* Flag to track validity of input */
    int sure = 0;
    int statpts = 15;  // Initialize stat points to 15 outside the loop
    reset_character_stats(&character);

    /* Loop to ensure input and handle errors */
    while (!sure && statpts > 0) {  /* Continue until sure is true and there are stat points remaining */
        printf("Select stat to assign: (Current points: %d)\n", statpts);
        
        /* List of stats */
        const char *list_of_stats[] = {"HP (Health points)", "MP (Mana Points)", "ATK (Attack)", "DEF (Defense)", "LUC (Luck)", NULL};
        
        /* Get user's selection */
        int selected_stat = get_selection(list_of_stats);

        /* Handle selected stat */
        switch (selected_stat) {
            case 1:
                printf("You selected HP (Health points)\n");
                printf("How many points do you wish to assign? (0-%d): ", statpts);
                int hp_points;
                scanf(" %d", &hp_points);
                getchar(); // Consume the newline character left in the input buffer

                // Validate the points
                if (hp_points >= 0 && hp_points <= statpts) {
                    // Assign points to HP and update statpts
                    character.stats.hp += hp_points;
                    statpts -= hp_points;
                } else {
                    printf("Invalid number of points. Please enter a number between 0 and %d.\n", statpts);
                }
                break;
            case 2:
                printf("You selected MP (Mana Points)\n");
                printf("How many points do you wish to assign? (0-%d): ", statpts);
                int mp_points;
                scanf(" %d", &mp_points);
                getchar(); // Consume the newline character left in the input buffer

                // Validate the points
                if (mp_points >= 0 && mp_points <= statpts) {
                    // Assign points to MP and update statpts
                    character.stats.mp += mp_points;
                    statpts -= mp_points;
                } else {
                    printf("Invalid number of points. Please enter a number between 0 and %d.\n", statpts);
                }
                break;
            case 3:
                printf("You selected ATK (Attack)\n");
                printf("How many points do you wish to assign? (0-%d): ", statpts);
                int atk_points;
                scanf(" %d", &atk_points);
                getchar(); // Consume the newline character left in the input buffer

                // Validate the points
                if (atk_points >= 0 && atk_points <= statpts) {
                    // Assign points to ATK and update statpts
                    character.stats.atk += atk_points;
                    statpts -= atk_points;
                } else {
                    printf("Invalid number of points. Please enter a number between 0 and %d.\n", statpts);
                }
                break;
            case 4:
                printf("You selected DEF (Defense)\n");
                printf("How many points do you wish to assign? (0-%d): ", statpts);
                int def_points;
                scanf(" %d", &def_points);
                getchar(); // Consume the newline character left in the input buffer

                // Validate the points
                if (def_points >= 0 && def_points <= statpts) {
                    // Assign points to DEF and update statpts
                    character.stats.def += def_points;
                    statpts -= def_points;
                } else {
                    printf("Invalid number of points. Please enter a number between 0 and %d.\n", statpts);
                }
                break;
            case 5:
                printf("You selected LUC (Luck)\n");
                printf("How many points do you wish to assign? (0-%d): ", statpts);
                int luc_points;
                scanf(" %d", &luc_points);
                getchar(); // Consume the newline character left in the input buffer

                // Validate the points
                if (luc_points >= 0 && luc_points <= statpts) {
                    // Assign points to LUC and update statpts
                    character.stats.luc += luc_points;
                    statpts -= luc_points;
                } else {
                    printf("Invalid number of points. Please enter a number between 0 and %d.\n", statpts);
                }
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }

    // If all points are allocated or the player chooses to proceed with their selection
    if (statpts == 0) {
        printf("You've spent all the stat points!\n");
        printf("This was your selection:\n");
        printf("· HP: %d\n", character.stats.hp);
        printf("· MP: %d\n", character.stats.mp);
        printf("· ATK: %d\n", character.stats.atk);
        printf("· DEF: %d\n", character.stats.def);
        printf("· LUC: %d\n", character.stats.luc);

        // Ask for confirmation
        printf("Do you wish to change your stat selection? (yes/no): ");
        char answer[MAX_STRING_LEN];
        fgets(answer, MAX_STRING_LEN, stdin);
        /* Remove the newline character from the end of the input */
        answer[strcspn(answer, "\n")] = '\0';

        if (strcmp(answer, "yes") == 0) {
            // Reset stat points and stats
            statpts = 15;
            character.stats.hp = 0;
            character.stats.mp = 0;
            character.stats.atk = 0;
            character.stats.def = 0;
            character.stats.luc = 0;
        } else {
            sure = 1;  // Set sure to 1 to exit the loop
        }
    }

    return character;
}

int main(){
    // Call create_character and assign its return value to a variable
    Character character = create_character();
    
    // Print some information about the created character (for example)
    printf("Character created with name: %s\n", character.name);
    
    return 0;
}
