# deadlocks

occur when dealing with [[concurrent_programming|concurrent programming]]

## detection and prevention of deadlock
### requirements of deadlock
// all 4 must hold for deadlock
- mutex: at least one held resource must be non-shareable
- no pre-emption: no way to break priority or remove resource once allocated
- hold and wait: there exists a process holding one resource and waiting for another
- circular wait: there exists a set of processes $p_1$, $p_2$, ..., $p_n$ such that $p_1$ is waiting for $p_2$, $p_2$ is waiting for $p_3$, and so on

// if only three hold, you can get starvation, but not deadlock

resolving this, we try to resolve circular wait problems
the others can actually make the code more efficient or be really hard to resolve, so we should leave them

one approach is to have an order for requiring locks

--- 
## deadlocks without locks
deadlocks can occur for any resource, or any time a process waits

### dealing with deadlocks
#### ignore:
just do nothing, reboot if it happens
embarassingly common

#### reactive:
periodically check for deadlock
bluescreen/terminate a low-priority process if it happens
// may corrupt data, so a cleanup must be performed afterwrds

#### proactive:
###### strategy 1: no mutex
make everything shareable
viable for read-only files
not for much else

##### strategy 2: avoid hold and wait
1) only request resources when you have none
release x if you want y
works in some cases, hard to maintain a relationship for x and y
2) acquire resources at once
z locks both x and y
low concurrency with this approach, as more is locked than necessary
	
##### strategy 3: add pre-emption
allow preemption of resources
problems:
only viable for some resources, e.g. virtual memory
not possible if a resource cannot be saved and restored
overhead cost of preempt and restore

##### strategy 4: eliminate circular wait
impose an ordering on resources
-> processes must acquire the highest ranked first

---
## preventing deadlocks

-> global order of locks
##### solution 1
order based on hash code of variables
##### solution 2
order based on client with smallest id

https://www.youtube.com/channel/UCBRYU9uye8e-ZuWQMPBAoYA/videos
- mike swift: concurrency

### classical problems of synchronisation

#### producer-consumer
two types of processes
- producer
process that, from some inner activity, produces data to send to other processes
- consumer
process that, on receipt of a data element, consume data in some internal computation

we can join processes synchronously, or, using semaphores, create a buffer
solution: bounded circular buffer
- as an exercise, prove no deadlock or starvation

#### dining philosophers
![[dining_philosophers_0.png]]
 5 philosophers working on a problem
each one has only two states: think and eat
table has five bowls, and five chopsticks/forks
a philosopher need two chopsticks to eat
philosophers may only pick up chopsticks to the left and right

for the system can operate correctly, it is required that
- a philosopher only eats when they have two chopsticks
- no two philosophers can hold the same chopstick simultaneously

solve this algorithmically

##### first attempt
```pseudocode
void philosopher(int id) {
	while(TRUE) {
		think();            // for some time
		take_fork(right);   
		take_fork(left);
		eat();
		put_fork(right);
		put_fork(left);
	}
}
```
// does this work?
![[dining_philosophers_1.png]]

##### second attempt
model each fork as a semaphore
```pseudocode
semaphore fork [5] := ((5) 1)
/* pseudo-code */
/* fork is array of semaphores all initialised to have value 1 */
process philosopher (i := 0 to 4) {
	while (1) {
		think ( );
		wait(fork (i)); // grab fork[i]
		wait(fork ((i+1) mod 5); // mod allows for circular
								 // table where P4 grabs fork 4 and fork 0
		eat ( );
		signal(fork (i)); // release fork[i]
		signal(fork ((i+1) mod 5); // release rh fork
	}
}

// this leads to deadlock, however
// what happens if everyone grabs their left one first?
// this can be solved if you order it to be the smallest number fork first
// so instead of wait(fork ((i + 1) % n));
// it becomes first get the smaller fork of i mod n and i+1 mod n
// the get the larger of the two
/*
	wait(fork (min(i, i+1 % n)) );
	wait(fork (max(i, i+1 % n)) );
*/
// only really makes a difference for philosopher n, as they're reaching for fork n and fork 0
```

this is an asymmetric solution
                each philosopher is the same, except due to their position, one philosopher acts wildly differently

symmetric solution
limiting the amount of philosophers allowed to sit at the table

```pseudocode
/* pseudo-code for room solution to dining philosophers */
/* fork is array of semaphores all initialised to have value 1 */
semaphore Room := 4
semaphore fork (5) := ((5) 1)
process philosopher (i := 0 to 4) {
	while (1) {
		Think ( ); // thinking not a cs!
		wait (Room);
		wait(fork (i));
		wait(fork ((i+1) mod 5);

		Eat ( ) // eating is the cs
		
		signal(fork (i));
		signal(fork ((i+1) mod 5);
		signal (Room);
	}
}
```

// hard-bottlenecking the amount of processes allowed to access resources

> #computing_systems 