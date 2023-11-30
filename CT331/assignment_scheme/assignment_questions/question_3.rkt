#lang racket

(provide 
    traverse_inorder
    search
    insert
    create_tree
    tree_sort
    tree_sort_high_order
    mirrored_tree
    ascending_last_digit
    descending_last_digit
    )

; not going to bother checking this every time but imagine i do
(define (is_tree? tree)
  ; remember, the shortest valid binary tree is empty
  (or (empty? tree)
      (and
       ; check that the tree is a list and is of length three
       [and
        (list? tree)
        (= (length tree) 3)]
       ; check that the branches are trees
       [or
        (is_tree? (cadr tree))]
       [or
        (is_tree? (caddr tree))])))

; in-order step through of a binary search tree
;   inorder algorithm
;       left subtree
;       current
;       right subtree
; display is annoying so we're going with returning the inorder list
(define (traverse_inorder tree)
    (cond 
        ; base case
        [(empty? tree) '()]
        [else
            ; append (left subtree) root (right subtree)
            (append
                (traverse_inorder (cadr tree))
                (list (car tree))
                (traverse_inorder (caddr tree)))]
))


; check if element is in a given tree
; assuming it is a binary tree
(define (search target tree)
    (cond
        [(empty? tree) #f]
        [(= target (car tree)) #t]
        [(< target (car tree))
            (search target (cadr tree))]
        [(> target (car tree))
            (search target (caddr tree))]
             ))

; insert into a tree
(define (insert el tree)
    ; if the tree is empty, return a new tree
    (if (empty? tree) 
        (list el '() '())
        ; if the item is already in the tree, return the unmodified tree
        (if (search el tree)
            tree
            ; otherwise traverse
            (cond
                ; i'd like to make this tail-recursive but since lists are immutable i don't know how to do that
                [(< el (car tree))
                    (list (car tree) (insert el (cadr tree)) (caddr tree))]
                [(> el (car tree))
                    (list (car tree) (cadr tree) (insert el (caddr tree)))]
              )
            )))
    
(define (create_tree lst)
    (define (ct lst current)
        (cond
            [(empty? lst) current]  ; base case
            [(ct (cdr lst) (insert (car lst) current))] ; reduction
            ))
    (ct lst '()))
    
(define (tree_sort lst)
    ; i like this one
    (traverse_inorder(create_tree lst)))


(define (tree_sort_high_order lst compare-func)
    ; picks a function and sorts based on that
    (define (create_tree_high_order lst)
        (define (ct_ho lst current)   
            (cond
                [(empty? lst) current]
                [(ct_ho (cdr lst) (insert_high_order (car lst) current compare-func))]
                ))
        (ct_ho lst '()))

    (define (insert_high_order el tree compare-func)
        (if (empty? tree)
            (list el '() '())
            (cond
                ; if whatever comparison returns true
                [(compare-func el (car tree))
                    (list (car tree) (insert_high_order el (cadr tree) compare-func) (caddr tree))]
                [else
                    (list (car tree) (cadr tree) (insert_high_order el (caddr tree) compare-func))]
                )))
    ; pretty much everything i here is a slightly modified version of another function
    (traverse_inorder(create_tree_high_order lst)))

(define (mirrored_tree a b)
    (> a b))

(define (ascending_last_digit a b)
  (< (remainder a 10) (remainder b 10)))

(define (descending_last_digit a b)
  (> (remainder a 10) (remainder b 10)))