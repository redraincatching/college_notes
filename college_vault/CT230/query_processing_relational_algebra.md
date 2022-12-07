# query processing and relational algebra

## query processing - definition
transforming sql, a high-level language, to a correct and efficient lower-level language representation of relational algebra

each relational algebra operator has code associated with it (a program) which, when run, performs the operation on the data specified, and outputs a result

### steps involved in processing a query
- process (parse and translate)
create an internal representation of the query - may be an operator tree, a query tree, or query graph
- optimise
- execute

#### how to translate
must have a meaningful set of relational algebra operators
must also have a mapping between these operators and sql queries

---

## two formal languages exist for the relational model
- relational algebra (procedural) 
- relational calculus (non-procedural)
// both are logically equivalent
// the implementation is sql

## relational algebra operations
a basic set of operations exist for the relational model
these allow for the specification of basic retrieval requests
a sequence of these operations forms a relational algebra expression
these expressions are divided into two groups
- operations based on set theory
- operations specific to relational databases

### sql vs ra
sql is declarative
-> you can specify the results you wish, not the order of operations required to retrieve them
ra is procedural
-> you must specify exactly how to retrieve the results

## ra expressions
a valid ra expression is built by connecting tables or expressions defined by unary or binary operators, and their arguments (where applicable)
temporary relations resulting from an expression can be used as input for further expressions
brackets are evaluated first

### unary operators
- selection
- projection
- rename
- order
- group

each one takes one relation (table) or expression as input, and gives a new relation as a result

ReLaX calculator: https://dbis-uibk.github.io/relax/calc/local/uibk/local/0

#### selection
operator: sigma, σ
used to select certain tuples (rows) from a relation R
usage:
$\sigma _p R$
where p = a selection predicate (a condition)

// note: not the same as SELECT, SELECT is more powerful
// degree of a relation resulting from selection from a table R is equal to the degree of the table; e.g. the no. of columns stays the same

#### projection
operator: pi, π
used to return certain attributes/columns
usage:
$\pi (a_1, a_2, ..., a_k) R$
where:
	- a_k are attributes of R
	- R is a relation
result:
	relation with the k attributes listed in the same order they were in the original table
	duplicate tuples are discarded

#### rename
operators: rho, ρ, ←
notation:
$\rho_x (E)$
where:
	- the result of the expression E is given the name x

#### order
operator: tau, τ
used to order certain columns from a given relation R
notation:
$\tau (a_1, a_2, ..., a_k) R$
where:
	$a_k$ are attributes with either asc or desc
e.g.
	τ lname asc (π fname, lname employee)

#### group by
operator: gamma, γ

#### supported aggregate functions
COUNT(\*)
COUNT(column)
MIN(column)
MAX(column)
SUM(column)
AVG(column)
// not technically part of relational algebra

### binary operators
general syntax:
```relational algebra
(<child_expression>) <function> <args> (<child_expression>)
```

#### union
operator: U
syntax: (R) U (S)
returns all tuples from tables R and S, no duplicates

#### intersection
operator: n
syntax: (R) n (s)
returns all tuples from R that are also in S

#### set difference
operator: -
syntax: (R) - (S)
returns tuples in R but not in S
// not commutative

> /*
> union compatability
> for union, intersection, and minus, relations must be union compatible
> that is, schemas of both relations must match
> i.e. same number of attributes with corresponding domains
> */

#### cartesian product
operator: x
syntax: (R) x (S)
returns tuples comprising the concatenation of every tuple in R with every tuple in S
![[cartesian_0.png]]
![[cartesian_1.png]]

#### join
operator: ⨝
syntax: (R) ⨝ \<att1>=\<att2> (S)
combination of cartesian product and select
tables are joined together based on the specified condition

#### equi and theta joins
equi joins only use = in the join condition
theta allows for comparisons such as >= 

> #databases #sql #relational_algebra