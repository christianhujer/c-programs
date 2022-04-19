#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int main(void) {
    assert(!isLeapYear(2022));
    assert(isLeapYear(2024));
    assert(!isLeapYear(2100));
    assert(isLeapYear(2400));
    return EXIT_SUCCESS;
}
