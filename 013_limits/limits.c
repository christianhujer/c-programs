#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
#if defined(__STDC_VERSION__)
    printf("Detected C version: %ld\n", __STDC_VERSION__);
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202000L
    printf("BOOL_WIDTH: %u\n", BOOL_WIDTH);     // Requires C2x
#endif
    printf("CHAR_BIT: %u\n", CHAR_BIT);
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202000L
    printf("USHRT_WIDTH: %u\n", USHRT_WIDTH);   // Requires C2x
    printf("SHRT_WIDTH: %u\n", SHRT_WIDTH);     // Requires C2x
    printf("UINT_WIDTH: %u\n", UINT_WIDTH);     // Requires C2x
    printf("INT_WIDTH: %u\n", INT_WIDTH);       // Requires C2x
    printf("ULONG_WIDTH: %u\n", ULONG_WIDTH);   // Requires C2x
    printf("LONG_WIDTH: %u\n", LONG_WIDTH);     // Requires C2x
    printf("ULLONG_WIDTH: %u\n", ULLONG_WIDTH); // Requires C2x
    printf("LLONG_WIDTH: %u\n", LLONG_WIDTH);   // Requires C2x
#endif
    printf("MB_LEN_MAX: %u\n", MB_LEN_MAX);

    // Note: BOOL_MIN does not exist
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202000L
    printf("BOOL_MAX: %u\n", BOOL_MAX);         // Requires C2x
#endif
    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    printf("SCHAR_MIN: %d\n", SCHAR_MIN);
    printf("SCHAR_MIN: %d\n", SCHAR_MIN);
    printf("UCHAR_MAX: %u\n", UCHAR_MAX);
    printf("UCHAR_MAX: %u\n", UCHAR_MAX);

    printf("USHRT_MAX: %u\n", USHRT_MAX);
    printf("SHRT_MIN: %d\n", SHRT_MIN);
    printf("SHRT_MAX: %d\n", SHRT_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("ULONG_MAX: %lu\n", ULONG_MAX);
    printf("LONG_MIN: %ld\n", LONG_MIN);
    printf("LONG_MAX: %ld\n", LONG_MAX);
    printf("ULLONG_MAX: %llu\n", ULLONG_MAX);
    printf("LLONG_MIN: %lld\n", LLONG_MIN);
    printf("LLONG_MAX: %lld\n", LLONG_MAX);

    return EXIT_SUCCESS;
}
