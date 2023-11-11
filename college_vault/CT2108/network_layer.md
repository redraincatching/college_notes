# network layer
## tcp/ip network layer
![[net_layer_0.png]]
tcp/ip protocol stack
// this is one of the best visualisations i've seen

> ###### vint cerf - description of how ip works
> say you're on holidays, and want to send a postcard to someone
> this postcard can hold a certain amount of information (the datagram), has an address, a stamp
> postcards don't always arrive, and they don't always arrive in the order posted (disorderly delivery)
> what if you wanted to send your friend the contents of your favourite book, all written on postcards?
> -> you'd need to paste pieces of the book onto the postcard, and number the postcards
> -> what happens if some get lost?
> friend has to, every now and then, send you a response
> "i got up to page 20, and i'm missing page 8"
> what if this acknowledgement gets lost, or you have to resend some? 
> -> keep a copy of everything you send
> 
> ip - the postcards and postal service
> tcp - the chopping up and checking receipt service
>
> ip is a fundamentally unreliable service, tcp makes it more reliable

## principles that drove tcp/ip design
- make sure it works
testing-driven
- keep it simple
- make clear choices
if many ways to do something, commit to one
- exploit modularity
- expect heterogeneity
did this exceptionally well, that's why it's lasted since the 70's
- avoid static parameters
negotiate a value rather than define one, where possible
- good design, not perfect
don't worry too much about special cases
- strict when sending, tolerant when receiving
- scalability
- performance and cost

---
## internet - connection of subnets
broken up into autonomous systems (AS)
AS - a subnet controlled by a single entity, such as an ISP, a company, etc
![[net_layer_1.png]]
routing different wrt inter- and intra-AS routing
important feature is the number of AS hops required to reach destination

### ip - internet protocol
glue that holds the internet together
provides a best-effort way to transport datagrams
workflow:
- transport layer takes the data streams and breaks them into datagrams
could, in theory, be up to 64kb, but the maximum transport unit (mtu) of ethernet is 1500 bytes, so not larger than this in practice (not including headers)
- each datatgram is transmitted through the internet
possible fragmentation here
- when all pieces have arrived at the destination machine, they are reassembled into the original datagram by the destination's source layer
- this datagram is handed to the transport layer, which then inserts it into the receiving process' input stream

// fragmentation is actually avoided as best as possible, as it's not efficient

### format of the ip datagram
![[net_layer_2.png]]
// transferred in big-endian
- version: 
4 bits
either ipv4 (0100) or ipv6 (0110)
- header length: 
4 bits
how long the header is in 32-bit words
minimum value is 5, when no options present, max is 15, but this is rare
- type of service:
6 bits
also called dscp, differentiated service codepoint
defines how the datagram should be handled; priority, level of throughput, delay, realtime flow
however, this field is almost always ignored by routers
- total length:
16 bits
includes everything in the datagram, header and data
currently the limit is 65,535 bytes
- identification:
16 bits
what datagram a newly arrived fragment belongs to
- df, mf:
flag bits meaning don't fragment or more fragments
df: useful for systems that can't undo fragmentation
mf: means more fragments left in the datagram, all except 
- fragment offset:
13 bits
where the current fragment resides in the datagram
position 
- time to live:
8 bits
renamed in ipv6 to hop count
used to limit maximum life of a packet
supposed to count time in seconds, but actually counts the amount of hops a packet can make
when it hits 0, it's discarded, and a warning is sent back to the source over icmp
- protocol:
8 bits
specifies the transport layer protocol (tcp/ip)
- header checksum:
16 bits
verifies only the header
the algorithm is to add up all 16 bit half words as they arrive using one’s complement arithmetic and then take one’s complement result
recomputed at each hop as it changes
source and destination addresses:
32 bits each
- ip options:
	- security
	how secret the datagram is, supposedly to stop routing through certain countries/ASs
	in practice fucking stupid, like stamping TOP SECRET on it
	- strict source routing
	exact path to be folowed
	- loose source routing
	points in path not to be missed
	- record route
	tells routers to append their address to the option list, but arpanet only had 9 routers when this was made, so this isn't useful today
	- time stamp
	similar to record route
	useful in debugging routing algorithms

// these are also usually ignored, some experimental or debug usage though
40 bytes

---
## ip addressing
internet address is made of four bytes that define a host's connection to a network
originally divided into classes, however these have been superceded by classless addresses, which are far more mutable

three fields of variable size
- class type field
- network id
- host id

###### ICANN
internet corporation for assigned names and numbers
nonprofit organisation that manages the assignment of ip addresses, AS numbers, ip address sapce to regional authorities

### internet classes
![[net_layer_3.png]]
determined by the first 4 bits
- 0 - A
- 10 - B
// full
- 110 - C
// available addresses
- 1110 - D
// multicasting
- 1111 - E
// reserved

class A, B, and C have kind of been merged into one class, D and E still exist
all of class A and B were sent out to early adopters like universities, so they filled up way too quickly
-> there were only ever 128 class A addresses

dotted decimal notation is used, as these four bytes translate pretty easily 
e.g. 128.0.0.66

#### class ranges for internet addresses
![[net_layer_4.png]]

special ip addresses
00000000 00000000 00000000 00000000
this host
00000000 00000000 \[host\]
a host on this network
11111111 11111111 11111111 11111111
broadast on a local network
\[network\] 11111111 11111111 11111111
boradcast on a distant network
great for ddos!
127 \[anything\]
loopback
not actually sent, just passed straight to incoming

##### sample internet
![[net_layer_5.png]]

moving away from classes
all addresses have a network and host id, this means there is a hierarchy in the ip addressing
to reach a host, we need to reach the network first with the first portion


##### example - campus network
nuig was allocated the class B addresses of 140
actually allocated a public ip address when using campus wifi
however, there was a massive amount of ARP traffic going through the whole network at all times (thousands of packets a second)
-> the network was flat, i.e. was organised as one massive LAN

solution:
allow subnets -> allow the network to be broken into individual lans (technically vlans)
still act as a single network to the outside world
![[net_layer_6.png]]

---
## subnets
![[net_layer_7.png]]
creates an intermediate level of hierarchy
uses a variable length network mask/subnet mask
bitmask used to select which bits are network and which are host
instead of having a single class b address with 14 bits for network and 16 for the host, some bits were taken away from the host to allow the use of a subnet number
to implement subnetting, the main router will need a subnet mask that indicates the split between network, and subnet & host number
the masking process extracts the address of a physical network from the ip address using a bitwise AND
masking can be done whether we have subnetting or not

because subnetting is entirely internal, it's invisible to outside observers

notation can be either dotted decimal (255.255.252.0) or slash (255.255.252/22)

// bitmask has to be 1s followed by 0s, which makes the conversion a lot easier
// that's also why slash notation works, because it's the length of the string of 1s

### practical example
![[net_layer_8.png]]

#### example actually using eduroam
my current ipv4 address:
140.203.129.12          // see the class B address?
subnet mask
255.255.248.0           // could alsobe written /21

corresponds to
```verbatim
ip:             10001100 11001011 10000001 00001100
subnet mask:    11111111 11111111 11111000 00000000
```

means the first 21 bits of the ip correspond to the network, and the remaining 11 are the subnet and host is

so basically the first subnet of 140.203.0.0 ranges from
	140.203.0.1 -> 140.203.7.254
because 0.0.7.254 is 00000000 00000000 00000111 11111111


see ipcalc

---
## ip address shortages
ip v4 is running out of addresses
- class A is too big for most organisatoins
- class C is too small
- B is roughly right
// in reality, half of class B networks have less than 50 hosts

two solutions
- Classles InterDomain Routing (cidr)
- Network Address Translation (nat)

### cidr
basic idea is to allocate the remaining ip addresses in variable-sized blocks, without regard to classes
if a site needs, say 2000 addresses, it is given a block of 2048 addresses on a 2048 byte boundary
-> this makes routing a lot more complicated

#### old routing algorithm
- incoming packet to the router
with destination address, e.g. 140.203.8.22
- router extracts destination ip and shift a copy of it right 28 bits to obtain the 4-bit class number
e.g. 1000
- have a 16-way branch that sorts them into the class
8 cases for a, 4 for b, 2 for c, 1 each for d and e
- these branches then apply the correct network mask, and can use the class lookup tables to find out the correct outgoing physical line

#### cidr routing algorithm
// called cidr because i would like to drink while working on it
- each routing table is extended by a 32 bit mask
- now a single routing table for all addresses, consisting of (net ip address, subnet mask, outgoing line) triples
- when a packet comes in:
- its destination address is first extracted
- the routing table is scanned, entry by entry, to find a match
// if multiple matches are found, the longest mask found is used
- commercial vsli chipsets for routers use this algorithm

##### practical example
addresses are available at 194.24.0.0
suppose that:
- cambridge needs 2048 addresses
given 194.24.0.0 to 194.24.7.255
- oxford asks for 4096
- edinburgh wants 1024

// nuig has a full /16

// TODO: finish this


            nat
                comes into play whenever there is a greater demand than there are real available ips
                used in private home networks - most home internet connections only have a single public ip address

                nat rfc 3022
                    basic idea is to assign a single ip address (or a small number of them) for internet traffic, withn that group assign every computer a unique ip, which is used for internal routing, however it gets translated to the public address for external routing
                    three ranges of ip addresses have been declared private to make this possible - these can be used as private within any organisation, however these packets cannot appear on the internet itself

                [diagram]
                // most common of these to be used is 192.168, which is a /16
                // can also have double nat-ing

                [diagram]
                // source port 5503, dest port 80
                // connection tracking has timeouts built in for the network mapping, basically like caching it for extended use (like several requests to and from a webpage)

                nat problems
                    - violates the architecture of the ip model, which states that every host worldwide should be identified should be identifiable by a unique ip
                    - changes the internet from a connectionless network to a connection-oriented one
                    - violates the most elementary rule of protocol layering, due to the use of port changing in the translation, which states that layer k should not make any assumption of what layer k+1 puts in the payload
                        -> this is the real issue
                        -> ports are associated with the transport layer
                    - can only work with tcp and udp protocols
                    - some applications inset ip in the text (payload), the receiver will extract these and use them, this obfuscation stops nat from working
                        -> e.g. ms messenger


> #networks_and_communications 