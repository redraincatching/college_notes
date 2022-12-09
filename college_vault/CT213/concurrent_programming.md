# concurrent programming

## concurrent programs
interleaving sets of sequential atomic instructions
interacting sequential processes run at the same time, on the same or different processors
as a programmer, you don't know how your program wil be interleaved

## correctness
say you have a program that loads a value to a register, adds one, and stores it
if all the maths is done in registers, then the results are dependent on interleaving (indeterminate computation)
imagine, for example, this program is run twice concurrently
```pseudocode
p_1: load reg, n
p_2: load reg, n
p_1: add reg, #1
p_2: add reg, #1
p_1: store reg, n
p_2: store reg, n
```

this may lead to whichever program is running second having an incorrect result
-> this dependency on unforseen circumstances is known as a race condition

### generalisation
a program is correct if when its preconditions hold, its post conditions hold
a concurrent program must be correct _under all possible interleavings_

## race conditions in practice
a race condition occurs when its output is dependent on the sequence or timing of the code execution
- if multiple processes enter a critical section at the same time, both attempt to update the shared data structure
- this is one of the hardest issues to debug as it only occurs conditionally

> **critical section**
> a part of the program where a shared resource is accessed
> this needs to be protected in ways that avoid concurrent access

example bank transaction
```c
int withdraw(account, amount) {
	int balance = account.balance;
	balance = balance - amount;
	account.balance = balance;
	
	return balance;
}

// two processes at once:
// account.balance = 100;
/*--- process 1 starts ---*/
int withdraw(account, amount = 10) {
	int balance = account.balance;  // 100
	balance = balance - amount;     // 90
/*--- process 2 starts --- */
int withdraw(account, amount = 20) {
	int balance = account.balance;  // 100
	balance = balance - amount;     // 80
	account.balance = balance;      // 80
/* --- process 1 interleaved again --- */
	account.balance = balance;      // 90
	return balance;                 // 90
}
/* --- process 2 again --- */
	return balance;                 // account.balance = 90 !!!
}
```

### consequences
results are indeterminate
deterministic computations have the same result each time
- we want deterministic concurrent code
- we can use synchronisation mechanisms

### handling race conditions
we need a mechanism to control access to shared resources in concurrent code
idea:
- focus on critical sections of code
- critical sections should run with mutual exclusion
-> only one process can execute that code at one time

> **critical section definition**
> the segment of code that tries to access or modify the value of the variables in a shared resource

what is the critical section in our previous example?
```c
int withdraw(account, amount) {
	int balance = account.balance;      <--
	balance = balance - amount;             this whole section
	account.balance = balance;          <--
	
	return balance;
}
```

anything between accessing the shared resource and dropping it for the last time should be protected

#### critical section properties
- mutual exclusion
- guarantee of progress
no other processes can execute _at all_ 
- bounded waiting
a process waiting to enter must eventually enter, and one in the section must eventually leave
- performance
a critical section has a severe overhead, and this must be minimised

#### synchronisation solutions
ways to protect critical solutions
##### atomicity
atomic interruptions cannot be interrupted
##### conditional synchronisation (ordering)
making sure one process runs before another


##### atomicity
basic atomicity is provided by the hardware
references and assignments, e.g. read/write are atomic in cpus
however, high-level constructs are not atomic in general
some languages have mechanisms to specify multiple instructions as atomic (e.g. java)

##### conditional synchronisation
strategy:
person A writes a rough draft, person B edits it
A and B cannot write at the same time, as they are working on different versions of the paper, and person B cannot start until person A finishes

what might this look like?
![[synchronisation_1.png]]

---
##  code constructs to support defining critical sections
- locks
very primitive, just provide mutual exclusion, minimal semantics, useful as a building block for other methods
- semaphores
basic, easy to understand
- monitors
higher level abstraction, requires language support, implicit operations



### locks
a token used to enter a critical section of code
if a process wants to execute a critical section, it must have the lock
- need to ask for lock, need to ask to release lock
-> no restrictions on executing other code
-> the process can go do whatever else
![[locks_1.png]]

#### locks have 2 states
- held: some process is in the critical section
- not held: no process is in the critical section
#### locks have two operations
- acquire:
mark lock as held, or wait until it is released
if not held, execute immediately
- release:
mark lock as not held
a process can hold as many locks as it wants, but only one process can hold a specific lock

#### using locks
locks are declared like variables
```c
Lock someLock;
```
a program can use multiple locks
```c
Lock someLock, otherLock;
```
to use a lock, surround critical section as follows
- call acquire() at the beginning of the critical section
- call release() at the end
// this is blocking, so use conditionals or whatever

#### lock benefits
- only one process can execute the critical section at a time
- when one process releases, another can progress
lock limitations
- acquiring a lock only blocks processes trying to acquire the same resource
-> lock the resource, not the operation

##### lock implementation - v1
```c
struct lock {
	bool held; //initially FALSE
}
void acquire(lock) {
	while(lock->held)
		; //just wait
	lock->held = TRUE;
}
void release(lock) {
	lock->held = FALSE;
}
```

does this work?
![[locks_2.png]]
no, lol
most of the time, locks needs a specific hardware implementation for this reason

// c code for test and set behaviour
```c
bool test_and_set (bool *flag) {
	bool old = *flag;
	*flag = true;
	return old;
}
// allows atomic read and update
```

##### hardware-based spinlock
```c
struct lock {
	bool held;
}
void acquire (lock) {
	while(test_and_set(&lock))
}
```

// note: mutex = mutual exclusion

#### spinlock drawbacks

- if a process holds a lock, and is removed from the cpu, any other process waiting for that lock will just "spin" and waste cpu time until the first process returns to finifh
- a form of busy waiting (burns cpu time)
- inefficient if held for a long time, espacially with the overhead of context switching

#### do locks give us sufficient safety?
check **safety** properties - these must always be true
- mutual exclusion: only one process can access a resource at a time
- absence of deadlock: when a non-terminating system cannot respond to any signal
check **liveliness** properties - these must eventually be true
- absence of starvation: information sent is delivered
- fairness: any contention must be resolved

if any of these can be proven to be false, the system does not work

#### lock deadlock scenario
![[lock_deadlock_scenario.png]]
- spinlocks are prone to deadlocks

#### protocols to avoid deadlocks
- add a timer to the acquire() method
cancel job and attempt it another time
- add a lock.check() method to see if the lock is already held before requesting it
can do something else and come back again
- avoid hold and wait protocol
never hold on to one resource when you need two

// ...these can all lead to their own problems

##### livelock due to trying to avoid deadlock
![[livelock_trying_to_resolve.png]]

##### starvation
more general form of livelock
1 process generates a disproportionate amount of hardware requests as it holds a lock for a disproportionate amount of time

##### locks, critical sections, and reliability
- what if a program is interrupted or crashes in a critical section?
developers must make sure critical sections are small always terminate

---
## mad max - beyond locks

locks only provide mutual exclusion
we need higher level locking mechanisms for this

higher level locking mechanisms: semaphores
producer-consumer relationship
producer: creates a resource (data)
consumer: uses a resource

e.g.    
```bash
ps | grep "gcc" | wc
```


don't want producers and consumers working in lockstep (atomicity)
this would require lots of time wasted from context switching

solution:
place a _fixed-size buffer_ between producers and consumers
synchronise access to buffer
producer waits if full, consumer waits if empty

    
### semaphores
invented by djikstra in 1965 as part of the os project
semaphores are a kind of generalised lock
the main synchronisation primitive used in the original unix
implemented with a counter that is manipulated atomically with signal() and wait()

#### wait(semaphore)
- a.k.a. down(), or P()
decrement counter
if counter is zero, then block until semaphore is signalled

#### signal(semaphore)
- a.k.a. up() or V()
increment counter
wake one waiter, if any

#### sem_init(semaphore, value)
set initial counter value

// wait and signal are critical sections, and must be executed atomically

each semaphore has an associated queue of processes 
// these processes are not spinning, which frees up the cpu

```pseudocode
struct semaphore {
	int value;      // number of processes allowed to run
	queue L;        // list of waiters
}
wait (semaphore s) {
	if (s.value > 0) {
		s.value--;
	}
	else {
		add this process to s.L;
		block;
	}
}
signal (semaphore s) {
	if (s.L != EMPTY) {
		remove a process P from s.L;
		wakeup(P);
	}
	else {
		s.value++;
	}
}
```


#### semaphore initialisation
- to 1?
	acts as a singular lock, as only one process can execute at a time
	called a binary semaphore
- to >1?

#### uses of semaphores
- allocating a number of resouces
shared buffers, each time you want to access a buffer call wait()
queued if no buffer available

- counter initialised to n = number of resources
called a counting semaphore
useful for conditional synchronisation

#### semaphores for mutual exclusion
trivial to implement

```c
semaphore mutex = 1;

void process(int i) {
	while (1) {
		// non critical section bit
		wait(mutex) // grab the mutual exclusion semaphore
		// do the critical section bit
		signal(mutex) //grab the mutual exclusion semaphore
	}
}

int main() {
	cobegin {
		process(1); process(2);
	}
}
```

#### bounded buffer problem
producer-consumer problem
- buffer in memory, with finite size of n entries
a producer inserts entries, a consumer removes them

processes are concurrent 
we must use a synchronisation mechanism to control access to shared resources

##### producer-consumer single buffer
![[single_buffer.png]]

semaphores can be hard to use
complex patterns of resource usage
- cannot capture relationships, require extra variables for this
doesn't solve a crashing problem, V() has to be called to release

### monitors
far higher level constructs, that extend the monolithic os to keep track of what resources can be accessed
won't actually go into detail as to what they are or how they work at the moment

> #computing_systems 