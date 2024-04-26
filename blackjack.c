#include "blackjack.h"

int play_blackjack(int balance) {
    int choice;

    do {
        // Print menu options
        printf("Welcome to the BlackJack table!\n");
        printf("1. Play!\n");
        printf("2. Exit table\n");
        printf("Enter your choice: ");

        // Take user input for choice
        scanf("%d", &choice);

        // Check the choice and perform corresponding action
        switch(choice) {
            case 1:
                if (balance>0){
                    printf("Playing!\n");
                Player player = {balance};
                Player dealer = {0};
                Card deck[DECKSIZE];

                initialize_deck(deck);
                shuffle_deck(deck);
                printf("Deck shuffled:\n");
                
                // Start the game
                play_game(&player, &dealer);
                }
                else printf("Insufficient balance!");
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

void deal_card(Card deck[], Player *player){
    // Check if player's hand is full
    if (player->handsize >= 10) {
        printf("Cannot deal card. Hand is full.\n");
        return;
    }

    // Deal a card from the deck to the player's hand
    player->hand[player->handsize] = deck[0]; // Deal the top card from the deck
    player->handsize++; // Increment the hand size

    // Shift the remaining cards in the deck to remove the dealt card
    for (int i = 0; i < DECKSIZE - 1; i++) {
        deck[i] = deck[i + 1];
    }

    // Clear the last card in the deck
    deck[DECKSIZE - 1].rank = 0;
    deck[DECKSIZE - 1].suit = 0;

    printf("Card dealt.\n");
}

int calculate_hand_value(Card hand[], int hand_size);
void display_game_state(Player *player, Player *dealer, int show_dealer_hand);
void play_game(Player *player, Player *dealer);