# data structures
## arrays
random access, see [[c_arrays|c arrays]] and [[js_arrays|js arrays]].
## self-referential structs
structs that contain a pointer to a struct of the same type, or a "link"
-> linked list!
terminated with a NULL pointer

---
### linked lists
- linear collection of structures
- connected by pointers
- accessed via a pointer to the first node, the "head"

#### strengths vs. arrays
- good for dynamically sized collections of data
- excellent at insertion or deletion of any node in the list
#### weaknesses vs. arrays
- sequential access

---
### binary search tree
tree nodes contain two or more pointers to other nodes
-> one or all may be null

the root node is the first in the tree
-> each link a node has is a child
-> each node with no children is a leaf

recursion is a very natural way of operating on trees
-> data is inserted in a particular way to facilitate rapid searching

> #c #programming 