#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECKSIZE 52
#define NUMRANKS 13
#define NUMSUITS 4

int play_blackjack(int balance);
void initialize_deck(Card deck[]);
void shuffle_deck(Card deck[]);
void deal_card(Card deck[], Player *player);
int calculate_hand_value(Card hand[], int hand_size);
void display_game_state(Player *player, Player *dealer, int show_dealer_hand);
void play_game(Player *player, Player *dealer);

typedef struct{
    int rank, suit;
}Card;

typedef struct{
    int balance, handsize;
    Card hand[2];
}Player;

/*
Initialize deck of cards
Shuffle deck

Initialize players (including dealer)
Deal initial two cards to each player

For each player:
    If player has a blackjack:
        Payout at 3:2 odds unless dealer also has blackjack (push)
    Else:
        While player wants to continue playing:
            Display player's hand and dealer's visible card
            Prompt player to choose action (hit, stand, double down, split)
            If player chooses to hit:
                Deal one additional card to player
                If player busts (hand total > 21):
                    Player loses bet
                    Break out of loop
            If player chooses to stand:
                Break out of loop
            If player chooses to double down:
                Double player's bet
                Deal one additional card to player
                Break out of loop
            If player chooses to split:
                Split cards into two separate hands
                Deal one additional card to each hand
                Set up separate bets for each hand
                Repeat gameplay loop for each hand

Once all players have completed their turns:
    Reveal dealer's face-down card
    While dealer's hand total is 16 or less (or soft 17, depending on rules):
        Dealer hits and draws additional cards
    If dealer busts:
        All remaining players win
    Else:
        For each player:
            Compare player's hand to dealer's hand
            If player's hand total is higher than dealer's:
                Player wins even money (1:1) on their bet
            If player's hand total is lower than dealer's:
                Player loses their bet
            If player's hand total is the same as dealer's:
                It's a push, player's bet is returned
*/