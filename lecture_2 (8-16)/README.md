# Announcements
Still no class on August 21st

# Lecture Notes
**Operating System:** A collection of programs and data that is in charge of managing computer resources, and supporting virtual characteristics of computer. 

**Computer Resource:** Any hardware and software component. For example, Memory, CPU, Software, Compiler, Printer, etc. are computer resources. 

**Program:** Written series of instructions that are static (not in execution).

**Process:** Running program instance (in execution). 

**Job:** General name for both program and/or process (indistinguishable)

### Managing computer resources
1. Allocation and deallocation of computer resources
- Ex. If you need to use a printer, it allocates it to you, if another use wants to use it, it is deallocated from you and allocated to the other user
2. Acts as a controller of computer resources
- Tries to prevent errors: user and system errors
- Doesn't let you shut down a file that is in use
- Assigns memory spaces 
- Makes sure that you don't abuse compute resources
3. Acts as a facilitator 
- Knows what you need 

### Supporting Virtual Characteristics 
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
- (paraphrase) A utility program that is included with the system and performs a common (perhaps repetitive across user cases) task
3. Application Program 
- Ex. Photoshop, editor, web browser

#### Operating System
1. Kernel (*Old name* resident monitor)
- If you want to execute a program, then it must be brought into your ram, it cannot sit on the disk. So instead of loading the entire thing, we bring the absolute minimum (the part that we need) that we can onto the ram, and that is the Kernel. Then we delete it and keep the original copy on the slower harddrive. 
2. Memory Management Routines
3. Device Management Routines
4. Process Management Routines
5. File Management Routins
6. Secondary-Storage Management Routines
7. Network Access Management Routines
8. Protection Management Routines

## OS Evolution
1. Sign-up scheme
- Sign up, pay, get entire room containing super machine that you use for an hour. Have to upload the compiler, mount the harddrives, tapes, etc. 
2. Hiring Operators
- Did the slow things for users that they needed for their running environment. Downloaded compiler, mounted disk, etc. 
3. Batch Processing 
- Setting time of day for Fortran and Cobal and dedicated windows for each user to use the same compiler over and over again (batch)
4. Job Control Language - *JCL*
- Expresses need of program. I.e. Program needs a tape to be mounted  In a specific syntax.
5. Automatic Job Sequencing 
- **Job Sequencing:** Finishing engagement of your computer with a program that is ended, and then starting engagement of your computer with a new program. 
    - (aside) This was birth of Operating System. Decided to replace hiring manager with automatic sequencing. 
    
- **Resident Monitor**:
    - **JCL Interpreter** 
        - Needs of program translated to machine language (Job control language interpreter)
    - **Job Sequencing** (same def as previous)
    - **Device Driver**
        - Hides the details of the device from the operating system
    - **Interrupt and Trap Vectors**
        - Two vectors (arrays).
        - **What is an interrupt?**
            - Interrupt is a signal issued by a computer resource to get the attention of the operating system. Sent at finish and/or error of process.
        - Distinguish hardware and software interrupt:
            - Interrupt from hardware: **Interrupt**
            - Interrupt from software: **Trap**
        - Every interrupt and every trap has a solution (think error handling) that comes with the operating system. 
        - Each interrupt is part of an array in memory. For example, if interrupt signal 1 is sent, then the pointer to the solution 1 corresponding to interrupt 1 is immediately loaded into memory and given CPU cycles. 
        - Traps check solutions within running processes for solutions before checking traps array for solutions (ideally, the user has error handling that catches the trap before it has to be checked against the trap array).
        
## Machine Cycle
(paraphrase) In a CPU if you had 3.4 Ghz, then 3.4 Gh cycle will run in a second. 

Each cycle has:
1. Fetch Step
- PC (program counter) will point to a spot in memory, and load them into CPU registers called (IR). 
- PC contains the address of the next command
2. Decode
- Get meaning of program
3. Execute
- Run the program 

**IRQ** A flag (variable) that means *interrupt request*. 

`IRQ = false` by default.  Set to true when an interrupt happens, and is then handled with **context switching**. 

