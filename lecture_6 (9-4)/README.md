# Lecture 6
### Announcements
Quiz on Thursday (9/6)

### Previous Lecture Questions
Two lectures ago, you talked about a device controller storing the data it receives in pieces from a read operation in the buffer. Then you said the controller sends a signal to the CPU to fetch the data once it is finished reading. Is this signal an interrupt? Also, do we only use the buffer for read operations?

# Lecture Notes
OS Services Continued 
## Services for User
- File Manipulation
- Communication 
    - Exchange of information between two processes using one of two methods:
        - Shared Memory:
            - Area of RAM is set aside for purpose of communication. Process A and B check shared area
        - Message Passing:
            - Within area of OS, space is set aside for specific messages. Whenever process A or B has a chance, they check the specific space for communications from other process
            
- Error Detection
    - (TODO: Slides)
    
## Services for Efficiency 
All resource allocation is handled by the OS 
- Resource Allocation (must be done by OS)
    - Special Allocation Category: For resources that allocation must follow a custom algorithm. I.e. CPU and Memory allocation have separate allocation algorithms. 
        - Custom made algorithms for each resource to allocate/deallocate to/from a process
    - General Allocation Category
        - Use general allocation routines i.e. all I/O devices
        
        
### Accounting
OS Provides for collecting information that are used for.  
Two purposes
    - Billing: (need to know how much time they used system)
    - Configuration of System:
        - Use algorithm that is more appropriate for system, so that .
        
### Protection
Processes from each other and external users (see slides)
#### I/O Protection
- We need to protect all of the reading/writing of files (any access to data) protected from misuse by user. 
- We do this by supervising I/O from OS (program cannot I/O, but must ask OS services to finish I/O operations)

- **Dual Mode**
    - Monitor Mode
        - When an trap I/O is happening, another trap/interrupt cannot happen. The system is now in *monitor mode*. Any further interrupts are added to a queue and resolved when the current interrupt is finished. 
    - User Mode
        - **Mode bit:** Hardware bit. Set to 1, then in monitor mode. No processes can do anything. They are waiting. Set to 0, then in user mode. 

#### Memory Protection
When you boot a system you get copy of kernel and put in RAM.
Two choices of where to put it:
    - Top of memory (always know address of first byte available outside of resident monitor).
        - **Fence Register** holds last byte (bottom)
    - Bottom of memory (always know address of last byte available before resident monitor)
        - **Fence Register** holds first byte (top)

RAM Diagram For Kernel Position (depends on manufacturer)
```
byte 0
---------------
Kernel Here
---------------
Fence Register Points Here (at bottom)



Fence Register Points Here (at top)
---------------
Kernel Here
---------------
last byte
```

RAM Diagram For Limiting Processes to their own RAM space
```
byte 0
---------------
Kernel Here
---------------
Fence Register Points Here (at bottom)

---------------
Process A
---------------
Process B
---------------


last byte
```
**Lower and Upper Bound Registers**
- Two registers are set for beginning and end of RAM allowed for process. Address of first byte and last byte. 
   
**Base and Limit Registers**
- Base: address of first byte available to the process, from that point **Limit** contains how many bytes are available to that process. 

Changing the contents of any of the above registers is a privileged instruction.  

Means that a trap is fired when one needs to be changed, and handled by OS.


#### CPU Protection 
For everything going on in a CPU, there is a *timer*.
**Timer**: Anything that a CPU is asked to do, a timer is set. If time is violated, then operation is out. 

```
10 bits:
1 1 1 1 1 1 1 1 1 1

Each ticks decrements value to 0, gradually setting all 10 bits to 0:
0 0 0 0 0 0 0 0 0 0

Once timer gets to negative (not all 0), then the time is up.
Thus it takes 2^n bits.

Exanmple 
111
Would take 8 ticks to cancel 
```

Timer
   - Fixed Timer:
       - We cannot change timer, we can only set and reset it
   - Variable Timer:
       - OS can change timer on the fly

### How to Invoke OS Services
Example: A process needs an OS Service.

Can be invoked using:
1. System Calls: Small program that is invoked by process. An interface between the process that needs help and the OS. Runtime processes because they are given to process at runtime and not compiled in the code. 
    - Examples: (slides)
    - Different from one OS to the next. They are in 100s. 
2. System Programs: Large program (i.e. word processor). May use many system calls within it. An interface between user and OS. 

#### System Call Categories
Process Control (each one of these has a system call)
   - Creating a process
   - Load, execute
   - Halt execution (end, abort)
       - End (program nicely finished)
       - Abort: Something is wrong and aborted because of an error
   - Terminate process
   - Get process attributes, set process attribute
   - Wait for time, wait event, signal event
      - Wait for time (wait for X seconds, minutes, etc. then be executed)
      - Wait for event, then IF event happens, then execute 
      - Signal event, send signal to another process
    - Allocate Free memory
    
Process Control of Single Tasking System:
(see slides)
- Process eats command interpreter memory
- At end of program, the error thrown gives a new copy of command interpreter because some of it was eaten by process

Process Control of Multi-Tasking System:
(see slides)
- User invokes a fork system call.
- Have a module that is parent of processes that it has spawned. After process finishes, control goes back to parent process. 

System Calls for File Manipulation
    - create file, delete file
    - open, close
    - read, write, reposition
        - reposition: move within record
    - get file attributes, set file attributes 

System Calls for Device Management 
    - request device, release device
    - read, write, reposition
    - get device attributes
    
##### Logic vs Physical File
Chunks of physical files sits in the buffer, then the buffer feeds to the program.
From perspective of Java program, the file is a logical file. 
Physical file is the real file that exists on hard disk. 

System Calls for Information Maintenance
    - get time or date
    - set time or date
    - get system data, set system data
    
System Calls for Communication
    - create, delete communication connections
    - attach and detach remote devices
(see slides)

### A Reminder
Suppose OS needs an OS service or system call. 
Parameter sent to system call. Multiple solutions.
1. Use registers
2. Use RAM block (preferred)
3. Use stack where you can push parameters

### Accessibility of System Calls
- In UNIX are callable by C or C++ programs.
- In Windows use Win32 API comes with any compiler written for windows

## System Call vs System Program
1. Small vs Large 
2. Process and Operating System vs User and Operating System
3. A System Program may use several System Calls