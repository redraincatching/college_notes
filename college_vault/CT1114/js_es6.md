# javascript es6
new ways to declare variables - const and let
new array methods - map, reduce, filter
alternatives to callbacks for asynchronous programming - promises, async/await
_// not looking at these this year, however_

## var vs let vs const
### var - function scope
if a variable is declared anywhere in a function, it has function scope, this is called "hoisting"

### let - block scope
like a variable in c

### const - block scope
a keyword which stops values from changing

---
### .map(callback)
a new array method in es6
traverses the array left to right, performing the callback function on every element, and returning the new array
### .filter(callback)
traverses the array ltr and returns a boolean identifying whether the element will be kept or discarded
### .reduce(callback, initial_val)
for finding a cumulative or concatenated value for every element of the array
returns cumulative + initial_val

---
## arrow syntax
anonymous functions can be defined one of two ways
```js
var x = function(x, y) {
	return x * y;
}
```

// or

```js
const x = (x, y) => x * y;
```
// note: the return argument can be omitted if it is single line

> #javascript #web_dev 