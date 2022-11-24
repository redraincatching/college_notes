# Style Interactions

## Selecting and Deselecting Elements
usually used with form elements such as \<input\> and \<textarea\>, as only one of them can accept keyboard input at a time

- onfocus
when element gets keyboard focus, i.e. is clicked on
- onblur
triggered when an element loses focus
- onchange
triggered when an element content changes (by user or code)

## Mouse Interactions
### Motion events
- onmouseover
triggered for an element when the mouse cursor hovers over it
&nbsp&nbsp&nbsp&nbspcan be used to change img src
- onmouseout
when cursor is moved away
- onmousemove
triggered evey time a mouse moves while over an element
&nbsp&nbsp&nbsp&nbsprecieves the mouse's current position on the element as an argument

### Click events
- onclick
when clicked
- ondblclick
when doubleclicked
- onmousedown
when the mouse is pressed down on an element
- onmouseup
when mouse is released after being pressed on an element

## Keyboard interactions
- onkeydown
when key is first pressed
- onkeyup
when keypress is released
- onkeypress
onkeydown or on hold

// these key commands can be used with the .keyCode attribute of the element to return which key was pressed


> #javascript #web_dev 