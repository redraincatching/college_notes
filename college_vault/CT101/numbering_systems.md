# Binary Representation

One bit can be either **_1_** or **_0_**.
→ one bit can only represent one thing. n bits can represent 2^n things.
1 byte = 8 bits = 256 options

**Why binary?**
_(don't ask me lol)_
-   hardware: less expensive to manufacture, maps easily to current technology
-   easier to maintain: signal integrity



#### Data Formats
The internal representation must be appropriate for the type of processing that will take place.

-   image → colour at each data point
-   sound → sampling rate
-   etc.

Standards → either a widely used proprietary format or selected by an expert comittee, e.g. Unicode

>🦋 **Parity**
>Even or odd, used to check for corruption in data. The number of 1s in the byte had to be either even or odd, depending on the type of parity, and the last bit was used for this.
>e.g.
>-   1011011**1**
>-   1010101**0**

--- 

### Number Categories

natural, negative, irrational, etc.

> 🦋 **computer science definition of a number**
>
>unit belonging to an abstract mathematical system subject to specified laws of succession, addition, and multiplication

---
## Base

the number of digits used in a numbering system
base n → the digits are (0, 1, [...], n-1)
&nbsp&nbsp&nbsp&nbsp// also determines the positional value
&nbsp&nbsp&nbsp&nbsp// subscript can be used to indicate base

## Positional Notation

each position has a place value, and the total number is equal to the sum of each digit * their place value
&nbsp&nbsp&nbsp&nbsp// place value is base ^ (position from right, starting at 0)

e.g. 954 in decimal 
&nbsp&nbsp&nbsp&nbsp-> 9_10^2 + 5_10^1 + 4_10^0 = 954 in decimal 
954 in hex 
&nbsp&nbsp&nbsp&nbsp-> 9_16^2 + 5_16^1 + 4_16^0 = 2388 in decimal

---

# Binary Arithmetic
![[binary_addition]]
![[binary_subtraction]]
![[binary_multiplication]]
![[floating_point_conversion]]

---

### Base Conversions

^b1fcd8

#### Power of 2 Bases

binary - $2^1$ 
octal - $2^3$ 
hexadecimal - $2^4$

one octal digit can represent 3 binary digits (4|2|1) 
one hexadecimal digit represents 4 (8|4|2|1)

easiest way to convert these is by grouping into "cells" with n bits, where n is the base in terms of powers of two, and each of these cells equate to one digit

#### Decimal to Other Bases

divide by the base into which you're converting
divide, get a quotient and remainder
while quotient != 0
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspdivide the number by the new base make remainder next digit in the new base repeat, dividing into the quotient

example: 680 to hex

>$16^2 = 256$
>$16^1 = 16$
>$16^0 = 0$
>
>$680 / 256 = 2 r 168$
>$168 / 16 = 10 r 8$
>$8 / 1 = 8 r 0$

therefore, 680 in hex = 2A8

// each digit is the amount of times the power divided in
// if no remainder, all subsequent digits are 0

other method:

continually divide by the base itself until = 0
remainder builds up

example:
>512 to hexadecimal
>$512 / 16 = 32 r 0$
>$32 / 16 = 2 r 0$
>$2 / 16 = 0 r 2$

answer: 200

---

#### Base Fraction Conversions
different between bases
e.g.
>base 10 1/3
>= 0.333333...

>base 3 1/3
>= 0.1

strength of each digit is b * strength of its right neighbour, where b is the base
1000 in decimal is ten times bigger than 100.0 100 in binary is twice as big as 10.0

example:
>decimal number → 0.2589
>→ $2*(1/10) + 5*(1/100) + 8*(1/1000) + 9*(1/10000)$

>binary number → 0.101011
>→ $1*(1/2) + 0*(1/4) + 1*(1/8) + 0*(1/16) + 1*(1/32) + 1*(1/64)$

>ternary number → 0.12201
>→ $1*(1/3) + 2*(1/9) + 2*(1/27) + 0*(1/81) + 1*(1/243)$

***= 0.63374~ish***

other method

>0.110011 base 2 to base 10
jump the binary point over (here, six spaces) find answer (51) divide by base * jumps (51/64) answer (0.76875)

### fractional conversion methods

variation of the division method
&nbsp&nbsp&nbsp&nbsprepeatedly multiply by the new base
&nbsp&nbsp&nbsp&nbsprecord every digit that moves left of the point
&nbsp&nbsp&nbsp&nbsp-> that becomes the next value of the new number, after the point drop that number
&nbsp&nbsp&nbsp&nbsprepeat until required precision is achieved, or until remaining number is 0

##### fractional conversions between bases of 2^n
grouping goes left to right, method is otherwise identical

---

## representing negative numbers

**common schemas**
sign-magnitude
complementary representations
- 1's / 9's complement
- 2's / 10's complement

### sign magnitude
leftmost bit represents +ve or -ve
behaves like a flag
_1 is negative_
_0 is positive_

// this takes up a bit, so extra storage
// so the very first step is to decide on the number of bits to use to represent the number

#### difficulties involved

- two representations of 0
-0: 10000000
+0: 00000000

- arithmetic involved is difficult
more complexity in hardware necessary to implement an ALU
(arithmetic and logic unit)

### complementary notation

##### 9's (decimal) and 1's (binary) complement
- decide the number of digits (word length) to represent the numbers
- represent the negative numbers by the largest number minus the absolute value of the negative number

**example**
2-digit 9's complement of -12
&nbsp&nbsp&nbsp&nbsp99 - 12 = 87    
// get back the value by inverting this again

8-digit 1's complement of -101
&nbsp&nbsp&nbsp&nbsp11111111 - 101 = 11111010

positive numbers _map directly_ using half of the total combinations
negative numbers map onto the other half of the numbers
&nbsp&nbsp&nbsp&nbspso above, in the 2 digit 9's complement, 0-49 are +(0-49), and 50-99 are -(0-49)

#### failings
again, two representations of 0
arithmetic is still pretty awkward

##### 10's (decimal) and 2's (binary) complement

similar, but represent the negative number as largest number + 1, minus absolute value
removes the second 0, as two digits will never include the other 0

**examples**
2-digits 10's complement of -12
&nbsp&nbsp&nbsp&nbsp100 - 12 = 88

8-digit 2's complement of -101
&nbsp&nbsp&nbsp&nbsp100000000 - 101 = 11111011
// do a 1's complement, then add one after flipping the bits

// this representation can hold _one extra negative number_
// e.g., 2-digit 10s ranges from -50 to 49

// also note, just 9's complement with 1 added

##### binary complement tips and tricks
- positive numbers are always represented by themselves
- small negative numbers have representations starting with lots of 1s
- you can get a rough idea of the value of a negative number just by flipping the bits

---
## overflow and carry
### overflow
occurs when the result of the calculation doesn't fit into the fixed number of bits available for the result
&nbsp;&nbsp;&nbsp;&nbsp;in complementary notation, occurs whenever the result overflows into the sign bit
&nbsp;&nbsp;&nbsp;&nbsp;-> the sign of the result is different from that of both operands

### carry flag
necessary when breaking up a number that is too large for a system, and a carry or borrow is necessary
(e.g. subtracting two 64 bit numbers in a 32 bit system)

>overflow occurs when you can't represent the result as a signed value
>carry occurs when you can't represent the result as an unsigned value

> # examples
> 4-bit 2's complement
> 
> 0100 + 0010 = 0010
> (4) + (2) = (6)     _// no carry, no overflow, result is correct_
>
> 1100 + 1110 = 11010
> (-4) + (-2) = (-6)  _// no overflow, ignoring the carry, result is correct_
>_ // 1010 is -6_
>
> 0100 + 0110 = 1010
>(4) + (6) = (-6)    _// overflow, no carry, result is incorrect_
>
>1100 + 1010 = 10110
>(-4) + (-6) = (6)   _// overflow, carry, and ignoring the carry, result is incorrect_



>[[data_representation]]
>#computing_systems 