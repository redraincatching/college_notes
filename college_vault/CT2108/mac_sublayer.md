# mac sublayer
medium access control
part of the datalink layer, along with the logical link layer

## channel allocation
in a broadcast network, a key issue is handling competition
static channel allocation
fdm or tdm allocation, however there's some wasted spectrum as not all access is continuous, so multiplexing in this way is not ideal for a large amount of asynchronous users

-> dynamic channel allocation
most situations call for this

### CSMA protocol - carrier-sense multiple access
the stations listen for a carrier, or a transmission, and react accordingly
networks based on this protocol can achieve pretty good channel utilisation
variations on this protocol
- 1 persistent csma
- non persistent csma
- p persistent csma
- csma cd (collision detection)

#### 1 persistent
when a station has data to send, it listens to the channel
if busy, wait
else, transmit the frame
collisions can occur, as two stations can listen to the same idle channel and decide to send at the same time

> propagation delay - time between reading and sending

if collision, wait a random amount of time and try again
called 1 persistent because on finding an idle channel, sends with probability 1

#### non persistent
when a station has data to send, it listens to the channel
if idle, send
else, wait and try later
-> stops the busy waiting and just sleeps for a random amount of time
fewer collisions, however longer delays than 1 persistent

#### p persistent
applies to slotted channels

> slotted channel: access is divided into fixed timeslots

if channel is idle, checks against probabilities p and q
with p it sends during this frame
with q it delays transmitting until the next frame, at which point it checks againt p and q again
this is repeated until
1) data is sent
2) channel is no longer idle

-> stations waits random amount of time and tries again
can still get collisions, however drops with the value of p

![[csma_0.png]]

#### csma cd
causes stations to immediately end transmission on detecting a collision, as the data will be garbled and unusable
saves time and bandwidth
basis for ethernet lan

![[csma_1.png]]
can be in one of three states:
- transmission
- contention
- idle

#### collision-free protocols
- collisions adversely affect the system performance, especially if the cable is long, and the frames are short
- these protocols solve the contention issue with no need for collisions
- n stations are assumed to be connected to the same transmission channel
- options:
	- bitmap protocol
	- binary countdown

##### bitmap protocol
![[mac_0.png]]

each contention period consists of exactly n contention slots. if station j has a frame to send, it will send it in the $j^{th}$ contention slot.
once the contention period has passed, each station is free to transmit in the defined order, with no collision
-> protocols such as this are called reservation protocols

##### binary countdown
![[mac_1.png]]
a dash represents silence

bitmaps don't scale well with a large number of stations, as the overhead is fixed per station
in a binary countdown protocol, all stations have addresses of the same length, with stations of higher priority having a higer-value address.
the stations, if they wish to transmit, transmit their addresses as bitstrings, which are immediately OR'ed together
each station can see the results of this OR immediately, and if the result is a greater value than its own address, it stops trying to transmit, and cedes to the higher priority station

---

## wireless lan protocols
![[mac_2.png]]
in a wireless lan, not every station is within range of each other, so they can't always tell that the others are transmitting: the **hidden station problem**
on the other hand, the **exposed station problem** can occur if b is transmitting to a, and c detects it, incorrectly concluding that it may not transmit to d, despite that connection being well out of radio range of b.
in these cases, csma is useless, as they sender needs to know that there's no activity around the *receiver*.

### maca -multiple access with collision avoidance
![[mac_3.png]]
the sender stimulates the receiver to output a short data packet, which other surrounding stations can pick up on, allowing them to remain silent for the duration of the later, longer packet
the stimulus is called an RTS - request to send, and the response is a CTS - clear to send.

---

## ethernet

### historical ethernet cabling
![[mac_4.png]]
- 10base5:
the transceiver and interface board are separated. the interface board goes inside the computer, and the transceiver goes on the cable, close to the vampire tap. the transceiver contains the electronics that handle collision detection. uses coax
- 10base2:
the connection is just a passive bnct junction. the transceiver electronics are situated inside the pc. uses a shared twisted pair
- 10baseT:
no shared cable, just the hub. each device is connected to the hub with a dedicated twisted pair cable

> 10base5 and 10base2 both use bus topology, however 10baseT uses a star topology

---
## ethernet standards
> #frame

two competing standards, with small differences. can be used interchangeably
![[mac_5.png]]
- preamble:
bit pattern 10101010. the manchester encoding on this produces a 10 MHz sine wave that allows syncing between senders and receivers
- sof:
start of frame delimiter
- dest & src addresses:
high order bits define normal or group addresses. 2nd highest order defines local vs global, and all 1s (ff:ff:ff:ff:ff:ff) is a broadcast.
- type:
tells receiver what the associated protocol is
- length:
guess
- pad:
adds up to 46 bytes (64 - headers + checksum) to allow a small frame to reach the minimum 64 bytes, required for collision detection
- checksum:
32-bit CRC hash code. error detection, no correction done here, see the [[datalink_layer#crc - cyclic redundancy check|datalink layer]].

---

## wireless collision detection
![[mac_6.png]]
the minimum length for an ethernet frame is to enable collision detection
If we have a collision an time $\tau$, the station B (that detected the collision first) issues a 48 bit noise burst (known as jam signal) to warn the other stations. 
At about 2$\tau$ time, the sender (station A) will see the noise burst and aborts its transmission too. It waits a random time until it tries again. 
For a 2500 meters LAN with 4 repeaters, the round trip time (the propagation time for a signal to travel from one end of the LAN to the other end of the LAN and back) is about 50us. That is equivalent to about 500 bit times (one bit time for 10Mbps network is 100ns). 
Therefore, a station should be in transmit mode for at least 500 bit times, which gives us the minimum Ethernet frame of about 500 bits. The standard’s choice was 512 bits or 64 bytes minimum frame. So frames with fewer than 64 bytes will be padded out to 64 bytes. 

As the network speed goes up, the minimum frame length goes up too.

---
## binary exponential backoff algorithm
- after a collision, time is divided into slots, equal to the worst round trip propagation
- after the first collision, station waits 0 or 1 slots before trying again
- after a second, it waits 0 - 3 slots, and after third $2^3 - 1$ slots
- after 10 attempts, it is frozen between 0 and 1023 slots, and after 16 it gives up and reports a failure

---
## modern switched ethernet
![[mac_7.png]]
more station = more traffic, and at some point the LAN will be saturated
switches are typically devices that have 4 to 32 plug-in cards, each with one to eight ethernet connectors (rj45)
when a station wants to send an ethernet frame, it checks to see if the port is on the current card.
if it is, the frame is copied to that port. if not, the switch uses a multi-gigabit-per-second backplane to transfer it to the correct port.

---
## fast ethernet
approved as ieee starndard 802.3u standard in 1995
keeps all the old frame formats and procedural rules
reduces bit interval from 100ns to 10ns
uses only 10baseT wiring, so only star topologies
mainly supports utp cat 5 cables, but backwards compatabilit with cat3 is possible

### cabling
#### 100Base-T4
- twisted pair
- maximum segment of 100 m
- runs on cat3 cable if all 4 pairs are connected between station and hub. sends the 100 Mbps over the slower cables by fanning the signal out over three pairs of wires. this "demultiplexing" slows down each byte enough that the signal doesn't overrun the wires

#### 100Base-TX
- twisted pair
- maximum segment of 100 m
- full duplex at 100 Mbps
- most popular form, running on cat5 utp, and uses the same pin configurations as 10BaseT

#### 100Base-FX
- fibre
- maximum segment of 2000 m
- full duplex at 100 Mbps

#### 100Base-TX: in detail
only uses two of the available pairs, one for transmit and one for receive
for 100 Mbps, the waveform frequency would peak at 50MHz, while the Manchester encoding would pick at 100 MHz
-> cat5 is only rated for 100 MHz, so manchester encoding, which requires a higher bandwidth due to its two transitions needed to encode each bit, is unsuitable

100Base-TX uses two encoding schemes:
- 4B/5B to preserve synchronisation
- mlt-3 (multiple level transition, 3 levels) to decrease frequency, also called NRZI-3

100Base-FX uses NRZI: non-return-to-zero, invert-on-one encoding, which is objectively the worst acronym ever

##### 4B/5B
a byte is broken into two "nibbles", so if the byte is 0E, it is transmitted in the nibbles 0 and E. cause they're small bytes. (seriously, who named these)

these nibbles are then transformed into 5-bit 4b5b symbols, which are then transmitted using mlt-3. this is done at the physical layer.

this transformation can only be done using the 4b5b lookup table, or probably by using 2b2t somehow. the symbols 0-f are used as hex numbers, and h-t as control codes

![[mac_8.png]]
1 is change of state, 0 is lack of transition.
possible to think of mlt-3 as a continuous sine wave, which is halted on 0

#### 100Base-FX: in detail
very similar to tx, in that it uses 4b5b encoding, however it uses nrzi, which is a simpler version of mlt-3 
![[mac_9.png]]
this allows fx to use only a half wave to encode each bit, allowing for more efficient bandwidth usage

---
## gigabit ethernet
ieee 802.3z, approved in 1998
all point-to-point configurations, rather than classical multidrop
supports two modes of operation:
- full duplex:
all stations connected through a switch that allows traffic in both directions at once
csma/cd not employed, allows maximum cable length to be ignored
- half duplex:
all stations connected through a hub that simulates multidrop
csma/cd required, and corresponding max cable length is retained

### half duplex cable length extensions
these allow extension of the cable radius from 25m to 200m

#### carrier extension
hardware adds its own padding, 512 bytes, to the frame

#### frame bursting
allows the sender to concatenate multiple frames into the one transmission

![[mac_10.png]]
![[mac_11.png]]

> #networks_and_communications 