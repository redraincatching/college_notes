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
