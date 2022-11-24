# Javascript

js \<script\> tags don't need to be in the \<head\> section
js is case sensitive, and tends to use camelCase
No need for placeholders in [[web_development_overview#Javascript|javascript]].
```jsx
var num = 1;
p.innerHTML = "Here\\'s a number: " + num;    // <- concatenating
```

---
## js Variables

```jsx
var [name] = [value];   // let and const both declare variables, slightly differently
var num1, num2, num3;

// like most scripting languages, the data type is implicit, so only var needs to be
// declared
```

var can also store _objects_, like a paragraph

```jsx
var p = document.getElementById("some_paragraph");
p.innerHTML = "now it can be altered";
```

**"use strict";**
&nbsp&nbsp&nbsp&nbsp→ don't use variables that heven't been declared.
&nbsp&nbsp&nbsp&nbspput this at the start of the \<script\> tag.

---
### Expressions

a statement that evaluates to a value
&nbsp&nbsp&nbsp&nbsp→ can be a number, string, or boolean

**Boolean Value**
either true or false
a boolean _expression_ is one that evaluates to either true or false, and is often produced by logical or relational operators

#### Relational Operators
take two values, compare them, output a boolean variable (c-like)

#### Logical Operators

&& - AND
&nbsp&nbsp&nbsp&nbspequates to true if both boolean values are true
|| - OR
&nbsp&nbsp&nbsp&nbspequates to true if one or both values are true
! - NOT
&nbsp&nbsp&nbsp&nbspnegates the value of a boolean variable

---
##### Conditional Operators
if ... if else ... else
switch statements
_// both c-like_

> #javascript #web_dev
