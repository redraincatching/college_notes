# computing systems

instruction set architecture (isa) provides a good understanding of what a microprocessor can do, but provides no information on how to use the processor in a bigger system.
&nbsp;&nbsp;&nbsp;&nbsp;in order to design a computing system, more information is required

## computer system subsets
- cpu
- buses
- memory
- input/output

![[computing_systems_organisation.png]]
** ==// address bus is unidirectional== **

---
### system buses
set of wires that interconnect all of the components (subsystems) of a computer
- a source component sources out data onto the bus
- a destination bus

#### i/o buses
read/write data from input and output devices

#### address buses
***==!!! unidirectional !!!==***
cpu reads/writes data from the memory by addressing a unique location, and the memory uses the data based on this address

each i/o device has its own unique address, and with act according to instructions addressed to it
> /\*
> the cpu never reads the address bus, only points to the location, and other subsystems deal with that
> \*/

#### data bus
when the cpu fetches data from memory, it first outputs the address, and the data bus retrieves the data stored at that location

#### control bus
address and data buses consist of n lines, which combine to transmit one n bit value, whereas the control bus is a collection of individual control signals
&nbsp;&nbsp;&nbsp;&nbsp;these signals indicate whether data is being read or written
&nbsp;&nbsp;&nbsp;&nbsp;(a control bus)

---
### cpu

chip that acts as the control centre for all operations.
&nbsp;&nbsp;&nbsp;&nbsp;it executes instructions which are contained in the system memory

basic operations include
 - transfer of data between itself and the memory section
 - manipulation of data in the memory section, or stored internally
 - the transfer of data between itself and i/o devices
 
the cpu provides all timing and control signals necessary to transfer data from one point to another in the system
made of the [[cpu_programming_models#control unit|control and logic units]]
&nbsp;&nbsp;&nbsp;&nbsp;_// control unit does the above, the logic unit performs operations_
see [[cpu_functions]]

---
### programs
a number of cpu [[cpu_programming_models|instructions]]
##### instruction components
- an instruction code (or OPCODE)
- one or more operands (data which the instruction manipulates)

instructions specify to the cpu what to do, where the data is located, and where to put the output, if any

instructions are held in the memory, and are transferred one at a time to the cpu. instructions follow one another in successive memory locations, and the cpu keeps track of the instruction that it is executing by using an internal counter known as the program counter (or instruction pointer)

---
### types of computer architecture
###### von neumann
- allows data and instructions to be mixed and stored in the same memory module
- more flexible and easier to implement
- suitable for most general purpose processors

###### harvard
- uses separate memory modules for data and instructions
	- means that multiple instructions can be executed simultaneously
	- however, the instructions become read-only
- easier to pipeline, and there are no alignment issues
- higher memory throughout
- suitable for dsp (digital signal processors)

see also:[[cpu_programming_models#harvard vs von neumann architecture|cpu programming models]]

---
## address locations
(see also [[addressing_modes|address locations]])
memory consists of a sequential number of locations, each of which are a specific number of bits wide
- 8-bit (pc-8088), which is a byte wide
- 16-bit (xt-8086, at-80286)
- 32-bit (386dx, 486sx, 486dx)
- 64-bit (modern systems, pentium and up)

generally expressed in hexadecimal
size is number of locations times the total number of bits
&nbsp;&nbsp;&nbsp;&nbsp;32 bit limited to $2^{32}$, or about 4GB of main memory
the processor selects a specific address by placing that address on an address bus

the total number of locations that can be accessed by a processor is its physical address space
-> determined by the size of an address bus
&nbsp;&nbsp;&nbsp;&nbsp;16 bit bus -> 65kb (65535 locations)
&nbsp;&nbsp;&nbsp;&nbsp;32 bit bus -> 4gb

##### access times
refers to how long it takes the processor to read or write to a specific location in the chip

##### volatility
whether or not memory is lost when the computer is switched off

> ![[read-write_operations.png]]
> a) read
> b) write

---

## i/o devices
(see also [[i-o_subsystems|i/o subsystems]])

peripheral devices that allow input and output to occur
i/o read/write are similar to memory read/write
a processor may use
- memory mapped i/o - the address of the device is stored in the direct memory space, and the cpu accesses it the same way that it would access memory
- isolated i/o - the processor is similar, but the i/o addresses are stored in a different location, and so an extra control bus signal must be sent for the addresses to be called

> #computing_systems 