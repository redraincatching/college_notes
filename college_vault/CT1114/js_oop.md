# oop - object oriented programming
## classes
a class is a blueprint for a thing
classes have properties and methods
an object is an instance of a class

### js classes
syntax is a bit weird, based on the fact that ==functions are objects==
-> the keyword "this" is used to refer to its own instance

e.g.
```js
function class(var y) {
    this.y = y;     // y is now a property of class
}
// this object now has an implicitly created class, called prototype
class.prototype.function() {
    alert("hello");
}

// to declare a new instance
var obj = new class(6);
obj.hello();
```

#### classless objects
you can also declare arbitrary data like this
e.g.
```js
var o = {x:5, y:6, name:"red", data:[3,2,1], child:{a:2, b:6}};
```
you can access the members at any time
```js
o.x = 6;
```
and add more members at any time
```js
o.z = 20;
```

---
## json and data organisation in js
json - javascript object notation
-> a syntax for specifying js objects

### serialising
the act of turning a software object into a form that can be saved to a file or sent across a network, as a series of bytes or characters.
-> de-serialising is the inverse

JSON.stringify(o)
- returns a string representation of object o
- e.g. for saving or transmitting through ajax

JSON.parse(str)
- takes a string and returns an instantiated js object from it

> #javascript #web_dev 