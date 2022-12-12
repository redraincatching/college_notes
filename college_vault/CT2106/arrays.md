# arrays
if you use a superclass as a reference type, all subclasses can be entered
e.g. Animal array can store Canary, Shark, Cheetah, etc.

array.length returns length

implicit use of toString
in general, java will look for toString when it is required to print an object

```java
System.out.println(animals[i]);
``` 
will look for a toString method for all of these

## enhanced for loops
you can loop over a full array with the below syntax
```java
for (Animal a: animals){
	System.out.println(a);
}
```

a regular for loop increases the integer, and accesses the array through the index

an enhanced for loop starts by declaring the type of data stored in the array
then you create a temporary variable which is used to loop through this array
then, after a colon, the name of the array
the temp variable is then equal to the value of each element in the array

// NOTE: only goes beginning to end 

> #java #programming 