#include "anagram.h"
#define MAX_VARIANTS 12

void print_most_variants(AnagramList *list) {
    AnagramList *current = list;
    AnagramList *max = NULL;
    int max_count = 0;

    while (current != NULL) {
        int count = 0;
        Node *word = current->words;

        while (word != NULL) {
            count++;
            word = word->next;
        }

        if (count > max_count) {
            max_count = count;
            max = current;
        }

        current = current->next;
    }

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
    int max_length = 0;
    char *longest1 = NULL, *longest2 = NULL;

    while (list != NULL) {
        Node *word1 = list->words;

        while (word1 != NULL) {
            Node *word2 = word1->next;

            while (word2 != NULL) {
                int length = (int)strlen(word1->word);
                if (length > max_length) {
                    max_length = length;
                    longest1 = word1->word;
                    longest2 = word2->word;
                }
                word2 = word2->next;
            }
            word1 = word1->next;
        }

        list = list->next;
    }
    printf("Longest Anagram Pair: %s, %s (%d letters)\n", longest1, longest2, max_length);
    if (longest1 && longest2) {
        printf("Longest Anagram Pair: %s, %s (%d letters)\n", longest1, longest2, max_length);
    }else {
        printf("No Pairs Found\n");
    }
}

int *generate_histogram_data(AnagramList *list, int max_variants) {
    int *H = (int *)calloc(max_variants + 1, sizeof(int));
    if (H == NULL) {
        printf("Memory allocation failed for histogram data.\n");
        return NULL;
    }

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
    int count;
    char **words = read_words_from_file("words-smaller.txt", &count);
    AnagramList *list = make_anagram_list(words, count);
    print_most_variants(list);
    find_longest_anagram_pair(list);


    printf("Generating histogram data...\n");
    int *variant_counts = generate_histogram_data(list, MAX_VARIANTS);
    for (int i=0; i<= MAX_VARIANTS; i++){
	printf("variant_counts[%d]: %d\n", i, variant_counts[i]);
    }

    double log_values[MAX_VARIANTS+1];
    for (int i = 0; i <= MAX_VARIANTS; i++) {
	if (variant_counts[i] > 0){
        	log_values[i] = log10(variant_counts[i]);
	} else {
	log_values[i] = 0;
	}
    }

    histogram(variant_counts, log_values, MAX_VARIANTS, 50);
    
    
    free_anagram_list(list);

    for(int i=0; i<count; i++){
        free(words[i]);
    }


    free(words);
    free (variant_counts);
}
