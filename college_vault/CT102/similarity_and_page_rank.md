# Finding the Similarity Between a Web Page and a Query

document and query stop words are removed, and terms are stemmed
calculate tf\*idf for document terms

once this is done, we need to find a way to compare the document and query.

---
## Vector Space Model Approach
essentially, all documents are represented by *vectors of n dimensions*, where *n is the number of terms* in that document

### compare with the query vector

each document _d_ is represented as a vector of real-valued numbers where each number is the weight of a term in that document
&nbsp&nbsp&nbsp&nbsp// queries are viewed similarly

each position in the vector corresponds to a term in the document collection
&nbsp&nbsp&nbsp&nbsp-> the "vocabulary"

the idea is to measure the angle between vectors d and q using their *euclidean dot product*
&nbsp&nbsp&nbsp&nbsp-> then normalised

---
![[euclidean_dot_product.png]]


// the document normalisation can be done beforehand, and stored in the index
// similarly, the query norm only needs to be done once

// for the denominator we need to consider all the terms in the document
// for the numerator, just the non-zero values

// sometimes the similarity is written as the cos of the two vectors
// 0 < (theta) < (pi)/2

for the sake of efficiency, any documents in the index without a positive weight for thequery terms can be ignored

---
### advantages of a vector space comparison
- most similar documents can be found, no need for a 100% match
-> a boolean search wouldn't do this
- documents can be sorted in decreasing order of similarity, so ranking
- most commonly used approach across search engines, and widely applied elsewhere too
// such as seeing how similar documents are to each other

are query vectors always 1?
no, usually terms are expanded and weighted according to:
- whether the term was part of the original term, or whether it was added by the search
  engine (e.g. location, thesaurus lookup)
- whether term has been used by this user before (personal data)
however, if not told in a problem, we can assume query weights are 1

---
# Page ranking

**SERP** - search engine results pages
&nbsp&nbsp&nbsp&nbspranking involves ordering the pages displayed based on several scores, such as similarity scores
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsporganic, from index
&nbsp&nbsp&nbsp&nbsppage_rank scores
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsporganic, from links on pages
&nbsp&nbsp&nbsp&nbspad word scores
&nbsp&nbsp&nbsp&nbsp&nbsp&nbspsponsored, at search time
&nbsp&nbsp&nbsp&nbsppersonalised information
&nbsp&nbsp&nbsp&nbspfeatured articles

### page rank
uses a link analysis algorithm to determine the _relative importance of a webpage_
originally developed by the founders of google
// actually named after larry page, not webpages, but who cares
one factor which led to google's early dominance
only considers the _in and out links of a webpage, not internal links_

---
#### Overview
the higher the page_rank score, the more important the web page, and such it should be
ranked above pages with other equally relevant pages

the general idea is that a link to a site is an endorsement of that website
pages with higher page_rank scores -> endorsement is more important

page_rank algorithm tries to sum up all the endorsements

![[page_rank_algorithm.png]]

![[page_rank_algorithm_defn.png]]

to begin
&nbsp&nbsp&nbsp&nbspwe don't know the beginning page_rank of any of the pages involved (this needs to be calculated)
&nbsp&nbsp&nbsp&nbspeach page is therefore given an initial value, usually 1 or 1/n
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp// this is initially used for every page
&nbsp&nbsp&nbsp&nbspthis is modified over a number of iterations, until the page_ranks converge
&nbsp&nbsp&nbsp&nbspgenerally, .001 is considered close enough
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp// d is usually set to .85

> #algorithms
> [[search_engines]]