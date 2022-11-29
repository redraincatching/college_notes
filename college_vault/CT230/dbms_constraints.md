# dbms constraints

impact of setting data types, contraints like NOT NULL, primary and foreign keys
dbms has very strict constraint checking, and will not allow data to be entered if they are not met

## domain constraints
_defn_: the value of each atomic attribute A must be an atomic value from the domain $dom(A)$
essentially, data types and formats must conform to those specified

## entity integrity constraints
the primary key should uniquely identify each tuple in a relation
- no duplicate values allowed
- no null values allowed

// note: null values are permitted in other attributes unless the NOT NULL constraint is specified

## referential integrity constraints
_defn_: this constraint is specified between two relations and requires the concept of a foreign key. no foreign key must be unmatched
-> a relationship between foreign keys must be between attributes of the same type and size, and neither are empty

## semantic integrity constraints
specified and enforced using a constraint specification language
two types:
- state constraints
e.g. setting a min or max value, the attribute is restricted to occupying certain states
- transition states
e.g. a certain attribute can only increase, restricting how an attribute can change

### setting constraints
- domain constraints are set automatically upon choosing a data type
- entity constraints are set upon choosing a primary key
- usually default constraints are set on foreign keys, but these can be changed

--- 
update operations and constraint violations
the dbms must check that constraints are not violated whenever update operations take place
- insert
```sql
INSERT INTO <table> VALUES
(<value_1>), (<value_2>), ..., (<value_n>);
```
- delete
```sql
DELETE FROM <table> WHERE <condition>
```
- modify

cascade delete
whenever tuples in a table are altered or deleted, any tuples that reference them are also modified or deleted

> #databases #sql