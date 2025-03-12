#include "patience_game.h"


#define DECK_SIZE 52
#define MAX_PILES 9


int add_to_11(int visible[], int size, int *x, int *y){

	/*
	 *
	 * Function that checks if any combination of 2 visible cards add to 11
	 *
	 * Parameters
	 * ----------
	 *  visible : The list of cards that are visible
	 *  
	 *  size : The size of the list of visible cards
	 *
	 *  x : Reference to memory storing location of one of the visible cards that add to 11
	 *
	 *  y : Reference to memory of storing the other location of visible cards that adds to 11
	 *
	 * 
	 * Returns
	 * -------
	 *
	 *  int : Returns 1 if two of the cards add to 11
	 *  	  Returns 0 if two of the cards do not add to 11
	 *
	 */
	int i, j;

	/* Searches through every combination of 2 cards that are visible */
	for (i = 0; i < size; i++){
		for(j = i + 1; j < size; j++){
			/* If the two cards add to 11 then set the positions of them and return 1 */
			if (visible[i] + visible[j] == 11){
				*x = i;
				*y = j;
				return 1;
			}
		}
	}
	/* Retuns 0 if no cards add to 11 */
	return 0;
}


int jqk(int visible[], int size){

	/*
	 *
	 * Function that checks if Jack, Queen and King are in visible cards
	 *
	 * Parameters
	 * ----------
	 *  visible : The cards that are currently visible
	 *
	 *  size : The size of the visible cards
	 *
	 *
	 * Returns
	 * -------
	 *
	 *  int : 1 if J, Q and K are visible
	 *  	  Otherwise return 0
	 *
	 *
	 */

	/* Initialises flag for each card type to 0 */
	int hasJ = 0, hasQ = 0, hasK = 0;
	int i;

	/* Loops through all the visible cards */
	for (i = 0; i < size; i++) {

		/* If one of the cards is a Jack, Queen or King set the corresponding flag to 1 */
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
	/* Returns 1 if all three flags are 1 */
	return (hasJ && hasQ && hasK);
}


int play(int deck[], int verbose){

	/*
	 *
	 * Function that simulated one round of the patience card game
	 *
	 * Parameters
	 * ----------
	 *  
	 *  deck : The shuffled deck that the game should be played with
	 *
	 *  verbose : An int that decides if the output of the game should be printed
	 *
	 * Returns
	 * -------
	 *  int : 0 is returned if the game is won
	 *  	  The number of cards remaining in the deck is returned if the player wins
	 *
	 */

	/* Initialises values in visible to 0 */
	int visible[MAX_PILES] = {0};

	/* deck_index = Current card in the deck to draw, num_piles = Number of visible piles, cards_covered = Flag for if cards have been covered this round */
	int deck_index = 0, num_piles = 0, cards_covered=0;


	/* While the end of the deck has not been reached (Player wins) run rounds of patience */
	while (deck_index < DECK_SIZE){

		/* If no cards have been covered this round add a new pile */
		if(!cards_covered){
			/* Sets the new pile to have the next value in the deck and increments which pile is next and the next card in the deck */
			visible[num_piles++] = deck[deck_index++]; /* Adds a new pile */
		}
		/* Resets flag on each round */
		cards_covered=0;

		/* If verbose is 1 then print the output of the round */
		if (verbose){
			int i;
			for (i=0; i < num_piles; i++){
				printf("%2d ", visible[i]);
			}
			printf("\n");
		}

		/* Covering cards if J Q and K are visible */
		if(jqk(visible, num_piles)){
			int foundJ = -1, foundQ = -1, foundK = -1;
			int i;
			/* Searches through visible cards and finds the first occurence of the Jack, Queen, and King */
			for(i = 0; i < num_piles; i++){
				if(visible[i] == 11 && foundJ == -1){
					foundJ = i;
				} else if(visible[i] == 12 && foundQ == -1){
					foundQ = i;
				} else if(visible[i] == 13 && foundK == -1){
					foundK = i;
				}
			}

			/* If an occurence of J, Q and K is found then replace them with new cards */
			if (foundJ != -1 && foundQ != -1 && foundK != -1){
				if (deck_index < DECK_SIZE){
					visible[foundJ] = deck[deck_index++];
				} else visible[foundJ] = 0;

				if (deck_index < DECK_SIZE){
					visible[foundQ] = deck[deck_index++];
				} else visible[foundQ] = 0;

				if (deck_index < DECK_SIZE){ 
					visible[foundK] = deck[deck_index++];
				} else visible[foundK] = 0;

				/* Sets the flag that cards have been covered to true for this round */
				cards_covered = 1;

				/* Go to the next round */
				continue;
			}		
		}

		int x, y;

		/* If two cards add to 11 then replace the two cards with the next in the deck */
		if(add_to_11(visible, num_piles, &x, &y)){

			/* Ternary operator to replace cards if there are cards left in the deck */
			visible[x] = deck_index < DECK_SIZE ? deck[deck_index++] : 0;
			visible[y] = deck_index < DECK_SIZE ? deck[deck_index++] : 0;

			/* Sets the card_covered flag for this round */
			cards_covered = 1;

			/* Go to the next round */
			continue;
		}

		/* If you have reached the max number of piles then return a loss */
		if (num_piles >= MAX_PILES){ 
			return DECK_SIZE - deck_index; /* Happens on Loss */
		}
	}
	return 0; /* On Win */
}

