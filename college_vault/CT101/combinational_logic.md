# combinational logic

gates, latches, memories, and other components are used ot design computer systems and their subsystems
    
two types of digital logic
- combinational logic - output is a function of inputs
- sequential logic - output is a complex function of current + previous inputs, previous outputs, and state

_// neither is "better", they both have unique use cases_

---
## boolean algebra
basic functions and methods used to combine, manipulate, and transform boolean functions
&nbsp;&nbsp;&nbsp;&nbsp;these are implemented in combinational logic circuitry
boolean values can be either true or false
&nbsp;&nbsp;&nbsp;&nbsp;_// 1 is true, 0 is false_


### main operations
conjunction, AND
- output is 1 when _both_ inputs are 1
- multiplication
- ^ (called a caret) or .
![[and_example_waveform.png]]

disjunction, OR
- output is 1 when _any_ input is 1
- addition
- v (called a caron)
![[or_example_waveform.png]]

negation, NOT
- returns the opposite value to input
- ¬, -, ', or a bar over the number (conjugate)
![[not_example_waveform.png]]

exclusive or, XOR
- the output is 1 when the inputs are different


negative multiplication, NAND
- produces false only if all inputs are true

negative addition, NOR
- produces true only if both inputs are false

exclusive negative or, XNOR
- produces true when both inputs are _the same_.
- _// note: not X(NOR), actually NOT(XOR)_

#### manipulating boolean functions
consider a function that must be 1 if either x = 1 and y = 1, or y = 1 and z = 1
&nbsp;&nbsp;&nbsp;&nbsp; f(x, y, z) = xy' + yz

---
## de morgan's laws
(ab)' = a' + b'
&nbsp;&nbsp;&nbsp;&nbsp;_// changes AND to OR_
(a + b)' = a'b'
&nbsp;&nbsp;&nbsp;&nbsp;_// changes OR to AND_
allow for simplification and getting complements

>using the above, find the complement of
>```
>f(x, y, z) = xy' + yz
>	(xy' + yz)'                  // negate
>	(xy')(yz)''                   // second law
>	(x' + y)(y' + z')          // first law
>	x'y' + x'z' + yy' + yz' // multiply out
>	x'y' + x'z' + yz'          // final (yy' is 0)
>```
    
---
## karnaugh maps
pictorial method for minimizing logic
&nbsp;&nbsp;&nbsp;&nbsp;the rows and columns of the k-map correspond to the possible values of the function's input

each cell in the k-map represents a "minterm"
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// gray code order
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;// input values don't follow linear progression, so that every cell is one bit away from adjacent cells

-> then find groups of 2^n cells that cover all active minterms




> #computing_systems 