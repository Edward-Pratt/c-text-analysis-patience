#include "readfile.h"



char **read_words_from_file(char *filename, int *count) {
	/*
	 * Function to read in words from a file
	 *
	 * Parameters
	 * ----------
	 * 
	 * filename : Contains the filepath/name of the file you want to read from
	 *
	 * count : Contains a pointer to a piece of memory that will store the length of the file (number of words) read in
	 *
	 * Returns
	 * -------
	 *
	 *  words : char **words; A pointer to the list of words that have been read in from the file
	 *
	 */

	/* Opens a FILE reader*/
	FILE *file = fopen(filename, "r");
	if (!file) {
		printf("Error Opening File\n");
		return NULL;
	}


	/* Allocates an array with space for 250000 words*/
	char **words = (char **)malloc(250000 * sizeof(char *));
	if (!words) {
		printf("Error Allocating Memory\n");
		fclose(file);
		return NULL;
	}



	char buffer[100];
	int j = 0;

	/* While not at the end of the file reads in words line by line allocating space for each depending on its length*/
	while (fscanf(file, "%s", buffer) == 1){
		words[j] = malloc(strlen(buffer)+1);
		if (!words[j]) {
			printf("Error Allocating Memory\n");
			break;
		}
		strcpy(words[j], buffer); 
		j++; /* Increments the total number of words read in */
	}
	*count = j; /* Updates the total number of words*/

	/* Closes access to file */
	fclose(file);

	return words;
}

