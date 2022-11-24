# the css box model
all html elements are considered boxes
the box wraps around all the html elements

consists of four parts:
- content
the html element concerned
- padding
empty space surrounding the content
uses the same background colour as the content
- border
the border around the content
border-style attribute must be set for the border to take effect
- margin
transparent area used for spacing elements relative to others

![[css_box_model.png]]
border, padding, and margin are all 0 by default

border and margin can be set to sides individually
e.g.
```css
border-left: 40x;
```
can also be declared in one go
```css
border: 10px 11px 12px 13px;
```

## order
_// depends on how many arguments are given_
> T, R, B, L 	
> T, R/L, B
> T/B, R/L
> A

---
> width and height properties
> only affects the content of the box model

---
### grouping selectors
can apply a common style to multiple selectors
e.g.
```css
h1, h2, h3 {
	text-align: centre;
}
```
// note: overwritten by singular selectors

### general selectors
can also use the asterisk wildcard to apply a general style to all elements
```css
* {
    font-family: monospace;
}
```

---
#### em
equal to the computed font-size for the element to which the em applies
// roughly from the size of m, the widest letter, in typesetting

if no font-size is defined in the css, the em unit is equal to the browser's default font size, which is usually 16px
-> makes is easier to resize things for mobile

> #css #web_dev 