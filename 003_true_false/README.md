# 003 true false

These two programs are re-implementations of the POSIX programs `true` and `false`.
Use `man true` and `man false` (use Google if you do not have man pages on your system) to figure out what these programs do.

## true
The `true` program does nothing, successfully.
That means it does nothing, and when completing that, it signals success to the hosted environment.

## false
The `false` program does nothing, unsuccessfully.
That means it does nothing, and when completing that, it signals failure to the hosted environment.

# References
- ISO/IEC 9899:yyyy http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2731.pdf
  - 5.1.2.2.3 Program termination
  - 7.22 General utilities `<stdlib.h>` § 4 (`EXIT_FAILURE` and `EXIT_SUCCESS`)
  - 7.22.4.4 The `exit` function
