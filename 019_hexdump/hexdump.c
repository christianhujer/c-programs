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

char line[] = "UUUUUUUU  UU UU UU UU UU UU UU UU UU UU UU UU UU UU UU UU";

char digits[] = "0123456789abcdef";

char toASCII(int halfbyte) {
    assert(halfbyte >= 0 && halfbyte <= 15);
    return digits[halfbyte];
}
// toASCII(0) -> '0'
// toASCII(5) -> '5'
// toASCII(10) -> 'a'
// toASCII(15) -> 'f'
// toASCII(-1) -> assert will abort the program
// toASCII(16) -> assert will abort the program

// ++ and --
// x++ ++x x-- --x
// x++ post-increment
// x-- post-decrement
// ++x pre-increment
// --x pre-decrement

int main(void) {
    size_t bytesRead = 0;
    size_t lineOffset = 0;
    for (int c; (c = getchar()) != EOF; bytesRead++) {
        if (isStartOfLine(bytesRead)) {
            lineOffset = 0;
            line[lineOffset++] = toASCII((bytesRead & 0xF0000000) >> 28);
            line[lineOffset++] = toASCII((bytesRead & 0x0F000000) >> 24);
            line[lineOffset++] = toASCII((bytesRead & 0x00F00000) >> 20);
            line[lineOffset++] = toASCII((bytesRead & 0x000F0000) >> 16);
            line[lineOffset++] = toASCII((bytesRead & 0x0000F000) >> 12);
            line[lineOffset++] = toASCII((bytesRead & 0x00000F00) >>  8);
            line[lineOffset++] = toASCII((bytesRead & 0x000000F0) >>  4);
            line[lineOffset++] = toASCII((bytesRead & 0x0000000F) >>  0);
            line[lineOffset++] = ' ';
        }
        line[lineOffset++] = ' ';
        line[lineOffset++] = toASCII((c & 0xF0) >> 4);
        line[lineOffset++] = toASCII((c & 0x0F) >> 0);

        if (isEndOfLine(bytesRead))
            puts(line);
    }
    if (bytesRead % 16 != 0) {
        line[lineOffset] = '\0';
        puts(line);
    }
    lineOffset = 0;
    line[lineOffset++] = toASCII((bytesRead & 0xF0000000) >> 28);
    line[lineOffset++] = toASCII((bytesRead & 0x0F000000) >> 24);
    line[lineOffset++] = toASCII((bytesRead & 0x00F00000) >> 20);
    line[lineOffset++] = toASCII((bytesRead & 0x000F0000) >> 16);
    line[lineOffset++] = toASCII((bytesRead & 0x0000F000) >> 12);
    line[lineOffset++] = toASCII((bytesRead & 0x00000F00) >>  8);
    line[lineOffset++] = toASCII((bytesRead & 0x000000F0) >>  4);
    line[lineOffset++] = toASCII((bytesRead & 0x0000000F) >>  0);
    line[lineOffset++] = '\0';
    puts(line);
}
