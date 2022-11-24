# Rectifiers
a circuit that converts ac voltage to dc

---
## Half-wave Rectifier

a circuit that eliminates either positive or negative alternations of a signal

![[half-wave_rectifier.png]]

a [[eng_diodes|diode]] can be used here, to act as an open switch during the positive alternation, and as a closed one during the negative alternation

---
## Full-wave Rectifier

a circuit that converts ac to dc by controlling the direction of the output current so that only positive or negative output alternations are produced

### Full-wave Bridge Rectifier
![[full-wave_bridge_rectifier.png]]
based on the principle of switching current paths
involves an transformer i guess
(f in the diagram is a fuse)


#### Power supply filters

filtering is the process of smoothing the ripple from the rectifier
&nbsp&nbsp&nbsp&nbspusually, a capacitor input filter is used

the variation in output voltage that occurs as the capacitor is discharging is called the ripple voltage

the longer the time period between capacitor discharge cycles, the greater the ripple voltage. this is why a filtered full-wave rectifier has less ripple than a comparable half-wave rectifier

---
### IC Regulators

an integrated chip (ic) is a complete, functional circuit on a silicon chip.

an ic regulator is one that maintains a constant output current or voltage despite changes in input, load, or temperature.

most have three terminals; an input, an output, and a reference (or adjust) terminal

these only require an external capacitor to regulate current - typically a large one before the regulator, and a small one afterwards

an example of these are the 78xx series regulators 
![[78xx_regulators.png]]
_// the xx is the output voltage_

![[5v_full-wave_rectifier_with_capacitor.png]]
_full wave rectifier with an ic regulator_

> #engineering #analog