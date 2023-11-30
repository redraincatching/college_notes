# prolog
## logic programming
a series of assertions written in the language of formal logic
results are derived by symbolic reasoning

in general, most logic programming is based on
- horn-clause logic
- negation-as-failure
- backwards chaining

### horn-clause logic
in logic, a clause is formed from a finite collection of literals
a clause is called a horn clause if it contains at most one positive literal
- definite clause has exactly one
- negative clause has none, also called a goal

### negation as failure
failure of unification is treated as establishing the negation of a relation
- closed-world logic

e.g. if bono isn't in our database and we asked if he was irish, prolog would reply "no"

### backwards chaining
an algorithm that works backwards from the goal, chaining throuhg rules to find known facts that support the proof
follows classical depth-first search

## different perspectives of logical programming
- computation as deduction
- theorem proving
uses the notion of an automatic theorem prover as an interpreter
note that the proof must be constructive, so not just t/f
- non-procedural programming
- doesn't specify how to do something, just what to do
	- so the programmer specifies:
		- the set of objects involved
		- the relationships that hold them
		- the constraints which must hold for the problem to be solved
	- and the language or interpreter decides how to satisfy them

---

## prolog - programming en logique
- weakly typed
- no data or functional abstraction
- no mutable state
- no explicit control flow (get rekt goto)

used to solve problems involving objects, and relationships between them
the basics:
- facts
- questions
- variables
- conjunctions
- rules

declaring facts, declaring rules, and asking questions about objects and their relationships

### syntax
prolog is a database of clauses
these clauses can be:
- facts
- rules
- relations
the db is queried

### abstractions
data structure:
- list
control:
- recursion
- ordering of clauses
- built-in control facilities:
	- cut (should be avoided)
	- fail
	- not

### features
(clocksin and mellish)
several dialects
syntax relatively easy but hard to write efficient programs
performs a task in response to a query from the program
a question provides a conjunction of goals to be satisfied
uses known clauses in the db to try to satisfy the goals

### facts and backtracking
a fact can cause a goal to be satisfied immediately, whereas a rule can only reduce the task to that of satisfying a conjunction of sub-goals
a clause can only be used if it matches the goal under consideration
if a goal cannot be satisfied, ***backtracking*** will occur

#### backtracking
consists of reviewing what has been done and attempting to satisfy the goals in an alternative way

> prolog attempts to satisfy goals in a ltr-ttb manner

#### simple facts
statements which are true in a given knowledge base
we can represent the fact that it is sunny by writing the program:
```prolog
sunny.
```
we can now ask a query of prolog by asking
```prolog
?- sunny.
```
?- is the prolog prompt
the output here will be "true" or "yes", depending on the flavour of prolog

#### syntax rules for facts
- begin with a lowercase letter
- end with a full stop
- any combination of letters, numbers, and \_

#### facts with arguments
more complicated facts consist of a relation and the items that this refers to
- facts can have an arbitrary number of the arguments
model:
```prolog
relation(<arg_0>, <arg_1>, ..., <arg_n>).
```

---

### programming in prolog
load facts/rules into the interpreter
make queries to see if a fact is in the logic database (or can be inferred)

### rules
```prolog
head :- body
```

head is true if body is true

#### logical operators
, - and
; - or

> rules are used for dependence
> i use an umbrella if it is raining
>
> they are also used for definitions
> man is a featherless biped

### formulating rules
joe likes anyone who likes computers
joe likes x if x likes computers
```prolog
likes(joe, X) :- likes(X, computers)
```

---

### variables and unification
when querying a db, to match arguments we need a variable
these start with an uppercase letter
the process of matching them with arguments is called unification

#### unification
occurs
- implicitly when prolog searches for the head of a clause that matches a goal pattern
- explicitly using the = symbol

#### variable scope

```prolog
likes(joe, X) :- likes(X, computers),
	 likes(X, cars).
```

X is instantiated inside the rule, in likes(X, computers)
it is checked again in the second likes, and is then returned

essentially variable scope is per function

```prolog
func(X) :- 
	red(X),
	blue(X).
func(X) :-
	blue(X),
	green(X).
```

these two functions have two entirely unrelated variables, they just happen to look the same

---
### lists
\[a, b, c, d\]

different notation
```prolog
[head | tail]
		% head can be anything, tail must be a list
	[]  % empty
```

#### unification with lists
when \[X|Y\] is unified with a list
- X is bound to the head
- Y is bound to the tail list

##### examples
```prolog
?- [H | T] = [a, b]     
?- [H | T] = [[a,b], c, d, e]

% > H = a
%   T = b
% > H = [a,b]
%   T = [c,d,e]
```

#### control
depth first search
prolog picks the rules in order from top to bottom, and literal clauses left to right
it also works sequentially
control relies heavilly on being able to backtrack to decision points
execution can be very inefficient
have to write predicates that minimise both the search time and memory usage
-> similar to heuristic optimisation in relational db, most restrictive queries first to minimise the relations to check

#### membership in lists
recursive function
X is a member of a list if X == H || X == T

##### base case
```prolog
membr(X, [X|T])
```
##### reduce
```prolog
member(X, [H|T]) :- membr(X, T)
```

// essentially, check the head of the list, then to check the tail move to the second rule

##### using anonymous variables
anonymous variable - _
usable for any variable only referred to once

could rewrite these rules as
```prolog
member(X, [X|_])
member(X,[_|T]) :- member(X, T)
```

the anonymous variable is useful here for legibility, the first rule only deals with the head, so we can ignore the tail, and so on

#### deletion from a list
representation
del(X, L, L1)
	// delete x from list L resulting in L1
for example, if del is suitably defined
```prolog
?- del(a, [c, d, a, f], R).
```
##### base case
if x is head of L, result of deleting X is tail of L
##### reduction
add head of L to res and delete X from tail of L

##### strict prolog
```prolog
delete_one(Term, [Term | Tail], Tail)
% the base case
% because of ordering, the next versions only get checked if this is false

delete_one(Term, [Head | Tail], [Head | Result]) :-
delete_one(Term, Tail, Result)
% the recursion

% missing one clause - element not in list
% need another clause at the start
delete_one(_, [], [])
% wild card to match whatever, and if empty list, empty list
```

but this only deletes one instance, how do we delete every instance?
##### base case:
if L is empty result is \[\]
##### reduction:
- if X is head of L then delete X from tail of L
- if X is not head, add head of L to Res and delete X from tail of L

```prolog
delall(_, [], []).

delall(Term, [Term | Tail], Res) :-
	delall(Term, Tail, Res).

delall(Term, [Head | Tail], [Head | Res]) :-
	delall(Term, Tail, Res).
```

#### remove duplicates from a list
representation
deldups(L, Res)

delete duplicates of all elements from list L resulting in Res

##### base case:
empty list, result is empty list

##### reduction:
if the first element in the list is a member of the tail of the list, remove it and check the tail
otherwise, add it to the result and then check the tail

##### prolog
```prolog
deldups([], []).

deldups([H|T], Res1) :-
	membr(H,T), deldups(T,Res1).

// if we get here, membr was false so we know we can add the head to the result
deldups([H|T], [H|Res1]) :-
	deldups(T, Res1).
```

---

### arithmetic equality
not unification
```prolog
?- X = 4 + 5

> 4 + 5
```

need to use the "is" operator

note:
can do ``` [H | T] ```, but can also do ``` [A, B | T] ``` , which will only work if the list contains at least two elements

> #paradigms #prolog