#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("size of _Bool: %zu\n", sizeof(_Bool));
    printf("size of char: %zu\n", sizeof(char));
    printf("size of short int: %zu\n", sizeof(short int));
    printf("size of int: %zu\n", sizeof(int));
    printf("size of long int: %zu\n", sizeof(long int));
    printf("size of long long int: %zu\n", sizeof(long long int));
    printf("size of float: %zu\n", sizeof(float));
    printf("size of double: %zu\n", sizeof(double));
    printf("size of long double: %zu\n", sizeof(long double));
    return EXIT_SUCCESS;
}
