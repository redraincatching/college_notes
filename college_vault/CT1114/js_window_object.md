# The Window Object

represents an open window in a browser
a window is an object, which means that it has *attributes* and **methods** (things an object can do)

sample window methods
-   alert
-   [[prompt_nan_study.html|prompt]]
-   confirm
-   setTimeout

---
## Methods

// called using \<object\>.\<method\>
// that's how you access anything belonging to an object

### alert

displays a *modal* dialog box containing a message
&nbsp&nbsp&nbsp&nbsp// modal means that it must be acknowledged before anything else can take place
&nbsp&nbsp&nbsp&nbsptakes a string argument
**syntax**
```html
window.alert("<text>"); alert("<text>"); // both work
// window is implicit, all of your code belongs to the window
```

### prompt

prompts the user to enter input via a modal dialog box
&nbsp&nbsp&nbsp&nbsp// has a return value
e.g.
```html
var result = window.prompt("<prompt_text>", "<default_field_value>"); // note: the second argument is optional
```

### window.confirm()
modal dialog box with ok or cancel options
&nbsp&nbsp&nbsp&nbspreturns a boolean value based on the option picked
**syntax**
```js
confirm("<message>");
// returns true or false
```

### window.setTimeout()
deferred execution of code
takes two arguments
1) action to take
2) delay in ms

**syntax**
```js
window.setTimeout("<thing_to_do>", <delay>);
//or
window.setTimeout(function_name, <delay>);
// note: no brackets, as you're sending the function as an argument

```

> #javascript #web_dev 