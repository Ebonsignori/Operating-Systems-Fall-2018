# Announcements
Still no class on August 21st

# Lecture Notes
**Operating System:** A collection of programs and data that is in charge of managing computer resources, and supporting virtual characteristics of a computer. 

**Computer Resource:** Any hardware and software component. For example, Memory, CPU, Software, Compiler, Printer, etc. are computer resources. 

**Program:** Written series of instructions that are static (not in execution).

**Process:** Running program instance (in execution). 

**Job:** General name for both program and/or process (indistinguishable)

## Operating System 
An Operating System Manages Computer resources and Supports Virtual Characteristics of a Computer
### Computer resources
1. Allocation and deallocation of computer resources
- Ex. If you need to use a printer, it allocates it to you, if another use wants to use it, it is deallocated from you and allocated to the other user
2. Acts as a controller of computer resources
- Tries to prevent errors: user and system errors
- Doesn't let you shut down a file that is in use
- Assigns memory spaces 
- Makes sure that you don't abuse computer resources
3. Acts as a facilitator 
- Knows what you need 

### Virtual Characteristics 
Computer characteristics that do not exist in reality, but that you think exist. 
- Ex: Command interpreters or unix environment is in charge of providing virtual characteristics, for example, accepting english commands without speaking english. 


## Computer's Overall Picture
- User
- [System Programs](#system-programs)
- [Operating System](#operating-system)
- Computer Hardware

#### System Programs
3 Program Categories:
1. Program Development Aids
- Ex. Debugger, text editor, etc.
2. System Utilities 
- (paraphrase) A utility program that is included with the system and performs a common (often repetitive across user sessions) task
3. Application Program 
- Ex. Photoshop, editor, web browser

#### Operating System
1. Kernel (*Old name* resident monitor)
2. Memory Management Routines
3. Device Management Routines
4. Process Management Routines
5. File Management Routines
6. Secondary-Storage Management Routines
7. Network Access Management Routines
8. Protection Management Routines

**Kernel**: 
```diff
- Definition likely to be updated in future lectures
```

If you want to execute a program, then it must be brought into your ram, it cannot sit on the disk. 

When starting an operating system, instead of loading the entire OS, we load the absolute minimum (the part that we need) of the OS onto the ram upon startup, and that absolute minimum is called the Kernel.

After the kernel is loaded, we delete it from memory and keep the original copy on a slower harddrive. 

## OS Evolution
1. Sign-up Scheme
- Sign-up and pay to use a room containing a supercomputer for a limited amount of time. Much of this time is spent initializing your environment (mounting disk, downloading compiler, etc.)
2. Hiring Operators
- People who initialized the system with what a user needed before the user got to room (to give the user more time with computer and less time initializing)
3. Batch Processing
- Grouping users who needed to use identical initializations and only initializing the system once to handle each user in the group (batch process) before changing to a different setup. 
4. Job Control Language (JCL)
- Expressed the precise initialization needed by a user in a specific format (language). 
5. Automatic Job Sequencing
- Automated the previous processes using **job sequencing**, which gave birth to the **resident monitor**.

- **Job Sequencing:** Finishing engagement of your computer with a program that has ended, and then starting engagement of your computer with a new program. 
    - (aside) This was birth of Operating System. Decided to replace hiring manager with automatic sequencing. 
    
- **Resident Monitor**:
    - **JCL Interpreter** 
        - Needs of program translated to machine language (Job control language interpreter)
    - **Job Sequencing** (same def as previous)
    - **Device Driver**
        - Hides the details of the device from the operating system
    - **Interrupt and Trap Vectors**
        - Two separate vectors (arrays) that contain the interrupt and trap codes and their corresponding solutions.
        - Distinguish hardware and software interrupt:
            - Interrupt from hardware: **Interrupt**
            - Interrupt from software: **Trap**
        - Every interrupt and trap has a solution (think error handling) that comes with the operating system. 
        - Each interrupt is part of an array in memory. For example, if interrupt signal 1 is sent, then the pointer to the solution 1 corresponding to interrupt 1 is immediately loaded into memory and given CPU cycles. 

** Interrupt:** An interrupt is a signal issued by a computer resource to get the attention of the operating system. 
It is always sent at the completion of a process.

**Trap:** Traps are interrupts issued by a computer process. Traps check for solutions and are handled within the running process from which they are fired before they check the trap vector. (ideally, the user has error handling that catches the trap before it has to be checked against the trap array).
        
## Machine Cycle
Also called an instruction cycle, it is the basic operation performed by the CPU.
(paraphrase) In a CPU if you had 3.4 Ghz, then 3.4 Gh cycle will run in a second. 

Each cycle has:
1. Fetch Step
- PC (program counter) will point to a spot in memory, and load them into CPU registers called (IR). 
- PC contains the address of the next command
2. Decode
- Get meaning of program
3. Execute
- Run the program 

**Interrupt Checking**: At the end of each machine cycle, there is a check for interrupts. If there is an interrupt, the IRQ flag will be set to True. 

**IRQ** A flag (variable) that means *interrupt request*. 

`IRQ = false` by default.  Set to true when an interrupt happens, and is then handled with **context switching**. 

