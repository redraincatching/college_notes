# network software
## protocol hierarchies
![[protocol_hierarchies_0.png]]
layers, protocols, and interfaces


to reduce the complexity of design, networks are organised into layers
***not every layer has an associated protocol***
the basic purpose of a layer is to create interfaces to allow higher layers to use its resources

> protocol - a means for layers on the same level to communicate
> interface - a means for layers of different levels to communicate

 only 3 physical mediums are realistically used in communication; fibre, copper, and wireless
-> layer 1 might interface with this medium
-> layer 2 interfaces with layer 1, therefore the higher you go the more abstract, and the more common the layers become

> ### protocol stack
> -> the philosopher-translator-secretary architecture
> the philosopher has the "data", and wants to communicate this with a philosopher who speaks a different language
> the tranlsator switches it to a common language
> the secretary faxes it to the other philosopher's secretary, who begins undoing the process
> // each of these peer processes are a protocol

![[protocol_hierarchies_1.png]]
- a message is produced in layer 5, by an application for example
- this message is given to layer 4 for transmission, which adds a header related to its own protocol
- at layer three, the message has been split into packets as the message was too large to send, and the layer 3 header has been added
    // this is to do with the physical limitations of transmission protocols such as ethernet
- at layer 2 it is framed by a header and a trailer (maybe associated by wifi?)
- then the message is passed over the medium to the destination machine

### design issues for layers
- addressing
consequence of having multiple destinations
- error control
the receiver should be able to inform the sender which data was received correctly
- flow control
keep sender from swamping slow receiver with data
keep sender from swamping slow networks
- multiplexing
use same communication channel for multiple, unrelated conversations
- routing
when multiple paths exist between the source and destination, the optimal one must be chosen

### connection-oriented and connectionless services
#### connection-oriented
e.g. tcp
reliable message stream (sequence of pages, file transfer)
reliable byte stream (remote login)
unreliable connection (digitized voice of video) -> better to lose data than delay
#### connectionless
e.g. ip
datagram service (in analogy with telegram service)
	-> acknowledged datagram service
request-reply service

##### services to protocol relationship
![[services_to_protocols_0.png]]
service: set of primitives (operations) that a layer provides to the layer above it, relate to the interfaces
protocol: set of rules governing the format and meaning of packets exchanged by peers within a layer, relate to packets sent between entities in different machines

---
## reference models
### osi reference model
***open systems interconnect***
based on a proposal by the iso to standardise the protocols used in various layers
![[osi_0.png]]
// note: never actually got used, but is used as a reference
// sort of an ideal form

### design principles
- a layer should be created where different abstraction is needed
- each layer should have a well-defined function
- the function should be aimed towards an internationally standardised protocol
- layer boundaries should be chosen to minimise the data flow between layers
- the number of layers should be large enough to avoid throwing together small, disparate functions, and small enough to avoid inefficiency

> ### 7 layers
> // all 7 are only used in the first sender or the ultimate destination
> ##### 7 - application
> contains a number of different protocols and applications needed by users, such as https
> - when a browser wants a webpage, it sends the name of it to a web server using the http protocol
> ##### 6 - presentation
> not concerned with moving bits around, rather with the syntax and semantics of the data being mvoed by the lower layers
> in order to make it possible for computers with different data representations to communicate, the data structures to be exchanged can be defined in an abstract manner, along with a standard encoding
> ##### 5 - session
> allows users on different machines to establish sessions between them
> sessions offer:
> - dialog control, keeping track of whose turn it is to transmit
> - token management, preventing two parties from attempting the same critical operation at once
> - synchronisation, marking long transmissions so that they can be resumed
> ##### 4 - transport
> accepts data from layer above, splits it into smaller units, and passes them to the network layer
> ensures they arrive correctly at the other end
> determines what type of service to provide
> - error-free, point-to-point channel in order
> - rapid datagrams with no reliability
> - broadcast
> entirely end-to-end
> ##### 3 - network
> controls subnet operation
> design issues
> - routing
> - congestion control
> 	- if too many packets are present in the subnet at one time
> - heterogenous network interconnection
> ##### 2 - data link
> transform the raw transmission into a line free of transmission errors
> design issues:
> - error detection and correction:
> 	- the sender breaks up the input data into frames, and correct receipt of these is essential
> - flow control
> 	- keep a fast transmitter from drowning a slow receiver in data
> 	- some traffic regulation mechanism is needed to let the transmitter know how much buffer space the receiver has
> - broadcast networks also need to deal with access to the shared channel
> 	- however, the mac sublayer deals with this
> ##### 1 - physical
> 1 & 2 are basically inseperable, as they're tied to the specific physical medium that is used to transmit data
>  used for transmitting raw bits over the communication channel
>  typical problems addressed:
> - how many volts is a 1 or 0
> - how many nanoseconds a bit lasts
> - full duplex or not
> - how initial connection is established and torn down
> - how many pins the network connector will have and what they're used forr
> design issues:
> - 1 has to mean 1 on both sides
> - mechanical, electrical, and timing interfaces
> - physical transmission medium

---
## tcp/ip reference model
![[tcp-ip_0.png]]
- application layer
![[application_layer_0.png]]
contains all the high-level protocols; http, file transfer, email, dns...
- transport layer
designed to allow entities on the source and destination to carry on a conversation
two e2e protocols;
	- tcp
	- udp
- internet
permits the hosts to inject packets into any network ad have them travel independently to the destination, potentaially using different paths or networks
the higher layers rearrange them on arrival
defines an official packet format and protocol, the internet protocol (ip)
- host-to-network
below the layer, in the tcp/ip model, is a great void
the model doesn't give any details, as it varies from host to host and network to network

---
###  comparing tcp and osi
central concepts are similar
-> service, protocols, interfaces
the osi reference was developed before the protocols were created
-> model is not biased towards certain protocols, but is generic
-> designers didn't have much experience, and weren't sure what function to give each layer
tcp/ip:
-> protocols came first, and fit the model perfectly
-> model was too specific, could only describe tcp-ip

#### osi
7 layers
supports connectionless and connection-oriented at the network layer, and only one type of connection-oriented service at transport layer

#### tcp/ip
supports only connectionless at network layer, and both at transport layer

> why not osi?
- bad timing
standards came in too slow
- bad technology
session and presentation layers were nearly empty, whereas network and datalink were overcrowded
protocols and service definitions were too complex, almost incomprehensible
- bad implementations
given the compplexity of the protocols, the implementations were huge and inefficient
in contrast, one of the first implementations of tcp/ip was part of berkeley unix, and was good and free
- bad politics
osi was created by telecommunications ministries, tcp/ip was created by independent researchers

---
## hybrid model
![[hybrid_model.png]]
the hybrid model to be used in this course

> - application layer
> - transport layer
> - network layer
> - data link layer
> - [[physical_layer|physical layer]]

// TODO: link these
[[see also, the later diagram that makes more sense]]

> #networks_and_communications 