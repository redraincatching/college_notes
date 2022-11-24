# Strings
a collection of characters
// specfically an array of characters, in c

syntax
```c
char name[] = "scooby doo";
            // there is no variable type "string"
            // and yes, that's so dumb
```
---
## Printing Strings

```c
#include <stdio.h>
        void main() {
            char string_example[] = "hello";
            for (int i = 0; i < 5; i++) {
                printf("%c", string[i]);
            }
            printf("\\n\\n");
        }

        // this would work, but it sucks
				// possibly useful for checking individual letters/characters
```

### Quicker way of printing strings

```c
int i = 0;
        while (string_example[i] != '\\0') {
            printf("%c", string_example[i]);
            i++;
            }

        // sucks less, but still sucks
        // this is better

        printf("%s", string_example);
            // yeah, that's literally it
```

**→ strings vs. character arrays**
strings are terminated by the special character \0 -> this lets the compiler know that it's the end of the string so in our array string_example above, printf("%c", string_example[5]); would output "\0"

---
## Scanning strings

normally, you'd need the *&* symbol when scanning in variables
this isn't the case for strings, and the reason why is a bit technical
>*char array names decay to pointers in c, and the string name already points to the first element of the string, so no & necessary*

syntax
```c
char <stringname>[<length_of_array>];
scanf_s("%s", <stringname>, <length_of_array>);
    // you need to specify the length of the array
```

>note: scanf_s is limited to only one word by default, and will stop reading in after a space. 
>// this is only an issue with scanf_s, you can initialise strings with spaces with no issue

### Scanning Multiple Words

option 1:
&nbsp&nbsp&nbsp&nbspcreate multiple arrays, read in at separate times
&nbsp&nbsp&nbsp&nbsp// this sucks

option 2:
*✨flags✨*
```c
scanf_s("%[^\n]%*c", string_example, 10);
```

the \[^\n\] flag sets scanf_s to keep reading in characters until it reads the newline character, not the default space
&nbsp&nbsp&nbsp&nbsp// can be used for any character
the %\*c removes the newline from the input buffer

---
#### How long is a (piece of) string?

the length of a string is the number of characters up to (but not including) the string terminator
&nbsp&nbsp&nbsp&nbspe.g. "august 10\0" - length of 9, not 11

the size of a string, however, is that length plus one

##### finding the length of a string

option 1:
just count with a loop

```c
char string[100] = "this is some random text";
int len = 0;
while (string[len] != '\\0') {
	len++;
}
printf("length of string = %d\\n", len);
```

option 2:
use the strlen() function, part of the <string.h> library

---
### Data into Strings

to reassign a string, you can't just type
```c
this_string = "hi";
```

you need to use strcpy_s(), also in string.h

**syntax**

```c
strcpy_s(<string_name>, <length>, <new_string>);
// e.g.
strcpy_s(str_name, 50, "my name is margo");
```

---
## Common string functions

strcpy\_s() - copy one string to another
&nbsp&nbsp&nbsp&nbsp→ strncpy\_s() - copy n characters from a string to another
strcat\_s() - concatenate two strings
&nbsp&nbsp&nbsp&nbsp→ strncat\_s() - concatenate n charatcers from one string to another
strcmp() - compare two strings
&nbsp&nbsp&nbsp&nbsp **_// returns false if strings match_**
&nbsp&nbsp&nbsp&nbsp→ strncmp() - compare n characters from two strings

```c
// syntax for n functions
strncpy_s(<string_name>, <length>, <new_string>, <n>);
strcat_s(<string_name>, <length>, <to_cat>, <n>);
strcmp(<str_name>, <string_to_compare>, <n>);
```
---
### puts

a function that prints a string to the screen

**syntax**

```c
puts(<string>);
```

why use it over printf?
-   simple
-   less computationally expensive
-   more secure

// basically, if you're only printing a string, use puts, if it's anything else, printf

---
### gets

~~trash~~ a function that reads string input from the keyboard

**syntax**

```c
gets(<string>);
```

uses
- only for strings
- only stops reading on a newline character

*// but for some reason doesn't flush that newline from the buffer? stupid gets*

---
## sscanf\_s

for parsing data of a fixed format
useful for databases, or other circumstances where you know the format, and know that it won't change

**syntax**
```c
sscanf_s(<name_of_string>, "<format>", <output>);
// e.g.
puts("enter 'firstname' 'surname 'dd/mm/yyyy"); // firstly, get the string
gets(string);
sscanf_s(string, "%s %s %d/%d/%d", firstname, 20, surname, 20, &dd, &mm, &yyyy);
	// then, parse it with sscanf_s
```
---
### arrays of strings

list of strings, stored as a [[c_arrays#2d Arrays|2d array]]
&nbsp&nbsp&nbsp&nbsp→ each row is a different string
&nbsp&nbsp&nbsp&nbsp→ each column is a different character

---
## Strings and Functions
strings, as usual in c, are weird and fucky
so, if we want to return a string as a function value, we have to declare it like this

```c
const char* string_func() {

}
```

what this actually does is returns a [[c_pointers|pointer]] (\*) to the first element of a string
*// note: %p or %X can be used to access pointers*

if we want to pass a string as a value to a function, we have to use char* again, this time as an argument in the prototype

```c
void string_func(char* string) {

}
```

> #c #programming
> [[c_standard_input-output_library]] [[c_arrays]]