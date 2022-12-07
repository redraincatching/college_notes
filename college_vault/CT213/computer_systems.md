# overview of computer systems
## traditional classes of computer systems
- personal computer (pc)
-> designed for use by individuals, using incorporating graphical displays or other i/o elements

- server
-> a computer used for running larger programs for multiple users, often simultaneously, typically accessed only via a network

- supercomputer
-> a class of computers with the highest performance and cost, configured as servers
-> many powerful computers working in unison

- embedded computers
-> a computer inside another device, used for running one predetermined application or collection of software
e.g. powersteering

## post-pc era
- personal mobile devices
-> small wireless devices that connect to the internet
rely on batteries for power
software is installed through apps
conventional examples are phones, tablets

- cloud computing
-> large collections of servers that provide services over the internet
some providers rent dynamically varying numbers of servers as a utility

- software as a service
-> delivers software and data as a service over the internet, usually via a thin program such as a browser
e.g. web search or email

---

## seven levels of computer organisation
1) abstraction
lower level details are hidden to provide a simpler model at higher levels
2) efficient common case
enhancing the most common cases often improves performance more than optimising rare cases
ironically, this is more often simple and easier to do
3) parallelism
computing is more efficient when done in parallel
4) [[pipeline|pipelining]]
dear god why oh god oh fuck oh no
5) prediction
in some cases, it can be faster to guess the outcome and start working based on that, rather than waiting to see the outcome
this is assuming the cost of a mistake is not too expensive, and that the guess is relatively accurate
see xkcd/1938
6) hierarchy of memory
fastest memory is the most likely to be accessed
e.g. the [[memory_subsystems#cache|cache]]
7) dependability via redundancy
any system can fail, so we counteract this by two things
being able to detect failures
including redundant components that can take over in the case of failures

---
### [[operating_systems|operating systems]]
\[note: embedded systems rarely have operating systems, as they don't have to be "operated"\]
main use - resource management
-> runs in priveleged mode, and can stop and start user programs


> #computing_systems