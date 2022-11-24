# floating point arithmetic 

you need to "line up" the exponents, and so arithmetic is more complicated than with simple numbers

**example**
perform the addition $3_{10}$ + $1.5_{10}$

$3$
- $n_1$ = 3 = 11
- -> 11
$1.1 \times 2^1$


 $1.5$
- $n_1$ = 1
- $n_2$ = .1
- -> 1.1
$1.1 \times 2^0$

            
convert smaller exponent to larger
```
  1.1  * 2^1
+ 0.11 * 2^1
------------
 10.01 * 2^1    
 
 -> 1.001 * 2^2    // can't have more than 1 digit left of the point
```

---

## addition exercise
```
		x - 0100 0010 0000 1111 0000...
        y - 0100 0001 1010 0100 0000...

        x
            sb - 0
            exp - 10000100, 5
            mantissa - 00011110000...

        y
            sb - 0
            exp - 10000011, 4
            mantissa - 01001000000...

            1.0001111 * 2^5
            0.1010010 * 2^5
            ---------------
            1.1100001 * 2^5 = 111000.01 = 56.25_10
```

> #computing_systems 