# Lecture 9
### Announcements

# Lecture Notes
## Thread
Suppose you have process, **P1**. This process shares resources with process, **P2**. 

Both of them are executing within the same address space. 

In other words, they are using the same memory space for execution. 

Both P1 and P2 are part of a bigger entity called a proces, and the memory space belongs to this process.

Then P1 is a thread. 

Heavyweight vs lightweight processes. Heavyweight does not share memory, threads to (and are lightweight).

(get missed segment of recording and listen to what).

Carving part of a big task that a process must do and give that part of the task to a thread. 

### Attractive Property of Threads
Context switching from one thread to another is shorter than switching from one process to another. 

Because:
1. Because they are occupying the same memory space, you don't need to save the base and limit registers for threads. 
2. All the resources are shared between the threads. I.e. If a file is open and being used by thread 1, you don't need to close and reopen it again in order for thread 2 to use.
3. Support one thread is using global variables, those global variables must be shared from the other threads. We do not need to save and readmit variables when we switch between threads within the same process.

### Made up of
1. PC
2. Register Set
3. Stack 

[Shared]
4. Code Section
5. Data Section
6. Resource Section

A group of peer threads handles one task. This is faster than context switching between processes. 

### Process vs Thread
(TODO all: Slides)
1. A thread shares code 
2. A thread is much smaller than a process
3. Context Switching is shorter for a thread
4. Having one process 
5. No protection is needed in a multi-threading environment because the peer threads are dedicated to one task. 
6. Threads allow a sequential process to be executed in parallel. 

### Process and Thread Similarities
(TODO all: Slides)
1.
2.
3.

## Thread Types
Two types:
1. User Thread
2. System (Kernel) Thread

### User Thread
Is created in user space. 
Schedule in the user space.
Managed by a user-thread-library (without kernel intervention).

**User Space:** Size of ram allotted to user is decided by system, but all memory that can be accessed by the user (not being used by kernel).

**Kernel is not aware of user-level threads.**

User thread library: Is a system program.
A system program is above kernel. 
Examples of UTLs: (see slides).

### Kernel Thread
Is created in kernel space. 
Schedule in the kernel space.
Managed by kernel

For any user thread to be executed, a kernel thread must be created to run that thread. 

For each user thread, a kernel thread must be assigned and executed. 

All user threads are mapped to kernel threads by a system process. 

Kernel threads execute faster than user thread, but are created slower than user threads. (See recording). 

#### User vs Kernel Threads
1. (see slides)
2. In a single thread hardware (where only one thread can be processed at a time)
    - (TODO: See slides)
    
### Multi Threading
User threads map 1-1 to kernel threads. 
(See slides)

1-1

M-1

N-M
If you have M (bigger) user threads and N (smaller) kernel threads.
Some will go in parallel, some will be seq. (TODO: slides)


## Threading Issues
1. Fork and Exec System Calls
If a thread wants to create another thread it uses Fork. Give a name, X and create new thread, X. 

If you have a user thread t1. 

You are using `Fork t2` inside of t1. 

Within the larger process memory space, t1 is copied into t2 exactly the way it is, but gives it its own name, t2. 

You need a system call to go into t2 and Exec clears the contents of t2 and brings in the context of t2. Before calling `Frok` t2, t1 decides the contents of t2 and then calls Fork. Some systems automatically call Exec, but some systems require a manual `Exec` sys call.

This happens before the user thread is mapped to the kernel thread. 

2. Cancellation: Termination of a thread before it is completed. 
In two ways:
    1. Asynchronous: Immediately cancel the target thread. As soon as you say cancel, it cancels.
        - Problems:
            - Updating Data: Suppose you have a thread in the middle of updating a database and is not finished updating and you send an async cancel call. You now have inconsistency in your database.
            - Reallocation of resources: Can not be 100% relieved and given to other resources. If thread is in middle of updating and something happens, **Rollback** database returns to status before the updating started. During rollback it needs some resources that the thread is using, but cannot get it. 
    2. Deferred (periodic cancellation): Check in a loop if there is a cancellation. 
        - Overhead cost: Loop that checks periodically, steals cpu cycles. 

3. Signal Handling:
**Signal** : Generally speaking, interrupts and traps are signals. 

A resource issues a signal. (TODO: See slides)

(TODO: Slides again)

Signal Types:
    1. Synchronous:  (TODO: slides)
    2. Asynchronous:
    
The signal is delivered... (TODO: Slides)


## Thread Pool
Suppose you have a process that creates a thread, that creates a thread, etc. 
Sooner or later the resources of computer are exhausted after tons of threads are created. 

Thread pools limits the number of threads that the process can handle at any given time. 

When a process is created a number of empty threads are assigned to that process. 
Those threads are called a thread pool. Each process has a number of threads. 

## Thread Specific Data
Data that is specific to every thread.
i.e. Every thread has an ID number. 

