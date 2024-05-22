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
    character->health = 100+(20*(character->stats.hp-1));
    character->bullets = 100+(10*(character->stats.bp-1));

    for (int i = 0; i < number_of_enemies; ++i) {
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
void turn_player(Character *character, Enemy *enemies, Stack* attack_stack, int number_of_enemies, int *attacks_done, int *time_strike_done, int *dead_enemies) {
    const char *options1[] = {"Shoot", "Skill: +DEF", "Skill: +ATK", "Skill: +LUC", "Skill: Time Strike", "Skill: Heal", NULL};
    int atk_type = get_selection(options1);
    int turn_done = 0;
    while (!turn_done){
        switch (atk_type) {
            case 1: {
                // BASE ATTACK: SHOOT
                int enemy_selected = select_enemy(enemies, number_of_enemies);
                int total_damage = (10 * ((character->stats.atk) * (character->active_modifiers.tempatk))) / (enemies[enemy_selected].stats.def);
                enemies[enemy_selected].health -= total_damage;
                printf("You've dealt %d damage to %s\n", total_damage, enemies[enemy_selected].name);
                if (enemies[enemy_selected].health <= 0) {
                    printf("%s has died\n", enemies[enemy_selected].name);
                    (*dead_enemies)++;
                }
                else {
                    printf("%s health: %d\n", enemies[enemy_selected].name, enemies[enemy_selected].health);
                }
                push_stack(attack_stack, total_damage);
                (*attacks_done)++;
                turn_done = 1;
                break;
            }
            case 2: {
                // SKILL 1: AUGMENTING DEF
                character->active_modifiers.tempdef += 1;
                printf("You've added +1 to your defense for the next turn\n");
                turn_done = 1;
                break;
            }
            case 3: {
                // SKILL 2: AUGMENTING ATK
                character->active_modifiers.tempatk += 1;
                printf("You've added +1 to your attack for the next turn\n");
                turn_done = 1;
                break;
            }
            case 4: {
                // SKILL 3: AUGMENTING LUC
                character->active_modifiers.templuc += 1;
                printf("You've added +1 to your luck for the next turn\n");
                turn_done = 1;
                break;
            }
            case 5: {
                // SKILL 4: TIME STRIKE
                if (!is_empty_stack(attack_stack) && !time_strike_done) {
                    // Seed the random number generator (optional)
                    srand(time(NULL));

                    // Generate a random number between 0 and n-1
                    int random_number = rand() % (*attacks_done) + 1;
                    // Initialise past_damage variable to store random attack
                    int past_damage = -1;

                    for (int i = 0; i < random_number; ++i){
                        past_damage = pop_stack(attack_stack);
                    }
                    int total_damage = 2 * past_damage;
                    int enemy_selected = select_enemy(enemies, number_of_enemies);
                    enemies[enemy_selected].health -= total_damage;
                    printf("You've dealt %d damage to %s\n", total_damage, enemies[enemy_selected].name);
                    (*attacks_done)++;
                    free_stack(attack_stack);
                    (*time_strike_done) = 1;
                    turn_done = 1;
                }
                else { 
                    if (time_strike_done) {
                        printf("You've already used Time Strike this fight!\n");
                    }
                    else printf("No past attacks to use Time Strike!\n");
                }
                break;
            }
            case 6: {
                // SKILL 5: HEAL
                int healing = (character->stats.hp + character->stats.luc + character->active_modifiers.templuc);
                character->health += healing;
                printf("You've healed yourself by %d points!\n", healing);
                turn_done = 1;
                break;
            }
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

    /* Seed a random number generator */
    srand(time(NULL));

    /* Generate a random number between 0 and 10 */
    int r = rand() % 10;

    /* There's a 10% chance that the enemy heals, otherwise it attacks normally */
    if (r!=0) {
        int total_damage = (10 * enemy->stats.atk) / (character->stats.def * character->active_modifiers.tempdef);    
        character->health -= total_damage;
        printf("%s has done a base attack and caused %d damage\n", enemy->name, total_damage);
    }
    else {
        enemy->health += 5*(enemy->stats.hp);
        printf("%s has missed but healed himself! No damage\n", enemy->name);
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
void do_combat(Character *character, Enemy *enemies, int number_of_enemies, int *game_over) {
    
    //Initialisation of characters
    init_fight_characters(character, enemies, number_of_enemies); 

    printf("You've started a combat with:\n ");
    for (int i=0; i<number_of_enemies; ++i) {
        printf("%s ", enemies[i].name);
    }

    /* We generate a random value from 10 to 20, that will be the number of turns for each fighter */
    srand(time(NULL));
    int n = rand() % 11 + 10;

    /* We initialise the queue */
    Queue *turn_queue = create_queue(n*(number_of_enemies+1));

    for (int i=0; i<((number_of_enemies+1)*n); ++i) {
        enqueue(turn_queue, i%(number_of_enemies+1));
    }

    /* Dequeue a random number of turns from 1 to number_of_enemies to randomize who starts attacking */
    srand(time(NULL));
    int r = rand() % number_of_enemies + 1;
    for (int i = 0; i < r; ++i){
        dequeue(turn_queue);
    }

    /* We initialise the stack of size n turns */
    Stack *attack_stack = create_stack(n);

    /* We initialise a flag to limit Time Strike to 1 use per fight */
    int time_strike_done = 0;

    /* Here we set the player index for readibility and a counter for number of attacks done by us */
    int player_index = number_of_enemies;
    int dead_enemies = 0;
    int attacks_done = 0;

    /* While loop of fight */
    while (dead_enemies != number_of_enemies && !is_empty_queue(turn_queue) && character->health>0) {
        //Here we do the first turn control 
        int turn = dequeue(turn_queue);
        if (turn == player_index){
            printf("Your turn to attack! \n");
            turn_player(character, enemies, attack_stack, number_of_enemies, &attacks_done, &time_strike_done, &dead_enemies);
        }
        else {
            printf("%s is now attacking!\n", enemies[turn].name);
            turn_enemy(character, &(enemies[turn]));
            printf("%s health: %d\n", character->name, character->health);
        }
    }

    /* Check end of battle result */ 
    if (dead_enemies == number_of_enemies){
        printf("You've killed all enemies!\n");
    }
    else if (is_empty_queue(turn_queue)){
        printf("You ran out of turns and lost!");
        (*game_over) = 1;
    }
    else if (character->health<=0){
        printf("You've died!\n");
    }
}

int main(){
    int game_over = 0;
    Character jose = create_character();
    Enemy paco = {"Paco", 100, {10, 10, 10, 10, 10}};
    Enemy manolo = {"Manolo", 100, {10, 10, 10, 10, 10}};
    Enemy enemies[2];
    int number_of_enemies = 2;
    enemies[0] = paco;
    enemies[1] = manolo;

    do_combat(&jose, enemies, number_of_enemies, &game_over);
}