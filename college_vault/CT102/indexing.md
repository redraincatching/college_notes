# Indexing
- stores + organises data crawled so that it can be searched efficiently
- typically stores <url, term, weight>
- preprocessing and weighting terms

---
## How to Represent/Index Organic Data?

we need to extract some abstract representation to support complex matching **and to speed up querying.**

this is typically automatic, and involves choosing a subset of words from the webpage, and giving them a specific "weight" that indicates their relative importance

---

### Indexing

associates a webpage with one or more terms

automatic indexing starts with _no_ predefined index of terms

the [[web_crawlers|crawler]] picks terms from the sites visited as necessary

these indexes are dynamic, as the crawlers are constantly gaining information, even the weight of the terms is dynamic


#### The Process of Indexing a Text

what is it about?
&nbsp&nbsp&nbsp&nbspwhat _words_ tell us what it is about?
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp→ most frequent words?
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspobtained by a "tokeniser", finds words from whitespace gaps
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp→ is each word equally important?
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp→ what's going into the index?

we can discount words such as "like", or "and"
(see [[preprocessing#stop word removal|stop words]])

---
##### other language issues
-   synonyms
-   words with multiple meanings

what counts as an important word?
is each unique word important?
&nbsp&nbsp&nbsp&nbspno, usually just verbs and nouns
are upper and lowercase words different in terms of meaning?
&nbsp&nbsp&nbsp&nbspnot usually, barring proper nouns
plural and tenses?
&nbsp&nbsp&nbsp&nbspignore
punctuation?
&nbsp&nbsp&nbsp&nbspignore
synonyms?
&nbsp&nbsp&nbsp&nbsponline thesaurus
multiple meanings?
&nbsp&nbsp&nbsp&nbspdisambiguation can be done from context, so these words are sometimes indexed in groups

---
### Automatic Indexing - terms

the word "term" is used to encompass many words
e.g.
&nbsp&nbsp&nbsp&nbspterm = "rain";
&nbsp&nbsp&nbsp&nbsprelated words = "raining", "rains", "pleuvoir";

> #algorithms 
> [[search_engines]]