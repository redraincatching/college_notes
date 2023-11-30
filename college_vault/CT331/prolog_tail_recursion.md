# tail recursion prolog
## tail recursion
only one recursive call - the last goal of the last clause in the procedure
the goals preceeding the recursive call must be deterministic so that no backtracking occurs

## everse a list
### base case:
empty list -> empty list

### reduction:
reduce towards empty list by reversing the tail
```prolog
reverse(T,L)
```
add head of list to a new list using merge/conc already defined
```prolog
conc(L, [H], R)
```

### prolog
```prolog
reverselist([], [])

reverselist([H|T], R) :-
	reverselist(T, L), conc(L, [H], R).

% not tail recursive though
```

### tail recursive version
use temporary list to add each successive head value
use a helper funciton reverse2 with empty list as current value of temporary list

#### base case:
\[\] -> \[\]

#### reduction:
add head to Temp for each call of reverse2

#### prolog
```prolog
reversetr(L, R) :-
	reverse2(L, [], R).

reverse2([], R, R).
	% once we've emptied the imput, we have the answer

reverse2([H|T], Temp, R) :-
	reverse2(T, [H|Temp], R).
```


> #paradigms #prolog 