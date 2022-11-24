# SQL

the programming language for relational databases is sql - _structured query language_

sql is a _declarative_ language
this means you can specify the results you require, not the order of operations to retrieve those results

not an imperative language like c
-> can't do low level operations, such as assigning a value to a variable

allows for _specification of queries_
queries represent information needs, and can be run to produce results
results might be
- output to user
- modification of data in database
- **crud** operations: **c**reate **r**ead **u**pdate **d**elete

### Select Statement

specifications provided by clauses

SELECT \[DISTINCT\] \<attribute list\>
FROM \<table list\>
WHERE \<condition\>
; comes at the end of a statement

e.g.
```sql
SELECT fullname, phone_no FROM address_book WHERE county = 'galway';
```

#### Querying across multiple tables
a number of different approaches can be used
however, the query becomes more complex

one approach is to use an outer query, and a subquery
-> these queries can be connected with a mathematical operator, if the output is a single number
-> similarly, string comparator operators (=, !=) can also be used
e.g. 
```sql
/*
find from tables
patient(pid, pname, birthyear)
consultant(cid, cname, room, speciality)
appointments(id, pid, cid, aptdate)
what room ali byrne should attend for the appointment on 23/11/2021
*/

SELECT room
FROM consultant
WHERE cid IN
	(SELECT cid
	FROM appointment
	WHERE aptdate = #23/11/2021# 
	AND pid =
    	(SELECT pid
    	FROM patient
		WHERE pname = 'ali byrne')
    );


/*
find in the school table the names of all students who recieved an a in maths
*/

SELECT sname FROM school WHERE grade = 'A' AND modname 'maths';

```

#### Using aggregate functions

sql supports several aggregate functions which can be used in the SELECT clause
e.g.
- SUM, AVG, MIN, MAX applied to numerical fields
- COUNT returns the amount of tuples that fulfill the conditions

for example
```sql
/*
using the appointments table (and a subquery), find the youngest person with an appointment
*/

SELECT patientname
FROM appointments
WHERE birthyear =
	(SELECT MAX(birthyear)
    FROM appointments);

```

### Insert Statements
allows data to be inserted as part of a query
**syntax**
```sql
INSERT INTO <table> (<attribute_list>)
VALUES (<value_list>);
```
	
### Update Statements
can modify one or more records
**syntax**
```sql
UPDATE <table>
SET <attribute_name> = <value>
WHERE <condition>;

```

### Delete Statements
deletes data, not table structure
**syntax**
```sql
DELETE *
FROM <table>
WHERE <condition>;
```
_// note: not to be confused with DROP_

> #algorithms 