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
Character create_character() {
    printf("Welcome to Character Creation!\nWarning: Previous character will be erased\n");

    /* Character initialization */
    Character character;

    character.active_weapon = weapons[0];
    character.weapon_inventory[0] = weapons[0];

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

    /* Initialize skills array with empty values */
    for (int i = 0; i < MAX_SKILLS; i++) {
        strcpy(character.skills[i].name, "");
        strcpy(character.skills[i].description, "");
        character.skills[i].skill_modifier.tempatk = 0;
        character.skills[i].skill_modifier.tempdef = 0;
        character.skills[i].skill_modifier.templuc = 0;
    }

    /* Initialize active modifier to default values */
    for (int i = 0; i < MAX_MODIFIERS; i++) {
        character.active_modifier[i].tempatk = 0;
        character.active_modifier[i].tempdef = 0;
        character.active_modifier[i].templuc = 0;
    }
    
    /* We initialize balance */
    character.balance = 0;

    /* We add the initial weapon */
    character.active_weapon = weapons[0];

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

void attack_player(Character *character, Enemy *enemies, int dead_enemies){
    /*Do a scanf for the player to choose the enemy to which attack (they will range from 0 to max_enemies)*/
    const char *options1[] = {"Attack", "Skills", NULL};
    int tipo_ataque = get_selection(options1);
    if (tipo_ataque == 0){
        const char *Enemies[] = {enemies[0].name, "Skills", NULL};
        int enemigo = funcion_de_marcel(a que enemigo le quieres zurrar);
        reducir vida del enemigo con las bhgv

    }else{
        int ability = funcion_de_marcel(que habilidad hacer);
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