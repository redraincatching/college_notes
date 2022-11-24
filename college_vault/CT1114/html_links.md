# Hyperlink Anchors
\<a\> ... \</a\> 
used to make clickable hyperlink 
&nbsp&nbsp&nbsp&nbspuse href attribute to define content to link to

if content is on a different website, 
&nbsp&nbsp&nbsp&nbsphref is full address, with http and stuff 
if content is on the same website (in the same folder), just 
&nbsp&nbsp&nbsp&nbsppage_name.html 
if content is on the same page 
&nbsp&nbsp&nbsp&nbspdefine anchor 
```html
<a name="faq1"> faq #1 </a> 
<a href="#faq1"> click here to go to faq #1 </a>
```
---
## URL

the path to a reference uses http - hypertext transfer protocol can be given as an absolute or relative reference

absolute 
	&nbsp&nbsp&nbsp&nbspcomplete globally unique path 
	&nbsp&nbsp&nbsp&nbspuses full url, including protocol (http) and path

relative path to the resource 
&nbsp&nbsp&nbsp&nbsprelative to the page 
&nbsp&nbsp&nbsp&nbspjust filename if in same folder 
&nbsp&nbsp&nbsp&nbspfolder/filename if in a subfolder

---
### [[html_tags#images|Images]]

added with the empty tag \<img\>, and require an src attribute with the url of the image
&nbsp&nbsp&nbsp&nbsp→ can be relative or absolute


> #html #web_dev 
