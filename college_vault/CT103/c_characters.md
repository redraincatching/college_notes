# Character Nonsense
## Testing Characters

there are a number of tests that we can use to analyse characters
we first need to include the _<ctype.h>_ library

**useful tests**
- isalpha - checks if the character is alphabetical (i.e. a letter) 
- isalnum- checks if the character is alphanumeric (letter or number) 
- isdigit - checks if the character is a digit 
- isupper - checks if the character is uppercase 
- islower - checks if the character is lowercase 
- isspace - checks if the character is a space

**syntax**

```c
<test>(<character>);
```
---
## Character Mapping

functions to convert a character case

```c
toupper(<character>); // converts a charcter to uppercase
tolower(<character>); // converts a charactaer to lowercase
```

> #c #programming
> [[c_standard_input-output_library]] [[c_strings]]