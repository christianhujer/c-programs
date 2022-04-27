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

void printHeader() {
    fputs(
        "<?xml version=\"1.0\"?>\n"
        "<!DOCTYPE html>\n"
        "<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\">\n"
        "<head>\n"
        "<title>Hex Dump</title>\n"
        "</head>\n"
        "<body>\n"
        "<h1>Hex Dump</h1>\n"
        "<table border=\"border\">\n"
        "<thead>\n"
        "<tr><th scope=\"col\">Offset</th><th scope=\"col\">Data</th></tr>\n"
        "</thead>\n"
        "<tbody>\n"
        , stdout);
}

char *append(char *ptr, char *str) {
    while (*str) // short for: while (*str != '\0')
        *ptr++ = *str++;
    return ptr;
}

char *appendHex(char *ptr, int value, int initialShift) {
    assert(initialShift % 4 == 0 && initialShift > 0);
    for (int shift = initialShift - 4; shift >= 0; shift -= 4) {
        *ptr++ = toASCII((value >> shift) & 0xF);
    }
    return ptr;
}

char *appendAddressCell(char *ptr, size_t address) {
    ptr = append(ptr, "<td><code>");
    ptr = appendHex(ptr, address, 32);
    ptr = append(ptr, "</code></td>");
    return ptr;
}

char *startLine(size_t bytesRead) {
    char *ptr = line;
    ptr = append(ptr, "<tr>");
    ptr = appendAddressCell(ptr, bytesRead);
    return ptr;
}

void endLine(char *ptr) {
    ptr = append(ptr, "</code></td></tr>");
    *ptr = '\0';
}

void printBody() {
    size_t bytesRead = 0;
    char *ptr;

    for (int c; (c = getchar()) != EOF; bytesRead++) {
        if (isStartOfLine(bytesRead)) {
            ptr = startLine(bytesRead);
            ptr = append(ptr, "<td><code>");
        } else {
            *ptr++ = ' ';
        }
        ptr = appendHex(ptr, c, 8);

        if (isEndOfLine(bytesRead)) {
            endLine(ptr);
            puts(line);
        }
    }
    if (bytesRead % 16 != 0) {
        endLine(ptr);
        puts(line);
    }
    ptr = startLine(bytesRead);
    ptr = append(ptr, "</tr>");
    *ptr++ = '\0';
    puts(line);
}

void printFooter() {
    fputs(
        "</tbody>\n"
        "</table>\n"
        "</body>\n"
        "</html>\n"
        , stdout);
}

int main(void) {
    printHeader();
    printBody();
    printFooter();
}
