# operating systems
interface between user and hardware

### functions
- oversee computer operations
- schedule + coordinate program execution
- manage resources, establish ui, provide services for application software

---
#### evolution of shared computing
##### batch processing os
takes job, adds to job queue, executes them, produces results
jobs basically just get passed to the cpu
non-interactable, you can't change the operations of the cpu

##### multiprogramming os
users seeking services from the same machine at the same time
implemented with _multiprogramming techniques_, meaning the time is divided into multiple intervals, and the execution of a single task is limited to a single time interval (known as the time quantum)
&nbsp;&nbsp;&nbsp;&nbsp; -> each task is added to the queue of tasks to be completed, and the cpu executes each task in the order of the queue
&nbsp;&nbsp;&nbsp;&nbsp; -> if the task is not completed in the time quantum, it returns to the queue
&nbsp;&nbsp;&nbsp;&nbsp; -> this process repeats until each process is completed
&nbsp;&nbsp;&nbsp;&nbsp; -> multiple terminals can then be connected to the same machine
_// only one task at a time, no matter what_

##### multitasking os / timeshare
when multiprogramming is applied to a single-user environment

##### multiprocessing os
 provide timesharing capabilities by assigning different tasks to different processors, as well as sharing the time of each processor
###### problems to solve:
- load balancing: dynamically allocating tasks to processors for efficiency
- scaling: breaking tasks into sub-tasks

##### interactive / real-time os
two kinds: hard and soft
- hard: processes must be executed at the exact time specified
e.g. heart rate monitor, command control system
- soft: processes must be executed witin the expected time
e.g. traffic control

##### embedded os
can be found in handheld devices, cars, etc.
built for only _one application_
limited data storage and power conservation are the major issues
does not load and execute applications, they're built into the os

---

### software
application software
&nbsp;&nbsp;&nbsp;&nbsp;performs specific tasks for users
system software
&nbsp;&nbsp;&nbsp;&nbsp;foundation for other software
&nbsp;&nbsp;&nbsp;&nbsp;not human readable
&nbsp;&nbsp;&nbsp;&nbsp;also known as the kernel

---
### shell
graphical/text-based ui
interfaces between the user and the kernel

---
### kernel
performs basic required function

---

## storage/hard disk management
role: coordinate the use of the machine's mass storage facilities

**hierarchical organisation**
&nbsp;&nbsp;&nbsp;&nbsp;directory (or folder)
&nbsp;&nbsp;&nbsp;&nbsp;-> a user-created bundle of files and other directories
&nbsp;&nbsp;&nbsp;&nbsp;directory path
&nbsp;&nbsp;&nbsp;&nbsp;-> a sequence of directories within directories

 access/operations is provided by a _file descriptor_

---
## i/o device management
part of the os presented as a collection of device drivers (specialised software that communicates with and carry out operations on peripheral devices)

each driver is specifically designed for its type of device, and translates general requests into device-specific ones

---
## memory management
// main memory and ram
coordinates (allocates and deallocates space for) memory

when the total required memory space exceeds the physical available space, may create the illusion that the machine has more memory than it actually does (virtual memory) by playing a "shell game" in which blocks of data are shifted back and forth between "pages" in the ram and main memory

---
### process
the activity of executing a program
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;program - a static set of instructions

#### process status
the current state of a process

---
### scheduler
the part of the kernel in charge of allocating or deallocating the cpu to each competing process

maintains a record of all processes in the os via a process table, introduces and removes processes as needed

---
### dispatcher
the component of a kernel that oversees the execution of scheduled processes

![[timesharing_process.png]]

---
### security
one role of the os is to provide security
##### attacks from the outside
e.g. insecure passwords, sniffing software
countermeasures: auditing software
    
##### attacks from inside
security at the processor level: no process can interfere with another
countermeasures: securing the cpu to ensure that this does not occur

---
### handling competition for resources
_ semaphore_: a control flag
_critical region_: a group of instructions that should be executed by only one process at a time
_mutual exclusion_: requirement for proper implementation of a critical region, so that only one process at a time can execute the instructions in a critical region

##### resource issue - deadlock
processes block each other from continuing
conditions required:
- competition for non-shareable resources
- resources requested on a partial basis
     

---
### getting an os started - bootstrapping
##### booting
procedure that transfers os from mass storage (permanent) into main memory (volatile)

##### bootstrap
program in ROM (example of firmware)
run by CPU when power is turned on
&nbsp;&nbsp;&nbsp;&nbsp;_// the PC starts at a predetermined address at this time_
-> transfers os to main memory
-> executes jump to os

![[booting_process.png]]


> #computing_systems 