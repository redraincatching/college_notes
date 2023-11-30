#lang racket
; a cons pair of two numbers
(cons 1 2)
    ; a pair, printed (1 . 2)

; a list of three numbers using cons
(cons 3 (cons 2 (cons 1 '())))  
    ; have to pair the last one with an empty list, otherwise it's a pair and not a list

; a list containing a string, a number, and a nested list of three numbers, using cons
(cons "string" (cons 70 (cons '(1 2 3) '())))
    ; have to concat with the literal list, otherwise racket will try to evaluate it

; a list containing a string, a number, and a nested list of three numbers, using list
(list "another string" 71 '(4 5 6))
    ; much simpler, don't need to worry about pairs

; a list containing a string, a number, and a nested list of three numbers, using append
(append empty '("string time baby") '(4050) '((11 13 15)))
    ; append only takes lists as arguments, so we have to account for that