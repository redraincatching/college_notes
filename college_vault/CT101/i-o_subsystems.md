# i/o subsystems

there are many kinds of i/o device, which are all completely different, but they are all part of the same subsystem
the interface between the cpu and the i/o devices are very similar

each i/o device needs to be connected to
- address bus
to pass addresses to the peripheral
==unidirectional!==
- data bus
to pass data to and from the peripheral
- control bus
to pass control signals to the peripheral

## problems
wide variety of peripherals
-> delivering different amounts of data, in different formats, at different speeds

all slower than cpu and ram
- need i/o modules
	- these interface with the processor and memory system via system buses, or the central switch, and interface to one or more peripherals using specific data links

---
## i/o module
![[i-o_module.png]]

### peripheral device types
![[peripheral_device_types.png]]
- human readable
screen, printer, keyboard
- machine readable
monitoring and control, e.g. mouse or joystick
- communication
modem, network interface card (nic)

### i/o module functions
- control and timing of data flow
- cpu communication
- device communication
- data buffering
- error detection

### i/o cpu steps
- cpu checks i/o module device status
- i/o module returns status
- if ready, cpu requests data transfer
- i/o module gets data from device
- i/o module transfers data to cpu
- variations for output, dma (direct memory access), etc.

### i/o module diagram & design decisions
![[i-o_module_diagram.png]]
- hide or reveal device properties to cpu
- support multiple/single device
- control device functions or leave for cpu
- also os decisions
-> e.g. unix treats everything possible as a file

### i/o mapping
#### memory mapped i/o
- devices and memory share an adress space
- i/o looks just like mem rw operations
- no special i/o commands, just a wide range of mem
#### isolated i/o
- separate address spaces
- need i/o or mem select lines, or even a separate bus
- special commands and cpu control signals
- devices and memory can have overlapping addresses

### addressing i/o devices
i/o data transfer is very like memory access (cpu viewpoint)
each device has a unique identifier
-> cpu commands contain the identifier

---

### input devices
![[input_devices.png]]
when the values of the address/control bus are correct (the i/o device is addressed), the buffers are enabled, and the data passes on to the data bus
-> the cpu reads this data

when the conditions are not right, the logic bloc (the enable logic) will not enable the buffers, and no data will reach the bus
>the example shows an i/o device at address 1111 0000 on a computer with an 8-bit address bus and rd and io/m' control signals

### output devices
![[output_devices.png]]
since the output devices read data from the data bus, they don't need buffers, the data is made available to all buffers
-> only the correctly decoded (i.e. addressed) one will read in the data
>the example shows an i/o device at address 1111 0000 on a computer with an 8-bit address bus and wr and io/m' control signals

### bidirectional devices
![[bidirectional_devices.png]]
actually require two interfaces, one for input, one for output

same gates can be used to generate the enable signal, the read/write difference is made with control signals (rd, wr)

in real systems, we need to access more than just one input and one output register
usually peripherals are issued with commands by the processor, they take some action, and in response present data

---
## i/o techniques
![[i-o_techniques.png]]

### programmed i/o
#### overview
- cpu has direct control
	sensing status, r/w commands, transferring data
- cpu waits for module to complete operation
- wastes cpu time

#### operations
- cpu requests operation
- module performs operation
- module sets status bits
- cpu checks these periodically
	-> module does not directly inform cpu, does not interrupt cpu
- cpu may wait or come back later

### interrupt driven i/o
#### overview
- overcomes cpu waiting
- no repeated cpu checking
- i/o module interrupts when ready

#### operations
- cpu issues read command
- module gets data while cpu does other work
- module interrupts cpu when data retrieved
- cpu requests data
- module transfers data

![[interrupt_processing.png]]

#### cpu viewpoint
- issue read command
- do other work
- check for interrupt at the end of each instruction cycle
- if occurred:
	- save context (registers)
	- process interrupt
	- restore context

#### design issues
- how do you identify the module issuing the interrupt?
- how do you deal with multiple interrupts?
-> e.g. an interrupt handler being interrupted

##### identifying interrupt module
- different line for each module
	- limits number of devices
- software poll
	- cpu asks each module in turn
	- slow
- daisy chain or hardware poll
	- interrupt acknowledge sent down a chain
	- module responsible places vector on bus
	- cpu identifies handler routine with vector
- bus arbitration (e.g. pci, scsi)
	- module must claim the bus before it can issue the interrupt, thus only one module can interrupt at a time
	- when processor detects an interrupt, , it issues an acknowledge
	- device then places its vector on the bus

##### multiple interrupts
![[multiple_interrupts.png]]
each line has a given priority, and higher priority can override lower ones

### direct memory access
both other types require active cpu intervention
-> transfer rate limited by speed of processor testing and servicing
-> cpu tied up in managing i/o transfer
dma is most useful for large amounts of data

#### dma function and module
![[dma_function_and_module.png]]
dma controller able to mimic cpu and take over for i/o transfers
cpu tells dma controller:
- operation to execute
- device address involved (sent on data lines)
- starting address of memory block for data, which is stored in the dma register

cpu carries on with other work
dma controller deals with transfer, sends interrupt when finished

#### dma transfer "cycle stealing"
controller takes over bus for a cycle
transfers one word of data
not an interrupt, cpu does not switch context
cpu suspended just before it accesses bus
slows cpu, but not as much as cpu data transfer

#### dma operation example
![[dma_operation_example.png]]

> #computing_systems 