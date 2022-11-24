# structure pointers
structures take up the same amount of space as the individual variables would

e.g.
```c
typedef struct {
    int id;                 // 4 bytes
    char[21] firstname;     // 21 bytes
    char[21] surname;       // 21 bytes
    double balance;         // 8 bytes
    int day;                // 4 bytes
    int month;              // 4 bytes
    int year;               // 4 bytes
}account;                   // total memory: 66 bytes

account account1 = <...>        // initialise an account
account* acc_ptr = &account1    // now pointing at the start of the account

// now can access the contents of the struct the same way we would normally
printf("%s %s", account1.firstname, (*acc_ptr).surname);    // both work
```

## dereferencing struct pointers
we can also use the -> operator to dereference these variables in the struct
e.g.
```c
printf("%lf", acc_ptr->balance);
```

-> dereferences the pointer _and_ accesses the data member

---
## linking structures
linking structures is a powerful tool in c
when used with dynamic allocation, we can build chains of linked data structures of unlimited size on the fly

// dynamic memory allocation: the process of allocating memory during runtime

#### example code
```c
typedef struct{
    char name[100];
    struct person* child;   // second data member is a linked person struct
}person;

void display_person(person* p_ptr);

void main() {
    person p1 = {"mary jones", NULL};       // create first person
    person p2 = {"molly jones", NULL};      // create second person

    p1.child = &p2;             // now the first person "points" to their child
    person p3 = {"tom jones", NULL};        // create third person
    p2.child = &p3;
    display_person(&p1);        // and display
}

void display_person(person* p_ptr){
    person* child;
    printf("%s", p_ptr->name);
    child = p_ptr->child;
    // set new pointer to point towards the child named in the struct
    while (child != NULL){
        printf(", has child: ", child->name);
        child = child->child;
    }
    printf("\n");
}

/*
output:
mary jones, has child: molly jones, has child: tom jones
*/
```
> #c #programming 