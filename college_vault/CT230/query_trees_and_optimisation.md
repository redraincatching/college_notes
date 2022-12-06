# query processing and optimisation


## representing relational algebra with a query tree
-> tree: a finite set of elements (nodes) such that
- the tree is empty, or contains a distinguished node called the root node
- all other nodes are arranged in subtrees such that each node has a parent node

nodes may be:
- root:
no node points to it
- inner:
has parent and child nodes
- leaf:
has parent but no child nodes

_binary tree_: a tree where each node has at most two child nodes

## the query tree
a binary tree that corresponds to a relational algebra expression where
- input (the tables) are the leaf nodes
- operators are internal nodes
- output (the result) is the root node

order of operations is leaf to root, and left to right (both **ltr**)

---
## translating sql to relational algebra
SELECT attributes correspond to π
joins correspond to ⨝ joins, with any conditions specified as part of the join
any WHERE conditions correspond to σ

### executing the query tree
traverse ltr, replacing the internal operation with a leaf node containing the resulting table which can be used as input for other operators or the output

note: operators are unary or binary, so if an operation takes more than two operands, it's wrong

### annotating the tree
each ra operation can be evaluated using several different algorithms, and can even be evaluated several different ways
therefore, an evaluation plan, an annotated expression or tree specifying the execution strategy is necessary

#### dbms catalog
the dbms catalog stores statistical information about each table, such as sizes, depths, and indexes
this information can also be used to calculate the cost of a query

for each relation R, data is stored on
- the number of tuples stored
- the number of blocks containing tuples of table R
- the size of a record in bytes
- the [[file_organisation#blocking factor|blocking factor]]
- information on the number of distinct values per attribute
- the number of values that would satisfy equality operations (stores averages, min, max, etc.)
- information on indices

---
## issues to consider with query trees
- size of temporary tables
- algorithms used for the evaluation plan

### optimisation
- different query trees for a given expression have different costs
- different evaluation plans have different costs

there exist different techniques to choose the lowest overall cost

>/*
>calculating cost
>cost factors include cpu speed, network communication time, and predominantly, disk access time
>disk access can be measured by the number of blocks read and written to during a query, so this is the main cost estimate used
>
>the number of blocks transferred depends on the size of the buffer in memory, the indexing structures used, andwhether all blocks of a file must be transferred or not
>
>as is typical in computing, we often use worst-case estimates
>*/

#### approach 1: cost-based bruteforce
cost is usually measured as total time spent executing a query
one approach is to calculate all possible cost estimates, and choose the lowest

##### steps:
- generate query trees and plans
- get cost estimates using dbms catalog

this results in a set of cost estimates from which the best can be chosen

the estimates for cost also involve the size of the tables that result from any given operation, and if they are sorted

this is effective, but expensive
// note: it is important that the time it takes an optimiser to calculate the best solution and execute it not exceed the time it would take to simply execute a solution at random

#### approach 2: heuristic optimisation
transforming the query tree using a set of rules that typically (but not always) improve performance
some cost-based estimation is also performed

##### steps:
- create a **canonical query tree**
- apply a set of heuristics to it to create a more efficient query tree
- create cost estimates, if appropriate, to ensure the best evaluation plan

>/*
>canonical query tree:
>an inefficient query tree representing relational algebra expressions which can be created directly from the sql query
> - uses cartesian product rather than joins
> - keeps all conditions (σ) together in one internal node
> - π is root node
> 
>*/

##### creating a canonical query tree
- all relations specified in FROM become leaf nodes, which are then joined by cartesian products
- all conditions in WHERE and any JOINs become a sequence of relational algebra expressions in one inner node of the tree
- all conditions in select become an expression in the root

e.g. 
```sql
SELECT fname, lname
FROM employee, department
WHERE dno = dnumber AND
	dname = "Research";
```

// to canonical query tree
![[canon_0.png]]

// this would be very inefficient if executed directly, due to the use of cartesian products

heuristic optimisation attempts to apply the most restrictive operation early on (i.e. as low as possible in the tree) to reduce the size of the temporary tables that are stored as soon as possible
it must also have set rules for equivalence among expressions

###### algorithm:
**input**: canonical query tree
**process**:
- decompose any σ with AND conditions into individual σ
- move each σ operator as far down the tree as possible
- rearrange the leaf nodes such that the most restrictive σ can be applied first (using data from dbms catalog) and so that future joins are possible
- combine x with σ to form ⨝ (replace all x)
- decompose π and move as far down the tree as possible, possibly creating new π in the process
- identify subtrees that represent groups of operations that can be executed by a single algorithm
- add evaluation plan
**ouptut**: efficient query tree

// using prior query tree
1) decompose σ and move down tree
	part of σ can be moved before a x, so do that
	![[canon_1.png]]
2) rearrange leaf nodes
	if we have no dbms cat information, we may leave nodes as they are, or use schema and sample data (no. of columns and rows) to estimate
	![[canon_2.png]]
3) replace x with ⨝
	first, make sure leaf nodes are in a position where this is viable
	if not, rearrange
	![[canon_3.png]]
4) move π down tree
	eliminates unwanted columns -> check to see if π can be moved before joins
	can add additional joins so long as you do not remove any columns that are necessary further up the tree
	![[canon_4.png]]

> #databases #sql #relational_algebra 