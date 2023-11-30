# diffie-hellman key exchange
problem: how do we circulate secure keys?
![[circulate_key.png]]

## groups, rings, and fields
### group
a set equipped with a binary operation that is associative, has an identity element, and such that every element has an inverse (Z, +)
### ring
a set equipped with two binary operations satisfying properties analogous to addition and multiplication, (Z, +, \*)
### fields
a set on which addition, subtraction, multiplication, and division are defined and behave as corresponding operations do on the real and rational numbers

#### properties of groups, rings, and fields
![[properties_of_groups_rings_fields.png]]
// but also type it out so you understand

### modulus multiplication table
![[mod_table.png]]

## diffie-hellman
provides secure key exchange between two partners, which is then used for private key encryption/authentication

uses the multiplicative group of integers modulo n (Z/nZ)
based on the difficulty of computing discrete logarithms over such groups
e.g.
$6^3$ mod 17 = 12      (easy)
12 = $6^y$ mod 17?    (hard)

the core equation for the key exchange is 
K = $A^B$ mod q

### global public elements
select prime number q and positive integer a where a is a primitive root of q and a < q

```verbatim
/* 
primitive root
	a is a primitive root if all a mod q, a^2 mod q, a^3 mod q, ..., a^(q-1) mod q are distinct integer values between 1 and q-1 in some permutation, i.e. that they are the elements of (Z/nZ)
	e.g. 3 is a primitive root of (Z/5Z), but 4 is not
	easy to check using a boolean array of length q-1
		-> arr[(a^i) % q] = !(arr[(a^i) % q]);
	then && the whole array
*/
```

### generation of a secret key
both users share a public prime number q and primitive a
user a:
- selects secret number XA with XA < q
- calculate public value YA = $a^{XA}$ mod q    // difficult to reverse
- YA sent to user b

user b:
- select secret number XB with XB < q
- calculate public value YB = $a^{XB}$ mod q
- YB sent to user a

a:
- owns XA, receives YB
- generates secret key K = $(YB)^{XA}$ mod q

b:
- owns XB, receives YA
- generates secret key K = $(YA)^{XB}$ mod q

// these keys are the same

/\*
	proof
		K = (YB)^XA mod q
			= (a^XB mod q)^XA mod q
			= (a^XB)^XA mod q
			= a^(XB XA) mod q = a^(XA XB) mod q
			= (a^XA)^XB mod q
			= (a^XA mod q)^XB mod q
		= (YA)^XB mod q
\*/

### d-h example
- let q = 5 and a = 3;
- XA = 2, therefore YA = $a^{XA}$ mod 5 = 4
- XB = 3, therefore YB = $a^{XB}$ mod 5 = 2
- user A: K = $(YB)^{XA}$ mod q = $2^2$ mod 5 = 4
- user B: K = $(YA)^{XB}$ mod q = $4^3$ mod 5 = 4

> #next_generation_technologies #cryptography 