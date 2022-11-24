# finite state machine design

a finite state machine (FSM) is a tool to model the desired behaviour of a sequential system
- the designer must develop a finite state model of the system behaviour, and develop a circuit to implement it

an FSM consists of several states. inputs into the machine are combined with the current state of the machine to determine the next state of the machine
 - inputs are based on just the state, or state and inputs

> ![[fsm_structure_wtf.png]]
> wtf.png

x represents the range of possible input values ($2^n$)
y represents the range of possible output values ($2^m$)
q represents the range of possible states of the system ($2^k$)
&nbsp;&nbsp;&nbsp;&nbsp;transfer functions:
- $f: x * q \mapsto y$
- $g: x * q \mapsto q$

_// ess., f calculates the output, g calculates the new state_

---
#### finite state machine representation
![[fsm_representation.png]]

FSM = (x, y, q, f, g)
if there is no state in the q range ($q \equiv\emptyset$, the circuitry has no history)
 - $g: x * \emptyset \mapsto \emptyset$, there is no state transition function
- $f: x * \emptyset \mapsto y$, becomes $f: x \mapsto y$

in this case, the FSM is equivalent to a combinational logic circuit (CLC)
- $FSM\mid _{q≡ø} = CLC = (x, y, f)$

---
## synchronous vs. asynchronous
- async FSM
the next state becomes the present state after the delays through the delay elements
- sync FSM
obtained by replacing the delay elements $d_i$ with memory elements (registers)
the $w_i$ bits of the next state will be written in the registers only on the clock (edge or level)
![[sync_vs_async.png]]

### sync FSM with immediate outputs
![[sync_imm_out.png]]
the outputs, after they have been calculated, are used immediately (of course, in the stable period of the state interval), is called an immediate state machine

### sync FSM with delayed outputs
![[sync_delay_out.png]]
the next state is assigned as the present state on the next clock interval, and the outputs are made available similarly. each bit of the output is passed through a memory element

![[timing_diagram_sync_fsm.png]]
transient interval: the longest propagation path through the CLC

> #computing_systems #finite_state_machines