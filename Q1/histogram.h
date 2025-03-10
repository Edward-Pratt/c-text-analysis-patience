
#ifndef __HISTOGRAM_H
#define __HISTOGRAM_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void histogram(int *x, double *y, int n, int width);


int *histogram_lengths(char **strings, int n);

#endif
