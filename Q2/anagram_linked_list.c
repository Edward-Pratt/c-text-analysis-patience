#include "anagram_linked_list.h"


Node *create_node(char *word){

	/*
	 *
	 * Function to create a new node containing a word
	 *
	 * Parameters
	 * ----------
	 *
	 *  word : The word that you want to store in the node
	 *
	 * Returns
	 * -------
	 *
	 *  new_node : Node *new_node; A pointer to the memory of the newly created node
	 *
	 */

	/* Allocates space in memory to store the Node */
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (!new_node) {
		return NULL;
	}

	/* Allocates space in memory to store the word in the node */
	new_node->word = (char *)malloc(strlen(word)+1);
	if (!new_node->word) {
		free(new_node);
		return NULL;
	}

	/* Copies the given word into the Node's word slot and sets its next node to NULL */
	strcpy(new_node->word, word);
	new_node->next = NULL;

	return new_node;
};



AnagramList *make_anagram_list(char **words, int n){

	/*
	 *
	 * Function that generates the anagram list for future use
	 *
	 *  Parameters
	 *  ----------
	 *
	 *  words : The list of words that will be added to the anagram list
	 *
	 *  n : The length of the list of words to be added to the anagram list
	 *
	 *  Returns
	 *  -------
	 *
	 *  list : Anagramlist *list; A pointer to the created AnagramList
	 *
	 */

	/* Initialises the first node of the anagram list */
	AnagramList *list = NULL;

	/* Inserts each word from the given list into the AnagramList using insert_word */
	int i;
	for (i=1; i<n; i++) {
		insert_word(&list, words[i]);
		/*
		   if (i % 1000 == 0) {
		   printf("Processing word %d of %d...\n", i, n);
		   }
		   */
	}

	return list;
};


void insert_word(AnagramList **list, char *word) {

	/*
	 * 
	 * Function that adds a new word into the AnagramList
	 *
	 * Parameters
	 * ----------
	 *
	 *  list : This contains the AnagramList that you want to insert the word into
	 *
	 *  word : The word that you want to add to the anagram list
	 *
	 *
	 */


	/* Takes the word and sorts its characters into alphabetical order */
	char *key = sort_string(word);

	/* Initialises memory to store the current AnagramList and previous for help when inserting new nodes */
	AnagramList *current = *list;
	AnagramList *prev = NULL;

	/* Traverse the list to find the correct position */
	int cmp = 0;
	/* Runs through the AnagramList nodes until it finds the one containing the key you are inserting or reaches the end */
	while (current != NULL && (cmp = strcmp(current->key, key)) < 0) {
		prev = current;
		current = current->next;

	}

	/* If the key of the selected list is equal to the key you want to insert then add to its wordlist */
	if (current != NULL && cmp == 0) {
		Node *new_node = create_node(word); /* Creates a new node with the word */
		new_node->next = current->words; /* Sets the new nodes next node to the word node already stored by the AnagramList */
		current->words = new_node; /* Sets the current AnagramList node's word to the newly created node */
		free(key);

		/* If the end of the AnagramList has been reached and the key not been found then make a new AnagramList node */
	} else {
		/* Allocates space in memory for the new AnagramList */
		AnagramList *new_anagram_list = (AnagramList *)malloc(sizeof(AnagramList));
		if (!new_anagram_list) {

			return;
		}

		/* Sets the lists key, creates and adds the node for the inserted word and puts onto the chain of AnagramList nodes */
		new_anagram_list->key = key;
		new_anagram_list->words = create_node(word);
		new_anagram_list->next = current;

		if (prev == NULL) {
			*list = new_anagram_list;
		} else {
			prev->next = new_anagram_list;
		}
	}
}


char *sort_string(char *word){

	/*
	 * 
	 * Function that sorts the characters of a word
	 *
	 * Parameters
	 * ----------
	 * 
	 * word : The word that needs to be sorted
	 *
	 * Returns
	 * -------
	 * 
	 * sorted : char *sorted; A pointer to the string that has been sorted
	 * 
	 */

	/* Allocates space for the sorted word */
	char *sorted = (char *)malloc(strlen(word)+1);
	if (!sorted) {
		return NULL;
	}

	/* Sets each character of the word to lowercase */
	for (int i = 0; word[i]; i++) {
		sorted[i] = tolower(word[i]);
	}

	/* Adds the null terminator the string */
	sorted[strlen(word)] = '\0';

	/* Uses qsort to sort the string's characters */
	qsort(sorted, strlen(sorted), sizeof(char), compare_strings);

	return sorted;

};

int compare_strings(const void *a, const void *b) {

	/*
	 * Comparison function used by qsort
	 *
	 * Parameters
	 * ----------
	 * Pointers to the characters being sorted
	 *
	 * Returns
	 * -------
	 * Returns 0 if the characters are equal
	 * Returns negative value if a is less than b
	 * Returns positive value if a is greater than b
	 *
	 */
	return (*(char *)a - *(char *)b);
}







void free_anagram_list(AnagramList *list){

	/*
	 * Function used to free the memory taken up by a AnagramList
	 *
	 * Parameters
	 * ----------
	 * list : The anagram list that you want to free
	 *
	 */

	/* While the AnagramList still has nodes */
	while(list != NULL){
		/* Mark the next list */
		AnagramList *next_list = list->next;

		/* Free the key of the list */
		free(list->key);

		/* Frees the word nodes linked to the anagram list */
		Node *word = list->words;
		while(word != NULL){
			Node *next_word = word->next;
			free(word->word);
			free(word);
			word = next_word;
		}
		free(list);
		list = next_list;
	}
}

