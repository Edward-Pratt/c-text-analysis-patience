#ifndef ANAGRAM_LINKED_LIST_H
#define ANAGRAM_LINKED_LIST_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct Node{
    char *word;
    struct Node *next;
} Node;


typedef struct AnagramList{
    char *key;
    Node *words;
    struct AnagramList *next;
} AnagramList;


Node *create_node(char *word);



AnagramList *make_anagram_list(char **words, int n);


void insert_word(AnagramList **list, char *word);


char *sort_string(char *word);

int compare_strings(const void *a, const void *b);

void free_anagram_list(AnagramList *list);

#endif //ANAGRAM_LINKED_LIST_H
