# LaTeX
a document preparation system for high-quality typesetting

##### Usage
-   miktex - offline editore
-   overleaf - cloud-based editore

---
## Format of a Document

*preamble*
&nbsp&nbsp&nbsp&nbspdocument 
&nbsp&nbsp&nbsp&nbspclass 
&nbsp&nbsp&nbsp&nbsppackages

*front matter*
&nbsp&nbsp&nbsp&nbsptitle 
&nbsp&nbsp&nbsp&nbspauthor

*body*
&nbsp&nbsp&nbsp&nbspcontents

*back matter*
&nbsp&nbsp&nbsp&nbspbibliography

// can be simplified to just preamble and body

---
### LaTeX syntax

all keyword commands begin with a backslash \\ 
all parameters and arguments are passed with braces {} 
comments can be added using the % character

```latex
\documentclass{article}
\usepackage[utf8]{inputenc}        %preamble section
```

**reserved characters**
some characters need an escape character, as they have another function in latex generally, \\ works as an escape character

e.g. 
&nbsp&nbsp&nbsp&nbsp\$ opens math mode 
&nbsp&nbsp&nbsp&nbsp\\\$ prints a \$


**shortcuts**
ctrl + space - autocomplete reference (inside a \\cite block) 
ctrl + enter - recompile
> #professional_skills #latex