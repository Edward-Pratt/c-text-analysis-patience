#include "histogram.h"




void histogram(int *x, double *y, int max_length, int width) {
    if (max_length == 0) return; // Prevent undefined behavior

    // Find the maximum percentage value in y[]
    double max = y[0];
    for (int i = 1; i <= max_length; i++) {
        if (y[i] > max) {
            max = y[i];
        }
    }

    if (max == 0) max = 1; // Prevent division by zero

    // Print histogram from length 1 to max_length (ensuring no gaps)
    for (int i = 1; i <= max_length; i++) {
        double scaled_value = (y[i] * width) / max;
        int num_of_stars = (int)round(scaled_value);

        printf("%2d: ", i);
        for (int j = 0; j < num_of_stars; j++) {
            printf("*");
        }
        printf(" %6.2f\n", y[i]); // Print percentage value
    }
}

int *histogram_lengths(char **strings, int n) {
    int max_length = 0;
    int i;
    for (i=0; i<n; i++) {
        int length = strlen(strings[i]);
        if (length > max_length) {
            max_length = length;
        }
    }

    int *H = (int *)calloc(max_length+1, sizeof(int));
    if (H == NULL) {
        return NULL;
    }

    for (i=0; i<n; i++) {
        int len = strlen(strings[i]);
        H[len]++;
    }

    return H;
}
