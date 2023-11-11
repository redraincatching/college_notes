; a recursive and tail-recursive version of a function that reverses a list

; normal recursive
(define (reverse_list lst)
    (if (empty? lst)
        '()
        (append (reverse (cdr lst)) (list (car lst)))
    )
)


; tail recursive

; helper
(define (rev_list lst)
    (t_rev_list lst '())
)

(define (t_rev_list lst res)
    (if (empty? lst)
        res
        (t_rev_list (cdr lst) (append (list (car lst)) res))
    )
)

; so that line is
; res = 1st in lst + curr
; cdr of lst get passed to the next call

; given '(a b c d) we could fill in the variables on the first round as
; rev '(b c d) append '(a) '()