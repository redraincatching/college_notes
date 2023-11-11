
---
tags:
  - networks_and_communications
---
# modulation
due to attenuation - and other problems - digital (square) waves cannot be used over long distances
AC signalling is used instead
a continuous tone, called a sine wave carrier, at around 1000~2000 Hz is introduced
its amplitude, frequency, and phase can be modulated to transmit information
- amplitude modulation
two different amplitudes are used to represent 1 or 0
- frequency modulation
(or frequency shift keying)
- phase shifting
the carrier wave is shifted 0 or 180 degrees at bit intervals to show a transition
basically you have a 1 phase and a 0 phase, and switch between them as necessary
a better scheme is to use intervals of 45, 135, 225, and 315, to transmit 2 bits at a time
-> duo-binary phase-shift keying scheme

![[modulation_0.png]]
- amplitude: the presence or absence of a signal is the packet
- phase shift: no change means signal stays the same through the interval

## modems
a phone line has a band of 3000Hz, so no point sampling faster than 6000 times per second (nyquist)
in practice most lines sample more bits at a time, at around 2400 times per second
the number of samples per second is measured in ***bauds***
during one baud, one **symbol** is sent (remember, not only 1 or 0, could have more combinations)


> baud rate: samples per second
> bit rate: symbols/sec * bits/symbol

---

## trellis/constellation diagrams
![[modems_0.png]]
- qpsk: quadrature phase shift keying
four phases are used, a symbol can encode two bits
- qam-16: quadrature amplitude modulation
four amplitudes, four phases, can encode 4 bits per symbol
- qam-64
64 combinations, so 6 bits per symbol

gets ridiculous on some systems, even qam-2048, but this is rarely feasible

// wifi dynamically chooses which to use based on the snr ratio

![[modems_1.png]]
with many points in the constellation diagram, even a small amount of noise can cause errors
tcm - trellis coded modulation - is used, where beside the data, parity checking is employed
the v32 modem uses 32 points on the constellation to send 4 bits of data and 1 parity bit per symbol, with an effective bps of 9600
the next step up is v32.bis, is a 128 point constellation, using 6 data bits and 1 for parity

> #networks_and_communications 