#include <assert.h>
#include <stdlib.h>

int factorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++)
        factorial *= i;
    return factorial;
}

int main(void) {
    assert(1 == factorial(0));
    assert(1 == factorial(1));
    assert(2 == factorial(2));
    assert(6 == factorial(3));
    assert(24 == factorial(4));
    return EXIT_SUCCESS;
}
