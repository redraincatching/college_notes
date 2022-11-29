# aggregate functions
// only supported in SELECT and HAVING clauses
SUM, AVG, MIN, and MAX can only be applied to numeric data
	-> mathematical operations can also be used in the query

**COUNT** returns the number of tuples in a query

sample query using COUNT
```sql
SELECT COUNT(*) AS 'no. employee on prod. y'
	FROM works_on
	WHERE pno = 
		(SELECT pnumber
		FROM project
		WHERE pname = 'productY'
		);
```

// note: single value, use =, single or more use IN

## GROUP BY ... HAVING
recall 
```sql
SELECT ... 
FROM ... 
WHERE ... 
GROUP BY ...    <--
HAVING ...      <--
ORDER BY ...
```

### GROUP BY
allows the combining of rows of a table together so that all occurrences within a specified group are together
aggregate functions can be applied to these groups

// the aggregate functions are applied in the SELECT clause, not in group
// GROUP BY must mention all the arguments in the SELECT clause unless they are involved in an aggregate

example
```sql
SELECT dno, COUNT(*) AS num_emps
FROM employee
GROUP BY dno;
```
// output
dno     | num_emps
1         | 1
4         | 3
5         | 4

HAVING is just a conditional addition to that

> #databases #sql