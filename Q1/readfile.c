#include "readfile.h"



char **read_words_from_file(char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error Opening File\n");
        return NULL;
    }

    char **words = (char **)malloc(250000 * sizeof(char *));
    if (!words) {
        printf("Error Allocating Memory\n");
        fclose(file);
        return NULL;
    }

    char buffer[100];
    int j = 0;
    while (fscanf(file, "%s", buffer) == 1){
        words[j] = malloc(strlen(buffer)+1);
        if (!words[j]) {
            printf("Error Allocating Memory\n");
            break;
        }
        strcpy(words[j], buffer);
        j++;
    }
    *count = j;

    fclose(file);

    return words;
}

