# Loops
useful for repeating tasks

## while loops
→ repeats a task while a condition is true

```c
// syntax
    while (condition) {
        // do thing
    }

    // note, if using a variable as a counter, you can use [variable]++;
    // counter has to be initialised before the loop begins, i think
    // to increase it at the end of a loop
        // this is used to avoid infinite loops
```

### do while loops

→ variant on while loops

```c
// syntax
    do {
        // do thing
    } while (condition);

    // when you want to cause the action first, then enter the loop
        // ensures that the block of code is executed at least once
```

---
## For loops

useful if we want to repeat something a predetermined amount of times
&nbsp&nbsp&nbsp&nbsp→ possible with a while loops, but for loops are shorter

>steps 
>1. initialise variable 
>2. test + loop 
>3. increment 

>for
>1. test + loop

```c
    // syntax
    for (int i = 0; i < [max]; i++) {   // we can also initialise beforehand
        // do something
    }

    // useful for loops: when printing a variable, such as the counter here,
    // you could use printf("%d", i+1); to increase human readability
        // (arrays start at 0)
```

> #c #programming 
> [[c_standard_input-output_library]]