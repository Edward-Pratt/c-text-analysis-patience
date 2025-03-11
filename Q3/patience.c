#include "patience.h"


#define DECK_SIZE 52
#define MAX_PILES 9

int main(){
	int deck[DECK_SIZE] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13};
	

	int *shuffled_deck = shuffle_deck(deck);

	int result = play(shuffled_deck, 1);

	if (result == 0){
		printf("Player Wins!\n");
	}else{
		printf("Player Loses! %d cards left in deck. \n", result);
	}
}


