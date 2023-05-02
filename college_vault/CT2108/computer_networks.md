# Computer Network
a collection of autonomous devices interconnected by some kind of network technology
the internet is a network of networks
	-> the world wide web isn't a physical network, it's a distributed client-server application
teo computers are said to be interconnected if they are able to exchange information

## the client-server model
employed in most network applications
the server is a powerful machine that can provide resources to many clients concurrently
the client is a simpler device that interprets or displays those resources
involves requests and replies
![[client-server_0.png]]
employs at least two processes, one running on the client and one on the server
![[client-server_1.png]]
// in peer-to-peer systems there are no fixed clients and servers, each device can perform both

---
## network types
- wireless networks
- personal area networks
interprocessor distance: 1m
- local area networks
interprocessor distance: 10m - 1km
- metropolitan area networks
interprocessor distance: 10km
- wide area networks
interprocessor distance: 100km - 1,000km
- the internet
interprocessor distance: 10,000km

![[network_types_0.png]]

#### two main types of networks
- eyeball networks
- content provider networks
- tier one networks (interconnection, bandwidth providers)

### local area network - LAN
#### various topologies
- bus
![[lan_0.png]]
- ring
![[lan_1.png]]
useful due to redundancy and routing advantages
- star
ethernet

LANs are privately owned, and can occupy a single room, building, or campus
restricted in size, so the worst case transmission time is bounded and known
very often connect each machine to the same cable

#### ethernet
bus-based broadcast decentralised network
connected computers can transmit whenever they want, if packets collide they just wait a random time and try again

### metropolitan area network - MAN
![[man_0.png]]
example using cable tv network

###  wide area network
![[wan_0.png]]
relation between hosts on LANs and the subnet
spans over a large area
connects hosts to each other via a communication subnet
a subnet is comprised of two components
- transmission lines
moves bits between networks (fibre, copper, radio)
- switching components
specialised computers that connect transmission lines
chooses which outgoing line to put incoming data on
also called routers

![[wan_1.png]]
when sending a message, the message is cut up into small "envelopes", called 
a stream of packets from a sender to a receiver
a "store-and-forward" or packet switched network is one where the packets are received entirely at intermediate routers, stored until an outgoing line is free, and then forward them to the next router
// when the packets are small and the same size, they are called cells

> /\*
> HEAnet (higher education authority network)
> connects colleges
> WAN
> \*/

### wireless networks
![[wireless_network_0.png]]
- bluetooth
a system interconnection network, refers to interconnecting computer components
master-slave topology
the master tells the slave what addresses to use, when they can broadcast, how long they can transmit, what frequencies they can use, and other information
- wireless LAN
each computer has a radio modem and antenna with which it can communicate with other systems 
IEEE 802.11 is a basic standard for wirelesss LAN
a number of newer, derivative standards are in place now
- wireless WAN
cellular phone networks; 3g, 4g, 5g

> ## architecture of the internet
> ![[internet_0.png]]

> #networks_and_communications 