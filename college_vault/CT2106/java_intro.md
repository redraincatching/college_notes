# java introduction
topics to be covered
- classes, objects, methods
- primitive and reference types
- object interactions
- arrays, collections, iterations
- modelling decisions
- inheritance
- polymorphism & the open-close principle
- composition
- java libraries
- interfaces
- unit testing and exception handling
- using design patterns to solve oop problems

## object-oriented programming
3 m's
modelling, modularity, maintenance

### c vs. java
```c
#include <stdio.h>

void main() {
	printf("hello");
}
```
```java
public class Greeting {
	public Greeting() {
		System.out.println("hello");
	}

	public static void main(String[] args) {
		new Greeting();
	}
}
```

## class vs object
### class
- something from which you create an object
- a template of sorts
### object
- a self-contained component consisting of methods and properties
- a specific piece of code that has a state (field) and a behaviour (method)
-> created in code by _instantiating_ a class

#### bytecode
java is not compiled into machine code, but rather into bytecode, which is interpreted and executed by a java virtual machine, or a jvm
this is platform independent
pro - more versatile than c
con - slower execution than c


> #java #programming 