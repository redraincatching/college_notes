# Search Engines

Typically, general-purpose search engines deal with data that
-   has large portions of unstructured data, although potentially some structure thanks to HTML tags (title, section, etc.)
-   is often natural-language data
 
Some engines deal with [[databases|semantically tagged data]], such as database search engines

---
### Types of Data

Structured - data that resides in fixed fields that provide semantic information, e.g. spreadsheet columns

Semi-structured - some structure available, e.g. from HTML tags

Unstructured - not organised in any obvious or meaningful way

---
### Characteristics of html files

-   natural language text, audio, images, etc.
-   lots of formatting → some tags, esp. \<a href\> are very useful to search engines
-   web scrapers only see the raw html, not the rendered page

**Natural Language**
Unstructured, hard to extract meaning
language is compositional
machine learning is working on this, however many existing techniques use statistical approaches to infer meaning from the frequency of ertain symbols

#### Important html aspect - linked data

![[excalidraw_9.png]]

---
### Web Link Distribution

_not_ random

widely reported to be a "power law", so that a small portion of web pages have the majority of hyperlinks

**Inputs and Outputs**

2 types of content returned on a search - organic and sponsored content.
On the search engine results page, we can distinguish between these two
Sponsored content is listed (ranked) above organic content
&nbsp&nbsp&nbsp&nbsp→ "60,000,000 results in 0.67 seconds" in reality, only the top ~10 pages are loaded, far more efficient.

---
### Sponsored Content

additional search through ad database for listed keywords
automated "auction" takes place to select which ads get displayed
Several different systems make up a single search
-   organic unstructured content
-   personal data
-   organic html links
-   sponsored data
-   organic structured data
-   displaying results

---
## Basic components of organic search

![[excalidraw_10.png]]

##### Stages

**NOT** *at search time*
1.  [[web_crawlers|Crawl]]: navigate webpages by crawling, obtain representation of webpage
2.  Parse: parse content and extract meaningful terms, links + other information from page 
3.  Index: create index of web pages 
4.  Rank: assign page rank scores to indexed webpages

*At search time*

5.  Information Retrieval: e.g. vector similarity to find relevant indexed documents
6.  Reorder + Display: based on page rank and personal data
7.  sponsored content step
8.  search + incorporate structured documents (if applicable)
9.  Order + Display all results

> #algorithms