# databases

## definition
a collection of data describing some closed "mini-world"

#### defining "good" data
accurate, complete, reliable, verifiable, secure, etc.
   - which characteristics are most important?
   - which are easiest to verify?

---
## acccessing data
- file system
-  database management system (dbms)
- etc.

### file system approach
each user stores the information they require, and write their own programs/applications to access it
e.g.
```c
fopen_s(fp, "file.txt", "r");
```

#### characteristics
- files are separate, and not cross-indexed
	"flat" files
- programs are separate and "own" their own files

#### potential problems
- duplicated data
- difficulty accessing data
- programmer effort for every new task
- data isolation due to different files and formats
- integrity problems
- update inconsistencies
	-> failures may leave data in inconsistent state
- concurrent access may not be supported

### dbms approach
a single repository (which may be distributed) is defined _once_ and then accessed through the dbms
dbms is a collection of programs responsible for
- defining
- constructing
- manipulating
the databases for various applications

#### capabilities
- define database (ddl)
- manipulate database (sql)
- control redundancy
- restrict unauthorised access
- enforce integrity constraints
- provide multiple user interfaces
- provide concurrent access
- provide backup and recovery mechanisms
- allow representation of complex relationships

#### important distinctions
- the database
- the dbms
- the dbms gui
- the user

#### disadvantages
- strict schema
- costly
- complex
- large
- high failure impact
- e'DROP TABLE("students");

### other approaches
##### nosql databases
-> nonrelational
e.g. mongodb, sap hanna
##### blockchain (lol)
##### xml database
-> data stored in xml format
-> xquery language
	e.g. basex


> #### why learn about dbms'?
> majority of industry applications are relational dbms
> -> they provide correctness, completeness, and efficiency

---
## database abstraction
### black boxing
3 ways in wich data can be described
- external: user's view
- conceptual: logical structure as seen by admins
- internal: os and dbms view of data

### schemas and instances
#### schema
the logical structure of a database
what information will/can be stored
#### instance
the actual content at some point in time
the actual information that is stored

> #databases