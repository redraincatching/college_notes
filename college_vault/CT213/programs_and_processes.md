# programs and processes

## program
a static entity made up of source code statements which define the behaviour fo a process
## process
a dynamic entity that executes a program on a particular set of data using resources allocated by the system
-> multiple processes can execute the same program

a process is a program in execution
composed of 
- program
- data
- process control block, containing the state of the process

### execution of a process
a process needs an abstract machine environment in order to execute, to manage its use on resources
the process control block is required to map the environment state onto the physical machine state
the os keeps a process descriptor for each process
![[process_execution.png]]
-> this is all so the process does not need to constantly request the os for resources

### execution of a program
each execution of a program generates a process that is executed
inter-process relationships
- competition: processes are trying to access different parts of the system, therefore protection is necessary
- cooperation: sometimes the processes need to communicate between themselves in order to synchronise correctly

### process manager functions
implements: 
- cpu sharing: 
called scheduling, allocates resources in accordance with certain policies
- process synchronisation and inter-process communication:
deadlock strategies and protection mechanisms
![[process_manager.png]]

---
## processes from different perspectives
### user perspective
consider an application that monitors an industrial process, and records its operation
the application contains 4 program modules
- data acquisition (collect): 
reads 3 values from a converter
each collection is 1 time interval (1t), 1/4t processor, 3/4t waiting for read op to finish
// cpu is always the fastest thing in a computer, so it spends a lot of time waiting
- data storage (log)
writes the 3 collected values onto the disk
neads two operations: write 2 chars at a time, including '\n'
1/2t processor time, 3/2t waiting for write to finish
- statistical processing (stat)
statistical processing of values
2t processor time
- print results (report)
prints two vaues from stat
each print needs 1/4t processor time, 5/4t waiting for print to finish

#### sequential implementation
```c
main() {
	while (TRUE) {
		collect();
		log();
		stat();
		report();
	}
}

```
![[sequential_operation.png]]

time required for a cycle is 12t
4.25t processor time
7.75t waiting for various i/o operations

#### multitasking implementaion
while the cpu is waiting, use that time to work on other tasks
however; some programs depend on each other to run

we'll execute the processes in quasi-parallel, so that the programs can tlak to each other, using the following priority order
- log
- collect
- report
- stat

we need some synchronicity, this can be done using the wait and signal directives
**wait**: wait for a signal from a specific process
**signal**: signal another process to start

e.g. 
```c
void log(){
	while(TRUE){
		wait(collect);  // log needs to wait for collect to find data to log
		log_disk();
		signal (collect);
	}
}
void collect(){
	while(TRUE){
		wait (log);     // can't add more data if it's not logged
		wait (stat);    
		collect_ad();
		signal (log);   // tell log to start
		signal (stat);  // stat can start to run
	}
}
void report(){
	while (TRUE){
		wait (stat);    // wait for stats to be reported
		report_pr ();
		signal (stat);
	}
}
void stat(){
	while (TRUE){
		wait (collect);
		wait (report);
		stat_ad ();
		signal (collect);
		signal (report)
	}
}

main(){
	init_proc(&log(), …);
	init_proc(&collect(), …);
	init_proc(&report(), …);
	init_proc(&stat(),…);

	signal (collect); signal (collect);
	signal (stat);
	start_schedule();
}
```

![[multitasking_implementation.png]]
- 5.25t execution time
- only 1t lost waiting for i/o operations

the main challenge of synchronicity is modelling these cooperations and dependencies

from the user perspective, however, the important part is that the porgram runs as fast as possible
    
### os perspective
the processor's principal function: execute machine instructions residing in main memory
- those instructions are provided in the form of programs
- a processor may interleave the execution of multiple programs at a time

#### program view
its execution involves a sequence of instructions in the program
the behaviour of individual processes can be characterised by a sequence of instructions
-> the _trace_ of a process
every process will follow the steps of their trace in order, and the os cannot change this
// recall context switching - if the os switches which program is being executed, it won't notice
            
#### processor view
executes code as dictated by changing values in the pc register
the behaviour of the processor can be characterised by showing how the traces of various processes are interleaved

---
## state process models
![[state_process_model.png]]

// note: a computer can have as many processes running at one time as it has cores
    // the five-state model is generally what computers use today

### two-state model
the process can be in one of two states, running or not running
when a process is created, it is known to the os and enters the not running state
from time to time, the currently running process is interrupted and the dispatcher selects the next process to run from the queue

#### process creation
- the os builds the data structures that are used to manage the process
- the os allocates space in main memory for the process

##### reasons for process creation
- new batch job
- created by os to control a service, e.g. printing
- spawned by existing process, as child or to exploit parallelism

#### process termination
##### reasons
- process has finished execution
- total time limit exceeded
- errors
- parent request
- parent has terminated - e.g. terminal opening programs in linux

#### queueing discipline
each process needs to be represented
- info relating to each process, including current state and memory location
- waiting processes are kept in a queue
- list of pointers to data blocks, or linked list
##### dispatcher behaviour
- an interrupted process is transferred in the waiting queue
-> if process is completed or aborted, it is discarded
- the dispatcher selects a process to execute
![[2-state_queueing.png]]
simple, yet inefficient, as some processes may still be waiting when brought to the end of the queue, e.g. when waiting for data from the internet

### five-state model
#### states
- running
currently being executed
- ready
in the queue, and can be run once the cpu is available
- blocked
waiting for external stimulus to execute, e.g. i/o or internet operations
- new
has been created, but has not yet been allocated to the queue
- exit
a pool of processes that have been released from the os and just need to terminate

 #### os perspective
consider a, b, and c loaded in memory
in addition, there is a small dispatcher that switches the processor from one process to another
	// round robin 6 instructions, meaning it changes every six instructions
no use of virtual memory
b invokes an i/o operation in its fourth memory

execution time for this example
![[execution_time.png]]

#### queueing discipline
two queues now, ready and blocked
- when the process is admitted in the system, it is placed in the queue
- when a process is removed from the processor, it is either placed in ready or blocked
- when an event occurs, all the processes that are waiting on that event are moved into the ready queue
![[5-state_queueing.png]]
![[5-state_queueing_advanced.png]]
-> multi-event queueing
when an event occurs, the entire waiting queue is moved to ready

#### suspended processes
![[suspended_processes.png]]
- processor is faster than i/o, so all processes may be waiting for i/o
- swap these processes to disk to free up memmory
- blocked becomes suspended when swapped to disk

#### process management services
- create(&process_id, attributes)
create a new process
- delete(&process_id)
finishes the process specified
whenever it is terminated, all files are closed
all allocated resources are released
- abort(&process_id)
delete for abnormal termination
usually generates a "post-mortem dump" which contains the process state before termination
- suspend(&process_id)
suspends the specified process

---
## process descriptions
the information that the operating system needs to control the process and allocate the necessary resources
![[process_description_0.png]]

### operating system control structures
- memory tables
- i/o tables
- file tables
- primary process table
- process image
	- user program, user data, stack data and attributes of the process

#### memory tables
used to keep track of both real and virtual memory
// some of main memory is reserved by the os, but the rest is free to use
these tables contain:
- the main memory allocated to processes
- the secondary memory allocated to processes
- any protection attributes of blocks of memory (e.g. what is allowed to access certain shared regions)
- any information needed to manage virtual memory

#### i/o tables
hold the status of any i/o devices, and the locations in memory they are using for data transfer

#### file tables
hold information on:
- the existence of files
- the location of files in memory
- their current status
- other attributes
// much of this is often maintained by the file manager, in which case the process manager may have little to no knowledge of these

#### process tables
![[process_table.png]]

the primary process table is used to keep one entry per process in the os
-> each entry contains at least one pointer to a process image

the process image contains
- stack
	for storing parameters and calling addresses for procedure and system calls
- user data
	program data that can be modified
- process control block
	data needed by the operating system to control the process

##### process control block
contains:
- process identification:
	the unique identifier for the process
- processor state information
	defines the status of the process when it is suspended
- process control information
	how the process should be handled by the os

###### process identification
holds numeric identifiers such as
- the process itself
- any parent process
- the user

###### processor state information
- user-visible registers
	one that may be referenced via the machine language that the processor executes
- control and status registers
	a variety of registers employed to control the operation of the processor, e.g.
	- program counter
	- status flag register
	- condition codes
- stack pointer
	each process has at least one associated filo stack, and the stack pointers for these are located here

##### process control information
###### scheduling and state information
information needed to perform process scheduling
typical information includes:
- process state (ready, blocked, etc.)
- priority 
- event the process is awaiting
- scheduling algorithm-specific information

###### data structuring
a process may be linked to another in a queue, or other structure, e.g.
- in a waiting queue
- a parent-child relationship

###### inter-process communication
various flags and signals necessary for inter-process communication

###### process priveleges
any and all execution and reading priveleges that the process holds

###### memory management
pointers to segment or page tables that describe the asssigned virtual memory

###### resource ownership and utilisation
controlled resources may be indicated, such as opened files
a history of processor utilisation or other resources may also be included

> #computing_systems 