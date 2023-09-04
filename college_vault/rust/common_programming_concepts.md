# common programming concepts
## variables and mutability
variables are immutable by default, and can be declared with 'let', and are made mutable with the 'mut' keyword

### constants
declared with the const keyword
not just immutable by default, constantly immutable
type must be annotated, e.g.
```rust
const THREE_HOURS_IN_SECONDS : u32 = 60 * 60 * 3;
```
this is annotated as an unsigned 32-bit integer

const expressions, like the multiplication above, can be evaluated at compile time, and so are allowed in constant instantiation
these include expressions such as literals, arrays, paths to functions and parameters, casts, and so on. these simple expressions can be evaluated by the compiler

### shadowing
declaring a new variable with the same name
this basically creates a new variable that "overshadows" the first, taking precedence until the program or its scope ends
example:
```rust
fn main() {
	let x = 5;
	let x = x + 1;
	{
		let x = x * 2;
		println!("The value of x in the inner scope is: {x}");
	}
	println!("The value of x is: {x}");
}
// prints out 12, then 6
```

shadowing is different from marking a variable as mut, because it creates an entirely new variable. this is relevant because rust is statically typed, and this allows for a type pseudo-reassignment, like this:
```rust
let spaces = "   ";
let spaces = spaces.len();
```
whereas just declaring
```rust
let mut spaces
``` 
would cause a compiling error

---
## data types
every value of rust is of a certain data type
we'll look at two subsets of data types: scalar and compound

### scalar types
representing a single value

#### integers
signed or unsigned, prefixed with i or u, followed by a specific value, 8 - 128
signed are stored with 2's complement
another option is isize or usize, which depend on the architecture of the system it's running on, so on 64-bit architecture it would work the same as i64 or u64

integer literals can be written using _ as a visual separator without changing the value

integers default to i32

numbers can be specified in other bases, as follows
- decimal:  12345
- hex:      0xabcdef
- octal:    0o34567
- binary:   0b1111_0000
- byte:     b'A'

#### floating-point
f32 and f64, both signed
all algned to ieee-754 standard
defaults to f64

#### boolean
as normal

#### character
single quotes
4-byte unicode scalar, so yes, emojis are supported

### compound types
#### tuples
declared with round brackets
a general way of grouping variables of multiple types
fixed length
```rust
let tup: (i32, f64, u8) = (500, 6.4, 1);    
// note: these type annotations are optional
let (x, y, z) = tup;    
// allows binding to single variables, called destructuring
```

can access tuple elements via indexing, such as
```rust
let tup = (500, 6.4, 1);
println!("the second value of the tuple is {x.1}");
```

a tuple without any values is called the unit
this value and its corresponding type are both defined with ()

#### arrays
fixed length, declared with square brackets
// vectors are a similar data type that have a variable length
type annotation done as follows
```rust
let a : [i32; 5] = [1, 2, 3, 4, 5];
// five elements of type i32
let a = [32; 5];
// 32 five times
```
// the difference is before and after the equals
accessing elements is c-like
```rust
let x = a[0];
```

##### invalid array access
compiles, however panicks and produces runtime error

---
## functions
declared with the fn keyword
function names in rust use snake case
can be defined before or after main, just has to be in a scope the caller can see

separate parameters with commas, e.g.
```rust
fn print_measurements (count : u32, weight : f64) {
	println!("count is: {count}, weight is: {weight}");
}
```

### statements or expressions
function bodies are made up of a series of statements and expressions

- statement: instruction that performs an action and does not return a value
- expression: instructions that evaluate to a value

example
```rust
fn main() {
	let x = 6;  // works fine
	let x = (let y = 6);    // errors, the let statement won't return a value
	// this is different from c, where assigning returns the value of the assignment
}
```

functions are also statements
calling functions are expressions, as is calling a macro

creating a new scope with braces is an expression, see below

```rust
fn main() {
	let y = {
		let x = 3;
		x + 1
	};

	println("{}", y);   // prints 4
}
```

note that x + 1 does not have a semicolon
this is because it is an expression, adding a semicolon would make it a statement

### functions returning values
in rust, the returning value isn't named, but is synonymous with the final expression in the function
the return type must be specified with the -> operator

```rust
fn five() -> i32 {
	5
}
```
sidenote; this function is adorable

---
## comments
// single line comments
/\* block comments\*/

---

## control flow
if/else expressions
```rust
if number < 5 {
	...
} 
else if {
	...
}
else {
	...
}
```

if is an expression, and so can be placed in something like a let statement
```rust
let x = if condition { 5 } else { 3 };
```

note: the branches of the if statement need to be compatible types

### loops
loop keyword explicitly tells code to repeat
break and continue also exist

#### returning values from loops
can be placed after the break keyword to return

```rust
let mut counter = 0;

let result = loop {
	counter += 1;   // rust doesn't have increment or decrement operators

	if counter == 10 {
		break counter * 2;
	}
}

println!("{result}");   // prints 20
```

#### loop labels
break only exits the innermost loop, so loops can be named to specify which loop is broken
labels defined using ' operator

```rust
loop 'counting {
	count -= 1;
	
	loop {
		if count = 1 {
			break;  // exits this loop
		}
		else if count > 100 {
			break 'counting;    // exits the loop 'counting
		}
		else {
			count += 2;
		}
	}
}
```

#### conditional looping
##### while 
```rust
while condition {
	// do things
}

// over a collection
let mut i = 0;

while i < 5 {
	println!("{a[i]}");
}
```

##### for
```rust
for element in a {
	println!("{element}");
}
```

example use of a for loop to iterate a certain amount of times
```rust
for e in (1..4).rev() {
	println!("{e}");
}

// prints 4, 3, 2, 1
```

> #rust