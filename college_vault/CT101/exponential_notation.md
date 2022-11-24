# exponential notation

_e.g. -0.3579 x 10^-6_

four components needed to define a number in this notation
- sign of main number
- magnitude of main number (known as the mantissa)
- sign of exponent
- magnitude of exponent

two additional pieces of information are required to complete the representation
- base of exponent
- location of (binary/decimal) point
_// this is set at a particular location so that is doesn't need to be stored, such as at the beginning or the end of the mantissa_

## floating point format
typical representation in 8 digits
_SEEMMMMM_
- s - one digit for sign of mantissa
- e - two digits for exponent
- m - the mantissa representation

there's no provision for the sign of the exponent, so we need to use a method that includes it
-> one method is complementary notation
->another is offset representation (excess-n notation)
- pick a middle value to be zero (e.g. 50)
- a value greater than that is positive, and has a magnitude of the difference
- a value lower is the negative, and also has a magnitude of the difference

&nbsp;&nbsp;&nbsp;&nbsp;this is simpler than complementary for exponents, and allows for calculations

&nbsp;&nbsp;&nbsp;&nbsp;in base 10, allows us to store an exponential range of -50 to 49
e.g.
$0.00001 \times 10^{-50} \leq n \leq 0.99999 \times 10^{49}$

---
### floating point exceptions
**overflow**
using a number of a magnitude too large to be stored
**underflow**
where the number has a magnitude too small to be stored

---

## normalising and formatting

number of digits determined by desired precision
&nbsp;&nbsp;&nbsp;&nbsp;therefore, stored with no leading zeroes (normalisation)

> **example**
>     SEEMMMMM in base 10 - $0.MMMMM \times 10^{EE}$
>      -> excess-50
>     decimal at start of mantissa
>     sign is represented by 5 if +ve, 0 if -ve (arbitrary in decimal)

#### steps for normalising
e.g. 246.8035
1) provide an exponent of 0 if not specified ($246.8035\times10^0$)
2) shift decimal point by adjusting the exponent value until in correct position ($.2468035\times10^3$)
3) correct precision by adding or removing digits as necessary ($.24680\times10^3$)
4) formatting - place into standard exponential form ($0 53 24680$)

---
## floating point numbers in computing systems

the leading bit of the mantissa must be 1 if the number is normalised
_// this bit can be treated implicitly_

##### disadvantages
since leading bit is always 1, this limits the range of small numbers

---
## IEEE 754 standard
most common standard for representing floating point numbers
-> instructions on how to organise the processor


```         
single precision (32 bits)
	sign bit (1 bit)
	exponent (8 bits)
	mantissa (23 bits)
		| 1 |     8     |      23      |

double precision (64 bits)
    sign bit (1 bit)
    exponent (11 bits)
    mantissa (52 bits)
	    | 1 |       11       |        52        |
```

#### single precision format
the mantissa needs to be normalised
&nbsp;&nbsp;&nbsp;&nbsp;has an implied 1 on the left of the point
&nbsp;&nbsp;&nbsp;&nbsp;_// this is a logical flag, not a number_
e.g.
mantissa - $10100000000000000000000$
representation - $1.101_2$ = $1.625_{10}$

exponent is formatted excess-127, with an implied base of 2
&nbsp;&nbsp;&nbsp;&nbsp;exponent - 10000111 (135)
&nbsp;&nbsp;&nbsp;&nbsp;representation - 135 = 127 + 8 -> exponent is $^8$
&nbsp;&nbsp;&nbsp;&nbsp;_// note: exponential range is $2^{-126}$ to $2^{127}$_

#### double precision format
pretty much the same, except exponent uses 11 bits, therefore excess-1023 is used

---

## floating point operations

[[base_conversion_floating_point]]
[[floating_point_arithmetic]]
[[floating_point_multiplication]]


> [[numbering_systems]], [[data_representation]]
> #computing_systems 