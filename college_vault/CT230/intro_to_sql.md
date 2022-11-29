# sql
features:
- standardised since 1987
- based on relational algebra
- all relational, set, and hybrid operators are supported, but sql has additional operators
- american national standard institute (ansi) and international standard organisation (iso) form sql standards committees
	-> recent standards include xml-related features

## ansi/iso sql
often, vendors can create a lack of portability, so we will look at the standardised sql syntax
comprises three components
- ddl: data definition language
- dcl: data control language
- dml: data manipulation language

### dcl
used to control access to the database
useful for multiuser systems, database administration

**typical commands**
- GRANT
- REVOKE

### ddl
used to define schema
backend of design interfaces

**typical commands**
- CREATE
- ALTER
- DROP
- ADD
- CONSTRAINT

### dml
4 statements only
- SELECT
- INSERT
- UPDATE
- DELETE

---

## datatypes
3 main types
### String
- char(_size_)
	fixed length from 0 to 255, default 1
- varchar(_size_)
	variable length, 0 to 65535
- text
	string

### date/time
- date
	format: yyyy-mm-dd
- time
	format: hh:mm:ss
- datetime
	format yyyy-mm-dd hh:mm:ss
- year
	4-digit

### numeric
- integers
	tinyint - 1 byte
	smallint - 2 bytes
	mediumint - 3 bytes
	int - 4 bytes
	bigint - 8 bytes
- bool
	0 is false, nonzero is true
- FLOAT
	4-bytes, single precision floating point
- DOUBLE
	8-byte, double precision
- DECIMAL(_size_, _d_) or dec(_size_, _d_)
	fixed-point number
	size: total number of digits, max 65, default 10
	d: number of digits after decimal point, max 30, default 0

others fall outside these catagories, e.g. unicode char, blob, json

---
>autonumber
>AUTO_INCREMENT
>specifying an attribute to be auto_increment forces the table to generate a number automatically, and increment it
>useful for making an "artificial" primary key
>default val is 1, as is default increment
---
## sample create table
```sql
CREATE TABLE dept_locations {
    dnumber int NOT NULL,
    dlocation char(20),
    PRIMARY KEY (dnumber, dlocation),
    FOREIGN KEY (dnumber) REFERENCES departments(number)
}
```


> #databases #sql