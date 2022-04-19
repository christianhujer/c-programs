#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (i > 1)
            fputs(" ", stdout);
        fputs(argv[i], stdout);
    }
    fputs("\n", stdout);
    return EXIT_SUCCESS;
}
