#include "blackjack.h"

int main() {
    int choice;

    do {
        // Print menu options
        printf("Menu:\n");
        printf("1. Play!\n");
        printf("2. Exit table\n");
        printf("Enter your choice: ");

        // Take user input for choice
        scanf("%d", &choice);

        // Check the choice and perform corresponding action
        switch(choice) {
            case 1:
                printf("Playing!\n");
                Player player = {0};
                Player dealer = {0};
                Card deck[DECKSIZE];

                initialize_deck(deck);
                shuffle_deck(deck);
                printf("Shuffled deck:\n");
                for (int i = 0; i < DECKSIZE; i++) {
                    printf("Card %d: Rank = %d, Suit = %d\n", i + 1, deck[i].rank, deck[i].suit);
                }
                // Start the game
                play_game(&player, &dealer);

                break;
            case 2:
                printf("Exiting table. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 2); // Continue looping until user chooses to exit (option 2)

    return 0;
}

void initialize_deck(Card deck[]){
    int index = 0;
    // Loop through each suit
    for (int i = 0; i < NUMSUITS; i++) {
        // Loop through each rank
        for (int j = 0; j < NUMRANKS; j++) {
            deck[index].rank = j + 1;  // Rank ranges from 1 to 13
            deck[index].suit = i;       // Suit ranges from 0 to 3
            index++;
        }
    }
}

void shuffle_deck(Card deck[]){
    srand(time(NULL)); // Seed the random number generator

    // Perform Fisher-Yates shuffle algorithm
    for (int i = DECKSIZE - 1; i > 0; i--) {
        // Generate a random index between 0 and i (inclusive)
        int j = rand() % (i + 1);

        // Swap the card at index i with the card at index j
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_card(Card deck[], Player *player);
int calculate_hand_value(Card hand[], int hand_size);
void display_game_state(Player *player, Player *dealer, int show_dealer_hand);
void play_game(Player *player, Player *dealer);