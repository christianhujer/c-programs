#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 16

bool isStartOfLine(size_t offset) {
    return offset % LINE_LENGTH == 0;
}

bool isEndOfLine(size_t offset) {
    return offset % LINE_LENGTH == LINE_LENGTH - 1;
}

int main(void) {
    size_t offset = 0;
    for (int c; (c = getchar()) != EOF; offset++) {
        if (isStartOfLine(offset))
            printf("%08zx ", offset);
        printf(" %02hhx", (unsigned char) c);
        if (isEndOfLine(offset))
            printf("\n");
    }
    if (offset % 16 != 0)
        printf("\n");
    printf("%08zx\n", offset);
}
