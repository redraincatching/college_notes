# html forms
forms provide a standard set of input controls: text fields, buttons, check boxes, lists, etc.
the user's choices are entered into the controls

 the contents of the controls can be manipulated and processed on the client (with js) before being posted to the server, or after being posted, with a different language (e.g. node.js)

to post a form to the server, use either \<input type="submit"\> or the .submit() method

> <input type="submit"> example of submit input </input>

## \<form>
### attributes
- ACTION
defines the URL that the data will be sent to
- METHOD
defines how the data is sent
"post" - the form element names and values are sent as a request object to the server
"get" - the form element names and values are sent as part of the url using query strings

### form controls
>\<textarea>
> defines a field in which the user can type multiple lines of text
> 
> <textarea style="height:60px;"> example textarea </textarea>

> \<select>
> enables the user to choose among a number of options in the list
> 
> \<option>
> items in the select list
> 
> <select name="listlabel" id="listid">
> <option value="1"> item 1 </option>
> <option value="2" selected="selected"> item 2 </option>
> <option value="3"> item 3 </option>
> </select>
> 
>  _// "selected" attribute here denotes default_
> /\*
> to find the index of the item in the list at runtime, use
> var idx = document.getElementById("listid").selectedIndex;
> \*/

> \<input>
> provide other options such as checkboxes, radio buttons, single lines of text
> <input type="radio" name="example" id="1" value="1"> radio 1
> <input type="radio" name="example" id="2" value="2"> radio 2
> _// note: radio buttons like these are grouped using the name attribute
>_
> check boxes
> <input type="checkbox" name="label" checked="checked"> option 1
><input type="checkbox" name="label2"> option 2
> _// the "checked" sets the item to be selected by default_


> \<button>
> pushbuttons <br>
> <button > button </button>

#html #web_dev 