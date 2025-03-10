#include "anagram_linked_list.h"


Node *create_node(char *word){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        return NULL;
    }
    new_node->word = (char *)malloc(strlen(word)+1);
    if (!new_node->word) {
        free(new_node);
        return NULL;
    }

    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
};



AnagramList *make_anagram_list(char **words, int n){
     AnagramList *list = NULL;
     int i;
     for (i=1; i<n; i++) {
         insert_word(&list, words[i]);

         if (i % 1000 == 0) {
             printf("Processing word %d of %d...\n", i, n);
         }
     }
     return list;
};


void insert_word(AnagramList **list, char *word) {
    char *key = sort_string(word);

    AnagramList *current = *list;
    AnagramList *prev = NULL;

    // Traverse the list to find the correct position
    int cmp = 0;
    while (current != NULL && (cmp = strcmp(current->key, key)) < 0) {
        prev = current;
        current = current->next;
    }
    if (current != NULL && cmp == 0) {
        Node *new_node = create_node(word);
        new_node->next = current->words;
        current->words = new_node;
	free(key);

    } else {
        AnagramList *new_anagram_list = (AnagramList *)malloc(sizeof(AnagramList));
        if (!new_anagram_list) {
	    
            return;
        }
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
    char *sorted = (char *)malloc(strlen(word)+1);
    if (!sorted) {
        return NULL;
    }


    for (int i = 0; word[i]; i++) {
        sorted[i] = tolower(word[i]);
    }
    sorted[strlen(word)] = '\0';

    qsort(sorted, strlen(sorted), sizeof(char), compare_strings);

    return sorted;

};

int compare_strings(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}







void free_anagram_list(AnagramList *list){        
    while(list != NULL){
    	AnagramList *next_list = list->next;
	
	free(list->key);

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

