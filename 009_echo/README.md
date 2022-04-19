# Echo

The `echo` program prints its arguments on a single line, concatenated with `" "`, and terminated by `"\n"`.

## New Elements
- `stdin`, `stdout`, and `stderr` are 3 files that a process in a hosted environment can access without having to open them first.
- Unless redirected, the files `stdin`, `stdout`, and `stderr` are typically connected to a terminal window, that is:
  - `stdin` reads from the keyboard
  - `stdout` writes to the terminal screen
  - `stderr` wrties to the terminal screen (as well)
- Use `stdout` for the regular output of the program.
- Use `stderr` for messages that the user should receive.
  In the Unix philosophy, "silence is golden", aka "no news is good news".
  Unix programs usually don't print any messages unless they have errors to report.
  In hindsight, `stdmsg` would've been a better name.
  Think `stdmsg` when you see `stderr`.
