#lang racket
(provide tail_fact)

(define (tail_fact num)
    (tfact num 1)) ; helper function

(define (tfact num total)
    (cond
        [ (= num 1 ) total] ; base case return
        [ else (tfact (- num 1) (* num total))]
        ))

    ; the running total is passed down through recursions so the function can simply operate on it as it goes