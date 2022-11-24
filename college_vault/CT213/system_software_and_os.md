# system sofware and os
### application software
a computer program designed to perform a group of coordinated functions
designed to perform a specific task, or solve a certain problem

### system software
dedicated to managing the computer
provides a platform for other software
provide a general programming environment
two types
- operating system
- utility software

#### operating system
- provides functions used by the application software
- manages resources in a way that lets other programs efficiently and safely share the hardware
- interacts directly with the hardware to interface with other system software
	- application-domain independent
	- provides resource abstraction and sharing

#### utility software
system software desinged to analyse, configure, maintain, or optimise a computer

- registry cleaners
- data compressors
- disk cleaners
- system monitors

---
### resource abstraction
done by providing an abstract model of the operation of the hardware components
different components a program may access are the resources
any particular resource has a generic resource that defines how the programmer can make it perform a desired operation

abstraction can limit flexibilty
some specific hardware controls may become hard, if not impossible

an abstraction can be made far simpler than the actual interface
-> e.g. cd-roms and hard-disks in the same filesystem

### resource sharing
resources may need to be shared between concurrently executing programs
- space multiplex sharing
a resource is divided into distinct units that can be accessed independently
e.g. memory, storage
- time multiplex sharing
a process is allocated exclusive control of a non-space-divisible resource for a short period of time

---
##  os organisation
![[os_organisation.png]]
##### process and resource manager
- resource allocation
- uses abstrction provided by other managers
##### memory manager
- generally separate to other managers
- implements virtual memory
##### file manager
- abstracts device i/o
##### device manager
- handles r/w of physical devices
- implemented within device driver

### functional requirements
the base requirements for an os to work

##### process manager
- creation, termination, control, exception handling
- protection
- synchronisation and communication
- resource allocation
##### memory manager
- protection and sharing
- allocation
##### filesystem manager
- protection, sharing, security
- space allocation
- physical resource abstraction
##### i/o devices
- allocation
- protection and sharing
- physical resource abstraction

## evolution of operating systems
- computers with no os
programming in machine language, no i/o
punchcards!
- rudimentary os
programming in assembly
some basic i/o devices
some basic i/o control modules, assembler, debugger, loader, linker

#### batch processing system
serve a collection of jobs, called a batch, from the queue
job - a predefined sequence of commands, programs, and data combined into a single unit
job control language and monitor batch (jcl)
doesn't interact with programs as they operate

![[batch_system.png]]
**processor scheduling**: fifo
**memory management**: divided into system and program memory
**i/o management**: no special problems, only one program at a time, so they each have exclusive i/o access
**file management**: simple as well

// still somewhat used by computer clusters

#### multiprogramming
the technique of loading multiple programs into space-multiplexed memory while time-multiplexing the processor
- timesharing systems
- real-time os
- distributed os

##### common features:
- multitasking
	multiple processors sharing machine resources
- hardware support for memory protection and i/o
- multiuser and multitasking support
- optional support for real time operations
- interactive ui

#### timesharing systems
multiuser and multiprogramming support
![[timesharing_systems.png]]
**processor scheduling**: time-slice
**memory management**: protection and inter-process communication supported
**i/o management**: protection and sharing between users
**file management**: protection support and sharing between users

#### real-time operating systems
![[real-time_operating_systems.png]]
used whenever a large number of critical external events have to be treated in a short or limited amount of time
support for multitasking

**main goal**: minimising response time to service external events
**processor scheduling**: priority based preemptive
**memory management**: concurrent processes loaded in, protection and inter-process communication supported
**i/o**: time-critical, processes are directly connected to interrupt vectors
file management: may not exist, otherwise is very strict

// used in embedded systems

#### distributed operating systems
![[distributed_system.png]]
- multiprogramming introduces a strong centralisation tendency
- distributed os aims for decentralisation
- based on network technologies, with different communication and synchronisation protocols
- client-server architecture
- primary concerns are security and protection

#### modern os
_batch processing_ -> constant processor load of low-priority tasks
_timesharing_ -> interactive processes on timeshare
_realtime_ -> critical processes treated according to realtime concerns
_distributed_ -> client-server operations

---
## os implementations
- monolithic os
try to achieve the functional requirements by executing all of the code in the same address space to increase performance
not scalable in any way, but has specific use cases
- hierarchical os
run most of their services in user space, aiming to improve modularity and maintainability
suitable for oop, as encapsulation is very well defined
        
### implementation considerations
- multiprogramming
rapidly switching between programs, and executing them for a fixed time quantum, the timeslice
when a timeslice ends, the program stops it, removes it, and gives another program control - context switching
-> to do this, the os copies the contents of the current program register into memory, restores the context of the next program's register file into the processor, and executes that for the next timeslice
-> the program essentially doesn't notice that a context switch has occurred
![[context_switching.png]]
- protection
programs must not be able to access the data of other programs, or interfere with their use of i/o devices
achieved by giving the os full resource control
virtual memory is one of the techniques used to achieve this
-> each program operates in a full set of virtual address space, as if it were the only program on the computer
these virtual memory addresses are translated into physical memory addresses
as long as the translation keeps them separate, no two programs can write to the same space
- processor modes
operating modes for the cpu that the place restrictions on the operations that can be performed by the currently running process
these help renofrce rules that prevent malware from running
the os runs in privileged mode , which is responsible for low level ui, and can control all resources unrestrictedly
most programs run in user mode, and executes a "system call" when it needs permissions, i.e. asking the os itself to do the operation
![[modes.png]]
the mode bit defines the execution capability of the processor, which can be logically extended to even define different areas of memory for each mode
- kernels
the part of the processor that executes in supervisor mode
operates as trusted software
provides the lowest level of abstraction
fundamental design decision, protection and performance are inversely proportional


## methods for requesting system services
###### through command line interface
by calling a specific command or using a command interpreter (the shell)
###### from user processes requesting services from os
by calling a system function or sending a message to a system process

### command execution mechanism
keypress generates a hardware interrupt
specialised os module reads it and stores it in a special command line buffer
end of line detected: control taken by shell
analysis of command (with error or success)
if success, interpreter decides if it is internal, or for another module (external)
based on this, either tries to execute or looks for corresponding executable
                            
#### system call
![[system_call.png]]
parameters are passed according to hardware architecture and os convention
switch to protected mode using a specific mechanism
e.g. software interrupt or supervisor call
special module takes over to analyse the parameters and accept or reject the call
if accepted, corresponding os routine is executed, and user control is restored on return

#### system messages
![[system_messages.png]]
user process constructs a message describing a desired service A
uses a send function to pass the message to a trusted process
- send checks the message
- switches the process to protected mode
- delivers the message to the target process

user waits for a message received result
sent when kernel finishes processing the request

> #ct213 #computing_systems 