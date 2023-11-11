(provide sequence)
(define (sequence num)
    (if
        (< num 1) '() 
        (append (sequence (- num 1))) (list num)
        ))