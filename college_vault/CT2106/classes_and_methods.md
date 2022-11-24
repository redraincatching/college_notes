# classes
## constructors
"create" an instance of a class, and can take arguments

## methods
all written below the constructor
inbuilt functions in a class
### accessor methods
retrieve data from a class
### mutator methods
change data in a class

#### access modifiers
also called a visibility modifier
change the scope of a given class, method, field, or constructor
4 levels
- private
only within the class, and cannot be accessed from outside
- default
only within the package
- protected
within the package, and outside by child classes
- public
everywhere

/\*
notes:
when declaring a float, append f, or else it will be declared as a double
\*/

---
## class structure
every class has the following structure

```java
<access modifier> class <name> {
	<fields>
	<constructors>
	<methods>
}
```

### fields
store values for an object
known as _instance variables_
fields define the state of the object

### constructors
- initialise an object
- no return type keyword
- have the same name as their class
- close association with the fields
	- initial values are stored in the fields through this
	- parameter values often used for this

two ways to implement constructors
- different naming scheme
```java
public bicycle(int gr, int spd) {
	gear = gr;
	speed = spd;
}
```
- "this" keyword
```java
public bicycle(int gear, int speed) {
	this.gear = gear;
	this.speed = speed;
}
```

### methods
implement the behaviour of an object
have a consistent structure of header and body
#### header
```java 
public int get_speed()
```

- visibility
- return type
- name
- arguments

#### body
```java
... {
	// do code
	return x;
}
```

- encloses the method's statements

> #programming #java