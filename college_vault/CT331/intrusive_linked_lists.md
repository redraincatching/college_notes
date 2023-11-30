# intrusive linked lists
a variation of linked lists where the links are embedded into the structure that's being linked
in a typical implementation, a list node contains a ``` data ``` pointer to the linked data, and a ``` next ``` pointer to the next node in the list

[diagram]

in an intrusive implementaion, the node contains the ``` next ``` pointer, but no ``` data ``` pointer, because the list is embedded in the linked object itself

[diagram]

## structure
```c
typedef struct list {
    struct list *next;
} list;
```

this struct is then embedded in another struct that will be linked, for example:
```c
typedef struct item {
    int val;
    list items;
} items;
```

## usage
to add a new item i2 to the list of i1, you set the items.next pointer to the address of i2.items:

```c
item* i1 = create_item(16);
item* i2 = create_item(18);

i1->items.next = &i2->items;
```

you can access the object that contains a list node by first getting the address of the list object (e.g. i1.items.next), and then subtracting the offset of the list member from the address of the list object
the offset here is the number of bytes a member is positioned from the beginning of its containing object

[diagram]

consider a list object in an object i2 at memory address 0x18. the list member is offset 8 bytes from the beginning of the item data structure. therefore, the beginning address is 0x18 - 8 = 0x10.
in gcc-compiled c, you can subtract bytes from a pointer by casting it to a void pointer (which has a size of one byte)
you can then subtract bytes from the pointer val without it being scaled to num * sizeof(structure):

```c
item* _i2 = (void* ) (i1->items.next) - 8;
```

> note: this isn't legal in c, but is supported by gcc

this clearly isn't portable, so instead of subtracting an abstract value, we use the offsetof macro
```c
item* _s2 = (void* ) (i1->items.next) - (offsetof(item, items));
```

to summarise,
- the list node is embedded in a containing object
- the list node points to another list node embedded in the linking object
- the base address is calculated by subtracting the offset of the list member from the memory address of the linked list object

---

## why?
obviously pointer arithmetic makes this much more complex than normal liked lists, so why use it?
two main reasons:
- fewer memory allocations
- less cache thrashing

intrusive linked lists only require one allocation and dereference per access, as opposed to the normal two

---

## doubly and circularly linked lists
### doubly linked list
a linked list that keeps a next and prev pointer

[diagram]

the struct would look something like this:
```c
typedef struct dlist {
    struct dlist *next;
    struct dlist *prev;
}
```

this makes insertion and deletion much each, because you only need a reference to a single node to delete them

### circularly linked list
[diagram]
a linked list that never points to null, the last node points to the first node
in a doubly linked circular list, the first also points to the last

---
## implementation
linux includes a few types of linked list, most of which are defined in include/linux/list.h


> #paradigms #c 
