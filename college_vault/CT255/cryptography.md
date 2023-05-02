# cryptography

## cryptography
the art of encompassing the principles and methods of transforming an intelligible message into one that is unintelligible, and then transforming it into its original form

- plaintext
	- the original message
- ciphertext
	- the transformed message
- cipher
	- algorithm used to encipher the message
- key
	- some critical information used by the cipher, known only to the sender and the reciever, to encipher the message, selected from the keyspace k
- encryption
	- the mathematical function $e_k()$ mapping plaintext p to ciphertext c
		$c = e_k(p)$
- decryption
	- the function $e_k^-1()$ mapping ciphertext to plaintext as follows
		$p = e_k^-1(c)$
- cryptanalysis
	- the study of principles and methods used in transforming c to p without knowledge of the key
- cryptology
	- the field encompassing cryptography and cryptanalysis


"known plaintext" attack
attack using a "crib", or a piece of information, to decipher the message

### model of a conventional cryptosystem
![[cryptosystem.png]]

### classical cryptography
![[caesar_cipher.png]]
caesar cipher used letter+3

#### generalised caesar cipher
- use any shift from 1 to 25, and replace any letter with a letter that fixed displacement away
- therefore you have 26 ciphers you can try on any encoded text
- only one key will be useful, however there are only 25 other ciphers, so this is trivial to bruteforce

#### simple substitution cipher
- using a context alphabet, perform the same substitution as a caesar cipher
-> the "one letter at a time" method is what makes it simple

##### context alphabet
placing the letters of a keyword at the start of the alphabet rather than shifting
e.g.
```verbatim
zebrascdfghijklmnopqtuvwxy
```

---
## cryptanalysis via letter frequency
- human languages are redundant
- some letters or groups of letters are used more often than others

![[frequency_table.png]]
tables like this are available for one-, two-, and three-letter groups in various languages

sample c program for frequency analysis
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int data[26];
	char c;
	int i;
	memset(data, 0, sizeof(data));  
	// memset copies the character 'c' to the first n characters of the given pointer

	if (argc != 2) {
		return(-1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		return(-2);
	}

	while (!feof(fp))
	{
		c = toupper(fgetc(fp));
		if ((c >= 'A') && (c <= 'Z')) {
			data[c - 65]++;
			// ascii encoding of A is 65
		}
	}
	for (i = 0; i < 26; i++) {
		printf("%c: %i\n", i + 65, data[i]);
	}
   
	fclose(fp);
	return(1);
}
```

---
## known plaintext attacks (kpa)
an attack model where the attacker has both
- a sample of the plaintext, known as a crib
- the ciphertext including the encoded crib

not even the large number of keys in a monoalphabetic cipher provide security
monoalphabetic - cipher with single letter mapping
one approach is multiple-letter encryption

## playfair cipher (1854)
- create a 5x5 matrix using a key at the start
	![[playfair_cipher.png]]
	-> i = j
- letters encrypted in pairs
	-> repeats have a x inserted as an extra letter between them
- letters in the same row are both shifted once to the right
- letters in the same column are shifted down
- otherwise, letters are replaced by the letter in its row using 

example:
key: prunejuice
plaintext: kensentmex

```verbatim
p r u n e
j c a b d
f g h k l
m o q s t
v w x y z
```

ln by pe mo uz

ciphertext: lnbypemouz

security was much stronger than that of a monoalphabetic cipher, as there were $26^2$, or 676 combinations
however, this could still be broken using 2-letter frequency analysis

## vigenère cipher (1553)
- blaise de vigenère was known as the creator of polyalphabetic ciphers, or ciphers using multiple susbstitution alphabets
- more alphabets = more security
- uses a key to select which alphabet to use
- $i^th$ letter of key = $i^th$ alphabet

- write the plaintext out
- write the key out repeated below it
- encrypt the corresponding plaintext letter

```verbatim
plaintext:  hereismyplaintextlmao
key:        ciphercipherciphercip
```

h encrypted using alphabet c, e encrypted using alphabet i, etc.
// note: here, an alphabet just means the alphabet in order, starting with the letter of the key, so the p alphbet would be pqrstuvwxyzabcdefghijklmno, and the letter p would be encoded as e

### cracking the vigenère
- search for repeated strings, the longer the better
- for each repeated string, count how many letters between the first letters in both repetition, plus one
- factor the number
- repeat this process
- the most common factor is probably the length of the keyword

---
## transposition/permutation ciphers
hide the message by rearranging the letters without altering the letters used
- rail fence cipher
write letters as matrix, column-wise, then read off row-wise
- row transposition cipher

## product ciphers
a substitution cipher followed by a transposition cipher
-> principle that composing ciphers creates a stronger cipher

---
## steganography
an alternative to encryption
rather than hiding the contents of the message, hiding the existence of a message
drawback: not very economical in terms of overheads

### image steganography
assume an x by y pixel image stored in rgb format
each pixel intensity represented by a byte for each colour component
-> the image can be stored in a byte array of size \[x\]\[y\]\[3\]
![[image_steganography.png]]
for each entry we change the least significant bit to hide a bitwise message
// note: compression interferes with this

---
## passwords and hash functions
see [[social_engineering]]
a verifier needs to authenticate a claimant's password, two ways to do this
- store the claimant's password
- store a token derived from the password

### linux password storage
#### structure of the /etc/passwd file:
example:
```verbatim
oracle:x:1021:1020:Oracle user:/data/network/oracle:/bin/bash
```
structure:
```verbatim
username : password(x means encrypted and stored in /etc/shadow) : user_id : group_id : description : home_directory : command_path
```

#### structure of /etc/shadow
example:
```verbatim
root:$6$Ke02nYgo.9v0SF4p1:16431:0:99999:7:  :  :
```
structure:
```verbatim
username : encrypted password : epoch_last_changed : minimum days since changes : maximum valid days, 99999=unlimited : warn; number of days before expiry to be warned : number of days after expiry that the account is disabled : number of days since expiry
```

---
## hash function
a one-way function which produces a fixed-size hash code based on a variable-size input message
the function is public
conventional checksums are not suitable (see hash function requirements)
128-512 bit hash values are regarded as suitable

### putting it together
2 methods:
1) server-side hash
- user enters password
- password sent to server
- password hashed and checked against stored hash
2) client-side hash
- user enters password, which is hashed before sending over network auth protocol
- server checks against stored hash

### requirements for hash functions
#### one-way property
for a given hash code h it is infeasible to find x such that H(x) = h
#### weak collision resistance
for a given password x it is infeasibile to find another password y such that H(x) = H(y)
#### strong collision resistance
it is computationally infeasible to find a pair of passwords (x,y) such that H(x) = H(y)


## birthday paradox
what is the minimum value k such that the probability of two people in a group of size k have the same birthday is greater than 0.5?
> unintuitively, k = 23

### birthday paradox attack
the attack is used in the context of creating hash values for documents, used as an authenticator
- the document is stored as plaintext
- its authenticator, an m-bit hash value is safely stored elsewhere
- whenever the document is retrieved, its hash value is calculated and checked against the authenticator
- in the birthday paradox attack, the attacker creates a large number ($2^{0.5m}$) of variations of:
	- correct messages
	- fraudulent messages 
- birthday paradox makes it easy to find a collision

---
## hash algorithms
https://defuse.ca/checksums.htm
- defuse, an online checksum calculator

### reverse-engineer passwords?
hashes are, in theory, one-way funcions, so this should not be possible

#### dictionary-based brute-force search
dictionary search can be used to systematically identify a match for a given hash value
- the underlying hash function must be known
dictionaries are based on large word, password, or phrase collections

pros:
- straightforward
cons:
- significant computational effort to find a match
- no guaranteed result

https://crackstation.net/crackstation-wordlist-password-cracking-dictionary.htm
- crackstation's dictionary

## lookup table-based attacks
for a given hash function and dictionary
calculate hash value for all entries
store both values in a table, sorted in order of hash value
-> the lookup table
binary search can now be used

pros:
- can be gnerated offline
- search process itself is fast, $O(log_2(n))$
cons:
- massive table (for each function)
- no guaranteed result

https://crackstation.net/
- crackstation free hash cracker (lookup table)

### rainbow tables
uses less processing time and more storage than a brute-force attack
uses more processing time and less storage than a lookup table
-> space-time tradeoff

uses long pre-computed chains of hash values using a hash and reduction function
each chain starts with a given password and has a fixed length, e.g. 10,000 segments
the reduction function converts the output hash into an arbitrary string of the same length as the original input
we only store the starting and end points of the chain

assume we have a table with just two chains (2chainz)
assume arbitrary start and end values
```verbatim
-start-                                                            -end-
aaaaaa  → 173bdfede2ee3ab3 |→ … → 8995tg |→9fdde3a0027fbb36 →… |→    k3rtol
hfk39f  → 856385934954950  |→ … → delphi |→759858fde66e8aa8 →… |→    prp56e
```
where → is a hash function and |→ is a reduction function

and a hash value 759858fde66e8aa8 that we'd like to crack

we apply → and |→ consecutively until we either hit a known end value, or the desired hash
if we hit the hash, we repeat that chain up until we find the password that led to that hash

![[example_rainbow_table_0.png]]

#### chain lookup pseudocode
- input: hash value H
- reduce H to plaintext P
- look for plaintext P in list of final plaintexts -> break if so
- if not there, calculate hash of P
- goto 2, unless you've reacched the maximum amount of iterations
- if p matches a final plaintext, walk through chain with corresponding final plaintext until you find the original plaintext that correlates to H

#### chain collisions
when two passwords have the same hash value
in this case, two chains would merge from that point on
	as a result, there is no guarantee that your chains will ever cover all possible passwords
rainbow tables solve this problem by using a series of related reduction functions $r_1$ through $r_k$ rather than one single reduction functions
	in this way, the two passwords must hit the same value on the same iteration, which is unlikely

![[example_rainbow_table_1.png]]
// take notes on the example rainbow table case study

#### defenses against rainbow tables
- longer passwords
enforce a min length on the user
- salting
algorithmic approach
a unique and random, but known, string is appended to each password before it is hashed
a potentially short password is then extended
- peppering
like salting, however it is not stored, often is hardcoded into source code
- multiple iterations of hashing
H(H(H(H(..(H(p))..)))),  often >1000 times
- combination methods
new_hash(password) = H(H(password) || salt)
new_hash(password) = H_1(H_2(password) || salt), with hash functions H1 and H2

---
> #cybersecurity #cryptography #next_generation_technologies 
> [[bits_of_entropy]]