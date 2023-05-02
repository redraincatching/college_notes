# physical layer
theoretical basis for data communication
fourier analysis
a periodic signal with period T can be constructed as a sum of a number of sines and cosines
fourier series:
$g(t) = \frac{1}{2}c + \sum_{n=1}^{\inf}a_n sin(2 \pi n f t) + \sum_{n=1}^{\inf}b_n cos(2 \pi n f t)$

where:
- f = 1/T
- $a_n$ and $b_n$ are the sine nand cosine amplitudes of the $n^{th}$ harmonics
- c is a constant (the d/c component, relating to the voltage)

// the 2 pi n as n -> infinity is what produces the harmonics

when we send digital data we have a high value and a low value corresponding to 1 and 0, and a "bit interval", i.e. the time it takes for one bit to be transmitted, so that 1111 could be held as high for the duration of the signal
it's really hard to send these square waves through a physical medium such as a copper wire
this is why the fourier analysis is important, as it allows the reconstruction of the square wave from other periodic signals

## bandwidth-limited signals
let's consider the ascii character 'b' encoded in a byte (01100010)
![[bandwidth-limited_signals_0.png]]
we assume that it is a repeating pattern (isn't, but mathematically that doesn't matter)

the fourier analysis gives the coefficients:
![[bandwidth-limited_signals_1.png]]

the root-mean-square (rms) amplitudes are of interest because they show the energy transmitted at those frequencies
// $rms_n = \sqrt{a_n^2 + b_n^2}$
no transmission facility can transmit data without some loss of energy, and if every fourier component lost data equally, the signal would not be distorted, however in practice different mediums distort signals in different ways, resulting in corruption and attenuation of the signal

the amplitudes that can be transmitted undiminished between 0 and frequency Fc (where Fc is F cut, measured in Hz), with all frequencies above Fc being attenuated, is the _bandwidth_
// in the real world, this isn't a hard cutoff, so often the point where half the power gets through is used
		
![[bandwidth-limited_signals_2.png]]
- (b) here is solely the first harmonic, which is essentially unintelligible
- (c) adds in the second harmonic as well
![[bandwidth-limited_signals_3.png]]
- (d) and (e) are successive approximation, allowing for more accurate decoding

this is why the loss of data at higher harmonics due to bandwidth limitations is a major obstacle

// how decoding works is by gauging the voltage at the midpoint of a bit-interval, and comparing to the ideal values 

---
## nyquist's theorem
the maximum rate at which data can be transmitted through a noiseless data channel
$max = 2 B*log_2 V$       \[bits/sec\]
where:
- B: bandwidth
- V: the number of discrete levels of the signal transmitted through the channel

// digital data must only have two levels (1 and 0), however the signal itself can be more complex -> can compress data
this also means the number of levels to transmit digital data will always be a power of 2
in the real world, not just voltage levels, but phase shifting and other techniques can be used to push the levels as high as 1024 (although that is uncommon)

if random noise is present, then the situation deteriorates rapidly
in reality there is always random noise
the amount of thermal noise is measured by the snr, the signal to noise ratio (in decibels)

$SNR_{db} = 10 log_{10}(\frac{S}{N})$

## shannon's theorem
the absolute upper limit of a channel

$max = B*log_2 (1 + \frac{S}{N})$

where:
- B: bandwidth of a noisy channel
- s/n: the snr of that channel

demonstrates that the maximum data rate is limited by the amount of noise present, no matter the amount of signal levels used, or how frequently samples are taken

used in practice: wifi access points actually dynamically changes the modulation rates they use based on the amount of noise detected, to match the capabilities of the open channel

### worked example
a channel of 3000 Hz bandwidth (a phone line) has an snr ratio of 30 dB 
the transmitted signal has 8 levels
what is the maximum data rate this channel can accomodate?

nyquist:    2 (3000) ** $log_2$ 8 = 18,000 bits/sec = 18 kbps
shannon:    3000 * $log_2$ (1 + 1000) = ~30,000 bits/sec = ~30 kbps
	// have to convert from dB to a usable value

go with the lower one, so 18 kbps

what if the snr is 10 dB?

shannon: 3000 * $log_2$ (1 + 10) = ~10,500 bits/sec

---
## channel organisation
any communications channel has a direction associated with it
![[channel_organisation_0.png]]
- simplex: sender to receiver
- half-duplex: shared channel that can be used to send and receiver
- full duplex: separate channels for senders and receivers

### synchronisation
the receiver should know the exact moment when data is valid
synchronous channels
data and timing information are sent separately (through separate or the same channel)
the timing channel ptransmits clock pulses to the receiver
upon receive of clock pulse, the receiver reads the data and latches it
the data is not read again until the next clock pulse arrives
however, this clock signal takes up a lot of bandwidth
e.g.
- usb
- 12c
- spi
### asynchronous channels
no separate timing information used
transmitter and receiver agree in advance on timings
start and stop conditions are used
accurate oscillators measure the bit widths
e.g.
- rs232
- ethernet
- wifi

### parallel communication
![[parallel_communication_0.png]]
1) sender places data on the channel
2) sender asserts "data available"
3) receiver reads data and asserts "ready"
4) sender de-asserts "data available" and it will be ready for a new data transfer

would send multiple bits at the same time

today only really used inside devices, old computers used to have a parallel port for printers or other peripherals

### serial communication
![[serial_communication_0.png]]
usually 8 message bytes at a time, uses start and stop bits to delineate message frames
old serial ports did this bitwise, for ethernet or wifi their maximum frame size is over a thousand bytes

---
## noise and distortion
![[noise_and_distortion_0.png]]
- long conductors act like receiving antennas for electrical noise emitted by motors, switches, or other devices
- the signals get distorted by this noise

### noise compensation
![[noise_and_distortion_1.png]]
- for digital systems used over medium/short distances

### data transfer over long distances
![[noise_and_distortion_2.png]]
- bit serial transmission is almost always used over 10m
- balanced circuitry is used to send transmissions

#### balanced line transmission
![[noise_and_distortion_3.png]]
- the signal is sent over two wires simutaneously
-> the original signal and its inverse
- the signals are subtracted at the receiver by a summing amplifier, producing a stronger signal, and as a result any induced noise is cancelled out
- really only used for ethernets in LAN
- maximum distance it'll work is about 100m copper

### data transfer over even longer distances
![[noise_and_distortion_4.png]]
- special devices called [[modulation#modems|modems]] (MODulator/DEModulator) connect to a computer system and use analog signals as carriers to send digital signals over long distances
---
## guided transmission data - mediums
### twisted pair
![[twisted_pair_0.png]]
e.g. category 3 utp (cat3) - 16MHz bandwidth, category 6 utp (cat6) - 250MHz
-> utp: unshielded twisted pair
differences in categories is the number of twists per pair, and thickness of cable
rj45 connector on a cat5
8 cables inside (4 pairs)
orange + orange-white, green + green-white, blue + blue-white, brown + brown-white
only two pairs are in use at a time (one pair uplink, one pair downlink)
gives full duplex (benefit over wifi)
rj11 on phone lines (a little smaller)

cat5e - cat5 enhanced, the main standard today
-> about 100 MHz bandwidth
cat5 ftp - foil-shielded twisted pair
cat5swa - steel-wired armour

### coaxial cable
![[coaxial_0.png]]
historically used for tv antennas
better shielded than twisted pair
copper core, and can span over longer distances at higher speeds
-> higher bandwidth than cat5, up to 1GHz
50 ohms for digital transmission and 75 ohms for analog available

### fibre optics
// NEVER LOOK DOWN A FIBRE CABLE //
![[fibre_0.png]]
- diagram: three examples of a light ray from inside a silica fibre impinging on the air/silica boundary at different angles
- light trapped by total internal reflection

- capable of up to 50 terabits per second, essentially no bandwidth limitations
- however, the circuitry (the light sources and decoders available) simply can't keep up
- generally, fibre transceivers today run between 10 and 100 Gbps
-> 100 is often 4x25 at different wavelengths
- much higher distances possible
- raw materials more readibly available (sand is cheaper than copper)
- size: a fibre cable can be as small as 9 microns in diameter


#### transmission of light through fibre
![[fibre_1.png]]
the attenuation of light through glass depends on the wavelength used (the colour of a light) and the physical properties of the glass
attenuation is measured in **dB/km**
three wavelength bands are used for communication, centred on 0.85 microns, 1.3 microns, and 1.55 microns
these correspond to dips in the attenuation curve of light
// note: visible light is about 0.4 - 0.7 microns
as the ray travels down the fibre, chromatic dispersion occurs (the wavelength spreads out) 
by making pulses of a certain shape, called solitons, nearly all of this dispersion can be cancelled out
can actually use multiple wavelengths in the same fibre, essentially multiplexing, done with passive optic couplers

#### multimode fibre
can use many different rays at different angles of incidence
multimode patch leads (cables) are usually orange or blue
#### single mode fibre
the diameter of the fibre is reduced, allowing the light to only propagate (travel) in an essentially straight line
patch leads are yellow
more common now, given that its distance is usually measured in tens or hundreds of kilometers

#### anatomy of a fibre cable
![[fibre_2.png]]
- two types of glass have different refractive indices, allowing for constant total internal reflection in the internal core
- not unusual to have a cable with 24 to 48 cores that are the same size as or even smaller than a cat5 cable

### l.e.d.s vs semiconductor lasers as light sources
off the shelf transceivers use l.e.d.s, even the campus would use them

```verbatim
							l.e.d.      |   semiconductors
data rate:                  low         |   high
fibre type:                 multimode   |   multimode or single mode
distance:                   short       |   long
lifetime:                   long        |   short
temperature sensitivity:    minor       |   substantial
cost:                       low         |   expensive
```


> #### fibre optics networks:
> ![[fibre_3.png]]
> - pretty much always built in a ring structure for redundancy reasons
> - usually human error, but one reason that equipment might fail is literally a speck of dust

---
## wireless transmission
the electromagnetic spectrum
the number of ocsillations of a wave per second is its frequency, and the distance between any two maxima or two minima is the wavelength, lambda
in a vaccuum, all electromagnetic waves travel at the same speed, about $3x10^8$ m/s
in copper, it's about $2x10^8$ m/s

the formula that links wavelength, frequency, and speed of a wave in a medium is $\lambda * f = c$

the frequency of wifi is usually either 2.4, 5, or 6 GHz (there are a couple bands), which corresponds to 0.125 m of a wavelength

![[electromagnetic_0.png]]
the spectrum itself and its uses for communication
x-rays and above are known as ionising radiation
wifi is actually a microwave signal, and uses a very low power over a very wide spectrum, however it runs at the same frequency as a microwave oven

### common frequency bands
- elf = extremely low frequency, $1\times10^8$ m
- slf = super low frequency, $1\times10^7$ m
- ulf = ultra low frequency, $1\times10^6$ m
- vlf = very low frequency, $1\times10^5$ m
- lf = low frequency, $1\times10^4$ m
- mf = medium frequency, $1\times10^3$ m
- hf = high frequency, $1\times10^2$ m
- vhf = very high frequency, $1\times10^1$ m
- vf = voice frequency, $1\times10^0$ m
- uhf = ultra high frequency, $1\times10^0$ m
- shf = super high frequency, $1\times10^-1$ m
- ehf = extremely high frequency, $1\times10^-2$ m

#### radio transmission
![[radio_0.png]]
- radio covers ELF to VHF, so everything from 3Hz to 30MHz, and wavelengths of 100 Mm to 10m
- in the vlf, lf, and mf bands, radio waves follow the curvature of the earth
- in the hf bands, they bounce off the ionosphere (not often used for datacomms)

#### microwave transmission
UHF to EHF bands, so 1m to 1cm, tn the range of hundreds of MHz to tens of GHz
above 1000MHz these travel in a straight line
repeaters are necessary if two communication points are too far apart (basically line-of-sight)
microwaves don't pass through solid walls very well
multipath fading problem
-> the signals can cancel each other out or go out of phase due to reflections in a small area
-> happens over water especially, and depends on tides
over 5GHz, absorption by water
widely used for long-distance broadcasting, has led to a shortage of bandwidth

#### infrared and millimeter waves
hundreds of GHz
widely used in short range communication
directional and easy to build
can't pass through solid objects
no license needed to operate

### politics of the electromagnetic spectrum
![[electromagnetic_1.png]]
- ism bands: industrial, scientific, and medial
- these are licensed differently

---

### communication satellites
![[electromagnetic_2.png]]
geostationary, medium-earth, and low-earth orbits
geo only needs 3 satellites to cover the entire planet

#### the principal satellite bands
![[electromagnetic_3.png]]
-> rain is only an issue above 5GHz, generally, although heavy snowfall can cause problems
-> Ku is pronounced 'q'

#### vsats using a hub
![[electromagnetic_4.png]]
-> very small aperture terminals

#### middle earth orbit satellites
not hobbits
must be tracked as they move through the sky
less powerful transmitters needed to reach them
not usually used for communication
used for gps - transmitting a very accurate time pulse at frequent intervals, and using the time difference to determine local positioning

### low earth orbit
massive number in comparison needed for coverage
ground stations don't need much power, and the round trip delay is only a few seconds

> example: iridium
> ![[electromagnetic_5.png]]

used in remote areas, or areas with failing/nonexxistent infrastructure

---
see [[modulation|modulation]] for notes on modulation

---
## dsl - digital subscriber lines
![[dsl_1.png]]
dsl - opening the phoneline bandwidth above 25 kHz to about 1100 kHz, in 256 4-kHz channels
// prior to this, it was limited to 0-4 kHz, just for voice
// the channels were exactly 4312.5 kHz
DMT - discrete multi tone - modulation was used 

phone lines are full multiplex, and so the channels were divided between upstream and downstream usage, usually about a 20/80 split, as traffic has a downstream bias

![[dsl_0.png]]
this diagram shows on a telephone line (of reasonable quality) the data rate that you can expect


### vdsl
very-high-speed dsl
over 30 MBps
requires a really close cabinet (the receiver)
uses fttc technology (fibre to the cabinet), which is a fibre optic drop near the home, and everyone's phone line runs to a vdsl modem at the cabinet

#### vdsl vs. dsl
went from about 1.1 MHz to about 17 MHz, however the usable distance was cut from over a kilometer to a few hundred metres
![[dsl_2.png]]
just used more channels
similar to wifi, uses the phoneline as best it can

standard connector in ireland is an rj11 cable

#### fibre to the cabinet (fttc)
fibre connection to a cabinet on the street, essentially, and vdsl from there

#### fibre to the home (ftth)
mainly use GPON (gigabit passive optical network)
a single fibre is shared in a typical 64:1 split
// gpon is 1 gb raw, other variations include the 10 gb xgpon

----

## trunks and data multiplexing
fdm - frequency division multiplexing
multiplexing by division of wavelengths
tdm - time division multiplexing
timeslice multiplexing

### fdm
![[multiplex_0.png]]
// analog voice telephony is about 3 kHz in width
the principle fm radio is based on, from about 88 to 108 mHz

wavelength division multiplexing - a variation on this
![[multiplex_1.png]]
the same principle for fibre optics
// here the combiner and splitter aren't really electronic components, rather precision-engineered optical components

### tdm
![[multiplex_2.png]]
a snippet of the analog signal is sent within a channel of 8 bits (7 data and 1 signal bits) over a 193bit data frame
this frame takes 125 microseconds to pass
// this is a T1 frame, in europe we use E1

![[multiplex_3.png]]
the analog signal is first recorded, and encoded into a digital form by sampling it to a certain degree of accuracy (the quantization level)
based on the idea that all analog signals are happening very slowly relative to the sampling speed
slight loss of fidelity due to this

![[multiplex_4.png]]
these frames can also be multiplexed into higher-index signals

### voip
e.g. deskphones in an office
in ireland we use G.711a codec (coder-decoder)
// also known as pulse code modulation
// one of the consequences of nyquist's theorem is that to reproduce an analog signal with a max spectral component of f, you must sample at a minimum rate of 2f
-> nyquist sampling rate

// landlines have a value of 4kHz, and a sampling rate of 8 kHz
// pcm uses 8 bit samples, 2^8


```verbatim
/*
	2.4 GHz wifi
		has 11 bands, and the bands 1, 6, and 11 (the smallest) don't overlap
		however, all the other bands receive interference from bluetooth and other devices
	5 GHz wifi
		smaller range, however far less interference, over 400 MHz, with at least 20 non-overlapping channels
*/
```


---
### cable tv
![[tv_0.png]]
// coax is actually better for this than fibre

#### internet over cable
![[tv_1.png]]
quicker than vdsl, and the bandwidth is ridiculously massive
when it comes to fibre, there's no interference, as there is no noise source
![[tv_2.png]]

#### spectrum allocation
![[tv_3.png]]
only about 200 MHz is used for downstream data, and about 40 for upstream, as the majority of the spectrum is given over to tv

#### cable modems
![[tv_4.png]]


> #networks_and_communications 