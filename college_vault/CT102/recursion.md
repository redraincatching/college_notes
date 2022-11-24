# recursion
"self-reference"

##### computing definition
functions and procedures whose definition involves a reference to themselves

---
## recursion in computing
a problem-solving approach that can solve similar problems to iteration
-> some languages support recursion better than others

### "recursive on all control paths"
problem:
- no stopping conditions, therefore will cause a runtime stack overflow
- such functions are not well defined

### well-defined recursive functions
- halting condition; ***"base criteria"***
- each time the function calls itself, it must get closer to the base criteria; must "reduce"

---
## activations
with recursion, we often have the illusion of multiple copies of the function existing
-> these are known as activations

a number of activations may exist at a given time, although only one is active at any given point

### runtime stack
a stack data structure keeps track of all these activations
-> the function at the top of the stack is the current active one

when the current function completes, it is popped off the stack, and activation moves to the next function on the stack

each activation has its own scope

---
#### recursive tree
a diagram which visualises the recursive calls, and allows for timestep analysis

---
#### general approach for solving problems recursively
1) what is the base case?
2) what should the answer be at the base case?
3) how do you reduce to get to this base case?
4) what other work needs to be done for every function call?
5) how can these steps be put together?

---

###### recursion example - factorial
```c
int factorial (int n){
    if(n <= 1) {
        return 1;
    }
    else {
        return(n * factorial(n-1));
    }
}
```

> #algorithms 