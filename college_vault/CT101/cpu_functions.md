# instruction cycle
procedure of processing an instruction by the microprocessor
- FETCHES the instruction from the memory
- DECODES the instruction, determining what is to be executed
 - EXECUTES the instruction
 
 -> fetch-decode-execute cycle

### fetch phase
in the first phase, the processor generates the necessary timing signal to fetch the next instruction
the instruction is then transferred from memory to an internal location inside the processor (the instruction register)
![[fetch_cycle.png]]
in this diagram, the processor is ready to begin the fetch cycle


### decode phase
the processor transfers the instruction from the instruction register to the decode unit
it compares the instruction to an internal table, and when a match is found, the table contains the list of macro instructions required to perform the instruction
![[decode_cycle.png]]


### execute phase
the instruction is carried out, and then the instruction pointer is incremented to point to the next instruction
![[execute_cycle.png]]

> #computing_systems 