# lisp
given the same problem to solve, a program for this problem in any programming language can be considered equivalent to a program in any other language in that they would both perform the same black-boxed input-output operation

######  consider building an embedded system
- assembly & c
fast, efficient, lightweight
- java, go, rust, python, haskell, etc.
too much overhead

###### consider building a webserver
- assembly
platform specific, too long to develop
- c
memory allocation for every connection, memory leak risk
- python
memory safe but weak types allow for xss attacks, etc.
- java
memory safe and type safe, but large overhead for small projects
- rust
memory sfae, type safe, lightweight, frontend may not be native
- node
memory safe, type safe (maybe), lightweight, isomorphic, single threaded, callback hell
- scheme/haskell
custom types, memory safe, little community support

###### consider building an ai system
- assembly
platform specific, too long to develop
- c
efficient calculation, memory allocation for every data point? multithreading? memory leaks?
- python
high level data + memory, multithreading, scipy/numpy/matplotlib available
- java
memory safe but long-winded code
- go/rust
type and memory safe, but very low level
- nodejs
suitable for distributed systems, but single-threaded and callback hell is a worry
- scheme
elegant, custom types, memory safe, lightweight, mathematical code


---

## what is lisp?
lisp: list processing
	// family of languages
scheme: dialect of lisp
racket: implementation of scheme

prefix notation
```lisp
3 + 4 -> (+ 3 4)

(- 4 ( * 5 6)) = -26
```

functions vs literals
() means function
```lisp
(+ 3 4) = 7
```
' means literal
```lisp
'(+ 3 4) = (+ 3 4)
```
// isn't evaluated

// one thing you can do is leave a hole, that is leave an empty and give an argument later

## s-expressions
both code and data are structured as nested lists in lisp
symbolic expressions (s-expressions, sexprs, sexps) are a notation for nested list structures
defined with a very simple recursive grammar, but produces a very flexible framework for computing

defined as
- an atom
- or, an expression in the form (X . Y) where X and Y are s-expressions

an atom is indivisible, so primitive data types are atoms
lists are not

## cons pairs
two pieces of data together
pairs are created by the cons function, short for construct

```lisp
> (cons 1 2)
'(1 . 2)
```

the two values joined by cons are printed between parentheses, with a dot in between

## lists
ordered group of data
displayed between parentheses, separated by a space

the list syntax is a shorthand for s-expressions 

```lisp
'(1 2 3)
'("hi" "how" "are" "you")
'(1 2 "three" "four")
```

// elements could be any type

---

## car and cdr
lisp used nested lists (basically linked lists)

car - access the first element of a list
// returns first element no matter what it is, possibly a list
cdr - access the rest of the list
// always returns a list

```lisp
> (car '(1 2 3))
1
> (cdr '(1 2 3))
'(2 3)
> (car (cdr '(1 2 3)))
2
```

### c\*r
there exists a shorthand for a combination of car and cdr, usually up to 4 layers deep, depending on the scheme environment

```lisp
; given (a b c d e f) extract d
	(car (cdr (cdr (cdr '(a b c d e f)))))
		; or
	(cadddr '(a b c d e f))

; given ((a b) 3 (c d)) extract a
	(caar ((a b) 3 (c d)))

; given ((a b) 3 (c d)) extract b
	(cadar ((a b) 3 (c d)))
```

---

## empty

lists are essentially just cons pairs where the second value is either another list or empty
// empty is a keyword similar to null

> (cons 1 (cons 2 empty))
'(1 2)

// this is clunky, use the built in list and append functions to build up lists

## define
binds a variable to some data
(define variable value)

or, user-defined functions

```lisp
(define (function_name parameter_list)
	function_body)
```

functions must be defined before they are invoked

```lisp
(define (sumabs num1 num2)
	(+ (abs num1) (abs num2)))
```

// note: no return statement
	// also, returning at the highest level just prints out

```lisp
> (sumabs 2 -3)
5
```

need to have the line (provide function\_name) at the start of the program for it to work

## list

create a list of length n from
```lisp
(list el_0 el_1 … el_n-1)
```

### cons vs list
what's the difference between
```lisp
(cons '(a) '(b))
```
and
```lisp
(list '(a) '(b))
```
?

```lisp
> (cons '(a) '(b))
'((a) b)

> (list '(a) '(b))
'((a) (b))
```


## append
collects components from several lists into one list
```lisp
(append list_0 list_1 ... list_n-1)
```

all arguments must be lists

```lisp
> (append '(mr) '(john) '(jones))
'(mr john jones)

> (append 4 '(2))
error
```

---
## if
carries out program control
(if \<expr\> \<expr\> … \<expr\>)
first is always evaluated, second only if first isn't \#f, and so on

```lisp
> (if (> 2 3)
	"bigger"
	"smaller")

"smaller"
```

## cond
carries out more complex program control
cond can consist of multiple condition-action pairs

```lisp
(cond (clause_0)
	(clause_1)
	...
	(clause_n-1)
	(else (expression))
)

; where each clause is 
	(clause) = ((condition) (expression))

(cond [(cond_0) (expr_0)]
	[(cond_1) (expr_1)]
	...
	[(cond_n-1) (expr_n-1)]
	[else (expr_else)])

	; note: in racket, () and [] are interchangeable, but must be matched together

; conditions are evaluated top to bottom
```

## output
```lisp
> (display "hello world")
hello world

> (printf "the answer is ~a" (add 4 5))
the answer is 9

; see https://docs.racket-lang.org/reference/Writing.html

; generally don't use this, as it's not functional
; try and avoid where possible

; similarly, you can use begin to force lisp to be sequential, but try to avoid it because why would you do that
```

> #paradigms #lisp