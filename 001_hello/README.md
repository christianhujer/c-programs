# 001 hello

This program shows you a simple "Hello, world!" program in C.

## New elements
- Use `#include` to include library headers.
- Include the `<stdio.h>` library header to get access to I/O-related library definitions like the `puts()` function.
- Use `int main(void)` as the signature of the main program when the main program does not need to access command line arguments.
  This is where the program will start execution.
- Use the `puts()` function to print a string to `stdout`.
  Note: Some other examples instead use `printf("Hello, world!\n");`.
  In this context, this has the same effect.
  However, `puts()` is simpler.
- To compile the program, you can do any of the following:
  - If your system has `make` and C compiler, you can run `make hello` or, as a `Makefile` is present, just `make`.
  - If you have a standard C compiler, you can run `cc -o hello hello.c`.
  - Or else, you can just try the _Run_ feature of your C IDE.

# References
- ISO/IEC 9899:yyyy http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2731.pdf
  - 1. Scope
  - 2. Normative references
  - 3. Terms, definitions, and symbols (completely)
  - 4. Conformance
  - 5. Environment
  - 5.1.2 Execution Environments
  - 5.1.2.2 Hosted environment
  - 5.1.2.2.1 Program startup
  - 5.1.2.2.2 Program execution
  - 5.1.2.2.3 Program termination
  - 7.21.1 Introduction, the section about `stderr`, `stdin`, `stdout`
  - 7.21.7.9 The `puts` function
