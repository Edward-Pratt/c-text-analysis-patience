#include "patience.h"


#define DECK_SIZE 52
#define MAX_PILES 9

int main(int argc, char **argv){

	/*
	 *
	 * Runs one game of patience printing the progress and final result of the game
	 *
	 * If argument supplied it is used as the seed, otherwise the seed is generated from the time
	 *
	 */

	int deck[52] = {10, 4, 9, 8, 5, 1, 2, 12, 9, 11, 2, 12, 1, 3, 12, 10, 6, 13, 7, 6, 10,
		4, 7, 5, 8, 2, 4, 1, 3, 9, 5, 4, 6, 9, 11, 10, 13, 11, 11, 1, 12, 3, 13,
		2, 5, 13, 7, 3, 7, 6, 8, 8
	};

	gsl_rng *r;

	/* Sets seed depending on arguments */
	int seed;
	if (argc > 1){
		seed = atoi(argv[1]);
	} else {
		seed = time(NULL);
	}


	/* Shuffles the deck */
	r = shuffle(deck, DECK_SIZE, seed);

	/* Runs the game of patience with verbose active */
	int result = play(deck, 1);


	/* Prints the result of the game */
	if (result == 0){
		printf("Player Wins!\n");
	}else{
		printf("Player Loses! %d cards left in deck. \n", result);
	}

	/* Frees memory used in the shuffle function */
	free_shuffle(r);
	return 0;
}


