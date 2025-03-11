#include "patience_game.h"


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
	int deck_index = 0, num_piles = 0, cards_covered=0;

	while (deck_index < DECK_SIZE){
		if(!cards_covered){
			visible[num_piles++] = deck[deck_index++]; /* Adds a new pile */
		}
		cards_covered=0;
		if (verbose){
			int i;
			for (i=0; i < num_piles; i++){
				printf("%2d ", visible[i]);
			}
			printf("\n");
		}

		if(jqk(visible, num_piles)){
			int foundJ = -1, foundQ = -1, foundK = -1;
			int i;
			for(i = 0; i < num_piles; i++){
				if(visible[i] == 11 && foundJ == -1){
					foundJ = i;
				} else if(visible[i] == 12 && foundQ == -1){
					foundQ = i;
				} else if(visible[i] == 13 && foundK == -1){
					foundK = i;
				}
			}
			if (foundJ != -1 && foundQ != -1 && foundK != -1){
				if (deck_index < DECK_SIZE){
				       	visible[foundJ] = deck[deck_index++];
				} else visible[foundJ] = 0;

			        if (deck_index < DECK_SIZE){
				       	visible[foundQ] = deck[deck_index++];
				} else visible[foundQ] = 0;

			        if (deck_index < DECK_SIZE){ visible[foundK] = deck[deck_index++];
				} else visible[foundK] = 0;

			
				cards_covered = 1;
				continue;
				}		
		}
		
		int x, y;
		if(add_to_11(visible, num_piles, &x, &y)){
			visible[x] = deck_index < DECK_SIZE ? deck[deck_index++] : 0;
			visible[y] = deck_index < DECK_SIZE ? deck[deck_index++] : 0;
			cards_covered = 1;
			continue;
			}


		if (num_piles >= MAX_PILES){ 
			return DECK_SIZE - deck_index; /* Happens on Loss */
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


			
