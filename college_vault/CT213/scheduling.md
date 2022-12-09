# scheduling

scheduling allows one process to use te cpu while the execution of another process is on hold due to the unavailability of a resource like i/o
-> aims to make the system efficient, fast, and fair
part of the process manager

scheduling is the mechanism that handles
- the removal of the running process from the cpu
- the selection of the next process
// that's it

responsible for multiplexing processes on the cpu
when it is time for the running process to be removed from the cpu (to a ready or suspended state), a different process is selected from the ready queue

the scheduling algorithm is what decides to select next

## scheduler organisation
![[scheduler_organisation.png]]
 - the enqueuer creates the pointer to the process description, and places it in the ready list
- the context switch is essentially copying the exact state from the cpu to the process description
-> the contents of all the cpu registers are saved
- all algorithms essentially run in the dispatcher

## scheduler types
### cooperative scheduler / voluntary cpu sharing
- each process will periodically invoke the process scheduler, voluntarily sharing the cpu
- each process should call a function that will implement the scheduling
- yield(p_current, p_next), sometimes implemented in hardware
### preemptive scheduler / involuntary cpu sharing
- enforces periodic interval interruptions of the running process
- uses an interval timer to determine when to perform a context switch

### cooperative scheduler
![[cooperative_scheduler.png]]
- possible problems
- if the processes do not communicate, one could keep the cpu forever
- if a process crashes, the next will never be called
-> some systems have a hybrid enforced yield, to avoid this
- allows much simpler implementation of applications
-> interruption is never enexpectedly interrupted

### preemptive scheduler
```c
interval_timer {
	interrupt_count = interrupt_count - 1;
	if (interrupt_count <= 0) {
		interrupt_request = TRUE;
		interrupt_count = k;
	}
}
set_interval(<programmable-value>) {
	k = programmable_value;
	interrupt_count = k;
}
```
- a programmable interrupt timer will cause an interrupt timer every k ticks
-> the hardware will then send a signal to execute the logical equivalent of a yield to invoke the interrupt handler
- the interrupt handler for the timer interrupt will call the scheduler to reschedule the processor without any action of the part of the running process
- the schedule decides which process to run next

---
## performance elements

having a set of processes P = {$p_i$, 0 <= i < n}
- service time, 𝜏($p_i$)
the amount of time a process needs to be in active/running state before it completes
of given as input data or predicted by the scheduler
- turnaround time, $T_trnd(p_i)$
the amount of time between a process entering the ready state and the moment it exits the running state for the last time
-> (completion time) - (arrival time)
// note: some programs take, by design, longer than others, so there's no value to 
// reducing the average turnaround time
- wait time, $W(p_i)$
the time the process waits in the ready state
-> (completion time) - ((arrival time) + (service time))
// this is what we wish to reduce for efficiency

we want the ratio of running:waiting to be as high as possible
this often means prioritising shorter processes to remove them from the queue as soon as possible

### selection strategies
**non-preemptive**
- allow processes to run to completion once it has been allocated control of the cpu
- a process that gets control of the cpu releases control voluntarily at certain points, or periodically
**preemptive**
- the highest priority process among all ready processes is allocated the cpu
- all lower priority processes yield to higher-priority ones when they request the cpu

#### scheduling algorithms
- fifo/fcfs
does what it says on the tin
- sjf
shortest job first
- srtn
shortest remaining time next
- timeslice / round robin
- priority-based preemptive
- mlq
multilevel queue
- mlqf
multilevel queue with feedback


##### fcfs
- non-preemptive
- assigns priority in the order in which they request the processor
	-> the priority is computed by the enqueuer timestamping each process and the dispatcher selecting the oldest timestamp
- implementation:
	fifo data structure, like a queue
	enqueuer adds processes to the tail, dispatcher selects from the head
- easy to implement
- not widely used, due to inefficient turnaround time

###### fcfs example
![[fcfs_example.png]]

##### sjf
- non-preemptive
- an optimal algorithm for minimising average turnaround time
- preferential service of short processes
// will be predicted if not known
- requires knowledge of service time for ideal implementation
- in the extreme case, where the system has little idle time, the longest process will never run

###### sjf example
![[sjf_example.png]]

##### srtn
- similar to sjf, but preemptive
- if at any point, a shorter job comes in which has less remaining time, it will be prioritised
- a half-finished long job may be shorter than a full short job

##### timeslice
- preemptive
- each process gets a timeslice of cpu time, distributing the processing time equitably amongst all processes requesting the cpu
- issue: context switching takes time, so it may actually take longer than the timeslice
- this implies the existence of a specialised timer which is initialised whenever a new process is put into the cpu
// finish later

// great for interfaces, as you don't need a result, but everything to progress

###### timeslice example
![[rr_example.png]]
- timeslice 50, context switch time negligible

![[rr_overhead_example.png]]
- timeslice 50, context switch 10

##### priority-based scheduling (event driven)
- both preemptive and nonpreemptive, depends on implementation
- each process has an externally assigned priority
- every time an event occur that generates a process switch, the process with the highest priority, is chosen from the ready list 
-> this event is generally a high-priority process entering the ready list
- possibility that low-priority processes may never gain cpu time
- there are static and dynamic variants, dynamic solves the above issue (time in queue++ = priority++)
- used for real-time systems
- priorities are often in levels, and if processes have the same priority, there is another algorithm in place, e.g. random or sjf

###### priority-based example
![[pb_example.png]]
- highest number = highest priority, by convention

##### mlq scheduling
- complex systems have requirements forr real-time use, interactive users, and batch jobs
-> combined shceduling mechanism should be used
- proesses divided into classes
- each class has a process queue, and assigned a specific algorithm

###### mlq example
![[mlq_example.png]]
- 2 queues
- foreground, highest priority
- background, lowest priority

- 3 queues
- os processes and interrupts (highest priority, serviced ed)
- interactive processes (medium priority, serviced rr)
- batch jobs (lowest priority, serviced fcfs)

###### mlqf
- same as mlq, however processes can migrate between classes
- different strategies to modify the priority, based on necessity and remaining time, or if the process will exit the cpu in less time than a full timeslice would take


> #computing_systems 