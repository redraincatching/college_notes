# string checker finite state machine
inputs a string of bits, one per cycle

when the previous bits match the pattern **110**, sets output m=1, otherwise m=0
&nbsp;&nbsp;&nbsp;&nbsp;the pattern is checked continuously throughout the stream
&nbsp;&nbsp;&nbsp;&nbsp;-> checks bits 123, then 234, then 345, and so on
![[string_checker_state_table.png]]
- previous three bits represented by the state
- bits are received from left to right
- each state goes to one of two possible values, depending on the next bit being read in, I

![[string_checker_state_diagram.png]]

## moore machine
![[string_checker_moore.png]]
output logic is straightforward - when state is 6, the input is 110, so can implement M as $p_2\;p_1\;'p_0$, which is equal to 1


>this can be implemented far more simply
>- $s_0$: no bits match
>- $s_1$: one bit matches
>- $s_2$: two bits match
>- $s_3$: three bits match, m=1
>![[simpler_string_checker.png]]
>![[simpler_string_checker_diagram.png]]

> #finite_state_machines #computing_systems 