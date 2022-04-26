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

char line[] = "<tr><td><code>00000000</code></td><td><code>0U UU UU UU UU UU UU UU UU UU UU UU UU UU UU UU</code></td></tr>";

char digits[] = "0123456789abcdef";

char toASCII(int halfbyte) {
    assert(halfbyte >= 0 && halfbyte <= 15);
    return digits[halfbyte];
}

int main(void) {
    size_t bytesRead = 0;
    char *ptr;

    puts("<?xml version=\"1.0\"?>");
    puts("<!DOCTYPE html>");
    puts("<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\">");
    puts("<head>");
    puts("<title>Hex Dump</title>");
    puts("</head>");
    puts("<body>");
    puts("<h1>Hex Dump</h1>");
    puts("<table border=\"border\">");
    puts("<thead>");
    puts("<tr><th scope=\"col\">Offset</th><th scope=\"col\">Data</th></tr>");
    puts("</thead>");
    puts("<tbody>");

    for (int c; (c = getchar()) != EOF; bytesRead++) {
        if (isStartOfLine(bytesRead)) {
            ptr = line;
            *ptr++ = '<'; *ptr++ = 't'; *ptr++ = 'r'; *ptr++ = '>';
            *ptr++ = '<'; *ptr++ = 't'; *ptr++ = 'd'; *ptr++ = '>';
            *ptr++ = '<'; *ptr++ = 'c'; *ptr++ = 'o'; *ptr++ = 'd'; *ptr++ = 'e'; *ptr++ = '>';
            for (int shift = 28; shift >= 0; shift -= 4) {
                *ptr++ = toASCII((bytesRead >> shift) & 0xF);
            }
            *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 'c'; *ptr++ = 'o'; *ptr++ = 'd'; *ptr++ = 'e'; *ptr++ = '>';
            *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 't'; *ptr++ = 'd'; *ptr++ = '>';
            *ptr++ = '<'; *ptr++ = 't'; *ptr++ = 'd'; *ptr++ = '>';
            *ptr++ = '<'; *ptr++ = 'c'; *ptr++ = 'o'; *ptr++ = 'd'; *ptr++ = 'e'; *ptr++ = '>';
        } else {
            *ptr++ = ' ';
        }
        *ptr++ = toASCII((c & 0xF0) >> 4);
        *ptr++ = toASCII((c & 0x0F) >> 0);

        if (isEndOfLine(bytesRead)) {
            *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 'c'; *ptr++ = 'o'; *ptr++ = 'd'; *ptr++ = 'e'; *ptr++ = '>';
            *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 't'; *ptr++ = 'd'; *ptr++ = '>';
            *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 't'; *ptr++ = 'r'; *ptr++ = '>';
            *ptr++ = '\0';
            puts(line);
        }
    }
    if (bytesRead % 16 != 0) {
        *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 'c'; *ptr++ = 'o'; *ptr++ = 'd'; *ptr++ = 'e'; *ptr++ = '>';
        *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 't'; *ptr++ = 'd'; *ptr++ = '>';
        *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 't'; *ptr++ = 'r'; *ptr++ = '>';
        *ptr++ = '\0';
        puts(line);
    }
    ptr = line;
    *ptr++ = '<'; *ptr++ = 't'; *ptr++ = 'r'; *ptr++ = '>';
    *ptr++ = '<'; *ptr++ = 't'; *ptr++ = 'd'; *ptr++ = '>';
    *ptr++ = '<'; *ptr++ = 'c'; *ptr++ = 'o'; *ptr++ = 'd'; *ptr++ = 'e'; *ptr++ = '>';
    for (int shift = 28; shift >= 0; shift -= 4) {
        *ptr++ = toASCII((bytesRead >> shift) & 0xF);
    }
    *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 'c'; *ptr++ = 'o'; *ptr++ = 'd'; *ptr++ = 'e'; *ptr++ = '>';
    *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 't'; *ptr++ = 'd'; *ptr++ = '>';
    *ptr++ = '<'; *ptr++ = '/'; *ptr++ = 't'; *ptr++ = 'r'; *ptr++ = '>';
    *ptr++ = '\0';
    puts(line);
    puts("</tbody>");
    puts("</table>");
    puts("</body>");
    puts("</html>");
}
