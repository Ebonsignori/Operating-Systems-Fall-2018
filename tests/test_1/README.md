# Test 1 Review 
*Listen to the beginning of [Lecture 7](test_1_review_recording.m4a) recording to hear Hashemi's review.*

**PDF For Reference:** [Test 1 - Evan Bonsignori (Highest Grade)](test_1.pdf)

1. Machine Cycle: things that take place before and after an interrupt 
- Before
    - Fetch, Decode, Execute 
    - After, if statement checks flag
    - Context Switching 

2. Define:
- OS (see previous lectures)
- Memory Mapped I/O
    - When registers of device controller are physically part of the RAM instead of separate
- BIOS
    - Locates and loads the kernel into the RAM and runs it and it initializes all of the related registers and variables needed for the system. 

3. a) How are system call parameters sent?
    1. Registers
    2. RAM
    3. Stack
3. b) What are the two types of I/O communications
    1. Shared memory space
    2. Message Passing


4. Differences of Interrupt and Trap
    1. Interrupt, solution always provided by OS. Trap, solution can also be provided by process.
  
4 b). System vs User Mode: 
  - Mode bit is turned on when system is in system mode. System mode handles interrupts and everything. User mode is mode is when system program can be executed *except for privileged instructions*. System mode is a mode where only OS programs and privileged instructions are executed. 

4 c). Loosely vs Tightly Coupled Systems 
  - Loosely through network, tightly within same hardware. 
  - Communication done through network/telephone communication done through computer bus for tightly. 
  - When sharing peripherals, loosely is more fault tolerant.
  - Tightly share same CPU clock, PC system, sometimes memory, sometimes I/O, where in loosely, none of these are shared. 
  - Tightly coupled systems represent a centralized system, while a loosely coupled system represent a distributed system.
  
4 d). Linker vs Loader
    - Loader does not save a copy of the executable module, only loads it into computer memory for execution, but the linker does save a load module and also loads it into memory and lets the computer run it.