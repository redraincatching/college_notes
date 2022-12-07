# memory management
in multiprogramming systems, the user part of memory is subdivided to accomodate multiple processes
the task of subdivision is carried out by the os, and is known as memory management
// windows is bad at it lmao
memory needs to be allocated efficiently to pack as many processes into memory as possible

## requirements
- relocation
loading the program dynamically into an arbitrary memory space, whose adress limits are only known at execution time
- protection
each process should be protected against unwanted interference from other processes
- sharing
any protection mechanism should be flexible enough to allow several processes to access the same portion of main memory

## organisation
- logical
most programs are organised in modules
some are unmodifiable, read-/execute-only
others can be modified
the os must take care of the possibility of sharing modules across processes
- physical
memory should be at least two-level
the os should hide this fact and perform memory movement without the programmer's knowledge

> ![[memory_hierarchy_design.png]]
> memory hierarchy recap
>

### cache review
cache hit - data found in cache
cache miss - data was not in cache

![[cache_review_0.png]]
- typical computer applications access data with a high degree of locality of reference
temporal locality:
data is requested that has been recently requested already
spatial locality:
data is requested that is stored physically closed to data that was recently requested

- when a system writes data to the cache, it must at some point write that data to main memory following write policies
	- write-through
		write is done synchronously both to cache and main memory
	- write-back
		initially, writing is only done to cache
		the write to main is postponed until it is about to be replaced by another cache block

## process address space
when accessing memory, a process is said to operate within an address space
-> data items are accessible within the range of addresses available to the process

the number of bits allocated to specify the address is an architectural decision
early computers had 16 bits for addresses, allowing for 2^16 bits of direct addressing
the 32 bits
now, most computers have 64 bits for addressing
we say that such a system gives a virtual address space of 16 exabytes 
(although physical memory is almost certainly less than this)
            
### address binding
an address used in an instruction can point anywhere in the virtual address space
it must still be bound to a physical memory address
programs are made of modules
compilers or assemblers do not know where the module will be loaded in physical memory
addresses must be translated to physical
two ways of doing this

#### static address binding
os is responsible for managing the memory, so it will give the loader a base address of here to load the module
the loader converts each virtual address in the module to absolute physical addresses by _adding_ the base address
this is static binding
                
simple, easy to implement
**however**:
once loaded, the code or data of the program cannot be moved into another part of memory without chanigng the static binding
all the processes executing in such a system would share the same physical address space
- no protection if an addressing error occurs
- even os code is exposed

#### dynamic address binding
keeps loaded address _relative_ to start of process
##### advantages
- a given program can run anywhere and can be moved anywhere by the os
- unaware where it is in physical memory, as all locations are relative and virtual
- these can isolated using protection mechanisms

#####  disadvantages
- a mechanism is needed to bind the instructions being executed to the actual locations that they are being executed on

##### _hardware assisted_ relocation and protection
dynamic binding must be implemented in hardware, since it introduces translation at every part of memory access

the basic requirement for modules is to be held contiguously in physical memory and contain addresses relative to their start location
- the first location is called the base of the address
suppose an instruction is fetched and decoded, and contains an address reference
- this address is relative to the base, so the value of the base mmust be added to it in order for the correct address to be sent to the memory controller

![[hardware_relocation_0.png]]

the simplest form of dynamic binding hardware is a base register and a memory management unit (mmu) to perform the translation
the os must load the base register as part of setting up the state of a process before passing control to it

problem:
this approach provides no protection between processes
we cannot be sure that a process is not using an address that is not in its address space

![[hardware_relocation_1.png]]

solution:
combine the relocation and protection in on unit
this is done by adding a limit register that delimits the upper bound of the address space in physical memory

---
## segmentation and segmented virtual memory
in practice, it is not very useful for a program to occupy a contiguous range of physical addresses
such a scheme would prevent two processes from sharing the same code
e.g. two instances of the same process using different data
this can be achieved if the system has two base registers and two limit registers, allowing for two separate memory ranges, or two segments per process

### segmented virtual memory
![[seg_virtual_memory_0.png]]
two processes sharing code segments but having private data segments
![[seg_virtual_memory_1.png]]
most significant bit of virtual adress is taken as segment identifier, with 0 for data and 1 for code
![[seg_virtual_memory_2.png]]
- within a single program, it is usual to have separate areas for code, stack, and heap
- language systems have conventions on how the virtual space is arranged
- code segments won't grow in size
- heap will grow
- stack grows in the oppsite direction
- in order to realise the relocation, three segments is preferable

### segmented virtual addresses
the segment is the unit of protection and sharing
2 ways to organise these
- virtual address space is split into a segment number and a byte number within that segment, usually fixed by system designer
![[seg_virt_add_0.png]]]
- the segment number is supplied separated from the offset portion of the address
// done in x86 processors

#### segmented address translation
![[seg_virt_add_1.png]]
for dynamic address translation in the os
hardware must keep a segment table for each process in which the location of each segment is recorded
a process can have many segments, and only those being currently used for instruction fetch and operand access need to be in main memory
if an address is presented for a segment that is not present in main memory, then the address translating hardware generates an addressng exception
// handled by the os

#### address translation in segmentation system
![[seg_virt_add_2.png]]


## paged virtual memory
aims to resolve fragmentation and storage allocation issues

typical page size is small
1-4kb
the limited size of physical memory may cause problems
therefore
a portion of disk storage can be used as an extension (swap space)
the pages of a process may be in ram or in this backing storage
the os must manage two levels of storage and the transfer between them
it must keep a page table to record information for each process
present bit - whether page is in ram or not
modify bit - if page has been altered since last loaded
// if false, does not need to be written to disk when swapped out


### segmented memory
segments are swapped between disc and main memory as needed
program segments correspond to blocks of program code such as procedures and functions
data segments correspond to data structures such as stacks, queues, or graphs
segments vary in size
the os knows the start location and size of each segment in physical memory
each segment is atomic - it is either all in ram, or not in ram at all
segmentation can result in memory fragmentation
- a lot of small gaps between segments
segments can be "pushed together" to allow large processes to be loaded

### paged memory
memory split up into small, equally sized sections called pages, or page frames
a single aplication may occupy multiple pages, which are not necessarily contiguous
each application has its own view of memory - logical memory - in which it is the only process loaded
a logical lookup table - the page table - records the actual locations of the pages in physical memory
unused pages may be "paged out" to virtual memory - to the swap file - and paged back in when needed
***disk threshing*** - when too much paging activity is taking place, slowing down execution

#### paging example
![[paging_example_0.png]]
A has four pages
B has three
C has four
D has five
![[paging_example_1.png]]
various page tables at a time
each page table entry (pte) contains the number of the frame in memory that holds the page
in addition, all free spaces are usually listed
![[paging_example_2.png]]

### paged address translation
![[paged_address_translation.png]]
translation of virtual address (page + offset) into physical address (frame + offset)
page table is stored in main memory
each process maintains a pointer to the table
the page number is used to index that table and lookup the corresponding frame number

processes could occupy huge amounts of memory
e.g., in a 32 bit os with pages of size 4kb
- 12 bit offset
- 20 bits for page number
this means $2^20$ entries could be in each page table
// each entry is then 4 bytes, each table is 4mb -> too high
solution: a two-level scheme
root page table with $2^10$ entries, constantly residing in main memory
pointing to user page tables that can reside in main or on the disk
![[paged_address_translation_1.png]]
the first 10 bits of a virtual address are used to find a pte of the user page table
next 10 bits find the pte of the page referenced by the virtual address
![[paged_address_translation_2.png]]
however:
every virtual memory reference causes two physical accesses
- one to find the appropraite user page table
- one to find the desired page
this is slow
to combat this, we use:

#### TLB - translation lookaside buffer
![[tlb.png]]
a kind of high speed cache
contains the most recently used pages
present nearly every time paged memory is used

the virtual page number is extracted from the virtual address and lookup is initiated
if multiple processes are being run, then special care needs to be taken so the wrong process' pages are not extracted from cache

##### if a match is found (tlb hit)
the physical base page is appended to the offset to form the complete physical address
the flags field indicates access rights and other information
##### if a page is in main memory but not tlb (tlb miss)
a new entry in tlb is created for the page
##### if page is not in the main memory
the lookup will fail, and the hardware will raise an exception - a page fault
the os handles this

> #computing_systems [[memory_subsystems]]