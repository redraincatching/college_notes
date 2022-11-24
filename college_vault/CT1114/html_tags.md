# Tags

\< \> - tags denote markup elements 
tags normally appear in pairs, \<opening\> and \</closing\> tags 
NOT case sensitive 
text between the tags is the element content, or ***innerHTML*** 
&nbsp&nbsp&nbsp&nbspjs can modify innerHTML

html tags have _"attributes"_
these provide extra information to the browser 
they consist of name="value" pairs 
	&nbsp&nbsp&nbsp&nbspalways added to the opening tag
&nbsp&nbsp&nbsp&nbspe.g. \<body bgcolor="red"\>

multiple attributes can be provided
e.g. \<body bgcolor="red" onload='alert("loaded");'\>
&nbsp&nbsp&nbsp&nbsp// note the alternating single and double quotes, to avoid ambiguity

##### some useful tags

```html
<p> - paragraph
<br> - line break
<hr> - horizontal rule
<!--- text ---> - comment
<h1> ... </h1> - heading // 1-6 available

        <!--- not a tag, but &nbsp; is useful, stands for non-breaking space --->
            <!--- browsers will cut lots of whitespace down to one --->
```

###### lists

```html
<ul> <!---unordered list--->
            <ul>
                <li> ... </li>  <!--- each list item (li) shows up bulleted --->
            </ul>
        <ol> <!---ordered list--->
            <!---bullets replaced by number/letter--->
                <!---defined by type= attribute--->
```

###### \<span\>

used to define a section of content without a line break
e.g.

```html
some normal text and then <span style='color:purple';> some coloured text in a span </span>
```

###### images
```html
\<img src="url_of_image"\> 
```

known as an "empty" tag
&nbsp&nbsp&nbsp&nbsp-> it has no innerHTML or closing tag
&nbsp&nbsp&nbsp&nbsp// filenames are case sensitive on linux or mac servers

see also: [[html_links|links]]

> #html #web_dev 
> [[web_development_overview#HTML - HyperText Markup Language | web dev overview]]