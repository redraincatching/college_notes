# addressing modes
![[addressing_modes.png]]
        
when a [[cpu_programming_models|microprocessor]] accesses memory, it needs to specify which address it wishes to access
- several addressing modes to generate this are known, and a microprocessor instruction set architecture may contain some or all of these
- in the following examples, we will use LDAC instructions
_// loads data from a memory location into the AC, or accumulator register_

###### direct mode
![[direct_addressing_mode.png]]
- instruction includes the A memory address
- LDAC 5: accesses memory location 5, reads the data, and stores it in AC
- usually used to load variables and operands into the cpu

###### indirect mode
![[indirect_addressing_mode.png]]
- starts like direct mode, but the first location doesn't hold the data to be accessed itself, it's a pointer to the operand
- LDAC @5 or LDAC (5)
- used for relocatable code and data

###### register direct mode
![[register_direct_addressing_mode.png]]
- like direct, but specifies a register instead
- LDAC Rx, copies what value is stored in Rx into AC
- no memory access, so very fast
- very limited address space

###### register indirect mode
![[register_indirect_addressing_mode.png]]
- LDAC (Rx)
- one fewer memory access than indirect mode

###### immediate mode
- not specifying an address, is the actual data to be used
- LDAC #5
- fast, no memory reference

###### implicit addressing mode
- doesn't specify an operand
- instruction does this implicitly, as it always applis to a specific register
- e.g. CLAC, always clears the accumulator

###### displacment addressing mode
![[displacement_addressing_mode.png]]
- effective address = a + (r)

###### relative adressing mode
- special case of displacement, where the displacement is an offset
- the effective address is A + (PC)
- the same relative instruction will produce different addresses at different locations in the program
- useful for short jumps, and relocatable code

###### indexed addressing mode
- works like relative addressing, instead of adding A to (PC), it is added to the contents of an index register
- LDAC 5(x) = 5 + contents of index, to accumulator
- good for accessing arrays

###### ***based*** addressing mode
- similar to indexed mode, except the index is replaced by a base address register
- A holds displacement, R holds a pointer to the base address


> #computing_systems 