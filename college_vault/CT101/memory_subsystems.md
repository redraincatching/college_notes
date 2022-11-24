# memory subsystems

## memory hierachy
![[memory_hierarchy.png]]

- registers
-> in the cpu
- internal or main memory
-> may include one or more levels of cache
-> r.a.m.
- external memory
-> backup storage

---
## memory types
### internal
![[memory_types.png]]
##### ram
- rw
- electric, byte-level erasure
- electric write mechanism
- volatile
##### rom
- r
- no erasure
- written with masks
- nonvolatile
##### programmable rom (prom)
- r
- no erasure
- electrically written
- nonvolatile
##### erasable prom (eprom)
- read-"mostly" (possible to program them, but not often, and require a special device)
- uv light, chip-level erasure
- electrically written
- nonvolatile
##### electronically erasable prom (eeprom)
- read-"mostly"
- electric, byte-level erasure
- electrically written
- nonvolatile
##### flash memory
- read-"mostly"
- electric, block-level erasure
- electrically written
- nonvolatile

### external
##### hdd
- magnetic disks
##### ssd
- solid state drive
##### optical
- cd (rom, r, rw)
- dvd
##### magnetic tape

---
## RAM
#### dynamic ram (dram)
like leaky capacitors

initially, data is stored in the dram chip, "charging" its memory cells to full
this charge slowly leaks out, but before it can go too low to represent valid data, a refresh circuitry reads the dram contents and restores the data to its original locations
-> (happens every few milliseconds)

#### static ram (sram)
like a register, once written, it doesn't need to be refreshed
faster and more expensive than dram
cache memory is constructed from sram in pcs

// both are volatile

### dram
- bits stored as charge in capacitors
	- charges leak, and need refreshing even when powered
- simpler construction, and smaller than sram per bit, though slower
- used for main memory in computing systems
- essentially analogue
	-> the level of charge determines the values

![[dram_structure.png]]
address line is active when the bit is being read or written
&nbsp;&nbsp;&nbsp;&nbsp;the transistor switch is closed, and current flows
- write
	- voltage to bit line (hi or lo)
	- then signal address line
	- charge is then transferred to the capacitor
- read
	- address line selected
	-> transistor turns on
	- charge from capacitor sent via bit line to sense amplifier
	-> compares with reference value to determine 1 or 0
	- capacitor charge is then restored

#### dram refreshing
- refresh circuit included on the chip
- disable memory array chip
- count through rows and select each in turn
- read contents and write it back (restore)
-> takes time, slows down apparent performance
-> when the refresh cycle is occurring, the memory is not available for normal use

### sram
- bits stored as on/off switches
- no charges to leak
- much more complex construction
- larger per bit
- used for cache

![[sram_structure.png]]
transistor arrangement gives stable logic state
state 1
- $c_1$ high, $c_2$ low
- $t_1\;t_4$ off, $t_2\;t_3$ on

state 0
- $c_1$ low, $c_2$ high
- $t_1\;t_4$ on, $t_2\;t_3$ off

address line transistors ($t_5$ and $t_6$) are switches

write
- apply value to b and complement to 'b

read
- value is on b

---
## ROM
permanent, non-volatile storage
used for
- microprogramming
- library subroutines (code)
- constant data
- systems programs (bios)

### types
- written during mnufacture (very expensive)
- programmable once, by special equipment, prom
- read-"mostly"
	- eprom
	erasable by uv light
	- eeprom
	much slower to write than read
	- flash
	can erase total memory electrically

### internal linear organisation
![[internal_linear_organisation.png]]
- 8x2 rom chip
- as the number of locations increases, the size of the address decoder increases rapidly
-> multiple dimensions of decoding can be used to solve this

internal 2-d organisation
![[internal_2-d_organisation.png]]
- high order bits ($a_2 a_1$) select the row
- low order bit selects the location in row

### memory subsystems organisation
![[memory_subsystems_organisation_1.png]]
two or more memory chips can be combined to create memory with more bits per location
![[memory_subsystems_organisation_2.png]]
or alternatively, combined to create more locations

---
## memory hierachy design
![[memory_hierarchy_design.png]]

faster as we go left
- buses let the different memory levels interact
- the overall design is a tradeoff between size, speed, and cost
_// this exploits the principle of locality_

### cache
the first level of memory hierarchy encountered once an address leaves the cpu
_// cache is often used as a catchall term whenever buffering is employed to reuse commonly occurring items_

every address reference first goes to the cache
- if the desired address is there, we have a "cache hit", and the content is very quickly brought from the cache into the cpu
- if not, we have a "cache miss", so the contents are retrieved from main memory, and stored in the cache

most software exhibits _temporal locality of access_, meaning that it assumes the same address will be accessed again soon
transfers between main memory and cache occur at a granularity of cache lines or cache blocks, around 32 or 64 bytes at a time.
- burst transfers like this receive hardware support and exploit spatial locality (it's likely that memory in similar locations will be used at similar times)

> ![[cache_organisation.png]]
> cache organisation

> ![[cache_structure.png]]
> cache structure

#### questions to consider
where can a block be placed in the upper level?
- block placement

how is a block found in the upper level?
- block identification

which block should be replaced on a miss?
- block replacement

how to deal with writes
- write strategy

##### block placement
![[block_placement.png]]
_// sample cache has 8 block frames, main memory has 32_
- direct mapped cache
each block only has one place where it can go
-> \<address\> mod \<no. of cache blocks\>
- fully associative cache
block can be placed anywhere
- set-associative cache
a block can be placed in a specific groups of blocks in the cache (a set)
\<address\> mod \<no. of sets\>
-> n sets, cache is n-way set associative

##### block identification
![[block_identification.png]]
caches have an address tag in each block frame that gives the block address, which is checked against the address coming from the cpu
- all tags are searched in parallel, since speed is critical
- a valid bit is appended to every tag to say whether this entry contains valid addresses or not

address fields:
- block address
	- tag - compared against for a hit
	- index - selects the set
- block offset
selects the desired data from the block

set associative cache
-> large index means large sets, few blocks per set
-> smaller index, associativity increases

##### block replacement
when a miss occurs, the cache controller must select a block to be replaced with the desired data
benefit of direct mapping is that the hardware design is much simpler

> #computing_systems 