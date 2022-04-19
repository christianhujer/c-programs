# Echo

This version of the `echo` program fixes a potential issue of the previous version.
The previous version might have sub-optimal behavior in a multitasking environment when mutliple programs share the same output stream.

## New Elements
- A String in C is an array of characters, terminated by the `'\0'` character (ASCII/Unicode: NUL).
- The function `strlen()` determins the size of a string without its terminating `'\0'` character.
- The function `malloc()` dynamically allocates a requested size of memory on the heap.
- The function `malloc()` can fail (out of memory, for example), in which case it will return `NULL`.
- `NULL` is the null-pointer, typically defined as `((void *)0)`.
- `NULL` is used to indicate that a pointer has not been initialized to point at something.
  `NULL` means as much as "this points to nothing" or "this doesn't point to anything".
- Always check the return value of the `malloc()` function.
- The memory returned by `malloc()` has undefined content.
  Make sure to initialize it before use.
- The function `free()` has to be called for all memory that was previously allocated by `malloc()` (or any similar function).
- Failing to call `free()` leads to a so-called memory leak.
- The function `memset()` can be used to fill a block of memory with a defined value.
  A frequent use case is to clear memory so that it is initialized with 0 before use.
- The function `strncat()` is used to append a string to another.
- The function `fflush()` is used to ensure that in case the hosted environment uses buffered I/O, that these I/O buffers are flushed.
