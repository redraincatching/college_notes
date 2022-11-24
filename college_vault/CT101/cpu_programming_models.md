# cpu programming models

#### basic computer organisation
![[computing_systems_organisation.png]]
***==address bus is unidirectional==***

![[computer_organisation.png]]

---
#### harvard vs von neumann architecture
von neumann:
- allows instructions and data to be mixed and stored in the same memory module
- more flexible, easier to implement
- suitable for most general-purpose processors
- data is stored linearly

harvard
- uses separate memory modules for instructions and data
- easier to pipeline
- higher memory throughout
- suitable for digital signal processors

---
## programs
instruction sequences that tell the computer what to do
to the computer, these are made of a sequence of numbers that represent individual operations
- machine instructions
- a set of instructions that a processor can execute is known as the instruction set

### processor - instruction cycles
the procedure of processing an instruction by the microprocessor
- fetches the instruction from memory
- decodes the instruction, determines what process needs to be executed
- executes the instruction


![[processor_organisation.png]]
![[execution_unit_example.png]]
before we can actually carry out the operation, there are some primitive tasks that need to be carried out
-> in this case, we read the values a and b from memory, and load them into the registers
-> then we can call our add instruction
        
#### control unit
![[control_unit.png]]
the control unit controls the execution of the instructions stored in the main memory (retrieves and executes them)

---
## programming models
defines how programs access their operands, and how instructions are defined in their assembly language

processors with different models can offer a similar set of operations, but may require very different programming approaches

### stack based architecture
**FILO** data structure - first in, last out
- consists of locations, each of which can hold a word of data
- can be used to explicitly save/restore data

-> supports two operations
- push - takes one argument and places the value on the top of the stack
- pop - removes one element from the stack, saving it into a predefined register of the processor
-> used implicitly by procedure call instructions, if available in the instruction set

when new data is added to the stack, and all the contents is pushed down one location
consider the following code
```
push #10
push #11
pop
push #8
```

![[stack_visualisation.png]]


#### implementing stacks
###### dedicated hardware stack
- hardware limitation
- very fast

###### memory implemented stack
- limited by system's physical memory
- slow compared to hardware stack, since extra addressing has to take place for each operation

stack overflows can occur in each implementation
- when the amount of data in the stack exceeds the amount of space allocated to the stack
![[stack_implemented_in_memory.png]]
every push operation will increment the top of the stack pointer (with the word size of the machine)
every pop operation will decrement the top of the stack pointer

#### instructions in a stack based architecture
![[add_instruction_execution.png]]
        get their operands from the stack, and write the results to the stack
        advantage - takes little memory, no need to soecify the address of the operands in memory or registers
            push is an exception, as it needs to specify the instruction, either as a constant or an address

##### simple stack-based instruction set
```
	- push #a
 	   stack <- a
    - pop
 	   a <- stack (the value popped is discarded)
    - st            ;store
 	   a <- stack
 	   (a) <- stack        ;(a) is a register
    - ld            ;load
 	   stack <- a
 	   stack <- (a)
    - add
 	   a <- stack
 	   b <- stack
 	   stack <- a + b
    - sub
 	   a <- stack
 	   b <- stack
 	   stack <- a - b
    - and
 	   a <- stack
 	   b <- stack
 	   stack <- a & b (bitwise computation)
    - or
 	   a <- stack
 	   b <- stack
 	   stack <- a || b (bitwise computation)
```

writing programs for stack-based architectures is not easy, as stack-based processors are better suited for **postfix notation** than infix notation

- infix
 -> the traditional way of representing math expressions, with operations placed between operands
- postfix
the operation is placed after the operands

once the operation has been converted to postifx, implementing it in programs is easy

e.g.
-> 2 + (7&3)
-> 2 + (7 3 &)
-> (2 (7 3 &) +)

```x86-64
push 2
push 7
push 3
and [0], [1]
add [0], [1]    ;[0] = 5
```
> #computing_systems 