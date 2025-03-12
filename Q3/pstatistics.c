#include "pstatistics.h"

#define DECK_SIZE 52


int *many_plays(int N){

	/*
	 *
	 * Function that plays N games of patience and tallys the results of how many cards were left in each
	 *
	 * Parameters
	 * ----------
	 *  N : The number of games you want to simulate
	 *
	 * Returns
	 * -------
	 *  remaining : int *remaning; Returns the tally of games ending in a specific number of cards 
	 *
	 */

 	/* Initialises a base deck */
	int deck[DECK_SIZE] = {
		10, 4, 9, 8, 5, 1, 2, 12, 9, 11, 2, 12, 1, 3, 12, 10, 6, 13, 7, 6, 10,
		4, 7, 5, 8, 2, 4, 1, 3, 9, 5, 4, 6, 9, 11, 10, 13, 11, 11, 1, 12, 3, 13,
		2, 5, 13, 7, 3, 7, 6, 8, 8
	};
	int seed;



	static int remaining[DECK_SIZE + 1] = {0};
	int i;
	gsl_rng *r;

	/* Plays N games of patience */
	for (i = 0; i < N; i++){
		/* Seed for each game is set by time and an offset of which game you are on */
		seed = time(NULL)+i;

		/* Deck is shuffled for each game */
		r = shuffle(deck, DECK_SIZE, seed);

		/* Collects the result of the current game iteration and adds to the tally for cards remaining */
		int result = play(deck, 0);	
		remaining[result]++;
	}
	/* Frees memory used by shuffle */
	free_shuffle(r);

	return remaining;
}


int main() {

	/*
	 *
	 * Runs pstatistics simulating 10000 games of patience and printing results as a histogram
	 * 
	 */

	int N = 10000; // Play 10,000 games
	int *results = many_plays(N);

	/*	
	   printf("Cards Left | Games Ended\n");
	   printf("------------------------\n");
	   for (int i = 0; i <= DECK_SIZE; i++) {
	   if (results[i] > 0) {
	   printf("%10d | %d\n", i, results[i]);
	   }
	   }
	*/  
	
	/* Calculates percentages for the histogram function to use */
	double y[DECK_SIZE+1] = {0};
	int i;
	for (i = 0; i <= DECK_SIZE; i++){
		y[i] = (double)results[i] / N*100;

	}
	
	/* Prints a histogram */
	histogram(results, y, DECK_SIZE+1, 50);

	return 0;
}



