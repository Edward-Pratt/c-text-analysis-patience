#include "anaquery.h"
#define MAX_INPUT_SIZE 100




void find_anagrams(AnagramList *list, char *word_to_find){

	/*
	 * Function to find all the anagrams of the word that you enter
	 *
	 * Parameters
	 * ----------
	 *
	 * list : The AnagramList that you want to search for the word
	 *
	 * word_to_find : The word that you are looking for
	 *
	 */

	/* Sorts the word you are looking for into a key */
	char *sorted_word = sort_string(word_to_find);	


	/* printf("Sorted word is: %s\n", sorted_word); */

	AnagramList *current = list;
	/* Searches through each AnagramList node until it finds the key of the word you are looking for */
	while (current != NULL){
		/* If the key equals the key of your word print the words stored */
		if(strcmp(current->key, sorted_word)==0){
			printf("Anagrams of '%s':\n", word_to_find);
			Node *word_node = current->words;
			while (word_node != NULL){
				printf("%s\n", word_node->word);
				word_node = word_node->next;
			}
			/* Frees memory taken by the sorted_word */
			free(sorted_word);
			return;
		}
		current = current->next;
	}
	/* If anagrams not found print and free sorted_word */
	printf("No anagrams found for word: '%s'\n", word_to_find);
	free(sorted_word);
}


void print_all_keys(AnagramList *list) {

	/*
	 * Helper function for debugging the program, Prints all keys that have been stored
	 * 
	 * Parameters
	 * ----------
	 *
	 *  list : The anagram list you want to print the keys of
	 *
	 */
	printf("\nAll Keys in Anagram List:\n");
	while (list != NULL) {
		printf("Key: %s -> ", list->key);
		Node *word = list->words;
		while (word != NULL) {
			printf("%s ", word->word);
			word = word->next;
		}
		printf("\n");
		list = list->next;
	}
}


int main(){

	/*
	 *
	 * Runs the anaquery program repeatedly asking users for words they want to find
	 *
	 */

	int count;

	/* Reads in the word from a file and constructs an anagram list using them */
	char **words = read_words_from_file("words-smaller.txt", &count);
	AnagramList *list = make_anagram_list(words, count);

	/*print_all_keys(list);*/	
	char input[MAX_INPUT_SIZE];

	/* Continuously asks the user for a word input */
	while(1){
		/* Reads in the word the user has put, if 'exit' frees memory and stops the program, Otherwise searches for anagrams and prints them */
		printf("\nInput word you are looking for (Type 'exit' to stop the program): ");
		scanf("%99s", input);
		if (strcmp(input, "exit")==0){
			/* Freeing Memory */
			free_anagram_list(list);
			for(int i = 0; i<count; i++){
				free(words[i]);
			}
			free(words);
			exit(0);
		}		

		/* Finds the anagrams using the constructed list and your word */
		find_anagrams(list, input);
	}
	return 0;
}
