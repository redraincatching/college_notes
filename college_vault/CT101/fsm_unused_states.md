# unused states
what happens if the fsm loads up into an unused/unknown/undefined state, or reaches it by some flaw in the machine?
_// in our [[modulo_6_counter|mod 6 counter]], 110 and 111 are both undefined_


![[dummy_state_diagram.png]]
- create dummy state for all unused states
- each would go to a known state on the next cycle of the clock (usually a reset state)
- by convention, the value of 1 on the arcs indicate that the action is always taken

> ![[dummy_state_table.png]]
> table with dummy states

> #computing_systems #finite_state_machines 