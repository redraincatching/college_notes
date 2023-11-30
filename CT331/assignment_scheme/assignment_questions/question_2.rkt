#lang racket

(provide ins_beg ins_end count_top_level count_instances count_instances_tr count_instances_deep)

(define (ins_beg el lst)
    (cons el lst))

(define (ins_end el lst)
    (append lst (list el)))


(define (count_top_level lst)
    (count_tl lst 0))

(define (count_tl lst total)
    (if (empty? lst)
        total     ; base case
        (count_tl (cdr lst) (+ total 1))  ; reduce
        ))


(define (count_instances target lst)
    (if
        ; base case is empty list
        (empty? lst) 0
        ; then check if current car is equal to the target
        (if 
            ; if they are equal, increment then proceed
            (equal? (car lst) target) ( + 1 (count_instances target (cdr lst)))
            ; otherwise just proceed
            (count_instances target (cdr lst)))))


(define (count_instances_tr target lst)
    (ci_tr target lst 0))

(define (ci_tr target lst total)
    (cond 
        ; base case
        [(empty? lst) total]
            ; positive reduction
        [(equal? (car lst) target) (ci_tr target (cdr lst) (+ 1 total))]
            ; negative reduction
        [(ci_tr target (cdr lst) total)]
        ))

; so this one will be tail-recursive too
(define (count_instances_deep target lst)
    (ci_deep target lst 0))

(define (ci_deep target lst total)
    (cond
        ; base case
        [(empty? lst) total]
        ; then check equal to target, same as before
        [(equal? (car lst) target) 
            (ci_deep target (cdr lst) (+ 1 total))]
        ; but now we have two options - either the element is a sublist that we have to check, or it is an atom we can skip

        ; element is a sublist - this is regular recursion, but only into a sublist
            ; not that we reset the total for the sublist
        [(list? (car lst))
            (ci_deep target (cdr lst) (+ total (ci_deep target (car lst) 0)))]

        [else (ci_deep target (cdr lst) total)]
        ))