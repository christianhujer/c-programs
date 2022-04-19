# 011 Types

This program prints the sizes of the various types arithmetic types.
The arithmetic types defined by ISO/IEC 9899:202x are:
- `_Bool`, large enough to store the values 0 and 1
- The _standard signed integer types_ `signed char`, `short int`, `int`, `long int`, and `long long int`.
- The _standard unsigned integer types_ `unsigned char`, `unsigned short int`, `unsigned int`, `unsigned long int`, `unsigned long long int`, and `_Bool`.
- The standard signed integer types and the standard unsigned integer types are collectively called the _standard integer types_.
- The _standard floating types_ `float`, `double`, and `long double` (which typically adhere to _IEEE 754_ aka _ISO/IEC 60559_).
- The integer and floating types are colelctively called _arithmetic types_.

Note:
This program intentionally has no test.
The actual size of the various types is, apart from a few constraints about the order of their size, implementation-defined.

## References
- ISO/IEC 9899:yyyy http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2731.pdf
  - 3.4.1 implementation-defined behavior
  - 6.2.5 Types
  - 6.7.2 Type specifiers
