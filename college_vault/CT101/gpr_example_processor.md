# gpr example processor
consider a simple gpr architecture
- 32 registers, r0-r31
- value of r0 is always 0

data types
-> 8-bit bytes, 16-bit half-words, 32-bit words (integer data)
-> operations work on 32-bit integers
-> 8- and 16-bit operands are loaded into the 32-bit registers with the sign bit duplicated
    
addressing modes
- immediate (16-bit field)
- displacement mode (contents of register added to the 16-bit address field)

---
## GPR instruction examples
##### I-type instructions
![[gpr_i-type_instruction.png]]
e.g.
```gpr
LW R2, 50 (R3)      ;R2 <- 50 + contents(R3)
BNEZ R4, name       ;if(contents(R4) != 0) PC <- name, BNEZ "branch not equal zero"
```

##### R-type instructions
![[gpr_r-type_instruction.png]]
e.g.
```gpr
ADD r1, r2, r3      ;r1 <- (r2) + (r3)
```

##### J-type instructions
![[gpr_j-type_instruction.png]]
e.g.
```gpr
J name              ;PC <- name
JAL name            ;r(31) <- PC+4, PC <- name      "jump and link"
```
_// NOTE: see MIPS architecture_

---
## example processor implementation
![[gpr_processor_implementation.png]]
 
 #### instruction fetch (IF)
###### cycle
 - IR <- Mem\[PC\]         ;PC here is program counter
 - NPC <- PC+4
 
 ###### operation
send out the PC, and fetch the instruction from memory
increment the PC by 4 to address the next instruction, and store it in NPC, the Next Program Counter, register

#### instruction decode (ID)
"register fetch"
###### cycle
- A <- Regs\[IR_6…\_10\]               ;bits 6 to 10
- B <- Regs\[IR\_11…\_15\]              ;bits 11 to 15
- Imm <- ((IR_16)^16##IR\_16…\_31)    ;sign extending bits 16 to 31
###### operation
- decode the instruction, and access the register files to access the registers; the output of the general-purpose registers are read into two temporary registers, A and B, for use in later clock cycles
- the lower 16 bits of IR are also _sign extended_, and stored in the temporary register Imm, for later use

#### instruction execution (EX)
"effective address"
###### cycle
- memory reference instruction
	- ALUOutput <- A + Imm
	    - the ALU reads the operands to form the effective address, and places the result into the register ALUOutput
- register ALU instruction
	- ALUOutput <- A func B
		- the ALU performs the specified instruction, and places the result into ALUOutput
- immediate ALU instruction
	- ALUOutput <- A op Imm
		- ALU performs the operation indicated by the opcode on the value from A and Imm, and result is placed in ALUOutput
- branch instruction
	- ALUOutput <- NPC + Imm
	- Cond <- (A op 0)
		- the ALU adds the contents of NPC with the sign extended value of Imm to compute the address of the branch target, register A is checked to see if the branch is taken
		- the comparison operation op is determined by the branch opcode (e.g. op is "\=\=" for instruction BQEZ)

#### instruction memory access (MEM)
"branch completion"
###### cycle
- memory reference instruction
	- load
		- LMD <- Mem\[ALUOutput\]
	- store
		- Mem\[ALUOutput\] <- B
	- access memory if needed
		- if instruction is a load, then data returns from memory and is placed in LMD register (load memory data)
		- if instruction is a store, then the data from B register is written back into memory, at the location stored in the previous cycle in ALUOutput
- branch instruction
	- if (cond) {PC<-ALUOutput} else {PC<-NPC}
		- if the instruction branches, then the PC is replaced with branch destination address, otherwise it is replaced with the incremented PC, stored in NPC

#### instruction write-back (WB)
###### cycle
- register ALU instruction
	- Regs\[IR\_16…\_20\]<-ALUOutput
- immediate ALU instruction
	- Regs\[IR\_11…\_15\]<-ALUOutput
- load instruction
	- Regs\[IR\_11…\_15\]<-LMD

write the results back into the register file, whether the data comes from the main memory, or as a result of an operation (from ALU); the register destination can be in two positions, and is determined by the instruction type

> #computing_systems 
> [[gpr_architecture]]