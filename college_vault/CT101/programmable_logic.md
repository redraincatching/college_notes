# programmable logic devices
most of the [[sequential_logic|sequential logic circuits]] are available on a ttl ic chip
circuits can be constructed using these chips, and wiring them together
&nbsp;&nbsp;&nbsp;an alternative would be programming all of the components into a single chip
&nbsp;&nbsp;&nbsp;&nbsp;an example of this would be a **PLA**, or a programmable logic array, that contains one or more and/or gates


## programmable logic array - PLA
![[pla.png]]
- the inputs and their complements are made available to several and gates
- the x indicates that the value is input to the and gate
- the outputs from these and gates are passed to the or gates, the output of which which form the output of the chip


## programmable array of logic - PAL
![[pal.png]]
- similar to PLA, however the or gates are hardwired, not programmable

both PAL and PLA are limited by the fact that they can only implement [[combinational_logic|combinational logic]], and do not contain any latches or flip-flops

---
## programmable logic device - PLD
a more complex device, needed to realise sequential circuits
usually made up of logic blocks, with the ability to interconnect them
-> each logic block is made out of macro cells, that may be equivalent to a PAL with an output flip-flop
-> the i/o pins of the PLD can be configured to the desired function

### complex programmable logic devices - CPLD
![[CT101/images/cpld.png]]
an array of PLDs
has global routing resources for connections between PLDs, and between PLD and I/Os

---
## field programmable gate array - FPGA
most complex
contains an array of cells, each of which can be programmed to realise a function
programmable interconnects between cells
include flip-flops, allowing the design and implementation of complex sequential logic
![[fpga.png]]

### basic FPGA operation
![[fpga_operation.png]]
- load configuration memory
-> defines system function
- changing configuration memory
-> changes system function
-> can change at any time, even at runtime

---
## programmable logic blocks - PLB
![[plb.png]]
can perform any logic function
- look-up tables (LUTs)
-> combinational logic or in RAM
- flip-flops
-> sequential logic
- special logic
-> add, subtract, multiply
-> count up or down

### programmable interconnect
wire segments and programmable interconnect points (PIPs)
- cross-point PIPs - connect/disconnect wire segments
	- to turn corners
- break-point PIPs - connect/disconnect also
	- to make long and short signal routes
- multiplexer (MUX) PIPs select one of many wires for output
	- used at PLB inputs
	- primary interconnect for new FPGAs

![[pips.png]]

> #computing_systems 