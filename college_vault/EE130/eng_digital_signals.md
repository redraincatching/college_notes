# Digital Signals

##### Analogue Quantities
most natural quantities are analogue, and vary continuously

digital systems can process this data more efficiently, but can only assign values to each point

##### digital signals
a waveform that [[data_representation|represents]] a sequence of discrete values (1s and 0s)
// also called bit streams

---
### digital modulation
provides a means of transmitting data from one type to another
one approach is to _modulate the amplitude of a sine wave_, called a carrier
![[sine_wave_carrier.png]]

### pulse-code modulation (pcm)
uses a sequence of digital codes to represent a sampled analogue signal
![[pcm.png]]

---
## analogue and digital systems
many systems use a mix of analogue and digital circuits (e.g. cd player)

### binary digits and logic levels
digital electronics use circuits that have two states, represented by two voltage levels - high and low, representing binary numbers

digital waveforms change between these two levels

- a positive-going pulse is one that goes from a normally low level to a high one, and then back again
- a negative-going pulse is one that goes from a normally high level to a low one, and then back again

actual pulses are not ideal square waves, but are described by the rise time, fall time, amplitude, and other characteristics
![[pulse_definitions.png]]

---
## periodic pulse waveforms
composed of pulses that repeat in a fixed interval called a period
the rate that it repeats is the frequency (measured in _hertz_)

the clock, the repeating signal used to synchronise others, is a basic example of this

> #engineering #digital 