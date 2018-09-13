# Lecture 7
### Announcements
After threads we start with the first assignment. 

### Quiz 1 Review
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
    - Locates and loads the kernel into the RAM and runs it and it initalizes all of the related registers and variables needed for the system. 

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

# Lecture Notes
So far we have discussed:
1. OS definition
2. OS evolution
3. OS Structure managed by OS
3. OS Services

## OS Structure
1. Simple Structure
2. Layered Structure
3. Combination of 1 and 2
4. Virtual Machine

## Simple Structure
You do not a have a structure or well defined model. The entire OS is one program. When more features are needed, another method is added, not thinking or planning. 

First MSDOS that came out had a simple structure. Example, program eats up command interpreter in memory. 

### Original Unix Structure
Kernel was one large program that included:
    a. Interfaces: need two separate interfaces
        1. Terminal controllers, device controllers, and memory controlleds
        2. System Calls interface (see slides)
    b. Device Drivers

## Layered Structure
Assume the Operating System is made up of layers. Layer 0, ..., N layers.
Two assumptions
1. Layer N is based on layer N-1 to 0 (N - 1, ..., 0). Any function that the layer does not provide for itself and it needs can be found in a previous layer. 
2. If working on layer M if something goes wrong, then the error that happens is only part of that layer, M. Therefor all layers below must be correct. This improves the speed of debugging and the ease of writing the program. 

This advantage creates modularity that is easier to deal with than one program made up of N parts.

2. Error containment. The error in the program must belong to the current layer. Therefor all layers below must be correct.
Advantages:
    1. Modularization
    2. Error Containment
    3. Writing OS much easier
    4. Debugging is much easier
    5. Easy to expand
Disadvantages:
    1. Can't access from layers above. It's difficult to decide what functionality goes in each layer.
    2. Less efficient system. (? Have to access previous layers ?)
    
#### Disadvantage 1 Example
Backing Storage Driver:
Purpose is to support virtual memory. 
Virtual Memory: Think you have a lot of memory even if you don't have. 

Space on disk for virtual memory. Driver is part of the memory management routine (layer with all memory management processes). 

Support CPU is below memory layer, and there are too many processes in the RAM. Backing Storage Driver lives in memory layer and cannot be accessed upwards. 


## Combination of 1/2
K layers that are smaller than N, but larger layers. I.e. memory and cpu routines combined into one layer.

## Virtual Machine
Provides illusion that every user had their own CPU, memory, and disk. Provides virtual CPU, memory, and disk. 

Perfect protection if no communications between users take place. 

Advantages
1. Protection
2. A research vehicle for OS.
    - Example: Can test CPU scheduler for an algorithm because you have a virtual CPU.
Disadvantages:
1. Lack of sharing (communications)
Solutions to sharing:
1. Treat every user as a node in a network and can send messages between each other through network.
2. Shared mini-disk to put communications on. 
    
### Virtual Machines are Coming Back
Virtual machines are coming back for: solving system compatibility problems. 
Running on platforms that a program wasn't designed for.

#### JVM Includes
1. Class Loader
    - It loads bytecodes to the JVM on the native platform 
2. Class Verifier
    - Makes sure that bytecodes will not harm the native system
3. Java Interpreter
    - Takes the bytecodes and can treat them as:
        1. Acts as an interpreter (Slides). Takes 1 bytecode at a time and converts it to native machine code and lets the native machine handle it.
        2. Acts as a compiler (JIT). Interprets and translates all the bytecodes into the machine language and feeds it all to the machine at once. 

Java Program -> Java Compiler -> Bytecode -> JVM

## OS Design and Implementation
Design Goals are Influenced by:
    1. Types of Hardware
    2. Type of Desired OS
    3. User Goals
        - (see slides)
    4. Crew Team Goals
        - Team building OS. (see slides)
        
## Mechanism vs Policy
**Machanism**: How to *build* a feature
**Policy**: How to *use* a feature

## Languages for Writing OS
1. Assembly Language (traditional)
2. High level (typically C/C++)