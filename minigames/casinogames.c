#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*----------
|   DICE   |
----------*/

int roll_dice() {
    return rand() % 6 + 1; // Returns a random number between 1 and 6
}

int play_dice() {
    int previousRoll, currentRoll;
    char guess;

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Dice Game!\n\n");
    printf("Guess whether the next roll will be higher (H) or lower (L) than the previous roll.\n");

    previousRoll = roll_dice();
    printf("The previous roll was: %d\n", previousRoll);

    printf("Enter your guess (H/L): ");
    scanf(" %c", &guess);

    currentRoll = roll_dice();
    printf("The current roll is: %d\n", currentRoll);

    if ((guess == 'H' && currentRoll > previousRoll) || (guess == 'L' && currentRoll < previousRoll)) {
        printf("Congratulations! You won!\n");
    } else {
        printf("You lost :)\n");
    }

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

int play_slotmachine() {
    char symbol1, symbol2, symbol3;
    int balance = 100; // Initial balance
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
