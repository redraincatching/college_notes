# dml - data manipulation language

4 statements
- SELECT
- INSERT
- UPDATE
- DELETE
    
dml supports **crud** statements
create, read, update, delete

## SELECT
basic syntax
```sql
SELECT [distinct] <attribute_list>
FROM <table_list>
WHERE <condition>
GROUP BY <group attributes>
HAVING <group condition>
ORDER BY <attribute list>
```

// note: only SELECT and FROM are necessary to form a query

## WHERE
boolean condition
operators:
- = <= < > >= !=
conditions can be compounded using AND and OR, and can be negated with NOT

### calculated or derived fields
can specify an sql expression in the SELECT clause which can involve numerical or counting operations
e.g. find monthly salary
```sql
SELECT ssn, salary/12
FROM employee;
```

#### tidying this output using CAST/AS and DECIMAL(x,y)
```sql
SELECT ssn, CAST(salary/12.0 AS DECIMAL(8, 2))
			AS mnthlySalary
FROM employee;
# decimal shows 8 digits before the ., and 2 after
```

## DISTINCT
removes duplicates
e.g. 
```sql
SELECT DISTINCT salary FROM employee;
```

## SELECT *
select all

## BETWEEN
range search, inclusive

## IN/NOT IN
tests if data matches a list of values

## LIKE
string comparison where evaluation is too strict

## IS NULL
explicit search for null

### set operators
UNION, INTERSECTION, MINUS/DIFFERENCE

## comments
```sql
# this is a comment
-- this is a comment --
/*
*   these are all
*   commented out
*/
```

// note: strings must be enclosed in single quotes

> #databases #sql