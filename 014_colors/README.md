# Colors

Colors are often represented as hexadecimal 24-bit value `#RRGGBB`.
For example, `#000000` is black, `#FF0000` is red, `#00FF00` is green, `#0000FF` is blue, `#FFFFFF` is white, `#FF8000` is orange, `#9933000` is some shade of brown, and so on.

The program `decode` takes a combined RGB color value and splits it into its components.
The program `decode_annotated` does the same, but is annoted in comments and with printf statements that show the underlying binary operations that are going on for a specific sample value.

The prgoram `encode` combines an RGB color value into its components (homework).

Note: The program `decode_annotated` makes use of the C2x `%b` format specifier.
This format specifier may not yet be supported by all compilers.

## New elements
* The left-shift operator `<<`: `a << b` shifts the value of `a` to the left by `b` bits.
* The right-shift operator `>>`: `a >> b` shifts the value of `a` to  the right by `b` bits.
* The `&` operator: `a & b` performs a bit-wise AND of the values of `a` and `b`.
* The `|` operator: `a | b` performs a bit-wise OR of the values of `a` and `b`.
* The `^` operator: `a ^ b` performs a bit-wise XOR of the values of `a` and `b`.
* The `~` operator: `~a` performs a bit-wise NOT of the value of `a`.
