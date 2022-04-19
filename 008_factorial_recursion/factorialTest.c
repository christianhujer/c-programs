#include <assert.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main(void) {
    assert(1 == factorial(0));
    assert(1 == factorial(1));
    assert(2 == factorial(2));
    assert(6 == factorial(3));
    assert(24 == factorial(4));
    return EXIT_SUCCESS;
}
