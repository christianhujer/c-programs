# 016 hexdump

This program is a hex dump program.
That is, it prints the hexadecimal byte value of each of the input bytes that it reads from `stdin`.
For added convenience, it prints exactly 16 bytes per line, and it starts every line with a hexadecimal offset from the start of the file.
The last line printed is the number of bytes written, in hex, in other words, the file size.
