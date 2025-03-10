#include "wordlengths.h"



int main(int argc, char *argv[]) {
    int count = 0;
    char **words = read_words_from_file(argv[1], &count);

    int *length_counts = histogram_lengths(words, count);

    int lengths[25];
    double percentages[25];
    int n = 0;
    int i;

    int max_word_length = 0;
    for(i=0; i<count; i++) {
        if (strlen(words[i]) > max_word_length) {
            max_word_length = strlen(words[i]);
        }
    }

    for (i=0; i<max_word_length+1; i++) {
        if (length_counts[i] > 0) {
            lengths[n] = i;
            percentages[n] = (length_counts[i] * 100.0) / count;
            n++;
        }
    }

    histogram(lengths, percentages, n, 30);


    for (i = 0; i < count; i++) {
        free(words[i]);
    }

    free(words);
    free(length_counts);

    return 0;

}
