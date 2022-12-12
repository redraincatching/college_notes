# interfaces
similar to a class
can be used as a type
names often end in -able by convention

more like an outline of what methods a class should have

interface example
```java
public interface Eatable {
	
	public int getCalories();
	
	public int extractEnergy();
}
```

// fields can be input in the latest version of java, they are treated as public static final
// we won't worry about that for now

> **comparable interface**
> built in compareTo() method
> compares two objects

any class that wants to implement an interface needs to use the keyword implements in the class declaration
example
```java
public class Bombay extends Cat implements Predator {
	//...
}
```

> #java #programming 