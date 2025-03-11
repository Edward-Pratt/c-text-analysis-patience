#include "patience.h"


#define DECK_SIZE 52
#define MAX_PILES 9


int add_to_11(int visible[], int size, int *x, int *y){
	int i, j;
	for (i = 0; i < size; i++){
		for(j = i + 1; j < size; j++){
			if (visible[i] + visible[j] == 11){
				*x = i;
				*y = j;
				return 1;
			}
		}
	}
	return 0;
}


int jqk(int visible[], int size){
	int hasJ = 0, hasQ = 0, hasK = 0;
	int i;
	for (i = 0; i < size; i++) {
		if (visible[i] == 11){
		       	hasJ = 1;
		}
	       	if (visible[i] == 12){ 
			hasQ = 1;
		}
		if (visible[i] == 13){ 
			hasK = 1;
		}
	}
	return (hasJ && hasQ && hasK);
}


int play(int deck[], int verbose){
	int visible[MAX_PILES] = {0};
	int deck_index = 0, num_piles = 0;

	while (deck_index < DECK_SIZE){
		if (num_piles >= MAX_PILES){ 
			return DECK_SIZE - deck_index; /* Happens on Loss */
		}
		visible[num_piles++] = deck[deck_index++]; /* Adds a new pile */

		if (verbose){
			int i;
			for (i=0; i < num_piles; i++){
				printf("%d ", visible[i]);
			}
			printf("\n");
		}

		int x, y;
		while(add_to_11(visible, num_piles, &x, &y) || jqk(visible, num_piles)){
			if (add_to_11(visible, num_piles, &x, &y)){
				visible[x] = deck_index < DECK_SIZE ? deck[deck_index++] : 0;
				visible[y] = deck_index < DECK_SIZE ? deck[deck_index++] : 0;
			}
			if(jqk(visible, num_piles)){
				int i;
				for(i = 0; i < num_piles; i++){
					if(visible[i] == 11 || visible[i] == 12 || visible[i] == 13){
						visible[i] = deck_index < DECK_SIZE ? deck[deck_index++] : 0;
					}
				}
			}
		}
	}
	return 0; /* On Win */
}


int *shuffle_deck(int deck[]){
	gsl_rng *r;
	int seed = -1;
	r = shuffle(deck, 52, seed);
	return deck;
}


			
