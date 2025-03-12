#include "histogram.h"




void histogram(int *x, double *y, int n, int width) {
	/* 
	 * Prints a histogram made of stars
	 *
	 * Parameters 
	 * ----------
	 *
	 *  x : List of Numbers
	 *
	 *  y : Percentages corresponding to numbers by index
	 *
	 *  max_length : The length of the arrays given in x and y
	 *
	 *  width : Controls width in characters of the longest bar of stars
	 *
	 * */

	if (n == 0) return; /* Prevent undefined behavior */

	/* Find the maximum percentage value in y[] */
	double max = y[0];
	for (int i = 0; i < n; i++) {
		if (y[i] > max) {
			max = y[i];
		}
	}

	if (max == 0) max = 1; /* Prevent division by zero */

	/* Print histogram from length 1 to max_length (ensuring no gaps) */
	for (int i = 0; i < n; i++) {
		double scaled_value = (y[i] * width) / max;
		int num_of_stars = (int)round(scaled_value);

		printf("%2d: ", i);
		for (int j = 0; j < num_of_stars; j++) {
			printf("*");
		}
		printf(" %6.2f\n", y[i]); /* Print percentage value */
	}
}

int *histogram_lengths(char **strings, int n) {
	/*
	 * Searches through a list of strings and compiles them into an array with the values being the number of occurences of string of length of the index
	 *
	 * Parameters
	 * ----------
	 * 
	 * strings : An array of strings to be searched through for length
	 *
	 * n : The length of the array of strings
	 *
	 * Returns
	 * -------
	 * 
	 * H : int *H : Returns a pointer to the array containing the array connecting lengths and number of strings
	 * 
	 */



	int max_length = 0;
	int i;

	/* Loops through the array and finds the longest word */
	for (i=0; i<n; i++) {
		int length = strlen(strings[i]);
		if (length > max_length) {
			max_length = length;
		}
	}


	/* Allocates memory space with 0's to store up to the length of the maximum length word */
	int *H = (int *)calloc(max_length+1, sizeof(int));
	if (H == NULL) {
		return NULL;
	}

	/* Goes through each word in strings, gets its length and adds it to the array */
	for (i=0; i<n; i++) {
		int len = strlen(strings[i]);
		H[len]++;
	}

	return H;
}
