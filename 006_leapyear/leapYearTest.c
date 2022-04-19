#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool isDivisibleBy(int number, int factor) {
    return number % factor == 0;
}

bool isLeapYear(int year) {
    return (isDivisibleBy(year, 4) && !isDivisibleBy(year, 100)) || isDivisibleBy(year, 400);
}

int main(void) {
    assert(!isLeapYear(2022));
    assert(isLeapYear(2024));
    assert(!isLeapYear(2100));
    assert(isLeapYear(2400));
    return EXIT_SUCCESS;
}
