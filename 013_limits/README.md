# 012 Limits

This program prints the limits of the various arithmetic types.

Note:
This program intentionally has no test.
The actual limits of the various types are, apart from a few constraints about the order of their size, implementation-defined.

Note 2:
This program requires a C2x-compiler to print everything.
Some portions of this program will not compile on a C17 or older compiler.
The preprocessor is used to conditionally exclude the portions that require C2x on older compilers.
As C2x is not released yet, the assumed minimum value for `__STDC_VERSION__` is `202000L`.

## References
- ISO/IEC 9899:yyyy http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2731.pdf
  - 3.4.1 implementation-defined behavior
  - 5.2.4.2.1 Characteristics of integer types `<limits.h>`
  - 6.10.8.2 Environment macros (specificaly `__STDC_VERSION__`)
  - 7.10 Characteristics of integer types `<limits.h>`
