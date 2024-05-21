#include "game.h"
#include "scenario.h"
#include "decision_functions.h"

/*
This function receives:
    - nothing
It does:
    - inits the skills array
Returns:
    - pointer to array
*/
Skill *init_skill_list(){
    Skill skills_dictionary[11] = {
    /*0*/{10, "The Hermit", "Increases defense a 15%", {1, 1.15, 1}, 0},
    /*1*/{10, "The Chariot", "Increases defense a 30%", {1, 1.3, 1}, 0},
    /*2*/{10, "The Tower", "Increases attack a 15%", {1.15 , 1, 1}, 0},
    /*3*/{10, "The Devil", "Increases attack a 30%", {1.3, 1, 1}, 0},
    /*4*/{10, "The Hangman", "Eliminates luck", {1, 1, 0}, 10},
    /*5*/{10, "Weel Of Fortune", "Duplicates luck", {1, 1, 2}, 0},
    /*6*/{10, "Death of Theo", "Death is the only way", {0.5, 2, 1}, -5},
    /*7*/{10, "The Armadillo", "Nothing like home", {0.5, 2, 1}, 20},
    /*8*/{10, "The Fool", "Decreases defense a 10%, and increase luck a 30%", {1, 0.9, 1.3}, 0},
    /*9*/{10, "Justice", "Faith will guide you", {1.1, 1.1, 1.1}, 0},
    /*10*/{100, "Time Strike", "Repeat a random previous attack and double its damage", {1,1,1}, 0},
    /*11*/{0, "Sword Slash", "their blood, better spent in soil than veins", {100.0, 100.0, 100.0}, 100},
    /*12*/{10, "Sword Strie", "peirce the enemies' unfeeling heart", {200.0, 200.0, 200.0}, 100},
    };
    // i need to change this function as hell
    return skills_dictionary;
};
/*
this function receives:
    - filename and the skill_name
it does:
    - loads the skill from the file into a skill struct
returns:
    - the skill struct*/
void init_weapon_skill(Weapon *weapon, char filename[] /*weapons.txt*/, int index1, int index2){ //fix this function again later.
    FILE *file_pointer = fopen(filename, "r");
    if(file_pointer == NULL){
        perror("Error opening file!");
    }
    char skill_name[MAX_DESCRIPTION_LEN];
    int min, max, difference;
    if(index1 < index2){
        min = index1;
        max = index2;
    } else {
        min = index2;
        max = index1;
    }
    difference = max - min;
    if (difference < 1){perror("error indexing weapon skills.");}

    for(int i = 0; i < (min*4 + 1); i++){
        fgets(weapon->skills[0]->name, sizeof(weapon->skills[0]->name), file_pointer);
    }
    fgets(weapon->skills[0]->description, sizeof(weapon->skills[0]->description), file_pointer);
    fscanf(file_pointer, "%d %d %d\n", &(weapon->skills[0]->skill_modifier.tempatk), &(weapon->skills[0]->skill_modifier.tempdef), &(weapon->skills[0]->skill_modifier.templuc));

    for(int i = 0; i < ((difference-1)*4 + 2); i++){
        fgets(weapon->skills[1]->name, sizeof(weapon->skills[1]->name), file_pointer);
    }
    fgets(weapon->skills[1]->description, sizeof(weapon->skills[1]->description), file_pointer);
    fscanf(file_pointer, "%d %d %d\n", &(weapon->skills[1]->skill_modifier.tempatk), &(weapon->skills[1]->skill_modifier.tempdef), &(weapon->skills[1]->skill_modifier.templuc));

    fclose(file_pointer);
}
/*
this receives:
    - character by reference, filename and weapon name
it does:
    - find the weapon attributes in the file and assigns it to the character.
it returns:
 - nothing (updates character by reference)
*/
void pick_up_weapon(Character *character, FILE *file_pointer, char search_weapon_name[]){
    char file_weapon_name[MAX_DESCRIPTION_LEN];
    int equality = strcmp(fgets(file_weapon_name, sizeof(file_weapon_name), file_pointer), search_weapon_name); //this might need newline char

    while(equality != 0){
        for(int i = 0; i < 3; i++){ // you executre it 4 - 1 times sot aht the last correct one can be the assignemtn too.
            fgets(file_weapon_name, sizeof(file_weapon_name), file_pointer);
        }
    equality = strcmp(fgets(file_weapon_name, sizeof(file_weapon_name), file_pointer), search_weapon_name);
    }
    //line below is done just for the shorthand
    // Weapon *weapon_p_shorthand = &(character->inventory.weapons_in_inventory[character->inventory.fill]);
    if(character->inventory.fill >= 7){
        printf("Inventory Full!");
        return;
    }
    character->inventory.weapons_in_inventory[character->inventory.fill] = character->active_weapon;
    character->inventory.fill++;
    
    
    strncpy(character->active_weapon.name, search_weapon_name, MAX_DESCRIPTION_LEN);


    fgets(character->active_weapon.description, sizeof(character->active_weapon.description), file_pointer);
    int index1, index2;
    fgets(&index1, sizeof(int), file_pointer);
    fgets(&index2, sizeof(int), file_pointer);
    init_weapon_skill(&(character->active_weapon),"skills.txt",index1 ,index2);
}
/*
This function receives:
    - skills array
It does:
    - inits the wepons array
Returns:
    - pointer to array.
*/

Weapon *init_weapons_dictionary(Skill skills_dictionary[]) {
    Weapon weapons[7] = {
    {"Fists", "Ol' reliable bare knuckles", {&skills_dictionary[4], &skills_dictionary[10]}},
    {"Rusty Revolver", "Older than the mountains", {&skills_dictionary[0], &skills_dictionary[4]}},
    {"Linda", "Sweetest kisses in the wild west", {&skills_dictionary[2], &skills_dictionary[0]}},
    {"GOAT", "Gun Of Antilope Trilobites", {&skills_dictionary[5], &skills_dictionary[3]}},
    {"Gun & Barrel", "A gun in a barrel", {&skills_dictionary[1], &skills_dictionary[2]}},
    {"Cactus Thrower", "Ouch..", {&skills_dictionary[7], &skills_dictionary[8]}},
    {"Gatling Gun", "RATATATTATATA", {&skills_dictionary[6],&skills_dictionary[5]}}
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
        fgets(character->name, MAX_DESCRIPTION_LEN, stdin);

        /* Remove the newline character from the end of the input and add the null terminator */
        character->name[strcspn(character->name, "\n")] = '\0';

        printf("Are you sure you want the name '%s'? (yes/no): ", character->name);
        char answer[MAX_DESCRIPTION_LEN];
        fgets(answer, MAX_DESCRIPTION_LEN, stdin);
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
Character create_character(Weapon weapons_dictionary[] /* Weapons dictionary */, bool first_game) { //trya dn save this for later
    if (first_game == true){
        printf("Welcome to Character Creation!\n");
    } else{
        printf("Welcome to Character Creation!\nWarning: Previous character will be erased\n");
    }
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
            char answer[MAX_DESCRIPTION_LEN];
            fgets(answer, MAX_DESCRIPTION_LEN, stdin);
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
Decision *init_decision_list(){ //i have not implemented most of this its just a framework
    Decision decision_list[] = {
        {"CHAPA NUMERO 0", {{"REPUESTA 0.0"}, {"RESPUESTA 0.1"}, {"REPUESTA 0.2"}, {"RESPUESTA 0.3"}}},
        {"CHAPA NUMERO 1", {{"REPUESTA 1.0"}, {"RESPUESTA 1.1"}, {"REPUESTA 1.2"}, {"RESPUESTA 1.3"}}},
        {"CHAPA NUMERO 2", {{"REPUESTA 2.0"}, {"RESPUESTA 2.1"}, {"REPUESTA 2.2"}, {"RESPUESTA 2.3"}}},
        {"CHAPA NUMERO 3", {{"REPUESTA 3.0"}, {"RESPUESTA 3.1"}, {"REPUESTA 3.2"}, {"RESPUESTA 3.3"}}},
        {"CHAPA NUMERO 4", {{"REPUESTA 4.0"}, {"RESPUESTA 4.1"}, {"REPUESTA 4.2"}, {"RESPUESTA 4.3"}}},
        {"CHAPA NUMERO 5", {{"REPUESTA 5.0"}, {"RESPUESTA 5.1"}, {"REPUESTA 5.2"}, {"RESPUESTA 5.3"}}},
    };

    return decision_list;
}

Scenario *init_scenario_list(Decision decision_list[]){

    Scenario scenario_list[] = {
        {"name0", "description0", /*we need to put the other things here*/ .decision = decision_list[0]},
        {"name1", "description1", .decision = decision_list[1]},
        {"name2", "description2", .decision = decision_list[2]},
        {"name3", "description3", .decision = decision_list[3]},
        {"name4", "description4", .decision = decision_list[4]},
        {"name5", "description5", .decision = decision_list[5]},
    };

    return scenario_list;
}
/*This is conlicting with the same definition in scenario.h*/

//Scenario *init_first_scenario(Scenario scenario_list[], int index){
    //Scenario first_scenario = scenario_list[0]; //we just have to make sure that the first one in the list is the starting one
  //  return &first_scenario;
//}

Scenario *init_next_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario){
    Scenario *next_scenario = (Scenario *)malloc(sizeof(Scenario));
    *next_scenario = scenario_list[index];


    /*setting the doubly linked list.*/
    prev_scenario->next = next_scenario;
    next_scenario->prev = prev_scenario;

}

Scenario *init_other_scenario(Scenario scenario_list[], int index, Scenario *prev_scenario){
    Scenario *other_scenario = (Scenario *)malloc(sizeof(Scenario));
    *other_scenario = scenario_list[index];

    /*this is the same as the above function but with a other route.*/ //it might be useful to store the direction in an arry so that we can appluy marcels function
    prev_scenario->other_direction = other_scenario;
    other_scenario->prev = prev_scenario;
}

int backwards(int direction){
    return (4 - direction);
}

void change_scenario(Scenario *scenario, int direction /*should be passed in as macro*/){
    int backwards_direction = backwards(direction);
    /*there will need to be error checking here*/
}

void delete_scenarios(Scenario *scenario){
    // while there are valid directions to go you should delete them all this is done when you die and want to restart so that memory is not building up forever.
}

void play_scenario(Scenario *cuurent_scenario){ /*this is where you have the fight and everything*/}
