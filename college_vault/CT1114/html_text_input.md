# html text input

### html tag - \<input type="text"\>
text input field
&nbsp&nbsp&nbsp&nbspspecify default text with "value" attribute
&nbsp&nbsp&nbsp&nbspcan specify size with "style" attribute

### \<textarea\> ... \<textarea\>
an area where the user can type text, whose size is manipulable
can define the size with "rows" and "cols" attributes
e.g.
```html
<textarea rows="20" cols="40" id="text_area" value="default text goes here"></textarea>
```

#### methods
- .value
&nbsp&nbsp&nbsp&nbspgets the value of the area (the typed string)
- .substr(<start_char>, <end_char>)
&nbsp&nbsp&nbsp&nbsptake a section of the string, starting at start_char, and ending end_chars further over
- .length
&nbsp&nbsp&nbsp&nbsplength of string thing
    
#### attributes
- placeholder
&nbsp&nbsp&nbsp&nbspplaceholder text that stays until the user enters text

##### onkey attributes
- onkeydown   - when the hey is first pressed
- onkeypress  - registers when a key is held
- onkeyup     - when the key is released (when output of key is registered, as well)

###### sample code
[[text_input_study.html|text input study]]

> #web_dev #html