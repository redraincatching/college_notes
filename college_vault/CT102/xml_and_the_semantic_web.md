# XML and the Semantic Web
the aim of semantic web search technologies is to represent data in a form that can be parsed more easily by a program.

## Semantic web
**Definition**
"a set of standards and best practices for sharing data and the semantics of that data over the web for use by applications."

_"set of standards"_
- RDF data model
- RDF schema
- SPARQL query language     // no, seriously
- OWL standards for storing vocabularies and ontologies
- use of URIs to name things

---

## XML - Extensible Markup Language
universal metalanguage for specifying markup
-> set of tags which allow us to define the semantics of something, allowing us to _define the meaning of data_

both human _and_ machine readable
// not to be confused with html, this is data semantics, not data presentation

we can define our own tags, but it's more useful to use an existing standard

###### XML consists of
1) opening and closing tags
\<code\> ... \</code\>
2) elements
\<code\> ct102 \</code\>
3) nodes
root, sibling, and child nodes
// document should have one root element
// tag names are case sensitive

##### Attributes
designed to contain data related to a specific element
must always be quoted
can be used instead of elements, depending on context
(syntax similar to html)

### Formatting an XML document
the first line identifies the xml version and encoding used
e.g.
\<?xml version="1.0" encoding="UTF-8"?\>

---
![[semantic_web_stack.png]]
## URI / IRI
uniform / international resource identifier
uris only use ascii characters, iris use unicode
// not to be confused with a url, a uniform resource locator

## Namespace
a set of names used for a certain purpose
-> to avoid mixups like title for person vs. title of film

namespaces provide a method to avoid element and attribute name conflicts
essentially provide a standardised vocabulary to use, or allow you to specify a unique one

a namespace is a _uri_
an xml namespace is declared as below
```xml
<elementname xmlns:prefix=“namespace”>
```

##### XML query
query language that allows querying of xml statements
similar to an [[sql|sql query]]

##### XML schema
describes the structure of an xml document
the xml schema language is often referred to as xml schema definition (XSD)
these schemas
- are written in xml
- are extensible
- support data types and namespaces

#### RDF - resource description framework
rdf identifies "things" using uris, and describes resources with properties and property values
-> uses _xml_ (rdf/xml)

allows data to be specified about resources
resources can be anything
each rdf statement comprises a _triple_ of subject, predicate, object
subjects and objects are resources
predicates are the _directional_ relations between them

###### SPARQL
language used for querying and updating data based on rdf triples
sql-like

---
## Open Data
can be freely used, modified, and shared by anyone for any purpose
open data sources can be textual, maps, genomes, anything
e.g. openstreetmap.org, wikidata.org, genome.gov, ireland's open data portal

### Linked Open Data
open data that is linked to other open data (wow)
published in rdf format

> Three linked-data "rules" -> sir Tim Berners-Lee
> - all kinds of conceptual things should have a http prefix
> - looking up one of these http names returns data in a standard format
> - these things should have relations, i.e., links to other things with the http prefix

##### dbpedia
wikipedia converted to structured semantic format
9.5+ billion rdf triples
constantly updated

##### wikidata
similar, but started from scratch, not extracted from wikipedia
use unique identifiers
Q - item (e.g. Q692 - william shakespeare)
P - property (e.g. P19 - place of birth, P569 - date of birth)

---
## [[search_engines|search engines]] and semantic data
search engines use semantic data to answer questions, not just return results to queries
&nbsp&nbsp&nbsp&nbspthis data is referred to as the "knowledge base" or "knowledge graph"
        
this marks a move away from data and information processing, and towards knowledge processing
&nbsp&nbsp&nbsp&nbspthis "knowledge" is all scraped from databases like dbpedia, or from tagged websites

> #algorithms