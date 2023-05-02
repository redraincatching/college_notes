# datalink layer
## functions
- provide service interface to networks layer
- dealing with transmission errors
- regulating data flow

to accomplish these functions, the datalink layer takes incoming packets from the network layer, and encapsulates it in packets
![[datalink_0.png]]
frame management forms the heart of the datalink layer's function

## services 
![[datalink_1.png]]
the princpal service that the datalink layer provides is to transfer packets from the network layer of the source machine to the network layer of the source machine to the network layer of the destination machine
a process on the source machine  at the network layer is responsible for passing packets to the datalink layer for transmission
the abstraction it provides allows the data to be thought to pass straight from datalink to datalink, obscuring the physical layer and cable as a black box

the datalink layer can provide the following types of services:
- unacknowleged connectionless service:
	- no ack by destination dll
	- good for reliable services with low error rate
	- good for speech where data loss is not as important

- acknowledged connectionless service
	- all frames ack'ed individually
	- if no response in a given time, resend
	- good for unreliable services like udp

- acknowledged connection-oriented service
	- most reliable but most complex
	- in three stages: establish link, transfer data, disconnect

![[datalink_2.png]]
consider a WAN subnet consisting of routers connected by p2p leased lines
when a frame arrives at the router, the hardware checks to see if it is error-free, then passes it to the datalink layer.
the datalink then checks to see if it is the expected frame, then passes it to the routing software (network layer)
the routing software determines the correct outgoing line and passes the packet back down to the datalink layer , which transmits it

### framing
#### flag bytes and byte stuffing
![[datalink_3.png]]
flag bytes with byte stuffing: resolving issues with resynchronisation after an error by having each frame start and end with special bytes, called flag bytes
a receiver can look for these if it is losing sync

if binary data is being sent, then the flag byte may appear within the data
one way to deal with his is by escaping each accidental flag byte
the data link layer on the receiving end removes these on receipt of the frame
this process is known as **byte stuffing**

#### bit stuffing
![[datalink_4.png]]
the previous method only allowed multiples of 8 bits to be a frame, rather than an arbitrary amount of bits. a different scheme, bit stuffing, is required for this
each frame begins and ends with a specific pattern: 0111 1110
so as to avoid this showing up in the binary transmission, a 0 is inserted after any five consecutive 1s, and is removed automatically at the receiving end

---
## error control
frames may be received incorrectly so the receiver will provide feedback
a frame may also just not arrive, or could be received multiple times

### flow control
- feedback based
the receiver sends back information to the sender, giving it permission to send more data [[there's a transport layer link here somewhere]]
- rate based
the sender has a built in mechanism that limits the rate at which data can be sent, which is negotiated before hand

### error detection and correction
- error-detecting codes
	- allow enough redundancy to allow the receiver to realise that an error has occurred, but not what or how to fix it
	- wastes less bandwidth
- error-correcting codes
	- include enough redundancy to allow the the receiver to deduce the transmitted data
	- also called forward error correction

a frame consists of: 
- m data bits (message)
- r check bits (redundancy)

this becomes an n-bit codeword, where n = m + r

###### hamming distance
the number of bit positions in which two codewords differ
can be found using a bitwise XOR

in most data transmission apps, $2^m$ messages are possible, but not all $2^n$ codewords are used
	> the two codewords with the minimum hamming distance give the hamming distance of the complete code

to **detect** d errors, you need a d+1 distance code
	> this is because with such distance there is no chance that d errors could change one valid code into another
	
to **correct** d errors, you need a 2d+1 code
	> the legal codewords are so far apart that even with d changes, the original codeword is still the closest valid codeword

#### parity
a single bit is appended to the data
in an even parity system, if the number of 1s is even, the parity bit appended is 1, and vice verse. obviously the opposite is true in an odd parity system
has a distance of 2, as any single bit error will produce a different parity


#### example error correction
consider a code with only four codewords: 0000000000, 0000011111, 1111100000, and 1111111111
this has a distance of 5, meaning that it can detect up to four errors, and can correct double errors.
given an original codeword of 0000000000, the double error 0000000011 could be corrected, as the closest codeword is the original, but the triple error 0000000111 could not

---
### applying error detection
adding parity bits to frames: alright, but gives a maximum probability of 0.5 of detecting a long burst of noise generating errors

therefore, we organise the frame into an m x k matrix, appending a parity bit every column, and send the matrix line by line
this would produce a distance of m

#### crc - cyclic redundancy check
also known as polynomial code
- bit strings are treated as representations of polynomials with coefficients 0 and 1 
	- e.g. the string 110001 would be treated as the polynomial $x^5 + x^4 + x^0$
	- polynomial arithmetic is done modulo 2, with no carries or borrows. with XOR, both addition and subtraction are identical
	- division is carried out as normal binary, except subtraction is done mod 2

[[TODO: FINISH LATER]]


> #networks_and_communications 