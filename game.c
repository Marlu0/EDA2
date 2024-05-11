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

void init_skill(char filename[], char skill_name[]){
    FILE *file_pointer = fopen(filename, "r");
    if(file_pointer == NULL){
        perror("Error opening file!"); //this is a boss function use it more often
    }
    char skill_name[MAX_STRING_LEN];
    int equality = strncpm(fgets(skill_name, sizeof(skill_name), file_pointer), skill_name); //maybe newline char?

    while(equality == 0){
            for(int i = 0; i < 3; i++){ // you executre it 4 - 1 times sot aht the last correct one can be the assignemtn too.
            fgets(skill_name, sizeof(skill_name), file_pointer);
        }
    equality = strncpm(fgets(skill_name, sizeof(skill_name), file_pointer), skill_name);
    }
}
/*
this receives:
    - character by reference, filename and weapon name
it does:
    - find the weapon attributes in the file and assigns it to the character.
it returns:
 - nothing (updates character by reference)
*/
void init_weapon(Character *character, char filename[], char weapon_name[]){ // puts it in their inventory. and then there should be another one that takes it from your inventory and equips it immidiately. grabbing a weapon can be a combination of these functions.
    FILE *file_pointer = fopen(filename, "r");
    if(file_pointer ==  NULL){
        perror("Error opening file!");
    }
    char weapon_name[MAX_STRING_LEN]; //you named the variable the same thing twice!!! fix tommorow
    int equality = strncpm(fgets(weapon_name, sizeof(weapon_name), file_pointer), weapon_name); //this might need newline char

    while(equality != 0){
        for(int i = 0; i < 3; i++){ // you executre it 4 - 1 times sot aht the last correct one can be the assignemtn too.
            fgets(weapon_name, sizeof(weapon_name), file_pointer);
        }
    equality = strncpm(fgets(weapon_name, sizeof(weapon_name), file_pointer), weapon_name);
    }
    //line below is done just for the shorthand
    Weapon *weapon_p_shorthand = &(character->inventory.weapons_in_inventory[character->inventory.fill]);
    
    strncpy(weapon_p_shorthand->name, weapon_name, MAX_STRING_LEN);


    fgets(weapon_p_shorthand->description, sizeof(weapon_description), file_pointer);
     /*||here is where you put in the code to make it an index of the thang its not that hard but do the other thing first.||*/

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
        character.active_modifiers[i].tempatk = 0;
        character.active_modifiers[i].tempdef = 0;
        character.active_modifiers[i].templuc = 0;
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
This function recieves:
    - The character (by reference)
    - An array of enemies of size n 
    - Number of dead enemies 
It does:
    - The attack process of the player itself
Returns:
    - Nothing
*/

int select_skill(Character *character){ /*you need to pass sthe numEnemies in here*/
    printf("Available skills:\n");
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

void attack_player(Character *character, Enemy *enemies, int numEnemies){
    /*Do a scanf for the player to choose the enemy to which attack (they will range from 0 to max_enemies)*/
    const char *options1[] = {"Attack", "Skills", NULL};
    int tipo_ataque = get_selection(options1);
    if (tipo_ataque == 0){
        int enemigo = selectEnemy(enemies, numEnemies);
        enemies[enemigo].health -= (10*(character->stats.atk+character->active_modifiers->tempatk))/(enemies[enemigo].stats.def+enemies[enemigo].modifier.tempdef);
    }
    else{
        int skill = funcion_de_marcel(que habilidad hacer);
        aplicamos modificador
        int enemigo = funcion_de_marcel(a que enemigo le quieres zurrar);
        reducir vida del enemigo con las bhgv

    
    }

    /*Do the switch fot the differnt attacks possible*/
    /*To each switch possibility, relate it with the ability*/
    /*Add the attack chosen to the attack stack (for the time shot ability)*/
    /*Use the multiplier and substract the hp points form the baddie*/
    /*Return the modified abilities to normality*/
}

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
    Queue *turnQueue = createQueue(n*(number_of_enemies+1));

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
                    attack_player();
                    dequeue(turnQueue);
                }else{
                    printf("%s is now attacking!\n", enemy[turnQueue->items[turnQueue->front]].name);
                    attack_enemy();
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