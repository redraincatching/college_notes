# algorithmic analysis
focus: the analysis and comparison respect to resources used, specifically
- space (memory)
- time (to run)

## standardisation
- both programs in the same language
- same compiler
- same hardware
- identical data sets with many edge/corner cases

---

## types of analysis
worst case: maximum number of steps in any instance of size n
best case: minimum number of steps in any instance of size n
average case: average number of steps in any instance of size n, with random input

worst case is often the best to calculate, as it is easiest, it happens, and we know nothing will be worse

---
## 3 approaches
- actual time: code and run
- estimate time: count "steps" in code
- estimate rate of growth of time used: O notation for large input sizes

### actual time
get actual values of time and space
often focus on key operations as well as overall time to run
generally in practice, this is a preemptive check
-> we want an idea of the time and space efficiency before we fully code a solution

#### c approach using time.h
```c
clock_t time = clock();
double time_taken;

// run code

// check time elapsed
time_taken = clock() - time;
// convert to seconds
printf("time taken: %lf seconds", time_taken/CLOCKS_PER_SEC);
```

### counting time steps
estimate the amount of time by summing up time steps
the result is a function, f, which represents these steps, which is usually dependent of the size of the data set, referred to by a constant, e.g. N, and the function is then represented with f(N)

#### what counts as a time step?
- each "simple" statement = 1 step
-> declarations, initialisations, if statements, function calls
- each memory access = 1 step
- loops, function execution, built in libraries are not simple statements

loops:
in a simple case, any statement in a loop is multiplied by the number of iterations
the condition can be taken as 1 step
in for loops, can count everything in a loop guard separately or as one (usual method)

generally, do not count i/o steps

#### characteristics
- gives a good approximation of runtime
- requires effort in counting, and not very generic

### rate of growth analysis
given that n will have different values for each run, it is usually the rate of growth of f(n) that we want to analyse
e.g., with $f(n) = n^3 + 2n + 1234$, it is only as n gets larger that f(n) starts to get very large

#### commonly used rate of growth functions
- $1$
constant time, not n-dependent
- $\log_2 n$
logarithmic, seen in binary search
- $n$
linear
- $n\;log_2\;n$
superlinear, seen in mergesort and quicksort
- $n^2$
quadratic, typically an algorithm with a nested loop, e.g. bubblesort
- $n^3$
cubic, three nested loops
- $2^n$
exponential, some recursive solutions or pathfinding algorithms
- $n!$
factorial, borderline unusable

// note: those last three are huge, and impractical


#### O notation (big O notation, "order")
gives a measure of rate of growth in terms of upper and lower bounds in comparison to some standard functions
// note: ignores coefficients and additive/multiplicative constants

for example:
- n ≡ 2n
- n ≡ n + 500
- $n^2$ ≡ $5n^2$

more formally:
given f(n) for some algorithm;
$f(n)$ is $O(g(n))$ means that it is always possible to find some k such that
$f(n) <= k*g(n)$ for $n >= n_0$
_// $n_0$ is large enough n_
_// k g(n) is an upper bound on f(n)_

##### examples
- f(n) = 3n + 8
-> O(f(n)) is O(n)
- f(n) = (n^2)/2 + 10n + 5
-> O(f(n)) is O(n^2)
- f(n) = 2103
-> O(f(n)) is O(1)

we can define similar functions for the lower bound, Ω (best case), and lower and upper bound, Θ (average case)
// we generally consider the upper bound, O, however

#### dominance relations
O notation can be used to describe the growth rate for any particular algorithm where to coefficients and constants are of little consequence, and what's relevant for large n is the ordering of the rate of growth

###### note on polynomials
any algorithm whose rate of growth is O($n^x$) where x > 1 is said to be of polynomial time complexity
-> though impractical for all practical issues due to massive growth rate, can be useful for small n

#### but what about the constants?
k and $n_0$ are chosen so that for all $n > n_0$, $k*g(n) > f(n)$
![[O_constants.png]]
similar constants can be chosen for Ω (c) and for Θ (c1 and c2)
![[theta_omega_constants.png]]

##### examples
f(n) = 3n + 8
O(f(n)) is O(n), k = 4, $n_0$ = 8

f(n) = $n^4$ + 100$n^2$ + 50
O(f(n)) is O($n^4$), k = 2, $n_0$ = 11

_/\*
these were found just by guessing a k, and graphing f(n) vs O(f(n))
this constants aren't particularly relevant, however, so we often don't need to find them
\*/_

---
### bubblesort analysis

![[bubble_sort_1.c]]
O($n^2$), one of the worst sorting algorithms for general data

> #algorithms 