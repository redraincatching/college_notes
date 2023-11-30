#lang racket
(require rackunit 
        "question_2.rkt"
        "question_3.rkt")

; unit testing
    ; in this environment, passed tests don't output anything

; question 2

; A
(check-equal? (ins_beg 'a '(b c d)) '(a b c d))
(check-equal? (ins_beg '(a b) '(b c d)) '((a b) b c d))

; B
(check-equal? (ins_end 'a '(b c d)) '(b c d a))
(check-equal? (ins_end '(a b) '(b c d)) '(b c d (a b)))

; C
(check-equal? (count_top_level '(a b c d e)) 5)
(check-equal? (count_top_level '((65 70) c d (100 101 bcdef))) 4)

; D
(check-equal? (count_instances 3 '(1 2 3 3 3 4 5 6 3)) 4)
(check-equal? (count_instances 'd '(d e f g e c d)) 2)    ; the licc

; E
(check-equal? (count_instances_tr 3 '(1 2 3 3 3 4 5 6 3)) 4)
(check-equal? (count_instances_tr 'd '(d e f g e c d)) 2)    ; the licc

; F
(check-equal? (count_instances_deep 'e '(e e (e e e (e e e) e) e e e e e)) 14)
(check-equal? (count_instances_deep 5 '(1 2 (3 (4 5) 6) 7 (8 (9 (10 5) 11)) 12)) 2)


; question 3
(define binary_tree '(5 (3 (2 () ()) (4 () ())) (8 (7 () ()) (10 () ()))))

; A
(check-equal? (traverse_inorder binary_tree) '(2 3 4 5 7 8 10))

; B
(check-true (search 5 binary_tree))
(check-false (search 9 binary_tree))

; C
(check-equal? (insert 8 binary_tree) binary_tree)
(check-equal? (insert 9 binary_tree) '(5 (3 (2 () ()) (4 () ())) (8 (7 () ()) (10 (9 () ()) ()))))
(check-equal? (insert 1 binary_tree) '(5 (3 (2 (1 () ()) ()) (4 () ())) (8 (7 () ()) (10 () ()))))

; D
(check-equal? (create_tree '(5 3 2 4 8 7 10)) binary_tree)
(check-equal? (create_tree '(2 3 4 5 7 8 10)) '(2 () (3 () (4 () (5 () (7 () (8 () (10 () ()))))))))

; E
(check-equal? (tree_sort '(5 3 1 4 2)) '(1 2 3 4 5))
(check-equal? (tree_sort '(10 7 15 3 8)) '(3 7 8 10 15))
(check-equal? (tree_sort '(20 18 16 14 12 10 8 6 4 2)) '(2 4 6 8 10 12 14 16 18 20))

; F
(check-equal? (tree_sort_high_order '(20 18 16 14 12 10 8 6 4 2) mirrored_tree) '(20 18 16 14 12 10 8 6 4 2))
(check-equal? (tree_sort_high_order '(20 18 16 14 12 10 8 6 4 2) ascending_last_digit) '(20 10 12 2 14 4 16 6 18 8))
(check-equal? (tree_sort_high_order '(20 18 16 14 12 10 8 6 4 2) descending_last_digit) '(18 8 16 6 14 4 12 2 20 10))