#include "game.h"

/*----------
|   DICE   |
----------*/

int roll_dice() {
    return rand() % 6 + 1; // Returns a random number between 1 and 6
}

int play_dice(int balance) {            // If we implement the casino, Character should have Character.balance and func work with pointer
    int previousRoll, currentRoll;
    char guess;
    int bet;

    srand(time(NULL));

    printf("Welcome to the Dice Game!\n\n");
    printf("Guess whether the next roll will be higher (H) or lower (L) than the previous roll.\n");
    printf("Stakes are 1.25 to 1\n");
    printf("Your current balance is $%d\n\n", balance);

    while (balance > 0) {
        printf("Enter your bet (0 to quit): ");
        scanf("%d", &bet);

        if (balance<200) {
            printf("You've played enough dice, haven't you?\nYou better leave the table if you don't want trouble!\n");
            break;
        }

        if (bet == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        if (bet > balance) {
            printf("Insufficient balance. Please enter a smaller bet.\n");
            continue;
        }

        printf("Enter your guess (H/L): ");
        scanf(" %c", &guess);

        previousRoll = roll_dice();
        printf("The previous roll was: %d\n", previousRoll);

        currentRoll = roll_dice();
        printf("The current roll is: %d\n", currentRoll);

        if ((guess == 'H' && currentRoll > previousRoll) || (guess == 'L' && currentRoll < previousRoll)) {
            printf("Congratulations! You won $%d!\n", (int)(bet * 1.5));
            balance += (int)ceil(bet * 2);
        } else {
            printf("You lost $%d :)\n", bet);
            balance -= bet;
        }

        printf("Your current balance is $%d\n\n", balance);
    }

    printf("Game over!\n");

    return 0;
}

/*----------------
|  SLOT MACHINE  |
----------------*/
// Function to generate a random symbol for the slot machine
char getRandomSymbol() {
    char symbols[] = {'$', '#', '@', '&', '*', '%'}; // Array of symbols
    int randomIndex = rand() % 6; // Generate a random index between 0 and 5
    return symbols[randomIndex]; // Return the symbol at the random index
}

int play_slotmachine(int balance) {
    char symbol1, symbol2, symbol3;
    int bet;

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Slot Machine!\n");
    printf("Your initial balance is $%d\n\n", balance);

    while (balance > 0) {
        printf("Enter your bet (0 to quit): ");
        scanf("%d", &bet);

        if (bet == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        if (bet > balance) {
            printf("Insufficient balance. Please enter a smaller bet.\n");
            continue;
        }

        // Spin the slot machine
        symbol1 = getRandomSymbol();
        symbol2 = getRandomSymbol();
        symbol3 = getRandomSymbol();

        printf("Spinning...\n");
        printf("%c %c %c\n", symbol1, symbol2, symbol3);

        // Check for win or loss
        if (symbol1 == symbol2 && symbol2 == symbol3) {
            printf("Congratulations! You win $%d!\n", bet * 10);
            balance += bet * 10;
        } else {
            printf("Sorry, you lose $%d\n", bet);
            balance -= bet;
        }

        printf("Your current balance is $%d\n\n", balance);
    }

    printf("Game over!\n");

    return 0;
}

/*-----------------
|  SHOT ROULETTE  |
-----------------*/

int play_shotroulette(int balance, Character player) {
    int bet;
    int dealer_hp = 100; // Initial dealer HP
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to shot roulette!\n");
    printf("Your initial balance is $%d\n\n", balance);

    while (balance > 0 && dealer_hp > 0 && player.hp > 10) {
        printf("Enter your bet (0 to quit): ");
        scanf("%d", &bet);

        if (bet == 0) {
            printf("Thanks for playing!\n");
            printf("Your hp is now %d\n", player.hp);
            break;
        }

        if (bet > balance) {
            printf("Insufficient balance. Please enter a smaller bet.\n");
            continue;
        }

        // Spin the revolver's cylinder
        printf("Spinning...\n");
        int bulletposition = rand() % 6;
        int bulletshot = rand() % 6;

        printf("Choose who'll take the shot (1 for player, 2 for dealer): ");
        int choice;
        scanf("%d", &choice);

        // Check if player takes the shot
        if (choice == 1) {
            if (bulletshot == bulletposition) {
                printf("You were shot! You lose $%d\n", bet);
                balance -= bet;
                player.hp -= 10;
            } else {
                printf("You dodged the bullet! No change in bet.\n");
            }
        }
        // Check if dealer takes the shot
        else if (choice == 2) {
            if (bulletshot == bulletposition) {
                printf("The dealer was shot! You win $%d\n", bet * 10);
                balance += bet * 10;
                dealer_hp -= 10;
                if (dealer_hp <= 0) {
                    return 1; // Return 1 if dealer reaches 0 HP
                }
            } else {
                printf("The dealer dodged the bullet! No change in bet.\n");
            }
        } else {
            printf("Invalid choice! Please choose 1 for player or 2 for dealer.\n");
            continue;
        }

        printf("Your current balance is $%d\n", balance);
        printf("Your hp is now %d\n", player.hp);
        printf("Dealer's hp is now %d\n\n", dealer_hp);
    }

    if (player.hp <= 10) {
        printf("Your health is too low to continue playing. Game over!\n");
    } else if (dealer_hp <= 0) {
        printf("The dealer has no more HP. You win!\n");
        return 1; // Return 1 if dealer reaches 0 HP. This could let us change storyline and reputation if you kill the dealer
    } else {
        printf("Game over!\n");
    }

    return 0;
}