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

## Escape sequences
<table>
<thead>
<tr><th scope="col" colspan="3">ISO/IEC 9899</th><th scope="col" colspan="4">ASCII / Unicode</th></tr>
<tr><th scope="col">Escape</th><th scope="col">Meaning</th><th>Explanation</th><th scope="col">Hex</th><th scope="col">Dec</th><th scope="col">Abbreviation</th><th scope="col">Name</th></tr>
</thead>
<tbody>
<tr><td><code>\a</code></td><td>alert</td>          <td>audible or visible alert</td>    <td><code>0x07</code></td><td><code> 7</code></td><td><code>BEL</code></td><td>Bell</td>           </tr>
<tr><td><code>\b</code></td><td>backspace</td>      <td>cursor 1 position left</td>      <td><code>0x08</code></td><td><code> 8</code></td><td><code>BS</code></td> <td>Backspace</td>      </tr>
<tr><td><code>\f</code></td><td>form feed</td>      <td>start of next page</td>          <td><code>0x0C</code></td><td><code>12</code></td><td><code>FF</code></td> <td>Form Feed</td>      </tr>
<tr><td><code>\n</code></td><td>new line</td>       <td>start of next line</td>          <td><code>0x0A</code></td><td><code>10</code></td><td><code>LF</code></td> <td>Line Feed</td>      </tr>
<tr><td><code>\r</code></td><td>carriage return</td><td>start of current line</td>       <td><code>0x0D</code></td><td><code>13</code></td><td><code>CR</code></td> <td>Carriage Return</td></tr>
<tr><td><code>\t</code></td><td>horizontal tab</td> <td>next horizontal tab position</td><td><code>0x09</code></td><td><code> 9</code></td><td><code>HT</code></td> <td>Horizontal Tab</td> </tr>
<tr><td><code>\v</code></td><td>vertical tab</td>   <td>next vertical tab position</td>  <td><code>0x0B</code></td><td><code>11</code></td><td><code>VT</code></td> <td>Vertical Tab</td>   </tr>
</tbody>
</table>

## References
- ISO/IEC 9899:yyyy http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2731.pdf
  - 5.1.2.2.1 Program startup
  - 5.2.2 Character display semantics
  - 7.21.7.4 The `fputs` function
- Unicode code chart C0 Controls and Basic Latin (ASCII) https://unicode.org/charts/PDF/U0000.pdf
