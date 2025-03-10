#include "anaquery.h"
#define MAX_INPUT_SIZE 100




void find_anagrams(AnagramList *list, char *word_to_find){

	
	char *sorted_word = sort_string(word_to_find);	
	
	printf("Sorted word is: %s\n", sorted_word);
	AnagramList *current = list;
	while (current != NULL){
		if(strcmp(current->key, sorted_word)==0){
			printf("Anagrams of '%s':\n", word_to_find);
			Node *word_node = current->words;
			while (word_node != NULL){
				printf("%s\n", word_node->word);
				word_node = word_node->next;
			}
			free(sorted_word);
			return;
		}
		current = current->next;
	}
	printf("No anagrams found for word: '%s'\n", word_to_find);
	free(sorted_word);
}


void print_all_keys(AnagramList *list) {
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
	int count;
	char **words = read_words_from_file("words-smaller.txt", &count);
	AnagramList *list = make_anagram_list(words, count);
        /*print_all_keys(list);*/	
	char input[MAX_INPUT_SIZE];
	while(1){
		printf("\nInput word you are looking for (Type 'exit' to stop the program): ");
		scanf("%99s", input);
		if (strcmp(input, "exit")==0){
		    free_anagram_list(list);
		    for(int i = 0; i<count; i++){
			    free(words[i]);
		    }
		    free(words);
		    exit(0);
		}		

		find_anagrams(list, input);
	}
	return 0;
}
