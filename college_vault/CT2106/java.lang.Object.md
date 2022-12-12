# java.lang.Object

superclass of every object in java
all the methods provided by java.lang.Object are generic
they only relate to the class itself, not the subclasses


#### annotation
@Override
lets java know that the method is an overridden verion of one from the superclass
only rule is keep signature the same

---
## object equality
### equals method
- all objects have it
- for built-in classes, it is predefined, but you must write it for any new classes
- return a boolean
- commutative
- called implicitly if it exists and two objects are compared
	- requires @Override 

#### writing a new equals method
compare all fields, return bool

note: the equals method has a standard signature
```java
public boolean equals(java.lang.Object object)
```

this can be implemented for our previous bicycle class like this

```java
public boolean equals(Object object) {
	if(obj == null) {
		return false;
	}

	if (obj instanceof Bicycle) {
		Bicycle bike = (Bicycle) obj;   // casts the passed in object to bicycle

		if (/*compare fields*/) {
			return true;
		}
	}
	return false;
}

```

> #java #programming