#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Deal a random hand of cards
#define NUM_SUITS 4						// CLUBS, DIAMONDS, HEARTS, SPADES
#define NUM_RANKS 13					// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A

int main(void) {

	bool in_hand[NUM_SUITS][NUM_RANKS] = { false };
	int num_cards, rank, suit;

	const char rank_code[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
	const char suit_code[] = { 'c', 'd', 'h', 's' };

	srand(time(NULL));						// GET A RANDOM NUMBER

	printf("Enter number of cards in hand: ");
	scanf("%d", &num_cards);

	printf("Your hand:");

	// While loop to print the cards

	while (num_cards > 0) {
		suit = rand() % NUM_SUITS;					// PICKS A RANDOM SUIT (CLUB, HEARTS, ETC...)
		rank = rand() % NUM_RANKS;					// PICKS A RANDOM RANK (1, 5, J, J, ETC...)

		if (!in_hand[suit][rank]) {					// Check for duplicates
			in_hand[suit][rank] = true;
			num_cards--;
			printf(" %c%c", rank_code[rank], suit_code[suit]);
		}

	}
	printf("\n");

	return 0;
}
