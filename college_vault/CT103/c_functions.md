# Functions
a piece of code that can be called whenever we need to execute it
why?

-   avoids repetition
-   increases readability
-   enables division of problems
-   easier to maintain

**syntax**
```c
<type> <name> (<arguments>) {
    return;
}
```
---
## Function type

tells the compiler what type of variable the function returns can be a standard type (int, float, double, char) or can be void

// you can't name a function one of the 32 reserved words
![[reserved_words_c.png]]

---
### Function Prototypes

before you can use a function, you have to give it a prototype 
this is done before it is called, usually before main(), and after any \#include or \#define statements

> #c #programming
> [[c_standard_input-output_library]]