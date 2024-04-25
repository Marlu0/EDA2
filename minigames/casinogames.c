#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

        if (balance<200){
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
