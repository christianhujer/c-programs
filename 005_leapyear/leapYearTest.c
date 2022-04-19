#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main(void) {
    assert(!isLeapYear(2022));
    assert(isLeapYear(2024));
    assert(!isLeapYear(2100));
    assert(isLeapYear(2400));
    return EXIT_SUCCESS;
}
