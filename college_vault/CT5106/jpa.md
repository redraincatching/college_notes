# java persistence api
## connecting to databases
- connecting the ide to mysql
can query db from ide
- connect via payara server
allows application to use java persistence api which rely on payara connection pools
- add a dependency via maven
allows reverse engineering of databases

use the intranet database (make sure uname and stuff is set up)

payara admin console - localhost:4848

---
## jpa overview
bridges the gap between relational mapping and oop - object-relational mapping (orm)
used to persist data n relational form
generally 1:1 mapping isn't an issue
![[Pasted image 20231128151850.png]]

jpa annotations used for objects in database
have to have a totally empty constructor as well as any used ones
used in circumstances like when the database itself generates a primary key
the object would need to be instantiated, empty, then a key generated, then filled

also - need an empty constructor even if it is never called, sql doesn't like when there isn't one

1:n mapping is where it gets weird
- there can be multiple scenarios for mapping classes to tables or vice-versa
- may have to introduce pk's or associate classes at either end
![[Pasted image 20231128151925.png]]

inheritance also needs handling
- A is the simplest, but queries are separate for emp types
- B is efficient but not normalised, and mapping is more complicated
- C is the most likely, but requires more complicated classes & queries, and an additional association class
![[Pasted image 20231128152046.png]]


---
## classes or tables first?
generally have to do both
- generate a new schema based on classes
- or access a database and figure out how to manage the orm

all mappings are handled with annotations

### annotations
#### @Entity
- an entity (from the jpa perspective) is an object
	- persistable
	- unique (must have a primary key / unique id)
	- transactional (can perform crud)
	- granularity (not primitive types)
- basic requirements to transform java class into entity
	- no-argument constructor
	- annotation
		- at minimum @Entity, @Id
	- generally entities don't need to be serialisable, but keys and composite key classes do
	-  those weird getters and setters
example
![[Pasted image 20231128162552.png]]
> generally beyond the minimum annotations you'd add @Table for the class and @Column for the fields
> both of these will reference which table or column they're being assigned to with (name = "whatever")
for more on entities, see [[jpa_entities]].

---
## jpa entity manager

the entity manager (em) implements the jpa
- the interface by which we interact with the persistence context ( a cache within which entities and transactions are merged )
- used to access the db and run all queries
- objects are managed by the em

an entity manager factory (emf) interface is used to provide an em
```java
EntityManagerFactory emf = Persistence.createEntityManagerFactory("name_of_p_unit");
```
the persistence unit is defined in persistence.xml

rather than create these ourselvves, we can use context dependency injection, where the application container providese and manages the em
```java
@PersistenceContext(unitName = "whatever")
private EntityManager em;
```
examples:
GetEmployees
![[Pasted image 20231128163459.png]]
CreateEmployee
![[Pasted image 20231128163602.png]]
running a query
![[Pasted image 20231128164221.png]]


---

## querying the persistence storage
the java persistence query (jpql) allows you to perform both dynamic and static queries on the entities in your application
it's like sql in many ways, but has several benefits over it
- operates over the entities and their relationships rather than the actual db schema
    - this makes queries portable no matter what the underlying db looks like

there are three types of query
- select
    returns a set of entities from your db
    usually has specific constraints that limit the result set
- update
    changes one or more properties of an existing entity or set therof
- delete
    removes one or more entities from the db

### select
several options to create a query
the most basic way is to just ask the entity manager for one
```java
Query q1 = em.createQuery("select e from Employee e where e.name = 'mary'");
```
can also programmatically set the parameters of the where clause, with .setParamter()
```java
Query q2 = em.createQuery("select e from Employee e where e.name = :name");
q2.setParameter("name", "mary");
Employee e2 = (Employee) q2.getSingleResult();
```

once you've retrieved a managed entity, either by querying the database or by using find, updating the entity is as easy as modifying its properties and committing ~~seppukku~~ the open transaction
```java
userTransaction.begin();
{
e2.setSalary((long) 450000.00);
em.persist(e2);
}
userTransaction.commit();
```

> #software_engineering #java 
