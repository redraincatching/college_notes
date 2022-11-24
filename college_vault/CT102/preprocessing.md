# Pre-processing

a number of steps are carried out on each page/fragment

### case folding

changes everything to lowercase (exception for proper nouns) mostly for practical reasons, due to string matching

### punctuation removed

e.g. 
she's → she
they'll → they 
&nbsp&nbsp&nbsp&nbsp// no real extra meaning, index-wise

#### dealing with proper nouns

just normal words - just store as written, or tagged specially can be distinguished through punctuation or position in a sentence

#### abbreviations

e.g. U.S.A. / US, SCUBA

usually stored as the whole string, as the punctuation or cases would cause confusion if removed 
&nbsp&nbsp&nbsp&nbsp-> "us" is already a word

---
## "stop word" removal

common words in the language that provide no extra semantic meaning very common, and removed to save on storage space language dependent

// these days, stop word lists are small, the "removal" is done during weighting
//stop word lists are based, as they remove gender (pronouns)

### approach for stop word removal

when the document is originally processed, each word is checked against a stop list, then if not found, the word is written out to a new version of the document

(this is very resource-heavy)

**improved approach**
-> remove short (1-, 2-letter) words without even checking

---
## stemming

tries to find the _"stem"_ or root of the word

looks at suffixes, and cuts them off to get a shorter word
*// stemming algorithms don't look for real words*
*// stemming doesn't work in every language*

### stemming algorithms

- porter's stemming algorithm 
- snowball (porter 2) stemmer 
- lancaster stemming algorithm

## lemmatisation

a *lemma* is a base form (core), i.e. the form found in a dictionary lemmatisation is more difficult (automatically) than stemming

e.g.
goose & geese
&nbsp&nbsp&nbsp&nbspstemmer:
&nbsp&nbsp&nbsp&nbsp&nbsp&nbspgoos x1
&nbsp&nbsp&nbsp&nbsp&nbsp&nbspgees x1
&nbsp&nbsp&nbsp&nbsplemmatiser
&nbsp&nbsp&nbsp&nbsp&nbsp&nbspgoose x2

---
## Calculating the Weight of Terms

the abstraction is represented using terms, and a weight for each term
a weight is a real number, the higher the weight, the higher the importance

*tf*: term frequency
&nbsp&nbsp&nbsp&nbsp->if a term appears often in a document, it is an important term in relation to it

*idf*: inverse document frequency
&nbsp&nbsp&nbsp&nbsp->however, if a term appears many times across the entrie index, it is less useful in terms of distinguishing a document

_// stop words have a very high tf, but a very low idf_

### calculating tf

to not penalise short documents, _normalise_ by dividing the raw count of the number of times the term occurs by the total number of terms in the document (after pre-processing, this is ratio of terms to be indexed)

### calculating idf

for a term t and N documents with t occurring in $df_t$ documents the idf of t is defined as

$\large idf_t = log_{10}(1+\frac{N}{df_t})$

// $log_{10}$ of 1 = 0, so if the 1 wasn't added in the brackets, and $df_t$ was N, then the idf // would be very low for a very common term (zero is not very big :/ )

**after this stage, we can easily access**

<term, weight> for each url <doc, weight> for each document in the collection

// usually stored in complex structures, 0s are not stored, to save space + computing power

now that documents have been preprocessed, we can find their [[similarity_and_page_rank|similarity]] to a query.

> #algorithms 
> [[search_engines]]