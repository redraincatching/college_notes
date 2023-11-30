#lang racket
(provide maxlst)

(define (maxlst lst)
    (cond 
        [(null? lst) (display '(empty lst))]
        [(null? (cdr lst)) (car lst)]
        [ (> (car lst) (cadr lst))
            (maxlst (cons (car lst) (cddr lst)))]
        [ else (maxlst (cdr lst))]
    ))

(maxlst (list 1 2 3 4 69 4 5 6 7 8))
