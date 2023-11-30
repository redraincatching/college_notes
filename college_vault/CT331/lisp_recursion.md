# recursion in lisp
scheme has no concept of loops, or repetition
control flow is achieved through recursion

###### recap:
a well-defined recursive function has two characteristics
- a certain case, the base case / base criteria, where the function does not recurse
- each time the function is called, it moves closer to the base criteria

## recursive problem solving
- what is the base case?
- what should the answer be there?
- how do we reduce to it?
	// in lisp, this is often taking the cdr of a list
- what other work needs to be done for each function call?
- how can these steps be put together?

### base cases
- for numbers
often 0 or 1
- for lists
often when list is empty
- note: may have multiple base cases

### mistakes to avoid
- wrong number of arguments passed to function
- no base case/base case impossible to reach
- not reducing

## example recursive function - factorial
### base case: 1
answer at base case: 1 (1! = 1)

```lisp
(fact 1) => 1
(fact 2) => 2 * (fact 1)
```
what work needs to be done at each step?
```lisp
(fact n - 1) * input
```


### simpler example first: sum

```lisp
(define(sum num)
	(if (> num 1)
		(+ num (sum (- num 1)))
		1))
```

### recursive factorial

```lisp
(define (fact num)
	(if (> num 1)
		(* num (fact (- num 1)))
		1))
```


## another example - all_atom?
asks if all the elements of a list are atoms, returning \#t or \#f

### base cases:
- (null? lst)
stop and output \#t
- (car lst) != an atom
stop and output \#f
- one element in list, and it's an atom
stop and output \#t

### reduction
if (car lst) is an atom, continue and check (cdr lst)

### implementation
```racket
#lang racket
(provide all_atoms?)
(define (all_atoms? lst)
    (cond
        [(null? lst) #t]
        [(atom? (car lst)) (all_atoms? (cdr lst))]
        [#f]
        ))

    ; recursive function that checks if all items in list are atoms
    
(define (atom? x)
    (and (not (null? x))
        (not (pair? x))))
```

---

## efficient recursion
problem: 
multiple activations of a recursive function causes stack growth
space for multiple parameters needed
time needed to allocate and release memory

solution:
don't


### tail recursion
the value of the recursive call provides the complete result of the original call
no waiting to activate

in scheme
if the last action of a function is another function call, it is replaced by that function on the stack -> no stack growth

![[tail_recursion_0.png]]
![[tail_recursion_1.png]]
![[tail_recursion_2.png]]

#### advantages and disadvantages
- only requires enough memory space for one active invocation at a time
each invocation disappears as the next is called
- often difficult to create and read
- very good for dealing with infinite loops
however, if it gets into an infinite loop, it wouldn't stop due to lack of memory like normal recursion
- unless you write a helper function, you need to remember the extra value to pass to the function
> #paradigms #lisp 