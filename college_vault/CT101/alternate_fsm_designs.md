# alternate fsm designs

## counter/decoder design
using a counter to store the current state, and a decoder to generate signals corresponding to each state

the counter can be cleared, incremented, decremented, or loaded with another value to go from one state to another
_// therefore, to stay in the same state, the machine just has to not change the counter_    
![[fsm_counter_decoder.png]]
- the counter plays the role of the register in the mealy and moore designs, as well as a portion of the next state logic
- the state value is input into the decoder; each output of the decoder represents one state
- the decoder outputs and system inputs are input into the logic block that generates the system outputs, nd the information necessary to generate the next state value

-> if the system inputs are used to generate both the next state and the outputs, this design can be used to implement a mealy machine, and similarly if the state values only generate the system outputs, a moore machine has been implemented
![[mod_6_moore_counter-decoder.png]]

> #computing_systems #finite_state_machines 