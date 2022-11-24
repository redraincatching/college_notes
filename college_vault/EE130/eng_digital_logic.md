# Digital Logic
## basic logic functions
AND - produces a high output only if all inputs are high, performed by an AND gate
OR - produces a high output if any input is high, performed by an OR gate
NOT - changes one logic level to another, performed by an inverter

---

## logic circuits
##### comparison function
[[eng_digital_signals|and, or, and not functions]] can be combined to form various functions

the comparison function indicates whether a binary value is greater than, equal to, or less than another
&nbsp&nbsp&nbsp&nbspperformed by a comparator
![[comparison_function.png]]


##### arithmetic functions
include addition, subtraction, multiplication, and division
![[arithmetic_functions.png]]

##### encoder function
a circuit that converts information into a coded form
![[encoder_function.png]]

##### decoder function
circuit that converts binary code to a nonbinary code of some kind
_// based_
![[decoder_function.png]]

##### data selection function
- multiplexer
a circuit that connects one of several data inputs to a single data output line, also called a _mux_
![[data_selection_function.png]]
- demultiplexer
a circuit that connects one data input line to one of several data output lines, also called a _demux_

##### counting function
counter:
a sequential device, a state machine that has a unique internal sequence of states

used to count events, or generate output sequences represented by changing levels or pulses
![[counting_function.png]]

---
## Programmable Logic Devices

programmable logic devices (plds) are an alternative to fixed function devices, and can be programmed for a specific purpose.
&nbsp&nbsp&nbsp&nbspin general, they cost less and use less board space than fixed function devices.
![[pld.png]]

#### pld hierarchy
![[programmable_logic_hierarchy.png]]

###### simple programmable logic devices
- programmable array logic (PAL)
can be programmed once, has a programmable array of AND gates, and a fixed array of or gates.

- generic array logic (GAL)
similar to PAL, but can be reprogrammed
![[galpals.png]]

###### complex programmable logic devices
devices that contain multiple splds 
![[cpld.png]]

see also: [[programmable_logic|ct101 - programmable logic]]

> #engineering #digital 