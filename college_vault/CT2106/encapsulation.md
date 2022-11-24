# encapsulation

principle 1 of object oriented programming - encapsulation
the variables of a class should be hidden from other classes, and should only be accessible through their own methods
"data hiding"
each object is responsible for its own data

see: [[classes_and_methods#access modifiers|access_modifiers]]

## c vs java
![[c_vs_java.png]]
- unlike c, an oop program will not have a pool of global variables that each method can access
- each object has its own data, and others use accessor methods to access it

accessor methods receive data, mutators alter data
basic form of both, the _getter_ and _setter_ methods

a setter does not have to assign unconditionally to the fields, these parameters may be checked for validity
-> protective mutators

#### printing
System.out.println();
closer to puts than printf, although supports string concatenation
follows whatever it prints with a newline character
e.g.
System.out.println("the winner is " + winner + "!");
System.out.printf();
(shockingly) more similar to printf
no newline character added automatically
e.g.
System.out.printf("you win €%d!\\n", amount);

like c, java follows this format for its format specifiers
%\[flags\]\[width\]\[.precision\]conversion-char

// note, java supports %n as well as \\n, which prints a system-specific newline character
// %S will print an uppercase string
// the - flag will left-justify the string
// %e outputs scientific notation

> #java #programming