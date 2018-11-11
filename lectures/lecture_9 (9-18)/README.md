# Lecture 9
### Announcements
None
# Lecture Notes
## Thread
Suppose you have process, **P1**. This process shares resources with process, **P2**. 

Both of them are executing within the same address space. 

In other words, they are using the same memory space for execution. 

Both P1 and P2 are part of a bigger entity called a process, and this memory space belongs to this process.

Then P1 is a thread. 

(TODO: Get missed segment of recording here. I started recording the class at this point and missed the beginning. If anyone has a full recording, please share).

Threads are used when a process is performing a big task and carves out pieces of the task and gives the work to a thread to do.

### Heavyweight vs Lightweight processes 
Heavyweight processes do not share memory, but threads do and are therefore lightweight processes. 

A heavyweight process is equivalent of one task with only one thread. 

A thread is considered a lightweight process.

### Attractive Property of Threads
**Peer Thread:** Threads that are part of the same bigger entity process. A group of peer threads handles one task. 

Since a group of peer threads handles one task, context switching from one thread to another is shorter than switching from one process to another.

This is because:
1. Since they are occupying the same memory space, you don't need to save the base and limit registers for threads. 
2. All the resources are shared between the threads. I.e. If a file is open and being used by thread 1, you don't need to close and reopen it again in order for thread 2 to use it.
3. Suppose one thread is using global variables, those global variables must be shared from the other threads. We do not need to save and readmit variables when we switch between threads within the same process.

### Made up of
1. PC
2. Register Set
3. Stack Space

[Shared]
4. Code Section
5. Data Section
6. Resource Section

### Process vs Thread
1. A thread shares code section, data section, and resource section with peer threads.
2. A thread is much smaller than a process.
3. Context Switching is shorter for a thread.
4. Having one process with multiple-threads is more efficient than having multi-processes (assuming that the multi-processes share the same task).
5. No protection is needed in a multi-threading environment because the peer threads are dedicated to one task. 
6. Threads allow a sequential process to be executed in parallel. 

### Process and Thread Similarities
1. Both have the same set of states.
2. A thread may also create children. 
3. A thread within a process executes sequentially. 
4. Each thread has its own stack and program counter. 

## Thread Types
There are two types of threads:
1. User Thread
2. System (Kernel) Thread

### User Thread
**User Space:** The size of RAM allotted to user is decided by system, and all of the memory that can be accessed by the user is the user space. 

1. Is created in user space. 
2. Schedule within the user space.
3. Managed by a user-thread-library (without kernel intervention).

**Kernel is not aware of user-level threads.**

**User thread library:** Is a system program, and a system program is above kernel. 
(TODO: Improve this definition. What does it do exactly?)

### Kernel Thread
1. Is created in kernel space. 
2. Schedule within the kernel space.
3. Managed by the kernel

For any user thread to be executed, a kernel thread must be created to run that thread. 

For each user thread, a kernel thread must be assigned and executed. 

All user threads are mapped to kernel threads by a system process. 

Kernel threads execute faster than a user thread, but are created slower than user threads. (TODO: See recording to improve what else he says about this). 

#### User vs Kernel Threads
1. User threads are created faster and scheduled faster than kernel threads, but are slower in terms of execution. 
2. In a single thread hardware (where only one thread can be processed at a time):
    1. If a user thread goes to a "wait" state, so do all of its peers
    2. If a kernel thread goes to a "wait" state, then the Kernel may execute another thread from its peers. 
    
## Multi Threading Models
The following 3 models show the mappings of user threads onto kernel threads. 

*See the slides on page 3 of the [Lecture 9 Slides](slides_9.pdf)*

**1-1 (one-to-one):**
- Advantage: Great Parallelism
- Disadvantage: High Overhead Cost

**M-1 (many-to-one):**
- Advantage: Low Overhead Cost
- Disadvantage: No Parallelism 

**M-N (many-to-many):**

*Where m <= n* Where M are user threads (more of) and N are kernel threads (less or equal to). When not equal, some threads will execute in parallel, and some will execute sequentially. 
- Advantage: Some Overhead Cost, Some Parallelism 
- Disadvantage: Only to a degree of the advantages provided by other two methods  

## Threading Issues
There are three issues with threading
1. Fork and Exec System Calls
2. Cancellation
3. Signal Handling

### Fork and Exec System Calls
If a thread wants to create another thread it uses Fork. When forking, the thread will create new thread, and name it, X. 

If you have a user thread **t1**, and you use `Fork t2` inside of **t1** to create the forked thread, t2. 

Within the larger process memory space, t1 is copied into t2 exactly the way it is, but gives it its own name, t2. 

You need a system call to go into t2, and that call is `Exec`. Exec clears the contents of t2 and brings in the context of t2. Before calling `Fork t2`, t1 decides on the contents of t2. 

Some systems automatically call Exec, but some systems require a manual `Exec` system call after a Fork is made.

*This process happens before the user thread is mapped to the kernel thread.* 

### Cancellation
Cancellation is termination of a thread before it is completed. 

**Example of when cancellation is needed:** A DBMS is retrieving data from a database using several threads. One thread returns the result and thus the other threads must be canceled.

It happens in two ways:
1. **Asynchronous:** Immediately cancel the target thread. As soon as you say cancel, it cancels.
    - Problems:
        - Updating Data: Suppose you have a thread in the middle of updating a database and it is not finished updating when you send an asynchronous cancel call. You now have **inconsistency** in your database.
        - Reallocation of resources: Resources can not be 100% relieved and given to other resources. If the thread is in middle of updating and something happens, the **Rollback** database function returns to the state of the database before the updating started. During rollback, the database needs some resources that the thread is using, but cannot get them. 
2. **Deferred (periodic cancellation):** Check in a loop if there is a cancellation. 
    - Overhead cost: The loop that checks periodically for the cancellation signal, steals cpu cycles. 

### Signal Handling
 - *Signal Definition* : Generally speaking, interrupts and traps are signals. (TODO: Is there a better definition than this?)

#### Steps of signal application
1. A resource issues a signal.
2. It is delivered to another resource.
3. The receiving resource handles it using either:
    1. A user defined signal handler
    2. A system defined signal handler (default signal handler)
    3. Some resources use both types of handles

#### Signal Types
1. Synchronous: Sender and receiver are the same
2. Asynchronous: Sender and receiver are different 

#### Signal Delivery
The signal is delivered to a source by delivering it to:
1. The thread the the signal applies
2. Every thread within the process
3. A group of threads within the process
4. A predefined thread


## Thread Pool
Suppose you have a process that creates a thread, that creates a thread, etc. 
Sooner or later the resources of computer are exhausted after tons of threads are created. 

Thread pools limits the number of threads that the process can handle at any given time. 

When a process is created, a number of empty threads are assigned to that process. 
Those threads are called a thread pool. Each process has a number of threads. 

## Thread Specific Data
Data that is specific to every thread.
i.e. Every thread has an ID number. 

