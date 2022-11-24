# floating point base conversions
### conversions between base 10 and base 2
the whole and fractional parts of an embedded decimal or binary point must be converted separately

##### examples
>decimal value of 32-bit floating point number
> 1 10000010 11110110000000000000000

sb - 1, negative
exp - 130 = 2^3
mantissa - 1.1111011 (can discard the trailing zeroes) = 1.9609375
_// jump over, divide by $2^{<no\;of\;jumps>}$_

$-1.9609375 \times 2^3 = -15.6875$

>3.14 as a 32-bit floating number

// convert separately, use 10 significant bits for the mantissa

11 = 3 ($n_1$)

sb  - 0, positive
exp - \[later\]
man - .14

```
	.14 * 2 = 0.28   (0)
    .28 * 2 = 0.56   (0)
    .56 * 2 = 1.12   (1)
    .12 * 2 = 0.24   (0)
    .24 * 2 = 0.48   (0)
    .48 * 2 = 0.96   (0)
    .96 * 2 = 1.92   (1)
    .92 * 2 = 1.94   (1)
    .94 * 2 = 1.84   (1)
    .84 * 2 = 1.68   (1)
    .68 * 2 = 1.36   (1)
    .36 * 2 = 0.72   (0)
```
-> 0010001111100000000..... ($n_2$)

11.00100011110...
&nbsp;&nbsp;&nbsp;&nbsp;// normalise, so that only one number is left of the point
$1.100100011110 \times 2^1$
&nbsp;&nbsp;&nbsp;&nbsp;exponent here is 10000000 (128)

full number - 0 10000000 10010001111000000000000

> 45.45 as ieee 754 single precision

sb - 0
45 = 101101

.45
&nbsp;&nbsp;&nbsp;&nbsp;0 1 1 1 0 0 1 1 0 0 1
&nbsp;&nbsp;&nbsp;&nbsp;01110011001

101101.01110011001
$1.0110101110011001 \times 2 ^ 5$
0 10000100 01101011100110010000000


> #computing_systems 