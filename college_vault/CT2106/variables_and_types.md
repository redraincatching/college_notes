# variables and types
in a _strongly typed_ language, you have to tell the compiler what type every variable is
this allows the compiler to allocate memory for them

## java primitive types
- boolean - 1 bit
- byte    - 8 bits
- short   - 16 bits
- char    - 16 bits
- int     - 32 bits
- long    - 64 bits
- float   - 32 bits
- double  - 64 bits

each primitive variable has a default value
this is only assigned when the variable is used as a field, an instance variable, and there are no explicitly assigned values
all either 0, 0.0, false, or '\\u0000'

## reference/object types
a data type based on a class
four categories:
- object types
- interface types
- enum types
- array types

a reference type points to the location of an instance of a class of that type
primitives contain the value themselves

e.g.
```java
Wheel wheel = new Wheel();
// wheel is a pointer to the new Wheel object
```
default reference value is null

> null_pointer_exception
> when the program encounters an uninitialised reference variable

### memory leaks
if you initialise an object, and then "lose" the reference, for example by setting the pointer to null, the objects still occupy memory, despite not being useable. this is a memory leak
there's actually no way to deallocate memory manually in java

### garbage collector
part of the jre management system
runs in the background, keeping track of live objects and marking the rest as garbage
data marked as garbage is subsequently deleted

> #java #programming 