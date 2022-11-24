# strcpy from scratch
overwrites a string with another
let's build our own with [[c_pointers|pointers]]

```c
char* strcpy_clone(char* target, char* origin);

void main() {
    char t[100];    // target
    char o[] = "this is the origin string.";    // string to be copied
    char* tp = strcpy_clone(t, o);
    printf("%s\n", tp);
}

char* strcpy_clone(char* target, char* origin) {
    char* target_start = target;    // record the location of the start of the string
    while(*origin != '\0') {
        *target = *origin;
        target++;
        origin++;
    }
    *target = '\0';
    return target_start;    // return the start of the array
}
```

> #c #programming 