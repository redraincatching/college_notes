# modifying output

- AS
	rename or alias any tables found in SELECT or FROM
- CONCAT
	concatenate strings
- CAST
- CAST(expression AS datatype(length))
- ORDER BY
	last clause to order results
- ORDER BY \<attribute list\>
	ASC for ascending, DESC for descending
- LIMIT and TOP
	both select the first n tuples, however only limit is supported by mysql

example
```sql
SELECT
	CONCAT(fname, ' ', minit, ' ', lname) AS name
FROM
	employee
WHERE
	salary BETWEEN 50000 AND 80000
ORDER BY
	lname
LIMIT 6;

```

## sanitising data
for apostrophes in incoming data, either double the apostrophe ('') or escape it using backslash

> #databases #sql