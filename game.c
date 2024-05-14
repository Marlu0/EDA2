#include "game.h"

/*
This function receives:
    - nothing
It does:
    - inits the skills array
Returns:
    - pointer to array
*/
Skill *init_skills(){
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

Skill *init_skill(char filename[], char name[] /*pull it out on the name*/){
    FILE *file_pointer = fopen(filename, "w");
    if(file_pointer == NULL){
        perror("Error opening file") //this is a boss function use it more often
    }

    while(strncmp()) //this needs to be finished later
}

/*
This function receives:
    - skills array
It does:
    - inits the wepons array
Returns:
    - pointer to array.
*/

Weapon *init_weapons(Skill skills[]){
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
    character->stats.bp = 0;
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
Character create_character(Weapon weapons[]/*weapons list*/, Skill skills[] /*skills list*/) {
    printf("Welcome to Character Creation!\nWarning: Previous character will be erased\n");

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
    for (int i = 0; i < MAX_MODIFIERS; i++) {
        character.active_modifiers[i].tempatk = 1;
        character.active_modifiers[i].tempdef = 1;
        character.active_modifiers[i].templuc = 1;
    }
    
    /* We initialize balance */
    character.balance = 0;

    /* We add the initial weapon */
    character.active_weapon = weapons[0];
    character.inventory.weapons_in_inventory[0] = weapons[0];
    character.inventory.fill = 1;


    /* We initialise health and mana in function of hp and mp stats */
    character.health = 100 + (10*(character.stats.hp));
    character.bullets = 100 + (10*(character.stats.bp));

    return character;
}

/*
*/
int select_skill(Character *character) {
    int bullets = character->bullets;
    int available_skills[NUM_SKILLS]; // Array to store indices of available skills
    int num_available_skills = 0; // Counter for available skills

    // Check available skills and store their indices
    for (int i = 0; i < NUM_SKILLS; ++i) {
        if (bullets >= character->active_weapon.skills[i].bulletcost) {
            available_skills[num_available_skills++] = i;
        }
    }

    // If no available skills, return -1
    if (num_available_skills == 0) {
        printf("No available skills with current bullets.\n");
        return -1;
    }

    // Print available skills with their costs
    printf("Available Skills:\n");
    for (int i = 0; i < num_available_skills; ++i) {
        int index = available_skills[i];
        printf("%d. %s, Cost: %d\n", i + 1, character->active_weapon.skills[index].name, character->active_weapon.skills[index].bulletcost);
    }
    

    int selection;
    while (1) {
        // Scan the selection
        printf("Select a skill (1-%d): ", num_available_skills);
        if (scanf("%d", &selection) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue; // Skip the rest of the loop and ask again for input
        }

        // Validate the selection
        if (selection < 1 || selection > num_available_skills) {
            printf("Invalid selection. Please select a skill between 1 and %d.\n", num_available_skills);
            continue; // Skip the rest of the loop and ask again for input
        }

        break; // Break out of the loop if the input is valid
    }

    // Return the selected skill index
    return available_skills[selection - 1];
}

/*
This function recieves:
    - An array of enemies in form of pointer
    - An int numEnemies
It does:
    - Select an enemy with hp>0
Returns:
    - Selected enemy's index in array
*/
int selectEnemy(Enemy *enemies, int numEnemies) {
    printf("Available enemies:\n");
    for (int i = 0; i < numEnemies; ++i) {
        if (enemies[i].health > 0) {
            printf("%d. %s\n", (i + 1), enemies[i].name);
        }
    }

    int choice;
    do {
        printf("Choose an enemy (1-%d): ", numEnemies);
        scanf("%d", &choice);
        if (choice < 1 || choice > numEnemies || enemies[choice - 1].health <= 0) {
            printf("Invalid choice. Please choose a valid enemy.\n");
        }
    } while (choice < 1 || choice > numEnemies || enemies[choice - 1].health <= 0);

    return choice - 1; // Return index of selected enemy
}

void turn_player(Character *character, Enemy *enemies, int numEnemies, Stack* attackStack, int attacksDone){
    /*Do a scanf for the player to choose the enemy to which attack (they will range from 0 to max_enemies)*/
    const char *options1[] = {"Attack", "Skills", NULL};
    int atkType = get_selection(options1);
    switch (atkType){
        case 1:
            int enemySelected = selectEnemy(enemies, numEnemies);
            enemies[enemySelected].health -= (10*((character->stats.atk)*(character->active_modifiers->tempatk)))/((enemies[enemySelected].stats.def)*(enemies[enemySelected].modifier.tempdef));
        
        case 2:
            int skillSelected = select_skill(character);

            // Special skill, Time Strike
            if (character->active_weapon.skills[skillSelected]->name == "Time Strike"){
                //Generate a random number n between 1 and attacksDone and pop n times
                srand(time(NULL));
                int n = rand() % attacksDone + 1;
                int pastDamage = 0;
                for (int i=0; i<n; ++i){
                    pastDamage = pop_stack(attackStack);
                }
                int totalDamage = 2*pastDamage;
                int enemySelected = selectEnemy(enemies, numEnemies);
                enemies[enemySelected].health -= totalDamage;
                printf("You've used Time Strike and have given %d damage to %s\n",totalDamage, enemies[enemySelected].name);
            }

            else {
            //Apply modifiers to character
            character->active_modifiers->tempatk += character->active_weapon.skills[skillSelected]->skill_modifier.tempatk;
            character->active_modifiers->tempdef += character->active_weapon.skills[skillSelected]->skill_modifier.tempdef;
            character->active_modifiers->templuc += character->active_weapon.skills[skillSelected]->skill_modifier.templuc;
            
            //Apply healing in case skill heals
            character->health += character->active_weapon.skills[skillSelected]->healing;
            printf("You've healed %d health points", character->active_weapon.skills[skillSelected]->healing);

            //Do the attack part
            int enemySelected = selectEnemy(enemies, numEnemies);
            int totalDamage = (10*((character->stats.atk)*(character->active_modifiers->tempatk)))/((enemies[enemySelected].stats.def)*(enemies[enemySelected].modifier.tempdef));    
            enemies[enemySelected].health -= totalDamage;
            printf("You've used %s and have given %d damage to %s", character->active_weapon.skills[skillSelected]->name, totalDamage, enemies[enemySelected].name);

            push_stack(attackStack, totalDamage);

            ++attacksDone;
            }
        
        default:
            printf("Invalid selection. Please try again.\n");
    }
    /*Do the switch fot the differnt attacks possible*/
    /*To each switch possibility, relate it with the ability*/
    /*Add the attack chosen to the attack stack (for the time shot ability)*/
    /*Use the multiplier and substract the hp points form the baddie*/
    /*Return the modified abilities to normality*/
}
/*
This function recieves:
    - The character (by reference)
    - An array of enemies of size n 
It does:
    - The fight
Returns:
    - Nothing
*/
void do_combat(Character *character, Enemy *enemies, int number_of_enemies){
    printf("You've started a combat with:\n ");
    for (int i=0; i<MAX_ENEMIES; ++i){
        printf("%s ", enemies[i].name);
    }

    /* We generate a random value from 10 to 20, that will be the number of turns for each fighter */
    srand(time(NULL));
    int n = rand() % 11 + 10;

    /* We initialise the queue */
    Queue *turnQueue = create_queue(n*(number_of_enemies+1));

    srand(time(NULL));
    /*The baddies will have the indexes 0 to number_of_enemies-1 so we can acces their array, the goodie will be that value, so it is fixed*/
    int firstTurn = rand() % (number_of_enemies+1);

    for (int i=0; i<((number_of_enemies+1)*n); ++i){
        enqueue(turnQueue, i%(number_of_enemies+1));
    }
    
    /*Here we set a dead enemy counter and a copy of n to keep track of when the battle ends*/
    int goodie_index = number_of_enemies;
    int dead_enemies = 0;
    int N = n;
    bool first_turn_done = false;
    while(dead_enemies != 0 && !isEmpty(turnQueue) && character->health>0){
        //Here we do the first turn control
        if(!first_turn_done){
            if (turnQueue->items[turnQueue->front] = firstTurn){
                if(turnQueue->items[turnQueue->front] = goodie_index){
                    printf("Your turn to attack! \n");
                    turn_player();
                    dequeue(turnQueue);
                }else{
                    printf("%s is now attacking!\n", enemies[turnQueue->items[turnQueue->front]].name);
                    turn_enemy();
                    dequeue(turnQueue);
                }
                first_turn_done = true;
            }else{
                dequeue(turnQueue);
            }
        }
        else{
            if(turnQueue->items[turnQueue->front] = goodie_index){
                    /*For the player attack we pass the character and the array of enemies so we can choose to whom attack*/
                    attack_player(character, enemies, dead_enemies);
                    dequeue(turnQueue);
                }else{
                    /*In the enemy attack we pass the enemy in turn and the character*/
                    /*The enemy shoud be a pointer TALK WITH MARCELINO*/
                    attack_enemy(enemies[turnQueue->items[turnQueue->front]], character, dead_enemies);
                    dequeue(turnQueue);
                }
        }
    }
}

Character customize_character(Character *character){
    
}

void attain_weapon(Character *character, Weapon weapon){
    int size = character->inventory.fill; /*you need to us a dot on the second as it is by value.*/
    character->inventory.weapons_in_inventory[size] = weapon;
    character->inventory.fill++;

    /*realistically this function doesnt need to exist and can just be done at the
    bottom of the do_fight function*/
}
