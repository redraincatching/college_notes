# entities in jpa

the java persistence api requires that you identify the classes that you will store in a db
the api uses the term "entity" to define classes that it will map to a relational db
you identify the persistable entities and define their relations using annotations
using these annotations, the compiler can generate additional classes for you and perform compile time error checking

## table name defaults
every entity has a name, which is by default the entity class's name, but you can specify this explicitly
```java
@Entity
@Table(name="whatever")
```

## column name defaults
similarly, the persistence provider uses an eentity's field or property names as the column names, but these can be explicitly specified, e.e.
```java
@Size(max = 255)
@Column(name = "Address")
private String address;
```

---

## entity declarations

entity classes become tables in a db, and instances map to rows

### primary keys

all entities must have a unique primary key
keys can be a single unique field, or a combination thereof

key fields _must_ be one of the following types
- primitives
- wrappers fro primitives
- java.lang.String
-java.util.Date
- java.sql.Date

> the reference implementation will generate a key automatically if you add the @GeneratedValue annotation to the pk

---

## sequencing

the object id is defined through the @Id annotation, and is the pk
can either be natural (an address, ppsn, etc.) or a generated id
natural keys aren't immutable, and can also make queries more inefficient and complex

this is where the aforementioned @GeneratedValue comes in

### @GeneratedValue(strategy = GenerationType.IDENTITY)
popular but not necessarily supported by all dbs
lets the db control the id generation, the jpa doesn't act on it at all
therefore, to retrieve the id, the entity needs to be persisted first

### GenerationType.SEQUENCE 
used with a sequence generator, which is created via annotation
```java
@SequenceGenerator(name = Car.CAR_SEQUENCE_NAME,

sequenceName = Car.CAR_SEQUENCE_NAME, initialValue = 10,
allocationSize = 53)

@GeneratedValue(strategy = GenerationType.SEQUENCE,
generator = CAR_SEQUENCE_NAME)

allocationSize = # of id’s JPA keeps in a cache to used
```

not all databases support this though, sql doesn't

---
## @Basic(optional = false)
basic types map directly to a column in the db
the basic types are the ones that can be a pk, so primitives, wrappers, Strings and the two varieties of Date

## @Transient
it's the serializable annotation, works the same

---
## cascading changes to related entities
in a jpa entity relationship, the CascadeType.ALL annotation specifies that all operations (persist, merge, remove, refresh, and detach) that are performed on the parent should be cascaded to the child entity
example
```java
@OneToMany(cascade = CascadeType.ALL, mappedBy = "category")
private Collection<Product> productCollection;
```
in the following context
![[Pasted image 20231129122855.png]]

> cascading is dangerous, as deleting a parent will delete all children

### fetching related entries
![[Pasted image 20231129122649.png]]
example
![[Pasted image 20231129122714.png]]


---
## named queries
- fixed queries
- mapped to specific classes
- can include parameters

```java
@NamedQueries({
@NamedQuery(name = "Category.findAll", query = "SELECT c FROM Category c"),
@NamedQuery(name = "Category.findById", query = "SELECT c FROM Category c WHERE c.id = :id"),
@NamedQuery(name = "Category.findByName", query = "SELECT c FROM Category c WHERE c.name =
:name")})
```

---
## entity lifecycle
![[Pasted image 20231129124940.png]]

> #software_engineering #java
