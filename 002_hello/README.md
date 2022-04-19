# 002 hello

This is a slightly improved version of the "Hello, world!" program.
Instead of relying on the implicit behavior that `main()` returns `0` when reaching its end,
we are explicitly expressing the intent of telling the hosted environment that our program completed successfully.

## The 4 Rules of Simple Design
Purpose: Make change easier/Keep change easy
> 1. Passes the Tests
> 1. Communicates Intent
> 1. No Duplication
> 1. Fewest Elements

Credit: Kent Beck, Martin Fowler

Source: https://martinfowler.com/bliki/BeckDesignRules.html

## New elements
- Include the `<stdlib.h>` library header to get access to general standard library definitions like `EXIT_SUCCESS` and `EXIT_FAILURE`.
- Use `return EXIT_SUCCESS` (or `exit(EXIT_SUCCESS)`) to explicitly indicate successful completion of the program to the hosted environment.
- The 4 Rules of Simple Design show us that communicating intent is more important than no duplicaton or fewest elements.
  Therefore, a version of the "Hello, world!" program that explicitly does `return EXIT_SUCCESS` is better (more readable).

# References
- BeckDesignRules, Martin Fowler, https://martinfowler.com/bliki/BeckDesignRules.html
- ISO/IEC 9899:yyyy http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2731.pdf
  - 5.1.2.2.3 Program termination
  - 7.22 General utilities `<stdlib.h>` § 4 (`EXIT_FAILURE` and `EXIT_SUCCESS`)
  - 7.22.4.4 The `exit` function
