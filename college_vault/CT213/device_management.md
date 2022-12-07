# device management

the process of managing the implementation, operation, and maintenance of physical or virtual devices
a broad term
the other main function is to implement application programming interfaces (api)

the os manages devices with the help of 
- device controllers:
	hardware components that contain some buffer registers to store the data temporarily
	e.g. disk controller
- device drivers:
	programs used by the os to control devices

the device controller includes three diffferent registers
- command
- status
- data

![[device_management.png]]
each controller is specific to each device

## methods to detect device input
### polling
- implementation
	periodically checking status of the device to see if it is time for the next i/o operation
	i/o device simply puts the information in the status register, the process must retrieve it
- efficiency
	simplest implementation
	not efficient, wastes cpu time
        
### interrupt-driven
- implementation
	a device sends an interrupt signal when it needs cpu attention
	the cpu saves its current state, and invokes the proper interrupt handler using the interrupt vector
	then, the cpu continues its original task as if it had never been interrupted
- efficiency
	allows the cpu to handle input at any time
	removes need for cpu to waste time checking for input

### direct i/o
- implementation
	uses software which explicitly transfers data to and from the controller's data registers
	separate i/o and memory address space
	control indicates whether address information is for memory or i/o
	![[direct_i-o.png]]
- efficiency
	reduced cpu utilisation

### memory-mapped i/o
- implementation
	direct connection between i/o device and certain main memroy locations so the the i/o device can transfer a block of data without going through the cpu
	the os allocates a buffer in memory to the i/o device to send data to the cpu
	the i/o device operates asynchronously from the cpu, and interrupts it when finished
- efficiency
	ideal for communication and other high-speed i/o devices
	useful for long operations like network communicaton or transferring data to/from storage

---
## design objectives
- efficiency
most i/o devices are extrememly slow compared to the processor and main memory
- buffering is one way to deal with this issue
- generality

it is desirable to handle all devices in a consistent and uniform manner
- in the way user processes see the devices
- in the way the os manages the i/o devices and operations

### buffering
a technique the os can employ by which the device manager can keep slower i/o devices busy when the process does not require i/o operations
- input buffering:
	having the input device read information into the primary memory before the process requests it
- output buffering:
	saving the information to memory, and writing to the device while the process continues execution

#### hardware-level buffering
consider a simple character device controller that reads a single byte from a router for each input operation
##### nomal operation:
- read occurs
- the driver passes a read command to the controller
- the controller instructs the device to put the next character into the one-byte data controller's register
- the process calling for the byte waits for the operation to complete, then retrieves the character from the data register

##### buffered operation
- the next character to be read by the process has already been placed into the data register, even though the process has not yet called for the read operation
- adding a hardware buffer decreases the amount of time the process has to wait
![[hardware_level_buffering.png]]

##### driver-level buffering
generally called double-buffering
one for the driver to store data while waiting for the higher levels to read it
one to store data for the lower-level module
![[driver-level_buffering.png]]

##### using multiple buffers
the number of buffers is extended from two to n
the data producer is writing into buffer i while the data consumer is reading from buffer j

in this configuration
- if i\<j: buffers \[j+1, n-1] and \[0, i-1] are full
- if j\<i: buffers \[j+1, i-1] are full

this is known as circular buffering

![[multiple_buffers.png]]

> #computing_systems [[i-o_subsystems]]