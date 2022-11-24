# mealy vs moore machines

## moore machine
associates its outputs with states
the outputs are represented either within the vertex corresponding to the state, or adjacent to the vertex

## mealy machine
associates its outputs with transitions
in addition to the input values. each arc also shows the output values generated during the transition

// both types can be used to describe any sequential system

### moore fsm
![[moore_fsm.png]]
output is dependent only on the current state
- immediate moore fsm:
the output is obtained with a clock period delay, since the next state becomes the present state
- delayed moore fsm:
the output is actually obtained with two clock period delays, because of the registers bank 2

### mealy fsm
![[mealy_fsm.png]]
output is dependent on the current state and inputs
the delayed output fsm implies that the calculated output for the input, applied at time t, is assigned at time t+1

> #finite_state_machines #computing_systems 