# the relational database model

> ###### notation used in this module for databases
> 
snake_case
case not significant
primary key underlined
names of columns under brackets
e.g.
>```sql
>department(dname, _dnumber_, mgrssn, mgrstart)
>```

collection of relations (tables) with unique names, where each relation contains tuples (rows) and attributes (columns)
closely related to file systems

the number of attributes a relation has is its _grade_
the number of tuples a relation has is its _cardinality_

## attributes
each attribute belongs to one domain, and has a single
- name
- data type
- format

### atomic attributes
contains a single value of the appropriate type
the relational model should have only atomic attributes

### composite attributes
contains several more basic attributes
-> we often want to decompose composite attributes into atomic ones, unless there is a good reason not to, e.g. an address into city, street, house no. etc

### multi-valued attributes
has upper and lower bounds on the number of values the attibute may have
a relational database should not store this

### derived attribute
an attribute whose value can be derived from another
these are often redundant, and shouldn't really be stored
e.g. age from birthdate

## schema
a relational schema r is the definition of a table, and can be denoted by listing its attributes
$r(a_1, a_2, ..., a_n)$
where $a_i$ is an attribute

---

## primary key
all tuples (relations) in a row must be distinct
to achieve this we reuqire one or more attributes whose values will always be distinct for each tuple
-> the primary key
// note: may be different options for a primary key, called candidate keys

- can never be null
- one per table
- all values unique
- often used as indexes

### foreign key
allows data to be linked across tables by matching the data values in those tables
// matching must be to a primary or candidate key

#### definition
given relations $r_1$ and $r_2$, a foreign key of $r_2$ is an attribute or set thereof where that attribute is a candidate key of $r_1$.

// relations $r_1$ and $r_2$ may be the same relations

> #databases 