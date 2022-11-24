# css
cascading style sheets
controls the visual style of the page

allows a developer to define a set of styles which can be used across multiple pages
&nbsp&nbsp&nbsp&nbspeasier to maintain

---
### styles are composed of two parts
- selector
- declaration

##### selector
&nbsp&nbsp&nbsp&nbspthe html element involved

##### declaration
&nbsp&nbsp&nbsp&nbspconsists of two parts, the property to be affected, and a value to set it to

**syntax**
\<selector\> {\<property\>:\<value\>; \<property\>:\<value\>; \[etc\]}
e.g.
```css
h1 {
color: blue;
font-size: 12px;
}
/* no spaces between unit and value */
/* css can't use // to comment */
```
	
---
## styling
### background-color
&nbsp&nbsp&nbsp&nbspaccepts hex codes or words
&nbsp&nbsp&nbsp&nbspapplicable to many elements (heading, paragraph, document, etc.)

### text formatting
- colour of text can be set with color:\<colour\>;
&nbsp&nbsp&nbsp&nbsp// note: us spelling
- text can be aligned with text-align:(center, left, right, justify);
- font can be specified with font-family:\<value\>;

_/\* multiple fonts can be specified if the user doesn't have the first, but final font specified should be a generic family of fonts (serif, sans-serif, or monospace) \*/_

---
#### styling links
links can be styled like any other text, but also have special characteristics
```css
	a:link {color:<value>;}       /* unvisited link */
	a:visited {color:<value>;}    /* visited link */
	a:hover {color:<value>;}      /* mouse over link */
	a:active {color:<value>;}     /* selected link */
```

---
## placement of style
##### inline style
defined for a single element in its \<style\> attribute
##### embedded style
block of css inside the document \<head\> tag, in its own \<css\> tag
##### external style
globally affects all pages calling it

### priority
inline > embedded > external
// _cascading_ part of cascading style sheets

### external style sheets
separate file with .css extension
link should be in \<head\> tag

**syntax**
```css
<link rel="stylesheet" type="text/css" href="<name_of_file>" />
```

> #web_dev #css 