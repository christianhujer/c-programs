#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    size_t size = 0;
    for (int i = 1; i < argc; i++) {
        if (i > 1)
            size += 1;
        size += strlen(argv[i]);
    }
    size += 2; // '\n' '\0'

    char *buffer = malloc(size);
    if (buffer == NULL)
        abort();
    memset(buffer, 0, size);
    for (int i = 1; i < argc; i++) {
        if (i > 1)
            strncat(buffer, " ", size);
        strncat(buffer, argv[i], size);
    }
    strncat(buffer, "\n", size);
    fputs(buffer, stdout);
    fflush(stdout);
    free(buffer);

    return EXIT_SUCCESS;
}
