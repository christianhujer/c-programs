#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%s: error: Expecting one argument (hex color value).\n", argv[0]);
        abort();
    }
    int color = (int) strtol(argv[1], NULL, 16);
    printf("red:   %3d\n", ((color >> 16) & 0xFF));
    printf("green: %3d\n", ((color >>  8) & 0xFF));
    printf("blue:  %3d\n", ((color >>  0) & 0xFF));
    return EXIT_SUCCESS;
}
