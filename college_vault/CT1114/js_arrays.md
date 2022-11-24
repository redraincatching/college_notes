# arrays in javascript
[[c_arrays|c-like]], [] brackets
random-access data structure - can access any data point at any time

## differences between js and c
- js can have "sparse" arrays, i.e. can have gaps
- can be indexed on strings as well as integers
- each element can contain any type of data (***even functions***)

_// all of these seem prime for fuckery_

### sample array code
```js
var a = []           // create an empty array
a.push(22);          // .push adds an element at the end of the array
a.splice(10,1);      // .splice removes 1 element from position 10, and shifts the rest down
a["exit"] = "amach"  // sets an element at the index "exit"
a.length;            // returns the index of the last element (doesn't make much sense here)
```

---
##### "undefined" data type
the data type of variables that don't exist
useful for checking if an element is in an array

---
### hash tables
![[hash_function.png]]
a data structure used to implement an associative array, a structure that can map keys to values. uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

_// note: javascript actually implements arrays like this internally_


## iterating through arrays
dense, integer-indexed arrays ("normal" arrays)
```js
for (var i = 0; i < a.length; i++) {
	// do thing
}
```

sparse or string-indexed arrays
```js
for (var i in a) {
	// do thing
}
```

> #javascript #web_dev 