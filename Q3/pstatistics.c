#include "pstatistics.h"

#define DECK_SIZE 52


int *many_plays(int N){
	static int remaining[DECK_SIZE + 1] = {0};
	

	int i;
	for (i = 0; i < N; i++){
		int deck[DECK_SIZE] = {
            10, 4, 9, 8, 5, 1, 2, 12, 9, 11, 2, 12, 1, 3, 12, 10, 6, 13, 7, 6, 10,
            4, 7, 5, 8, 2, 4, 1, 3, 9, 5, 4, 6, 9, 11, 10, 13, 11, 11, 1, 12, 3, 13,
            2, 5, 13, 7, 3, 7, 6, 8, 8
        	};
	int seed = time(NULL) + i;
	shuffle_deck(deck, seed);
		
	int result = play(deck, 0);
	
	remaining[result]++;
	}

	return remaining;
}


int main() {
    int N = 100000; // Play 10,000 games
    int *results = many_plays(N);

    // Print statistics
    printf("Cards Left | Games Ended\n");
    printf("------------------------\n");
    for (int i = 0; i <= DECK_SIZE; i++) {
        if (results[i] > 0) {
            printf("%10d | %d\n", i, results[i]);
        }
    }

    return 0;
}



