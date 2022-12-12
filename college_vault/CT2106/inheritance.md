# inheritance
"is-a" relationships

## class hierarchy
not the unjust kind
topmost classes are the most generic attributes and behaviours
bottommost classes are the most specific

each level inherits and customises the attributes of previous classes

### rules of class hierarchies
the variable type can be the superclass of the object
// any superclass, not just Object

---
## explicit inheritance
all classes inherit implicitly from java.lang.Object
// equals(), toString()

first, decide what is a method and what is a field

### steps
1) create the classes (empty at first)
2) insert the inheritance relationships
	- -> extends keyword
3) insert the fields
4) insert the methods
5) override necessary fields
6) override necessary methods
7) test object by putting them in an array and calling methods

## abstract classes
it may not make sense to have an object of the type superclass
a "bird" doesn't exist, but an ostrich does

public abstract class Bird extends Animal...

however, they can still be used as reference variables

```java
Bird bird = new Bird();                 // error, it's abstract 
Bird canary = new Canary("tweety");     // works fine
```

useful for seeing at a glance that the classes are related

> #java #programming 