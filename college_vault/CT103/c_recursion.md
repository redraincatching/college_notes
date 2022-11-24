# [[recursion|recursion]]
method of problem solving by reducing them to smaller problems, that resemble the form of the original problem
-> can make code more readable
-> a recursive function is one that calls itself

recursion can lead to an "infinite" loop quite easily
// well, until a stack overflow crash, at least

```c
int fibonacci(int n){
    if (n<=1) {
        return n;   // cause the first 2 terms are 0 and 1
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
```

often less efficient than loops, but certain problems (e.g. towers of hannoi) can be solved more easily this way
-> the lack of efficiency comes from abuse of the stack

> #programming #c