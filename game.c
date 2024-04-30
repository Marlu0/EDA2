#include "game.h"

/*
This function recieves: 
    - Pointer to character of type Character 
It does:
    - Sets character.name and handles errors
Returns:
    - Nothing
*/
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

/*
This function recieves: 
    - Pointer to character of type Character
It does:
    - Resets all stats in character.stats to 0
Returns:
    - Nothing
*/
void reset_character_stats(Character *character) {
    character->stats.hp = 0;
    character->stats.mp = 0;
    character->stats.atk = 0;
    character->stats.def = 0;
    character->stats.luc = 0;
}

/*
This function recieves: 
    - Pointer to stat to change, pointer to available statpts and a string containing the stat_name 
It does:
    - Adds an integer input of points (from 0 to statpts) to the stat
Returns:
    - Nothing
*/
void assign_points(int *stat, int *statpts, const char *stat_name) {
    printf("You selected %s\n", stat_name);
    printf("How many points do you wish to assign? (0-%d): ", *statpts);
    int points;
    scanf(" %d", &points);
    getchar(); /* Consume the newline character left in the input buffer */

    /* Validate the points */
    if (points >= 0 && points <= *statpts) {
        /* Assign points and update statpts */
        *stat += points;
        *statpts -= points;
    } else {
        printf("Invalid number of points. Please enter a number between 0 and %d.\n", *statpts);
    }
}

/*
This function recieves: 
    - Nothing
It does:
    - Creates a character, initializes its values and assigns name and stats depending on input
Returns:
    - character of type Character 
*/
Character create_character() {
    printf("Welcome to Character Creation!\n");

    /* Character initialization */
    Character character;

    /* We name our character */
    name_character(&character);
    
    /* We assign the skills to character*/

    /* Flag to track validity of input */
    int done = 0;
    int statpts = 15;  /* Initialize stat points to 15 outside the loop */
    reset_character_stats(&character);

    /* Outer loop in case of re-doing stats */
    while (!done){
        /* Loop until sure is true and there are stat points remaining */
        while (statpts > 0) {
            printf("Select stat to assign: (Current points: %d)\n", statpts);
            
            /* List of stats */
            const char *list_of_stats[] = {"HP (Health points)", "MP (Mana Points)", "ATK (Attack)", "DEF (Defense)", "LUC (Luck)", NULL};
            
            /* Get user's selection */
            int selected_stat = get_selection(list_of_stats);

            /* Handle selected stat */
            switch (selected_stat) {
                case 1:
                    assign_points(&character.stats.hp, &statpts, "HP (Health points)");
                    break;
                case 2:
                    assign_points(&character.stats.mp, &statpts, "MP (Mana Points)");
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
        /* If all points are allocated or the player chooses to proceed with their selection */
        if (statpts == 0) {
            printf("You've spent all the stat points!\n");
            printf("This was your selection:\n");
            printf("· HP: %d\n", character.stats.hp);
            printf("· MP: %d\n", character.stats.mp);
            printf("· ATK: %d\n", character.stats.atk);
            printf("· DEF: %d\n", character.stats.def);
            printf("· LUC: %d\n", character.stats.luc);

            // Ask for confirmation
            printf("Are you sure about your stat selection? (yes/no): ");
            char answer[MAX_STRING_LEN];
            fgets(answer, MAX_STRING_LEN, stdin);
            /* Remove the newline character from the end of the input */
            answer[strcspn(answer, "\n")] = '\0';

            if (strcmp(answer, "yes") == 0) {
                done = 1;  /* Set done to 1 to exit the loop */
            } 
            else {
                /* Reset stat points and stats */
                statpts = 15;
                reset_character_stats(&character);
            }
        }
    }
    /* We initialise reputation, skills,  */
    character.reputation = 0;
    
    // Initialize skills array with empty values
    for (int i = 0; i < MAX_SKILLS; i++) {
        strcpy(character.skills[i].name, "");
        strcpy(character.skills[i].description, "");
        character.skills[i].skill_modifier.tempatk = 0;
        character.skills[i].skill_modifier.tempdef = 0;
        character.skills[i].skill_modifier.templuc = 0;
    }

    // Initialize active modifier to default values
    for (int i = 0; i < MAX_MODIFIERS; i++) {
        character.active_modifier[i].tempatk = 0;
        character.active_modifier[i].tempdef = 0;
        character.active_modifier[i].templuc = 0;
    }
    
    /* We initialise health in function of hp stat */
    character.health = 50 + (10*(character.stats.hp));
    character.mana = 10 + (2*(character.stats.mp));

    return character;
}