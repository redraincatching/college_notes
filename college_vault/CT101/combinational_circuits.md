# combinational circuits
## buffers
a digital (or voltage) buffer is an electronic circuit element that is used to boost power _without changing the voltage waveform_
used to isolate the input from the output, providing either no voltage, or the same as the input voltage

##### regular buffer
passes the input to the output
purpose is to boost the signal of the input to a higher level (i.e. maintain 1 or 0 values)

##### tri-state buffer
(curse you perry the platypus)
has a data input, and also an ENABLE/CONTROLLER input
- if ENB=1, the buffer is enabled, and the input is passed to the output
- if ENB=0, the buffer is disabled, and the output will be in the high impedance state z

###### high-impedance state
the resistance is raised to a point where the flowing current is essentially zero
this state is used to effectively break connections

---
## multiplexer
a combinational circuit that selects binary information from one of the input lines, and directs it to the output line - functions as a selector

![[multiplexer_internal_structure.png]]
$S_1$ and $S_0$ and their complements are used to select input lines, the output of which is then passed to a tri-state buffer
![[mux_schematic.png]]

![[4_to_1_mux.png]]
multiplexers can be cascaded to select from a large number of inputs, see the above 4-to-1 multiplexer made of two 2-to-1 muxes.

---
## encoder
a circuit that changes a set of signals into codes
an encoder receives $2^n$ inputs, and outputs an n-bit value corresponding to the one input that has a value of 1
a 4-to-2 encoder is represented below
![[encoder.png]]
input: 4 data lines
- each input line has a corresponding binary number, and the output of the encoder is that signal (in our example, $S_1$ $S_0$ are our output bits)
- a decoder will take that output signal, and read the input signal from there

#### priority encoder
the same, but whenever one or more input is active, the output is set to correspond to the highest active input

---
## comparators
compare two input values or voltages
compares two n-bit binary values to determine which is greater, or if they are equal (reference voltage vs detected voltage)
![[1-bit_comparator.png]]

![[n-bit_comparator.png]]

---
## adder/half adder
_(not a snake)_
used to perform addition, subtraction, multiplication, and division
        
#### most basic: half adder
inputs two 1-bit values, x and y, and outputs their two-bit sum as bits C and S
&nbsp;&nbsp;&nbsp;&nbsp;C is the carry, S is the sum
![[half_adder.png]]

#### full adder
three inputs - one carry bit, two input bits
![[full_adder.png]]
two outputs - one carry, one sum

#### n-bit ripple adder
![[n-bit_ripple_adder.png]]
with the carry input, adders can be cascaded to produce an n-bit adder by connecting the carry output from one bit to the carry input of the next in sequence

---
## memory circuits
see also: [[memory_subsystems|memory subsystems]]
group of circuits used to store data
not strictly combinatorial in design, but can be used as a combinatorial component
- has some fixed number of memory locations, each containing a binary value of fixed length
- this size is denoted as the number of locations times the number of bits in each location

-> the address input of a memory chip chooses one of its locations
-> the data pins (one per bit in a location) are used to access the data
-> chip enable (CE) causes the data pins to output high impedance when active

#### ROM
![[rom_chip.png]]
non-volatile memory chip that is programmed externally, and can't be changed by the circuit itself
often used as lookup tables
non-volatile
-> has an output enable (OE) pin that must be active, or the data pins will be in high impedance


#### RAM
![[ram_chip.png]]
read/write memory that doesn't initially contain any data
bidirectional data pins
volatile
-> has a directional select signal r/w' pin to select which mode the chip is in

---
## combinational circuit design - l.e.d. display
7-segment decoder

![[bcd_to_7-segment_decoder.png]]

![[7-segment_display.png]]

![[7-segment_display_tt.png]]

![[7-segment_display_k_a.png]]
![[7-segment_display_k_b.png]]
![[7-segment_display_k_c.png]]
![[7-segment_display_k_d.png]]
![[7-segment_display_k_e.png]]
![[7-segment_display_k_f.png]]
![[7-segment_display_k_g.png]]

> [[combinational_logic]]
> #computing_systems 