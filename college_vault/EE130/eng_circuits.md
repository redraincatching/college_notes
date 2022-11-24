# Circuits
represent [[engineering_systems|systems]] as connected elements
-   through which currents flow (through variables)
-   and across which voltages develop (across variables)

circuits are important for two reasons
-   as physical systems (power, electronics)
-   as models of complex systems (neurons, cardiovascular systems)

![[myelinated_neuron_symbol.png]]
all circuits have three common attributes
-   a source
-   a load
-   a complete path

---
## Series Circuits

a series circuit is one that has only one circuit path
-   because there is only one path, the current everywhere is the same
-   the total resistance is the sum of the resistors in series
-   the total voltage in series is the algebraic sum of voltages

### Kirchoff's Voltage Law

[[eng_electricity#Ohm's Law|see also: Ohm's law]]
-   the sum of all voltage drops around a closed loop is equal to the total source voltage in that closed path
-   planar circuits are characterised by their "inner" loops, as those are linearly independent
-   the sign of a voltage is defined by its bias - the "entering" sign is placed before the voltage

![[kvl.png]]

---
#### Voltage Divider Rule

the voltage drop across any given resistor in a series circuit is equal to the ratio of that resistor to the total resistance, times the source voltage.

Voltage is relative, and is measured *with respect to another point on the circuit*

voltage with respect to ground (called reference ground) is written with one subscript

e.g. $V_a$ // voltage at a with respect to ground

voltage between two points is written with two subscripts

e.g. $V_{ab}$ // voltage between a and b

ground reference is not always the lowest point in the circuit in that case, any drops below ground are written as -ve

---
### Kirchoff's Current Law

sum i in = sum i out 
the number of linearly independent kcl equations is one less than the total number of nodes

#### Current Divider Rule

$\LARGE I_x = \frac{R_{total} || }{R_x} \times I_{total}$

![[current_divider_equations.png]]
*resistance of two || resistors*

$\LARGE R_t = \frac{R_1\times R_2}{R_1 + R_2}$

---
##### Equivalent Circuits
a circuit with electrical characteristics that are the same as another circuit, but is simpler

---
### Loaded Voltage Divider

voltage divider where another resistor (the load resistor) is added in parallel with a resistor in the voltage divider (the bleeder resistor)
&nbsp&nbsp&nbsp&nbsp-> this changes the voltage ratio in the voltage divider

##### Stiff voltage divider
provides a load voltage that is nearly equal to its no-load output voltage
this is achieved by having a load resistor that is $> 10R_{bleed}$
*// current wants to take the path of least resistance, so to keep the voltage similar to the no-load, we make sure that the added load resistance is massive*

###### voltmeter loading effect

occurs whenever we measure a voltage, as a voltmeter has an internal resistance, causing a loading effect, resulting in the measurement being slightly off

###### wheatstone bridge
four resistive arms forming two voltage dividers, with a galvanometer between them

> #engineering #analog