# designing tables with entity relationship models

## data models
concepts to describe the structure of a database
they comprise
- high-level or logical models
- representational/implementation data models
- physical data models

they allow for database abstraction

## entity relationship models
- provide a way to model the data that will be stored in the system

top-down approach to database design
used to identify:
1) important data, entities
2) relationship between entities
3) attributes of entities
4) the constraints of relationships and entities

### notations
#### chen notation
- entity
	a rectangle
- weak entity
	an entity dependent on another to be identified
	rectangle with offset
- attribute
	an oval
	can be subdivided into more ovals, e.g. "name" -> fname, minit, lname
- entity-attribute links
	straight line
- strong relationship
	diamond
- weak relationship
	offset diamond

##### cardinality
one-to-one - 1:1
many-to-one - 1:N, N:1
many-to-many - M:N

##### stored and derived attributes
if needed, a dotted oval can be used to show data that is not stored, but can be derived
##### multivalues
an attribute which has upper and lower bounds on the number of values for a given entry
offset oval

---
### strong vs weak entities
strong entity - one whose existence is not dependent on some other entity type
weak entity - one whose existence is dependent on another entity type, i.e. has no key attributes of its own

e.g. in company, dependents have can only be distinguished from employee ssn

---
### total and partial participation
#### total participation
all instances of an entity in one set must be related to an entity in a specified second set
double lines
#### partial participation
not all intances must be related
single lines

---
### optionality/ordinality
#### optionality of 0
if entity A has partial participation with B, then it has a 0 or more relationship, so optionality 0
#### optionality of 1
1 _or more_ relationship

##### crow's foot notation
single line
-> optionality 1
circle
-> optionality 0
double line
-> 1 and only 1
line and circle
-> 0 or 1

#### other notations
- crow's foot
- uml

#### weak entity
has total participation in a relationship with another entity
definitionally, they don't have a defining key of their own, so they rely on other entity for that identification

// note: sometimes in er models, multi-variable attributes can be modelled as tables

with a 1:1 relationship, doesn't really matter which side the foreign key is

---

## mapping an er diagram to tables
steps 
1) for each entity, create a table R that contains all the simple attributes of that entity
2) for strong entities, choose a primary key
3) for weak entities, choose a foreign key from the strong entity and create a primery key based on that
4) for each 1:1 binary relationship, choose foreign keys, if applicable the entity with total participation
5) for each 1:N binary relationship, choose foreign keys in the one-side table that identify at most one in the other
6) for each M:N, create a new table S to represent the relationship
	include as foreign kes in S the primary keys of the participating tables, and both keys together are the primary key
7) for each multivariate attribute, create a new table to represent that
	this includes an attribute corresponding to the original table and that original table's primary key, and a ocmbinationof both will be the primary key

<<<<<<< HEAD
> #databases 
=======
> #databases #sql
>>>>>>> b10663ae853b608f7cb3f402490b03140df2fcca
