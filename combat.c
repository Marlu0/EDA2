#include "global.h"
#include "game.h"

/* Functions for turn-based combat */

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
    printf("Available enemies:\n");
    for (int i = 0; i < number_of_enemies; ++i) {
        if (enemies[i].health > 0) {
            printf("%d. %s\n", (i + 1), enemies[i].name);
        }
    }

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
void turn_player(Character *character, Enemy *enemies, Stack* attack_stack, int number_of_enemies, int *attacks_done) {
    const char *options1[] = {"Shoot", "Skill: +DEF", "Skill: +ATK", "Skill: +LUC", "Skill: Time Strike", NULL};
    int atkType = get_selection(options1);

    switch (atkType) {
        case 1: {
            // BASE ATTACK
            int enemy_selected = select_enemy(enemies, number_of_enemies);
            int total_damage = (10 * ((character->stats.atk) * (character->active_modifiers.tempatk))) / (enemies[enemy_selected].stats.def);
            enemies[enemy_selected].health -= total_damage;
            push_stack(attack_stack, total_damage);
            (*attacks_done)++;
            break;
        }
        case 2: {
            // SKILL 1: AUGMENTING DEF
            character->active_modifiers.tempdef += 1;
            break;
        }
        case 3: {
            // SKILL 2: AUGMENTING ATK
            character->active_modifiers.tempatk += 1;
            break;
        }
        case 4: {
            // SKILL 3: AUGMENTING LUC
            character->active_modifiers.templuc += 1;
            break;
        }
        case 5: {
            // SKILL 4: TIME STRIKE
            if (!isEmpty(attack_stack)) {
                int past_damage = pop_stack(attack_stack);
                int total_damage = 2 * past_damage;
                // Implement logic to choose a past attack (e.g., store last few attacks)
                enemies[/*enemy_to_attack*/].health -= total_damage;
                (*attacks_done)++;
            }
            else {
                printf("No past attacks to use Time Strike!\n");
            }
            break;
        }
    }
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
    int character_health = character->health;
    int enemy_health = enemy->health;
    float aggressiveness = (float)character_health / enemy_health; // This can make the enemy more aggressive as its health goes down

    /* Initialize chance of types of attack */
    int base_attack_chance;
    int skill_chance;
    int miss_chance;

    /* Set base chances for the fight in function of character's luck */
    int luck = character->stats.luc;  
    base_attack_chance = luck * 4;
    skill_chance = 100 - base_attack_chance;
    miss_chance = 0; // Initially set to 0, will be recalculated if needed

    /* Adjust chances if enemy is in disadvantage */
    if (aggressiveness > AGGRESSIVE_MODE_ACTIVATOR) {
        base_attack_chance += 10;
        skill_chance -= 10;
        miss_chance = 100 - (base_attack_chance + skill_chance); // Recalculate miss chance
    }

    /* Seed a random number generator */
    srand(time(NULL));

    /* Generate a random number between 1 and 100 */
    int r = rand() % 100 + 1;

    /* Depending on the number and chances, do one thing or another */
    if (r <= base_attack_chance) {
        int total_damage = (10 * (enemy->stats.atk * enemy->active_modifiers[0].tempatk)) / (character->stats.def * character->active_modifiers[0].tempdef);    
        character->health -= total_damage;
        printf("%s has done a base attack and caused %d damage\n", enemy->name, total_damage);
    } else if (r <= base_attack_chance + skill_chance) {
        /* To choose the skill, we'll use a random integer generator from 0 to 1 */
        int skill_index = rand() % 2;
        Skill chosen_skill = *enemy->weapon.skills[skill_index];

        /* Now we apply the modifiers of the skill */
        enemy->active_modifiers[0].tempatk += chosen_skill.skill_modifier.tempatk;
        enemy->active_modifiers[0].tempdef += chosen_skill.skill_modifier.tempdef;
        enemy->active_modifiers[0].templuc += chosen_skill.skill_modifier.templuc;

        /* Finally, the enemy attacks */
        int total_damage = (10 * (enemy->stats.atk * enemy->active_modifiers[0].tempatk)) / (character->stats.def * character->active_modifiers[0].tempdef);    
        character->health -= total_damage;

        printf("%s has used %s and caused %d damage\n", enemy->name, chosen_skill.name, total_damage);
    } 
    else {
        enemy->health += 5*(enemy->stats.hp);
        printf("%s has skipped his turn but healed himself! No damage\n", enemy->name);
    }
}

/* DO COMBAT
This function recieves:
    - The character (by reference)
    - An array of enemies of size n 
It does:
    - The fight
Returns:
    - Nothing
*/
void do_combat(Character *character, Enemy *enemies, int number_of_enemies) {
    printf("You've started a combat with:\n ");
    for (int i=0; i<number_of_enemies; ++i) {
        printf("%s ", enemies[i].name);
    }

    /* We generate a random value from 10 to 20, that will be the number of turns for each fighter */
    srand(time(NULL));
    int n = rand() % 11 + 10;

    /* We initialise the queue */
    Queue *turn_queue = create_queue(n*(number_of_enemies+1));

    srand(time(NULL));
    /*The enemies will have the indexes 0 to number_of_enemies-1 so we can acces their array, the goodie will be that value, so it is fixed*/
    int first_turn = rand() % (number_of_enemies+1);

    for (int i=0; i<((number_of_enemies+1)*n); ++i) {
        enqueue(turn_queue, i%(number_of_enemies+1));
    }
    
    /* We initialise the stack of size n turns */
    Stack *attack_stack = create_stack(n);
    
    /* We initialise a flag to limit Time Strike to 1 use per fight */
    bool time_strike_done = false;

    /* Here we set a dead enemy counter, a copy of n to keep track of when the battle ends and a counter for number of attacks done by us */
    int goodie_index = number_of_enemies;
    int dead_enemies = 0;
    int N = n;
    int attacks_done = 0;
    bool first_turn_done = false;
    while (dead_enemies != 0 && !is_empty_queue(turn_queue) && character->health>0) {
        //Here we do the first turn control 
        if (!first_turn_done) {
            if (turn_queue->items[turn_queue->front] == first_turn) {
                if (turn_queue->items[turn_queue->front] == goodie_index) {
                    printf("Your turn to attack! \n");
                    turn_player(character, enemies,  attack_stack, number_of_enemies,attacks_done, time_strike_done);
                    dequeue(turn_queue);
                    ++attacks_done;
                }
                else {
                    printf("%s is now attacking!\n", enemies[turn_queue->items[turn_queue->front]].name);
                    turn_enemy(character, &enemies[turn_queue->front]);
                    dequeue(turn_queue);
                }
                first_turn_done = true;
            }
            else {
                dequeue(turn_queue);
            }
        }
        else {
            if (turn_queue->items[turn_queue->front] == goodie_index) {
                    /*For the player attack we pass the character and the array of enemies so we can choose to whom attack*/
                    turn_player(character, enemies, attack_stack, number_of_enemies, attacks_done, time_strike_done);
                    dequeue(turn_queue);
            }
            else {
                    /*In the enemy attack we pass the enemy in turn and the character*/
                    /*The enemy shoud be a pointer TALK WITH MARCELINO*/
                    turn_enemy(character, &enemies[turn_queue->items[turn_queue->front]]);
                    dequeue(turn_queue);
            }
        }
    }
}
