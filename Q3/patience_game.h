#ifndef PATIENCE_GAME_H
#define PATIENCE_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include "../shuffle/shuffle.h"
#include <gsl/gsl_rng.h>


int add_to_11(int visible[], int size, int* x, int *y);

int jqk(int visible[], int size);

int play(int deck[], int verbose);


#endif
