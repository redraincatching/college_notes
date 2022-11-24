# modulo 6 counter fsm
a 3-bit counter that cycles through counting from 000 to 101, and back again
doesn't use values 110 or 101
has an input U that controls the counter
- while U = 1, the counter increments its value on the rising edge of the clock
- while U = 0, the counter retains its value

the value of the count is represented as a three-bit value (V_2 V_1 V_0)
there is an additional output, C (carry), that is 1 when going from 5 to 0, and 0 otherwise
C remains 1 until the counter goes from 0 to 1

#### state table
![[dummy_state_table.png]]
// each state has to have a corresponding binary encoding

##### state diagram - [[mealy_and_moore#mealy machine|mealy]]
![[mealy_mod_6.png]]
arcs labelled $U/CV_2V_1V_0$


##### state diagram - [[mealy_and_moore#moore machine|moore]]
![[moore_mod_6.png]]

---

## implementation
converting the problem to a state table is the first step in the design process
next step is designing the system hardware
-> steps:
- assign a unique binary value to each of the states that the machine can be in
	-> a machine with n states needs $\log_2(n)$ bits
- design hardware to go from current state to correct next state
- generate the outputs using combinatorial machine

###### assigning states
any values can be assigned to the states, but some work better than others
this is an iterative process, first the designer creates a preliminary design to generate the outputs and the states, then modifies the state values and repeats the process
-> generally, the state should be assigned the same value as the associated output value
-> this way, the same logic can be used to generate the state and output

### mealy and moore implementations
![[generic_mealy.png]]
![[generic_moore.png]]
- the current state value is stored in the register
- the state values, together with the machine inputs, are input to a logic block (CLC) that generates the next state value and machine outputs
- the next state is loaded into the register on the rising edge of the clock signal


#### mod 6 counter - mealy
![[mod_6_mealy_implementation.png]]

the logic block is specific to every system and may consist of combinatorial logic gates, multiplexers, lookup ROMs and other logic components
_cannot include any sequential components_, as its value muse be generated in one clock cycle
contains two parts
- generates the outputs (f function, CLC1)
- generates the next state (g function, CLC2)

#### mod 6 counter - moore
![[mod_6_moore_implementation.png]]
outputs depend only on the present state, and not inputs
configuration is different to mealy - two separate logic units, since the output and next state logics require different inputs

### generating the next state
can be done with several methods, identical between mealy and moore
e.g.
- combinatorial logic gates
- multiplexers
- lookup ROM

first, we need the truth table for the next state logic
![[mod_6_nsl.png]]
the system inputs and present states are the inputs
next state bits are outputs
then, we construct a karnaugh map for each output bit, and design logic to fit the equations
![[mod_6_karnaugh.png]]
![[mod_6_gates.png]]


an alternative approach would be to use **multiplexers**
- each input to the multiplexer represents the next state under one possible value of the system inputs, the inputs drive the input signals of the multiplexer
	-> for the mod 6 counter, we use the U input for this purpose

to determine the inputs of the multiplexer, we begin by splitting the truth tables into multiple, one for each possible system input value
![[mod_6_multiplexer_tables.png]]
we then create a karnaugh map for n2, n1, and n0
![[mod_6_karnaugh_mux.png]]
the karnaugh map for u=0 in this case is irrelevant, the states stay the same, so we can simply pass in next_state = previous_state
![[mod_6_mux.png]]

one other approach is to use a **lookup ROM**
- in this approach, the present state values and inputs are connected to the input bus of a rom, and the next state is received from its memory
-> the correct value must be stored at each location for proper operation
![[mod_6_lookup_rom.png]]
![[mod_6_rom_table.png]]
the three bits that encode the present state ($p_2\;p_1\;p_0$) are connected to the three high-order bits ($a_3\;a_2\;a_1$), and the condition bit U is connected to the low order bit address, $a_0$

### generating system outputs
for both mealy and moore machines, we follow the same design procedure to develop their output logic
-> two approaches to generating it
- rom lookup table
- combinatorial logic gates

we begin by creating a truth table
- for a mealy machine:
the inputs will be the system inputs and the present state, and the outputs will be the system outputs
- for a moore machine:
only the state bits will be inputs, and the system output is the table output

![[mod_6_moore_implementation 1.png]]
![[mod_6_mealy_implementation 1.png]]

lookup rom implementation
- inputs:
present states and system inputs
- outputs:
system outputs

the same rom can be used to generate the next state and system outputs
![[mod_6_moore_implementation_rom.png]]

> #finite_state_machines #computing_systems 