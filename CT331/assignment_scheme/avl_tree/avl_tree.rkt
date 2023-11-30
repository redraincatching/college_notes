#lang racket
(module avl_tree racket 
    (provide all-defined-out)

    ; also, this assignment is a little vague, so i'm just going to write an AVL tree from scratch and implement everything asked for in the brief

    ; so our tree will be a list with three elements - (value <left_tree> <right_tree>)
    ;   as we know, a subtree can be null, otherwise it's another tree
    ;   and leaf nodes are nodes with only a value and no subtrees
    ; (4 (6 5 7) (2 1 3))   is a bst
    ; since we know that each tree is a list with a predetermined structure, we can simply navigate with cadr and caddr for the left and right

    ; here i'll define some helper functions

    ; note that this only checks if the value is a tree, not a bst
    (define (is_tree? tree)
        ; remember, the shortest valid binary tree is null
        (or (null? tree)
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

    ; these can be accessed with car, cadr, and cddr but for semantics
    (define (get_value tree)
        (car tree))

    (define (get_left_subtree tree)
        (cadr tree))

    (define (get_right_subtree tree)
        (caddr tree))





    ; now for some actual operations on the tree

    (define (height tree)
        ; get the height of the tree
        ; necessary for keeping O(n) small and logarithmic
        (if 
            (null? tree) 0
            (+ 1 (max (height (cadr tree)) (height (caddr tree))))))
    ; the central concept of an avl tree is making sure the left and right branches never have a height difference that exceeds 1
        ; this is called the balance factor

    (define (balance_factor tree)
        ; get the balance factor of a given tree
        (- (height (get_right_subtree tree)) (height (get_left_subtree tree)))
        ; where -2 is a left imbalance and 2 is a right imbalance
        )

    

    ; rotations
    (define (rotate_right tree)
        )

)



