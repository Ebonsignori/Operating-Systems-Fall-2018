# Lecture 7
### Announcements
After threads we start with the first assignment. 

### Quiz 1 Review
See tests/test_1 for the review

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

### Simple Structure: Original Unix Structure
Kernel was one large program that included:
  1. Interfaces: We need two separate interfaces:
     1. **Kernel Interface With The Kernel:** Terminal controllers, device controllers, and memory controllers, ...
     2. **Device Drivers:** Signal handling, file system, CPU scheduling, page replacement, page demand, ... 
  2. Device Drivers

## Layered Structure
In this structure, the Operating System is made up of layers. i.e. Layer 0, 1, 2, ..., N layers.

This structure has two assumptions:
1. Layer N is based on layer N-1 down to 0 (all the previous layers). Any function that the layer does not provide for itself and its own needs can be found in a previous layer. 
2. Error containment: If working on layer M and something goes wrong, then the error that happens is only part of that layer, M. Therefore all layers below must be correct. This improves the speed of debugging and the ease of writing the program. 

This advantage creates modularity that is easier to deal with than one program made up of N parts.

Advantages:
   1. Modularization
   2. Error Containment
   3. Writing OS much easier
   4. Debugging is much easier
   5. Easy to expand
Disadvantages:
   1. Can't access from layers above. It's difficult to decide what functionality goes in each layer.
   2. Less efficient system. Because you have to access previous layers to do anything. (TODO: Improve this explanation)
    
#### Disadvantage 1 Example
(TODO: Listen to recording and improve this example)

Backing Storage Driver:
Purpose is to support virtual memory. 
Virtual Memory: Think you have a lot of memory even if you don't have it. 

Space on disk for virtual memory. Driver is part of the memory management routine (layer with all memory management processes). 

Support CPU is below memory layer, and there are too many processes in the RAM. Backing Storage Driver lives in memory layer and cannot be accessed upwards.  

## Combination of 1/2
K layers that are smaller than N (layered structure), but each layer is much larger.
 
 Example: The memory and CPU routines are combined into one layer for the combined structure.

## Virtual Machine
Provides illusion that every user has their own CPU, memory, and disk. Provides virtual CPU, memory, and disk. 

In a VM, there is **perfect protection** if no communications between users take place. 

**Advantages**
1. Protection
2. A research vehicle for OS.
    - Example: Can test CPU scheduler for an algorithm because you have a virtual CPU.
    
**Disadvantages**
1. Lack of sharing (sharing = communications)
   - Solutions to sharing:
       1. Treat every user as a node in a network and nodes can send messages between each other through the network.
       2. Use a shared mini-disk to put communications on. 
    
### Virtual Machines are Coming Back
Virtual machines are coming back for: 
   1. Solving system compatibility problems. 
   2. Running programs on platforms that it wasn't designed for.
    - E

#### JVM Includes
1. Class Loader
    - It loads bytecodes to the JVM on the native platform 
2. Class Verifier
    - Makes sure that bytecodes will not harm the native system
3. Java Interpreter
    - Takes the bytecodes and treats them as:
        1. Acts as an interpreter (Slides). Takes 1 bytecode at a time and converts it to native machine code and lets the native machine handle it.
        2. Acts as a compiler (JIT). Interprets and translates all the bytecodes into the machine language and feeds it all to the machine at once. 

Java Program -> Java Compiler -> Bytecode -> JVM

## OS Design and Implementation
Design Goals are Influenced by:
   1. Types of Hardware
   2. Type of Desired OS
   3. User Goals
       - Easy to learn, safe, reliable, fast
   4. Crew Team Goals (The team building OS)
        - Easy to design, easy to implement, easy to maintain. Should be flexible. Should be reliable. Should be error-free. Should be efficient. 
        
## Mechanism vs Policy
**Mechanism**: How to *build* a feature
**Policy**: How to *use* a feature

## Languages for Writing OS
1. Assembly Language (traditional)
2. High level (typically C/C++)