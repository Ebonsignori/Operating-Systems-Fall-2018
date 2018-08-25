# Lecture 3
### Lecture 2 Questions
- Formal definition of Kernel?
- Formal definition of Device Driver? 

### Answers
- Is the bootloader considered part of the kernel?

No 

- Formal Kernel definition?

The part of OS that *always* stays in RAM

### Announcements
None


# Lecture Notes
## Previous Lecture Review
Each interrupt has an interrupt number that has a corresponding index in the interrupt vector (array). The array contains the address of the program that is the solution to the interrupt. 

Operating System:
- Is an event driven software 

Interrupt is checked after each machine cycle. 

Machine cycle
PC program counter has addr of next instruction to be fetched into the instruction register (IR) which has the next instruction.
PC is incremented.

```
while () {
    IR = (PC);
    PC++
    // Decode here
    execute(IR)
    
    if (IRQ) {
        "Context Switching"
    }
}
```

Called interrupt because it "interrupts" the CPU's current process and takes control (hijacks CPU)

### Context Switching 

a. Saving the contents of all registers in *old state* 

(Give address of solution to interrupt in PC)

b. Execution of the interrupt is completed

c. Restore the contents of the registers from the *old state*


```
while () {
    IR = (PC);
    PC++
    // Decode here
    execute(IR)
    
    if (IRQ) {
        "Context Switching"
        Save_All_Registers(); // Save into OldState
        Restore_PC(IV(IRQ#)); // IV = Interrupt vector
        // Execture the response
        Restore_PC(OldState); 
    }
}
```

### Resident Monitor of Linux (kernel)
1. Process, Resource, File Management (Persists in RAM)
2. Device Driver, Interrupt Handler (Persists in RAM)
3. Modules (In RAM at startup, then on hard drive)
- Temporarily loaded 

### Linux Shell
User -> Shell -> Kernel

### OS Evolution
6. Time Sharing
- CPU time will be shared among several users (or processes)

#### How Does Sharing Happen
Multiple solutions. One is Round Robin.

**Round Robin**: 
Break down unit of time into time slices (called quantums).
If you break down a second into 8, then each quantum is 1/8th of a second. 
Where each quantum is P1, P2, ... P8

If quantum P1 finishes (program completes and doesn't need CPU power) before its allotted time, then the next quantum, P2 will immediately take over and the slices will be readjusted so that the P2 doesn't get extra time

7. **Multi User System**:
Several users are using the CPU at the same time. 

8. **Multi Program System**:
Several Programs / Several Jobs are using the CPU

**Spooler**

**Spool**: (Symultanious Peripheral Operations Online)
It accomodates or manages the input jobs (new programs that are arriving) and the output jobs (jobs that have executed / finished and are waiting to use an ouput device) 

Several programs are finished and waiting to use an I/O device, and a spooler is in charge. 

9. **Real Time**:
    - Hard
        - Computer guarentees that it will give you the result within the restricted time.
    - Soft
        - No guarentee, but it will give priority to program and try its best to process it in real time. 
        
        
10. **PC Systems**:
Personal Computer. First was MS-DOS

11. **Coupled Systems**:
    A Number of computers that work together as a team to solve problems
    Two types:
    - Tightly Coupled
        - Number of processors that are sharing same CPU clock, same computer boss (data travels from the same boss to each computer), sometimes they share memory and I/O devices.
        - Ex. Multi-Processor Systems (Parallel Systems)
    - Loosely Coupled
        - A number of computers that can communicate with each other through ethernet or telephone cables. 
        - Ex. Clustered Systems: Several Distributed Systems put together. (It can cover a bigger area of connectivity)
        - Ex. Distributed Systems: Physically away from each other, but can communicated with each other.
        
We are interested in tightly coupled systems because they are cheaper, because they can share:
- Peripherals
- Mass Storage,
- Power Supplies
Also more fault tolerant / reliable (If one parts fails, uses another part)
Higher throughput (more CPUs)

### Parallel Systems
Mode of Operation
- Symmetric
Works independently, but shares the same RAM (?)
- Asymmetric (Employer-Employee Technique)
Master CPU and a bunch of slaves. Breaks down huge task to different slaves or (?)

#### New Trends of Parallel System
- Classic Parallel System:
Multiple chips, each chip has it's own CPU
- New Trend
Single Chip, multiple CPU 

**Core**: Basic functionality of a CPU


### Clustered Systems
Symmetric Clustering
a. Each node workds on its own task
b. Nodes monitor each other
(can help eacho ther, borrow files, etc.)

Asymmetric
a. One node is in "Hot-Standby Mode" and its function is to monitor other nodes
b. ()?

# BEOWULF Clusters
(?)

12. **Client-Server System**: 
Central Computer
Centralized System
Originally a nodes that connected to central server using "dumb" terminals

File vs Compute Servers.
File: Client is so sophisticated, but can't hold huge databases and needs info
Compute: Ex. Search Engine

**Client Software** (Sitting on client)
**Server Software** (sitting on server)
Work very seamlessly together

When client asks something of server
1. Some computation is involved
2. Data Transfer takes place
3. Bookkeeping (Bookkeeping Information: when the request was sent, length of request, etc.)

12. **Handheld Systems**
Example: Smart Phone.

Constraints that handheld systems must overcome
1. Memory Size
2. Screen
3. Keyboard