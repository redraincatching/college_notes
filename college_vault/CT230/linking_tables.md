# linking tables in an sql query

3 potential approaches
- joins
- subqueries
- union queries

// not all are always applicable

## subquery
nested query
usually returns data that will be used in the main query
may be a set of values, or a single value
can use full dml statements

### when to use
when an existing value from the databasse needs to be retrieved and used as part of the solution
when an aggregate function needs to be performed
can sometimes replace a join

subqueries can be used as part of the WHERE and HAVING clauses
```sql
SELECT ... FROM ... WHERE (SELECT ... FROM ... WHERE ...);
```

if a subquery returns only one value, operators such as !=, >= can be used
if a set of values could be returned, IN, ANY, or ALL must be used
NOT, EXISTS, and NOT EXISTS are all useful

\>ALL returns true if the comparison is true for every tuple in the subquery
=ANY returns true if true for any tuple
IN - checks for equality, true if at least one is true

---
## joins 
used when you require data from two different tables
combine multiple tables into one table
this new table is then queried to produce a result

tables are joined by specifying links across tables
tables are joined two at a time, but multiple can be added

### specifying joins
1) in sql we must specify all tables which are part of the join in the SELECT clause
	// there are many types of joins, not all of which are supported, but we will use the inner join, which always is
1) must then specify the join condition
	for an inner join the condition is foreign_key = primary_key/candidate_key
1) the join condition can be specified in the FROM or WHERE clause

#### inner join
![[inner_joining_tables.png]]
for our example company db
join condition
-> ssn = essn
syntax
```sql
SELECT *
FROM employee INNER JOIN dependent
	ON ssn = essn;
```

_example_
list the details (name, birth date and address) of the children of franklin t wong

```sql
SELECT dependent_name, dependent.bdate, address
FROM employee INNER JOIN dependent ON
	ssn = essn
WHERE relationship != 'spouse'
	AND fname = 'Franklin'
	AND minit = 'T'
	AND lname = 'Wong'; 
```

// note the dependent.bdate, as bdate is an attribute in both tables
// can always be done, not usually useful

#### explicit vs implicit joins
the join condition can be specified implicitly or explicitly
    
##### explicit
specified in the FROM clause where tables to be joined are listed
uses INNER JOIN keyword
join condition listed using ON

##### implicit
specified in WHERE without using ON
tables listed in FROM using commas

no additional syntax to learn
all tables involved must be listed in FROM
conditions concatenated using AND
inner join only - all rows from both tables will be returned whenever there is a match between attributes in the join condition

###### explicit join syntax
```sql
SELECT [DISTINCT] <attribute_list>
        FROM <table>
            [INNER/LEFT/RIGHT] JOIN <table>
            ON <join_condition>
        WHERE <condition>

        /* for three tables, FROM looks like
            FROM (<table>
                [INNER/LEFT/RIGHT] JOIN <table>
                ON <join_condition>)
                [INNER/LEFT/RIGHT] JOIN <table>
                ON <join_condition>
        two joined tables become a new table */
```

###### implicit join syntax
```sql
SELECT [DISTINCT] <attribute_list>
        FROM <tables>
        WHERE <join_condition> AND 
            <condition>
#example
SELECT a.*, b.*
FROM table a, table b
WHERE a.id = b.id;
```

_example using company database_ - explicit
"for every project located in stafford, list the project number, the controlling department name, and the department manager’s surname, address and birth date."

```sql
SELECT pnumber, dname, lname, address, bdate
FROM (project INNER JOIN department
	ON project.dnum = department.dnumber)
	INNER JOIN employee
	ON department.mgrssn = employee.ssn
WHERE plocation = 'stafford';
```

_example_ - implicit
```sql
SELECT  pnumber, dname, lname, address, bdate
FROM    project, department, employee
WHERE   project.dnum = department.dnumber
		AND department.mgrssn = employee.ssn
		AND plocation = 'stafford';
```

---
### types of joins
#### INNER JOIN
includes the tuples from the first (left) _only_ when they satisfy the join condition, and the second (right) _only_ when they satisfy it also
#### LEFT JOIN
"outer join"
all tuples from the left are included, tuples on the right are only included when they satisfy the join condition
#### RIGHT JOIN
also an outer join
the same as left, just the right are included

#### other variations
![[types_of_joins.png]]
// not all supported in mysql


#### self-joins and aliases
a normal sql join that joins a table to itself
for recursive relationships
e.g. the manager is an employee
accomplished using **the keyword AS** to give each instance of the database a different name
-> the alias

e.g. name of employees and name of their supervisors
```sql
SELECT CONCAT(e.fname, ' ', e.minit, ' ', e.lname) AS emp_name, CONCAT(s.fname, ' ', s.minit, ' ', s.lname) AS sup_name
	FROM employee AS e LEFT JOIN employee AS s
	ON e.superssn = s.ssn;

#broken, fix
```

> #databases #sql