#include "anagram.h"
#define MAX_VARIANTS 12


void print_most_variants(AnagramList *list) {
	/*
	 * Searches throught the provided AnagramList (linked list type structure) to find which words have to most variants
	 *
	 * Parameters
	 * ----------
	 *
	 *  list : A previously created anagram list containing keys of sorted words and words
	 *
	 */

	AnagramList *current = list;
	AnagramList *max = NULL;
	int max_count = 0;

	/* While not at the end of the primary linked list */
	while (current != NULL) {

		/* Counts how many words belong to this key/AnagramList */
		int count = 0;
		Node *word = current->words;

		while (word != NULL) {
			count++;
			word = word->next;
		}

		/* If more words belong than previously searched lists sets this to most variants */
		if (count > max_count) {
			max_count = count;
			max = current;
		}

		/* Move to next primary node */
		current = current->next;
	}


	/* If a max variants is found, print out the key and the words belonging to said key */
	if (max != NULL) {
		printf("Anagram Variants of %s:\n", max->key);
		Node *word = max->words;
		while (word != NULL) {
			printf("%s\n", word->word);
			word = word->next;
		}
	} else {
		printf("No anagrams found.\n");
	}
}


void find_longest_anagram_pair(AnagramList *list) {
	/*
	 * For anagrams where there are two corresponding words, finds the longest words stored in the list
	 *
	 * Parameters
	 * ----------
	 * list : A previously created anagram list containing keys of sorted words and words
	 * 
	 */
	int max_length = 0;
	char *longest1 = NULL, *longest2 = NULL;

	/* While not at the end of the primary list*/
	while (list != NULL) {
		int count = 0;
		Node *word1 = list->words;

		while(word1 != NULL){
			count++;
			word1 = word1->next;
		}
		/* Checks that only 2 words belong to each */
		if (count == 2){
			Node *word1 = list->words;
			Node *word2 = word1->next;
			/* If the words are longer than the previously stored then replace them */
			int length = (int)strlen(word1->word);
			if(length > max_length) {
				max_length = length;
				longest1 = word1->word;
				longest2 = word2->word;
			}
		}
		/* Moves to next primary list */
		list = list->next;
	}
	/* If a longest has been found, print them out with length */
	if (longest1 && longest2) {
		printf("Longest Anagram Pair: %s, %s (%d letters)\n", longest1, longest2, max_length);
	}else {
		printf("No Pairs Found\n");
	}
}

int *generate_histogram_data(AnagramList *list, int max_variants) {
	/*
	 * Generates the data to be used in the histogram function from the AnagramList
	 *
	 * Parameters
	 * ----------
	 * list : A previously created anagram list containing keys of sorted words and words
	 * 
	 * max_variants : Defines the length of the outputted array
	 *
	 * Returns
	 * -------
	 *
	 *  H : int *H; Returns the data for how many words are in each variant category
	 *
	 */


	/* Allocates space to store the number of variants with 0's*/
	int *H = (int *)calloc(max_variants + 1, sizeof(int));
	if (H == NULL) {
		printf("Memory allocation failed for histogram data.\n");
		return NULL;
	}

	/* Goes through the anagram lists, calculates the length of the stored words and adds the the right index */
	while (list != NULL) {
		int count = 0;
		Node *word = list->words;

		while (word != NULL) {
			count++;
			word = word->next;
		}

		if (count >= 2) {
			if (count <= max_variants) {
				H[count]++;
			}
		}
		list = list->next;
	}

	return H;
}




int main(int argc, char *argv[]) {

	/*
	 *
	 * Main Function which reads in data from a file, Turns the data into an AnagramList (Linked List Structure), then finds the longest pair, anagram with the most variants and generates a histogram
	 *
	 */

	int count;
	char **words = read_words_from_file("words-smaller.txt", &count);
	AnagramList *list = make_anagram_list(words, count);
	print_most_variants(list);
	find_longest_anagram_pair(list);


	printf("Generating histogram data...\n");
	int *variant_counts = generate_histogram_data(list, MAX_VARIANTS);

	/*
	   for (int i=0; i<= MAX_VARIANTS; i++){
	   printf("variant_counts[%d]: %d\n", i, variant_counts[i]);
	   }
	   */


	/* Logs the values to be printed to the histogram */
	double log_values[MAX_VARIANTS+1];
	for (int i = 0; i <= MAX_VARIANTS; i++) {
		if (variant_counts[i] > 0){
			log_values[i] = log10(variant_counts[i]);
		} else {
			log_values[i] = 0;
		}
	}

	histogram(variant_counts, log_values, MAX_VARIANTS, 50);


	/* Freeing Memory */
	free_anagram_list(list);

	for(int i=0; i<count; i++){
		free(words[i]);
	}


	free(words);
	free (variant_counts);
}
