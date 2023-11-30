# data structures in lisp
## binary search trees
data structure to store an ordered set of items
- fast lookup
- fast addition and removal
- can be used to implement
	- dynamic sets of items
	- lookup tables that allow finding an item by its key

### rules
- no duplicates
- maximum of 2 child nodes
- left child is smaller than the parent, right is larger

each leaf node is also a bst, a subtree
smallest possible subtree is null

bsts kep their keys in sorted order, so that lookup and other operations can use the principles of binary search
on average, this means each comparison allows operations to skip about half the tree
- not as fast as a hash table
- much faster than linear search

### operations
- searching
- insertion
- deletion
- traversal
- verification

#### search
```lisp
if curr == null?
	t: item not in tree
	f: continue
if curr == target
	t: return, found
	f: continue
if target < curr
	t: recurse on left
	f: recurse on right

```

#### insert
```lisp
if curr == null?
	t: insert
	f: continue
if curr == insert
	t: return, no duplicates
	f: continue
if insert < curr?
	t: recurse on left
	f: recurse on right
```

#### delete
```lisp
if curr == null?
	t: return, not in tree
	f: continue
if curr == target
	t: move to delete operation
	f: continue
if target < curr
	t: recurse on left
	f: recurse on right

delete
	if node has no children
		just delete
	if has one child
		set node value to child value
		delete child
	if has two
		copy in-order successor to node
		delete ios
```

> #paradigms #lisp 