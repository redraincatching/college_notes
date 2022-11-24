# Introduction to Operating Systems

![[excalidraw_11.png]]

drivers allow the OS to control the hardware
&nbsp&nbsp&nbsp&nbsp→ 3rd party hardware has to install separate drivers
&nbsp&nbsp&nbsp&nbsp→ proprietary / partnered hardware is "plug & play"

## OS Functions

-   Managing the overall system
-   Memory management
    1.   user requests action
    2.   OS loads program to r.a.m.
    3.   cpu uses the program
-   process management
-   provides security (user and system level)

OS interpreter
&nbsp&nbsp&nbsp&nbsp→ facilitates user interaction with OS

---
### Types of OS
-   single user single task
-   single user multi task
-   multi user multi task
-   multi processor (used for larger systems, like machine learning algorithms)
-   real time processor (heart rate monitor, airplane systems, etc.)


see also: [[CT101/operating_systems|operating systems]]

---
### Booting Processes

Load OS into main memory
&nbsp&nbsp&nbsp&nbsp→ BIOS (Basic Input Output System
&nbsp&nbsp&nbsp&nbsp→ read-only memory that stores instructions for the CPU to fetch the CMOS data
&nbsp&nbsp&nbsp&nbsp→ BIOS takes information from another source, the CMOS
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp→ chip on motherboard, powered by a separate battery

----
## Command Line
&nbsp&nbsp&nbsp&nbsp→ MS-DOS is case-insensitive

```c
cd     // change directory
			 // cd.. is go back one, cd\\ is jump to root
dir    // basically ls
		dir /s [directory]   // search that directory -> / is a "switch"
		dir /p               // display one page at a time
		dir /w               // wide display
md     // make directory (also mkdir)
rd     // remove directory
fsutil file createNew <filename> <length> // create new file (yes, really)
copy con <filename> [ENTER] <text>        // create new file & write to it
echo <text> > <filename>                  // write to a file
							 // > overwrites, >> appends
ren <oldname> <newname>      // renames a file
copy <source> <destination>  // copies a file
del <filename>               // deletes a file
help                         // take a wild guess
```

> #professional_skills