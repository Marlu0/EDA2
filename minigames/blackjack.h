#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECKSIZE 52
#define NUMRANKS 13
#define NUMSUITS 4

typedef struct{
    int rank, suit;
}Card;

typedef struct{
    int balance, handsize;
    Card hand[10];
}Player;

void initialize_deck(Card deck[]);

void shuffle_deck(Card deck[]);

void deal_card(Card deck[], Player *player);

int calculate_hand_value(Card hand[], int hand_size);

void display_game_state(Player *player, Player *dealer, int show_dealer_hand);

void play_game(Player *player, Player *dealer);

#endif