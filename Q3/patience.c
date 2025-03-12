#include "patience.h"


#define DECK_SIZE 52
#define MAX_PILES 9

int main(int argc, char **argv){
/*	int deck[DECK_SIZE] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13};
*/

	int deck[52] = {10, 4, 9, 8, 5, 1, 2, 12, 9, 11, 2, 12, 1, 3, 12, 10, 6, 13, 7, 6, 10,
	4, 7, 5, 8, 2, 4, 1, 3, 9, 5, 4, 6, 9, 11, 10, 13, 11, 11, 1, 12, 3, 13,
	2, 5, 13, 7, 3, 7, 6, 8, 8
	};

	gsl_rng *r;


	int seed;
	if (argc > 1){
		seed = atoi(argv[1]);
	} else {
		seed = time(NULL);
	}

	r = shuffle(deck, DECK_SIZE, seed);


	int result = play(deck, 1);

	if (result == 0){
		printf("Player Wins!\n");
	}else{
		printf("Player Loses! %d cards left in deck. \n", result);
	}
	free_shuffle(r);
	return 0;
}


