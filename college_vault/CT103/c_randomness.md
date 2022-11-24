# random numbers ✨✨
to do this, we can use the rand() function, from the \<stdlib.h\> library
gives a random number from 0 to 32767
_// use % to set a limit on which numbers can be given_

-> however, every time the program is run, the numbers printed will be the same
&nbsp&nbsp&nbsp&nbsprand() is an algorithm, and therefore has a starting point

use **srand()** to achieve more randomness
&nbsp&nbsp&nbsp&nbspdone by "seeding" the algorithm
&nbsp&nbsp&nbsp&nbspa different seed is necessary every time, done by using the current time as a seed

// getting truly random numbers is actually non-trivial, and is an active field of study
// the algorithms computers use are called *pseudorandom number generators*

## getting this seed
```c
long lt = time(NULL);  // gets the time sinc epoch
srand(lt);             // seeding the random number
randnum = rand();      // actually call the rand function
```

> #c #programming 