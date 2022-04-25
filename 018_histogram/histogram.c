#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Create a byte histogram.
// Calculate the frequency of each of the bytes in a file.

int main(void) {
    int histogram[256]; // histogram[0] … histogram[255]

    for (int i = 0; i < 256; i++)
        histogram[i] = 0;

    for (int c; (c = getchar()) != EOF; ) {
        assert(c >= 0 && c < 256);
        histogram[c]++; // histogram[c] += 1; // histogram[c] = histogram[c] + 1;
    }

    for (int i = 0; i < 256; i++)
        if (histogram[i])
            printf("%02x: %d\n", i, histogram[i]);

    return EXIT_SUCCESS;
}
