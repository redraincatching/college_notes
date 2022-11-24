# Databases
a database system is an information system that stores and retrieves data
> _definition_
> one or more tables where a table is an ordered collection of records, consisting of data

## Database Approach
a single repository of data that is maintained, defined once and then accessed by various users/programs through a DBMS
&nbsp&nbsp&nbsp&nbsp_DBMS_
&nbsp&nbsp&nbsp&nbsp->a collection of programs the facilitates the process of defining, constructing, and manipulating databases

##### DBMS
relational dbms usually have
- design/structure view
&nbsp&nbsp&nbsp&nbspwhere the structure of the tables are visible
- datasheet/browse view
&nbsp&nbsp&nbsp&nbspwhere you can see the database instance (the data in the tables)
- usually a results window
- usually an sql editor

#### Distributed Database Approach
defined once, and then maintained across multiple sites
&nbsp&nbsp&nbsp&nbsphowever, users have the impression of a single data repository

---
## Types of Database Systems
- relational databases - oracle, sybase
- non-relational databases - mongodb, apache cassandra
- xml databases - basex, sedna
- blockchain databases

### Relational Databases
based on mathematical theory of relations (codd, ibm, 1970)
can be seen as "tables, and only tables"
&nbsp&nbsp&nbsp&nbsptables are 2-d arrays, and are natural representations of relations

#### Relation Tables
(the theory refers to relations, the implementation refers to tables)

each relation has a name
the top row contains headings called *attributes*
&nbsp&nbsp&nbsp&nbspeach attribute corresponds to a column

every other row is an instance of the relation, and is defined by a _tuple_, with components corresponding to those attributes

**no duplicates**: no two tuples can be exactly the same in every attribute

to ensure this completely, one or more special attributes are chosen or added, that are called primary keys, which have unique values for that tuple
*// by convention, primary keys are underlined in writing*

### Primary Keys
a special attribute that has a unique value for every unique tuple, or row, in a database

very important that the primary key is *unique* and *unambiguous*, and *remains so* even when new, as yet unseen data is added to the table

repetition in a primary key is ruled out theoretically

often, considerable effort is involved in choosing a primary key
e.g. id numbers, unique identifiers

choosing a primary key
- simplest possible, generally
- not too long
- not too complex a data type (ideally int)
- chosen from existing attributes rather than adding one
- not too many attributes

-> some existing attribute may be unique, and can be chosen, or some combination of attributes
&nbsp&nbsp&nbsp&nbspsome new "artificial" data type may be chosen

one or more tables?
-> a large relational database _could_ consist of just one large table
this would, however, lead to a great deal of **redundancy**, and also just be very impractical

### Redundancy
unnecessary duplication of data in a table, as a result of data not being split into multiple tables

#### Duplication
if an attribute in a table has multiple identical values, data may be duplicated but not redundant
-> this is the case when restructuring into multiple tables results in loss of data

**Consequences from this**
- loss of data integrity
- wasted space
- difficult to maintain/update

### Normalisation
all tables in a databases must satisfy several desirable properties
a hierarchy of _“normal forms”_ exist that impose increasing restrictions on tables
these normal forms use "functional dependencies"
these forms are called
- 1st, 2nd, and 3rd normal forms
- boyce-codd normal form (bcnf)
- 4th and 5th normal form

> _functional dependency_
> x is functionally dependent on y if knowing y can uniquely determine x
> // reverse is not necessarily true

---

The programming language for relational databases is [[sql]].

> #algorithms 