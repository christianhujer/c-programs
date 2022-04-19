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
