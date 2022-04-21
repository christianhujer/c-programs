#include <stdio.h>
#include <stdlib.h>

int main(void) {
                //  RRGGBB
    int color = 0x00556B2F;

    // RED
    printf("red:   %3d\n", ((color >> 16) & 0xFF));
    // 0x00556B2F >> 16 -> 0x00000055 & 0xFF -> 0x00000055
    //           RRRR RRRR GGGG GGGG BBBB BBBB
    // 0000 0000 0101 0101 0110 1011 0010 1111
    // >> 16
    //                               RRRR RRRR
    // 0000 0000 0000 0000 0000 0000 0101 0101
    // 0000 0000 0000 0000 0000 0000 1111 1111 & 0xFF
    // 0000 0000 0000 0000 0000 0000 0101 0101 -> 0x55 -> 85
    printf(" color:               #%08x %032b\n", color, color);
    printf("(color >> 16):        #%08x %032b\n", color >> 16, color >> 16);
    printf("0xFF                            %032b\n", 0xFF);
    printf("(color >> 16) & 0xFF: #%08x %032b\n", (color >> 16) & 0xFF, (color >> 16) & 0xFF);

    // GREEN
    printf("green: %3d\n", ((color >>  8) & 0xFF));
    // 0x00556B2F >>  8 -> 0x0000556B & 0xFF -> 0x0000006B
    //           RRRR RRRR GGGG GGGG BBBB BBBB
    // 0000 0000 0101 0101 0110 1011 0010 1111
    // >> 8
    //                     RRRR RRRR GGGG GGGG
    // 0000 0000 0000 0000 0101 0101 0110 1011
    // 0000 0000 0000 0000 0000 0000 1111 1111 & 0xFF
    // 0000 0000 0000 0000 0000 0000 0110 1011 -> 0x6B -> 107
    printf(" color:               #%08x %032b\n", color, color);
    printf("(color >>  8):        #%08x %032b\n", color >>  8, color >>  8);
    printf("0xFF                            %032b\n", 0xFF);
    printf("(color >>  8) & 0xFF: #%08x %032b\n", (color >>  8) & 0xFF, (color >>  8) & 0xFF);

    // BLUE
    printf("blue:  %3d\n", ((color >>  0) & 0xFF));
    // 0x00556B2F >>  0 -> 0x00556B2F & 0xFF -> 0x0000002F
    //           RRRR RRRR GGGG GGGG BBBB BBBB
    // 0000 0000 0101 0101 0110 1011 0010 1111
    // >> 0
    //           RRRR RRRR GGGG GGGG BBBB BBBB
    // 0000 0000 0101 0101 0110 1011 0010 1111
    // 0000 0000 0000 0000 0000 0000 1111 1111 & 0xFF
    // 0000 0000 0000 0000 0000 0000 0010 1111 -> 0x2F -> 47
    printf(" color:               #%08x %032b\n", color, color);
    printf("(color >>  0):        #%08x %032b\n", color >>  0, color >>  0);
    printf("0xFF                            %032b\n", 0xFF);
    printf("(color >>  0) & 0xFF: #%08x %032b\n", (color >>  0) & 0xFF, (color >>  0) & 0xFF);

    return EXIT_SUCCESS;
}

