#include "combat.h"

/* Functions for turn-based combat */

/* INIT FIGHT CHARACTER
This function recieves:
    - Nothing
It does:
    - Initialize characters in fight
Returns:
    - Nothing
*/
void init_fight_characters(Character *character, Enemy *enemies, int number_of_enemies){
    
    // Initialize health and bullets of our character
    character->health = 100+(20*(character->stats.hp-1));
    character->bullets = 100+(10*(character->stats.bp-1));

    // Initialize modifiers on base value
    character->active_modifiers.tempatk = 1;
    character->active_modifiers.tempdef = 1;
    character->active_modifiers.templuc = 1;

    // Initialize enemies' health
    for (int i = 0; i < number_of_enemies; i++) {
        enemies[i].health = 100+(20*(enemies[i].stats.hp-1));
    }
}

/* SELECT ENEMY
This function recieves:
    - An array of enemies in form of pointer
    - An int number_of_enemies
It does:
    - Select an enemy with hp>0
Returns:
    - Selected enemy's index in array
*/
int select_enemy(Enemy *enemies, int number_of_enemies) {

    // Print available enemies (health>0)
    printf("Available enemies:\n");
    for (int i = 0; i < number_of_enemies; i++) {
        if (enemies[i].health > 0) {
            printf("%d. %s\n", (i + 1), enemies[i].name);
        }
    }
    // While loop to get a choice of enemy to attack, with error handling in case the enemy selection isn't correct
    int choice;
    do {
        printf("Choose an enemy (1-%d): ", number_of_enemies);
        scanf("%d", &choice);
        if (choice < 1 || choice > number_of_enemies || enemies[choice - 1].health <= 0) {
            printf("Invalid choice. Please choose a valid enemy.\n");
        }
    } while (choice < 1 || choice > number_of_enemies || enemies[choice - 1].health <= 0);

    return choice - 1; // Return index of selected enemy
}

/* TURN PLAYER 
This function recieves:
    - Pointer to character, array of enemies and stack of attacks. Also an int of number of enemies (size of array) and attacks done for Time Strike implementation
It does:
    - All the turn of the player: Choosing to attack or use skill, use of the skill, special skill Time Strike implementation.
Returns:
    - Nothing
*/
void turn_player(Character *character, Enemy *enemies, Stack* attack_stack, int number_of_enemies, int *attacks_done, int *time_strike_done, int *dead_enemies) {
    
    // We initialize the options for the combat, a variable to store the selected option and a flag to track if the turn is done
    const char *options[] = {"Shoot", "Skill: +DEF (Costs 20 BP)", "Skill: +ATK (Costs 20 BP)", "Skill: +LUC (Costs 20 BP)", "Skill: Time Strike (Costs 100 BP)", "Skill: Heal (Costs 10 BP)", NULL};
    int atk_type;
    int turn_done = 0;

    // Main loop with error handling
    while (!turn_done){
        // We get the selection between the options
        atk_type = get_selection(options);
        
        // Check for selected option and whether if you have enough bulletpoints to use it
        switch (atk_type) {
            case 1: {
                // BASE ATTACK: SHOOT

                // Select enemy
                int enemy_selected = select_enemy(enemies, number_of_enemies);

                // Calculate total damage by simple function that depends on character and enemy stats
                int total_damage = (10 * ((character->stats.atk) * (character->active_modifiers.tempatk))) / (enemies[enemy_selected].stats.def);
                enemies[enemy_selected].health -= total_damage;
                
                // Print output of the attack and/or update for the death of an enemy
                printf("You've dealt %d damage to %s\n", total_damage, enemies[enemy_selected].name);
                if (enemies[enemy_selected].health <= 0) {
                    printf("%s has died\n", enemies[enemy_selected].name);
                    (*dead_enemies)++;
                }
                else {
                    printf("%s health: %d\n", enemies[enemy_selected].name, enemies[enemy_selected].health);
                }
                // Push damage done into the attack stack
                push_stack(attack_stack, total_damage);
                (*attacks_done)++;
                turn_done = 1;
                break;
            }
            case 2: {
                // SKILL 1: AUGMENTING DEF

                // Check for enough bulletpoints
                if (character->bullets >= 20) {
                    // Apply modifier
                    character->active_modifiers.tempdef += 1;
                    printf("You've added +1 to your defense for the next turn\n");
                    character->bullets -= 20; // Deduct bullets
                    turn_done = 1;
                }
                else {
                    printf("Not enough bullet points to use this skill!\n");
                }
                break;
            }
            case 3: {
                // SKILL 2: AUGMENTING ATK

                // Check for enough bulletpoints
                if (character->bullets >= 20) {
                    // Apply modifier
                    character->active_modifiers.tempatk += 1;
                    printf("You've added +1 to your attack for the next turn\n");
                    turn_done = 1;
                }
                else {
                    printf("Not enough bullet points to use this skill!\n");
                }
                break;
            }
            case 4: {
                // SKILL 3: AUGMENTING LUC

                // Check for enough bulletpoints
                if (character->bullets >= 20) {
                    // Apply modifier
                    character->active_modifiers.templuc += 1;
                    printf("You've added +1 to your luck for the next turn\n");
                    turn_done = 1;
                }
                else {
                    printf("Not enough bullet points to use this skill!\n");
                }
                break;
            }
            case 5: {
                // SKILL 4: TIME STRIKE

                // Check for enough bulletpoints
                if (character->bullets >= 100 && (!is_empty_stack(attack_stack))) {
                    if ((*time_strike_done)==0) {
                        // Seed the random number generator (optional)
                        srand(time(NULL));

                        // Generate a random number between 0 and attacksdone-1
                        int random_number = rand() % (*attacks_done);
                        // Initialise past_damage variable to store random attack
                        int past_damage = -1;
                        if (random_number == 0) {
                            past_damage = pop_stack(attack_stack);
                        }
                        else {
                            for (int i = 0; i < random_number; i++){
                                past_damage = pop_stack(attack_stack);
                            }
                        }
                        // Calculate total damage by doubling past damage and apply it to enemy
                        int enemy_selected = select_enemy(enemies, number_of_enemies);
                        int total_damage = 2 * past_damage;
                        enemies[enemy_selected].health -= total_damage;

                        // Print output of the attack and/or update for the death of an enemy
                        printf("You've dealt %d damage to %s\n", total_damage, enemies[enemy_selected].name);
                        if (enemies[enemy_selected].health <= 0) {
                            printf("%s has died\n", enemies[enemy_selected].name);
                            (*dead_enemies)++;
                        }
                        else {
                            printf("%s health: %d\n", enemies[enemy_selected].name, enemies[enemy_selected].health);
                        }

                        // Free the stack and update time_strike_done
                        free_stack(attack_stack);
                        (*time_strike_done) = 1;
                        turn_done = 1;
                    }
                    else if ((*time_strike_done) == 1){
                        // Print appropiate response in case Time Strike is not available
                        printf("You've already used Time Strike this fight!\n");
                    }
                    }
                else {
                    if (is_empty_stack(attack_stack)) {
                        printf("You haven't done any previous attacks!\n");
                    }
                    else {
                        printf("Not enough bullet points to use this skill!\n");
                    }
                }
                break;
            }
            case 6: {
                // SKILL 5: HEAL

                // Check for enough bulletpoints
                if (character->bullets >= 10) {
                    // Heal depending on player's stats and print result
                    int healing = (character->stats.hp + character->stats.luc + character->active_modifiers.templuc);
                    character->health += healing;
                    printf("You've healed yourself by %d points!\n", healing);
                    turn_done = 1;
                }
                else {
                    printf("Not enough bullet points to use this skill!\n");
                }
                break;
            }
        }
    }
    // Print remaining bullet points
    printf("Remaining bullet points: %d\n", character->bullets);
}

/* TURN ENEMY 
This function recieves:
    - Pointers for a character and an enemy
Does:
    - The pattern of attack of the enemies
Returns:
    - Nothing
*/
void turn_enemy(Character *character, Enemy *enemy) {
    // Seed a random number generator
    srand(time(NULL));

    // Generate a random number between 0 and 10
    int r = rand() % 10;

    // There's a 10% chance that the enemy heals, otherwise it attacks normally
    if (r!=0) {
        int total_damage = (5 * enemy->stats.atk) / (character->stats.def * character->active_modifiers.tempdef);    
        character->health -= total_damage;
        printf("%s has done a base attack and caused %d damage\n", enemy->name, total_damage);
        printf("%s health: %d\n", character->name, character->health);
    }
    else {
        enemy->health += 5*(enemy->stats.hp);
        printf("%s has missed but healed himself! No damage\n", enemy->name);
        printf("%s health: %d\n", enemy->name, enemy->health);
    }
}

/* DO COMBAT
This function recieves:
    - The character (by reference)
    - An array of enemies of size n 
It does:
    - The fight
Returns:
    - Nothsing
*/
void do_combat(Game *game_state, Enemy *enemies, int number_of_enemies) {
    
    //Initialisation of characters
    init_fight_characters(game_state->character, enemies, number_of_enemies); 

    printf("You've started a combat with:\n");
    for (int i=0; i<number_of_enemies; i++) {
        printf("%s\n", enemies[i].name);
    }

    // We generate a random value from 10 to 20, that will be the number of turns for each fighter
    srand(time(NULL));
    int n = rand() % 11 + 10;

    // We initialise the queue and enqueue it with n times 0,1,..., number of enemies. That will let us manage the index of who's turn it is
    Queue *turn_queue = create_queue(n*(number_of_enemies+1));
    for (int i=0; i<((number_of_enemies+1)*n); i++) {
        enqueue(turn_queue, i%(number_of_enemies+1));
    }

    // Dequeue a random number of turns from 1 to number_of_enemies to randomize who starts attacking
    srand(time(NULL));
    int r = rand() % number_of_enemies + 1;
    for (int i = 0; i < r; i++){
        dequeue(turn_queue);
    }

    // We initialise the stack of size n turns
    Stack *attack_stack = create_stack(n);

    // We initialise a flag to limit Time Strike to 1 use per fight
    int time_strike_done = 0;

    // Here we set the player index for readibility and a counter for number of attacks done by us
    int player_index = number_of_enemies;
    int dead_enemies = 0;
    int attacks_done = 0;

    // While loop of fight
    while ((dead_enemies != number_of_enemies && !is_empty_queue(turn_queue)) && game_state->character->health>0) {

        // Since the queue has indexes from 0 to player_index, we dequeue once for each turn
        int turn = dequeue(turn_queue);
        if (turn == player_index){
            printf("Your turn to attack! \n");
            turn_player(game_state->character, enemies, attack_stack, number_of_enemies, &attacks_done, &time_strike_done, &dead_enemies);
        }
        else {
            printf("%s is now attacking!\n", enemies[turn].name);
            turn_enemy(game_state->character, &(enemies[turn]));
        }
    }
    // Check end of battle result
    if (dead_enemies == number_of_enemies){
        printf("You've killed all enemies!\n");
    }
    else if (is_empty_queue(turn_queue)){
        printf("You ran out of turns and lost!");
        (game_state->state) = DEAD;
    }
    else if (game_state->character->health<=0){
        printf("You've died!\n");
    }
}
