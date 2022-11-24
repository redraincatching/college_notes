# <stdio.h> and Standard Functions

### scanf_s

first input is format text, which tells scanf_s what input to expect, and how to parse it, then the names of the variables where the data will be stored

```c
scanf_s("%f %f %f", &grade1, &grade2, &grade3);
	// the & gives the address in memory where the variable is stored (in hex)
```

### Comments

```c
// this is a single-line comment

/*
this is all commented out, between the asterisks
*/
```

### Maths Operators

```c
+    // add
-    // subtract
/    // divide
*    // multiply
%    // modulus
```
---

#### Assignment vs. Relational Operators

```c
=    // assignment operator - assigning a value to a variable

==   // comparison - checks if rhs evaluates to lhs
		 // no bool type in c, 1 is true, 0 is false
```

**Relational Operators**

```c
==    // equal
>     // greater than
<     // less than
>=    // greater than or eequal to
<=    // less than or equal to
!=    // not equal
```
---

## if/else statements

```c
if (thing) {
	// do a
}
else if (other thing) {        // will be passed down this line until condition is
	// do b                      // true, then executes, then break. 
}                                  // note: this will not check subsequent else ifs
else {
	// do c
}

/* 
*    two-condition if statement?
*    either use nested statements, or (recommended) use &&, the AND operator
*/
```
---

### Boolean Logic

Boolean algebra is a form of algebra where all variables are true or false

Operators
-   AND - &&
-   OR - ||
-   NOT - !
-   XOR - !=
-   NAND - !&
---

### Switch Statements

→ test the value of a variable against multiple cases
→ if not found, default is executed
→ compiles really quickly

```c
switch (expression) {        // expression must return an int
	case value1:
		// thing
		break;                   // break is vital
	case value2:
		// other thing
		break;
	// [...]
	default:
		// default thing
		break;
}
```

---
**Characters**

```c
char c = 'a';        // note: single quotes are necessary for a character
printf("character \\'%c\\' represented by value %d \\n", c, c); 
		// finds the UTF (Unicode) value of the character
```
[[c_variables#Data Types|Characters are also data types]]

> #c #programming 