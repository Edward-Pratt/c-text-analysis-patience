#include "wordlengths.h"



int main(int argc, char *argv[]) {
	/*
	 *
	 * Main function which takes in argument of the filename you want to read calculates the wordlengths and prints a histogram
	 *
	 */

	/* Initialises a count to store number of words and reads in the words from the file give */
	int count = 0;
	char **words = read_words_from_file(argv[1], &count);


	/* Uses histogram_lengths to calculate the occurences of certain length strings */
	int *length_counts = histogram_lengths(words, count);

	int lengths[25];
	double percentages[25];
	int n = 0;
	int i;

	/* Finds the length of the longest word */
	int max_word_length = 0;
	for(i=0; i<count; i++) {
		if (strlen(words[i]) > max_word_length) {
			max_word_length = strlen(words[i]);
		}
	}

	/* Calculates the percentages corresponding to each word length */
	for (i=0; i<max_word_length+1; i++) {
		if (length_counts[i] > 0) {
			lengths[n] = i;
			percentages[n] = (length_counts[i] * 100.0) / count;
			n++;
		}
	}


	/* Generates the histogram */
	histogram(lengths, percentages, n, 30);

	/* Frees memory */
	for (i = 0; i < count; i++) {
		free(words[i]);
	}

	free(words);
	free(length_counts);

	return 0;

}
