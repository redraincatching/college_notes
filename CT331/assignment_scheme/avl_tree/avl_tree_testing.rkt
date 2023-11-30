#lang racket
(require rackunit)
(require "avl_tree.rkt")

(is_tree? '(5 (1 null null) (9 (6 null null) (10 null null))))



; going to change this later to common lisp