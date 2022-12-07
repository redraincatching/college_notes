# processes and threads
a [[programs_and_processes|process]] is sometimes defined as a heavyweight process
a thread is sometimes defined as a lightweight process

used to separate two ideas
**process**: the ownership of memory, files, other resources
**threads**: unit of execution we use to dispatch
-> each thread uses the same address space, hence it is much easier for them to communicate
-> they use the process' address space
        
_multithreading_
allowing multiple threads per process
    
## thread
a unit of computation associated with a particular heavyweight process, and uses many of that process' resources
a process with one thread is a "classic" process
a thread can belong to only one process

- individual execution states
- each thread has their own control block with a state, saved registers, and a pointer
- separate stack and hardware state per thread
- shares memory with other threads in that process
- faster to create than a heavyweight process
- because a family of threads access common resources, thread switching is far more efficient that a process [[scheduling|context switch]]
	- however, a thread switch to a thread in a different process remains as complex

> #computing_systems 