#include "pstatistics.h"

#define DECK_SIZE 52
int deck[DECK_SIZE] = {
            10, 4, 9, 8, 5, 1, 2, 12, 9, 11, 2, 12, 1, 3, 12, 10, 6, 13, 7, 6, 10,
            4, 7, 5, 8, 2, 4, 1, 3, 9, 5, 4, 6, 9, 11, 10, 13, 11, 11, 1, 12, 3, 13,
            2, 5, 13, 7, 3, 7, 6, 8, 8
        };
int seed;
	

int *many_plays(int N){
	static int remaining[DECK_SIZE + 1] = {0};
	int i;
	gsl_rng *r;
	for (i = 0; i < N; i++){
		seed = time(NULL)+i;
		r = shuffle(deck, DECK_SIZE, seed);
		int result = play(deck, 0);	
		remaining[result]++;
	}
	free_shuffle(r);
	return remaining;
}


int main() {
    int N = 10000; // Play 10,000 games
    int *results = many_plays(N);

    /* Print statistics
    printf("Cards Left | Games Ended\n");
    printf("------------------------\n");
    for (int i = 0; i <= DECK_SIZE; i++) {
        if (results[i] > 0) {
            printf("%10d | %d\n", i, results[i]);
        }
    }
    */

    double y[DECK_SIZE+1] = {0};
    int i;
    for (i = 0; i <= DECK_SIZE; i++){
	    y[i] = (double)results[i] / N*100;

    }
    histogram(results, y, DECK_SIZE, 50);

    return 0;
}



