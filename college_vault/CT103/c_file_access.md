# files
how do we access files?
- sequential access:
start at the beginning, and read in data as a continuous stream
- random access
jump around, reading and writing at different points

in order to read files, we need file pointers
a pointer used to manage and keep track of the files being accessed
a program needs a physical address to read/write from, and this is held by the file pointer
we open the file to set the pointer, and close it when we're finished

```c
void main() {
    FILE* fptr;
    fopen_s(&fptr, "<address>", "r");
    // note: backslashes in the address need to be escaped

    if (fptr == NULL) {
        printf("error opening file, exiting\n");
        return;
    }
    else {
        char c = fgetc(fptr);
        while (c != EOF) {      // EOF is end of file
            printf("%c", c);
            c = fgetc(fptr);
        }
    }
    fclose(fptr);

}
```

## writing to a file
the fopen_s function has a flag as its last argument, which tells the program how to open the file
- r : opens for reading. the file must exist
- w : creates an empty file for writing. if the file exists, it is erased
- a : appends to file. creates a new file if it doesn't exist
- r+: opens for reading and writing. file must exist
- w+: creates an empty file for reading and writing
- a+: opens a file for reading and appending

### actually writing to the file
most i/o functions have a corresponding file function, e.g. fprintf, however they take an extra argument - the file pointer

## reading from the file
- fgetc: reads one character at a time
- fgets: reads one array at a time, as a string. stops reading on a \n character

### fgets syntax
```c
fgets(<name_of_array>, <size_of_array>, <fptr>);
```
// the line being read is visible in the debugger

#### feof
returns true if fptr is EOF

### reading from a file more efficiently
```c
void read_file(char* filepath);

int data[1000];

void main() {
	char* filepath = "textfile.txt";
	read_file(filepath);
	
	printf("%d\n", data[420]);
}

void read_file(char* filepath) {
	FILE* fptr;
	char line[101];
	int i = 0;
	
	fopen_s(&fptr, filepath, "r");
	
	if (fptr != NULL) {
		while (fgets(line, 101, fptr) != NULL) {
			sscanf_s(line, "%d", &data[i], 101);
			i++;
		}
		
		fclose(fptr);
	}
}
```

---
## updating a file
updating records "in place" (i.e. reading/writing to them in their original position without destroying other records) is not something that you can do with only sequential access

### fseek()
moves the file pointer to allow reading/writing at different locations

function structure
```c
fseek(<FILE* fptr>, <long int offset>, <origin>);
```

- fptr is a file pointer
- offset is a long int that specifies the _number of bytes_ to skip forwards or backwards from the origin position
- origin tells fseek where to start searching

#### origin
// actually a macro defined by stdio.h
- SEEK_SET
beginning of file
- SEEK_CUR
current position in file
- SEEK_END
end of file

example
```c
fseek(fptr, 7, SEEK_SET);
```

if you reposition the file pointer over existing data, and start writing, you will overwrite the existing data

### ftell()
get the current file position of the stream

function structure
```c
long int ftell(FILE* fptr);
```

usage example
```c
fseek(fptr, 0, SEEK_END);
int len = ftell(fptr);
printf("size of file: %d bytes", len);
```

---
## file read issues
using fseek is useful with simple file structure that you know, however, most individual fields in records vary in length

problems reading data
1) fields of unpredictable length/content
multi word fields make %s useless
2) choosing an appropriate data structure
3) items with the same name, or one item in multiple places?
4) non-standard formats
5) missing/corrupt data, illegal characters
6) delimiters
7) date format
8) overall formatting rules


### parsing
analysing a string or text into logical syntactic components
[[fruits_basket_parsing.c|see here for an example]]

> #c #programming 