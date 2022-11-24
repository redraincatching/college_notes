# enumeration
enumeration is a user-defined datatype in the c language, used to assign names to variables
used with the enum keyword

for example:
in an ordering system, the status of an order could be
- open
- closed
- delivered
- cancelled

in an alarm system, it could be
- read
- asleep
- maintenance

underlying those names would need to be values
e.g.
- open      = 101
- closed    = 102
- delivered = 103
- cancelled = 104
![[enum_illustration.png]]

```c
// declaration
enum <variable_name> {<names>, <of>, <states>}; 
// 0-based index, of course

// instantiation
enum <variable_name> <object_of_this_enum>
// e.g.
enum days_of_week day;

// operation
<obj_enum> = <state>;
// e.g.
day = wed;
```

## enumeration using typedef
```c
typedef enum {<states>} <name_of_enum>;

// e.g.
typedef enum {mon, tue, wed, thurs, fri, sat, sun} days;
```

> #c #programming 