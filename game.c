#include "game.h"

/*
This function receives:
    - nothing
It does:
    - inits the skills array
Returns:
    - pointer to array
*/
Skill *init_skills() {
    Skill skills[10] = {
        /*0*/{ "The Hermit", "Increases +1 defense", {1.0, 1.15, 1.0}},
        /*1.0*/{ "The Chariot", "Increases +2 defense", {1.0, 1.3, 1.0}},
        /*2*/{ "The Tower", "Increases +1 attack", {1.15, 1.0, 1.0}},
        /*3*/{ "The Devil", "Increases +2 attack", {1.3, 1.0, 1.0}},
        /*4*/{ "The Hangman", "Reduces to 0 luck", {1.0, 1.0, 0.0}},
        /*5*/{ "Weel Of Fortune", "Duplicates luck", {1.0, 1.0, 2}},
        /*6*/{ "Death of Theo", "Death is the only way", {0.5, 2, 1.0}},
        /*7*/{ "The Armadillo", "Nothing like home", {2, 0.5, 1.0}},
        /*8*/{ "The Fool", "Decreases defense -1, and increase luck a +2", {1.0, 0.9, 1.3}},
        /*9*/{ "Justice", "Faith will guide you", {1.1, 1.1, 1.1}}
    };
    // i need to change this function as hell
    return skills;
};

Skill *init_skill(char filename[], char name[] /*pull it out on the name*/) {
    FILE *file_pointer = fopen(filename, "w");
    if (file_pointer == NULL) {
        perror("Error opening file"); //this is a boss function use it more often
    }

    while (strncmp()) //this needs to be finished later
}

/*
This function receives:
    - skills array
It does:
    - inits the wepons array
Returns:
    - pointer to array.
*/

Weapon *init_weapons(Skill skills[]) {
    Weapon weapons[6] = {
        {"Rusty Revolver", "Older that the mountains", skills[0], skills[4]}, //this does not work because items in an arry need to be constant size and these arrays are not
        {"Linda", "Sweetest kisses in the wild west", skills[2], skills[0]},
        {"GOAT", "Gun Of Antilope Trilobites ", skills[5], skills[3]},
        {"Gun & Barrel", "A gun in a barrel", skills[1], skills[2]},
        {"Cactus Thrower", "Ouch..", skills[7], skills[8]},
        {"Gatling Gun", "RATATATTATATA", skills[6], skills[5]}
    };
    return weapons;
};

/* Functions for character creation and customization*/

/* NAME CHARACTER
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

/* RESET CHARACTER STATS
This function recieves: 
    - Pointer to character of type Character
It does:
    - Resets all stats in character.stats to 0
Returns:
    - Nothing
*/
void reset_character_stats(Character *character) {
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

/* CREATE CHARACTER
This function recieves: 
    - weapons_dictionary array from dictionaries.h
It does:
    - Creates a character, initializes its values and assigns name and stats depending on input
Returns:
    - character of type Character 
*/
Character create_character(Weapon weapons_dictionary[] /* Weapons dictionary */) {
    printf("Welcome to Character Creation!\nWarning: Previous character will be erased\n");

    /* Character initialization */
    Character character;
    
    /* We name our character */
    name_character(&character);
    
    /* We assign the skills to character*/

    /* Flag to track validity of input */
    int done = 0;
    int statpts = 15;  /* Initialize stat points to 15 outside the loop */
    
    printf("Base level of all stats: 1\n");
    /* Initialize character stats to 1 */
    reset_character_stats(&character);

    /* Outer loop in case of re-doing stats */
    while (!done) {
        /* Loop until sure is true and there are stat points remaining */
        while (statpts > 0) {
            printf("Select stat to assign: (Current points: %d)\n", statpts);
            
            /* List of stats */
            const char *list_of_stats[] = {"HP (Health points)", "MP (Mana Points)", "ATK (Attack)", "DEF (Defense)", "LUC (Luck)", NULL};
            
            /* Get user's selection */
            int selected_stat = get_selection(list_of_stats);

            /* Handle selected stat and assign the respective points */
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
        /* If all points are allocated the selection is displayed */
        if (statpts == 0) {
            printf("You've spent all the stat points!\n");
            printf("This was your selection:\n");
            printf("· HP: %d\n", character.stats.hp);
            printf("· BP: %d\n", character.stats.bp);
            printf("· ATK: %d\n", character.stats.atk);
            printf("· DEF: %d\n", character.stats.def);
            printf("· LUC: %d\n", character.stats.luc);

            /* Confirmation is asked in case the user wants to change their selection */
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

    /* Initialize active modifier to default values */
    for (int i = 0; i < NUM_MODIFIERS; i++) {
        character.active_modifiers[i].tempatk = 1;
        character.active_modifiers[i].tempdef = 1;
        character.active_modifiers[i].templuc = 1;
    }
    
    /* We initialize balance */
    character.balance = 0;

    /* We add the initial weapon (fists) and initialise the inventory */
    character.active_weapon = weapons_dictionary[0];
    character.inventory.weapons_in_inventory[0] = weapons_dictionary[0];
    character.inventory.fill = 1;

    /* We initialise health and mana in function of hp and mp stats */
    character.health = 100+(20*(character.stats.hp-1));
    character.bullets = 100+(10*(character.stats.bp-1));

    return character;
}

/* Functions for inventory*/

/* OBTAIN WEAPON
This function recieves:
    - Pointer to character
It does:
    - Adds weapon to character's inventory
Returns:
    - Nothing

Note: This function lets us separe the weapon obtaining from the function of the fight, making the program more modular
*/
void obtain_weapon(Character *character, Weapon weapon) {

    /* Printing the name of the weapon obtained */
    printf("You obtained %s!", weapon.name);

    /* Temporary variable to store size of inventory */
    int size = character->inventory.fill; /* You need to use a dot on the second as it is by value */
    
    /* Add the new weapon to the empty slot [size] and update fill (size of inventory)*/
    character->inventory.weapons_in_inventory[size] = weapon;
    character->inventory.fill++;
}

/* CHANGE WEAPON 
This function recieves:
    - Pointer to character
Does:
    - Changes active_weapon in character's inventory
Returns:
    - Nothing
*/
void change_weapon(Character *character) {

    /* Create a selection variable for choosing your weapon */
    int selection;

    /* Create a temporary variable of inventory fill value for readability */
    int inventory_size = character->inventory.fill;

    /* Create a flag to track validity of input */
    bool valid_input = false;
    
    /* Do a while loop to ensure valid choice for weapon */
    while (!valid_input) {

        /* Printing the available weapons in your inventory */
        printf("Select a weapon from your inventory (1-%d): \n",inventory_size);
        for (int i=0; i<inventory_size; ++i) {
            printf("%d. %s: %s\n",i+1,character->inventory.weapons_in_inventory[i].name,character->inventory.weapons_in_inventory[i].description);
        }
        /* Getting the selection */
        if (scanf(" %d", &selection) != 1) {
            printf("Invalid input. Please enter a number.\n");
            /* Flush the input buffer to clear all characters but the first */
            while (getchar() != '\n');
        } 
        else {
            valid_input = true;
        }
        if (valid_input && (selection < 1 || selection > inventory_size)) {
            printf("Invalid selection. Please try again.\n");
            valid_input = false;
        }
    }
    int chosen_weapon_index = selection-1; /* We selected the option, which is index+1 in UI */
    
    /* We change the active weapon into the selection */
    character->active_weapon = character->inventory.weapons_in_inventory[chosen_weapon_index];
}
