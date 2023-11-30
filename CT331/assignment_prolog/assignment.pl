% the following facts are given
takes(tom, ct331).
takes(mary, ct331).
takes(joe, ct331).
takes(tom, ct345).
takes(mary, ct345).
instructs(bob, ct331).
instructs(ann, ct345).

% 1.1
teaches(X, Y) :-
	instructs(X, Class) , takes(Y, Class).

% 1.5
classmates(X, Y) :-
	takes(X, Class), takes(Y, Class).

% 2.3
contains1(El, [El|_]).

% 2.4
contains2(El, [_|El]).

% 3
% base case: empty list
isNotElementInList(_, []).

% reduction: continue through list if not equal to head
isNotElementInList(Target, [H|T]) :-
	Target \= H, isNotElementInList(Target, T).

% 4
% base case: empty list plus full list is the same as the full list
mergeLists([], List, List).

% reduction: concat head of one with the result
mergeLists([H|T], List, [H|Result]) :-
	mergeLists(T, List, Result).

% and to extend this to three lists just call it twice
mergeLists(L1, L2, L3, Result) :-
	mergeLists(L1, L2, Temp),
	mergeLists(Temp, L3, Result).

% 5
% definitely not taken straight from the lecture notes nope
% helper function to allow tail recursion
reverseList(List, Reversed) :-
	reverse_tr(List, [], Reversed).

% base case: accumulator is full of the reversed list
reverse_tr([], R, R).

% reduction: take the head of L and add it it R
reverse_tr([H|T], Temp, R) :-
	reverse_tr(T, [H|Temp], R).
	% i found this very weird at first, because it's moving from the head to the head, but that's forgetting
	% the fact that temp starts empty

% 6
% base case: inserting into an empty list is just the element
insertInOrder(El, [], [El]).

% base case: element in list, return (not allowing duplicates)
insertInOrder(El, [H|T], [H|T]) :-
	El = H.

% reduction: if el < head, insert, otherwise continue
insertInOrder(El, [H|T], Result) :-
	El < H,
	Result = [El, H | T].

insertInOrder(El, [H|T], Result) :-
	El > H,
	insertInOrder(El, T, RTail),
	Result = [H | RTail].
