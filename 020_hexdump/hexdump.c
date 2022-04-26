#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 16

bool isStartOfLine(size_t bytesRead) {
    return bytesRead % LINE_LENGTH == 0;
}

bool isEndOfLine(size_t bytesRead) {
    return bytesRead % LINE_LENGTH == LINE_LENGTH - 1;
}

char line[] = "00000000  0U UU UU UU UU UU UU UU UU UU UU UU UU UU UU UU";

char digits[] = "0123456789abcdef";

char toASCII(int halfbyte) {
    assert(halfbyte >= 0 && halfbyte <= 15);
    return digits[halfbyte];
}

int main(void) {
    size_t bytesRead = 0;
    char *ptr;
    for (int c; (c = getchar()) != EOF; bytesRead++) {
        if (isStartOfLine(bytesRead)) {
            ptr = line;
            *ptr++ = toASCII((bytesRead >> 28) & 0xF);
            *ptr++ = toASCII((bytesRead >> 24) & 0xF);
            *ptr++ = toASCII((bytesRead >> 20) & 0xF);
            *ptr++ = toASCII((bytesRead >> 16) & 0xF);
            *ptr++ = toASCII((bytesRead >> 12) & 0xF);
            *ptr++ = toASCII((bytesRead >>  8) & 0xF);
            *ptr++ = toASCII((bytesRead >>  4) & 0xF);
            *ptr++ = toASCII((bytesRead >>  0) & 0xF);
            *ptr++ = ' ';
        }
        *ptr++ = ' ';
        *ptr++ = toASCII((c & 0xF0) >> 4);
        *ptr++ = toASCII((c & 0x0F) >> 0);

        if (isEndOfLine(bytesRead))
            puts(line);
    }
    if (bytesRead % 16 != 0) {
        *ptr++ = '\0';
        puts(line);
    }
    ptr = line;
    *ptr++ = toASCII((bytesRead >> 28) & 0xF);
    *ptr++ = toASCII((bytesRead >> 24) & 0xF);
    *ptr++ = toASCII((bytesRead >> 20) & 0xF);
    *ptr++ = toASCII((bytesRead >> 16) & 0xF);
    *ptr++ = toASCII((bytesRead >> 12) & 0xF);
    *ptr++ = toASCII((bytesRead >>  8) & 0xF);
    *ptr++ = toASCII((bytesRead >>  4) & 0xF);
    *ptr++ = toASCII((bytesRead >>  0) & 0xF);
    *ptr++ = '\0';
    puts(line);
}
