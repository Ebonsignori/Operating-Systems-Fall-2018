# Lecture 14

### Announcements


# Lecture Notes
Last lecture:
Intraconcurrency / Intrasycronization
This lecture: Interconcurrency

## Background
**Independent Process**: A process that cannot affect any other processes, and/or be effected by other processes.

**Cooperating Process**: A process that can affect *and/or* be effected by other processes

(? TODO) 95% of processes in the system are effected processes

## Producer and Consumers
Example 1: Two processes. 1 produces some output. 2nd consumes output to do something. Then the first produces, the second consumes. 

Example 2: Compiler produces object module, linker consumes it

Example 3: PC sends files producer to consumer printer.

Whatever one produces, the other consumes it where they are. These are not independent processes.

Producer produces a product that lives in the buffer, consumer checks to see if there is a buffer to consume.

### Cases
1. Unlimited # of Buffers: Each works at its own speed, thus there is always a buffer for the product that the producer produces.
2. Limited # of Buffers (Bounded Buffers): This is the real life case. Each time a producer produces a product, we don't have a buffer available to it. 

### Buffer Pointer Management
Example: Suppose we have a set of buffers. Divide them in circle like time slices do that we have 6 buffers, 0 - 5.
 
 ```
 N = 6. We have 2 pointers.
 
 Pointer IN: Points to the first buffer available to the Producer.
 
 When the buffer IN is pointing to gets filled, IN is incremented. I.e. if pointing to 0, then it will point to 1 after incrementing. 
 
 Pointer OUT: Points to the buffer that is ready to be consumed. 
```

Incrementing Pointers = `(IN + 1) mod N` or `(OUT + 1) mod N`

If `(IN + 1) mod N = OUT `, then the buffers are all full.

If `IN = OUT`, then all the buffers are empty.

### Producer
Repeat:
```
next_product = produceAnTtem();

// Wait while buffer is full
while ((IN + 1) mod N == OUT)) {
  skip();
}

// Produce item into buffer
buffer[IN] = next_product;
IN = IN + 1;

// Repeat forever
if (false) {
 stop();
}
```

### Consumer
Repeat:
```
// Wait while buffer is full
while (IN == OUT)) {
  skip();
}

// Consume item in buffer
next_consumed = buffer[OUT];
OUT = OUT + IN mod N;

// Repeat forever
if (false) {
 stop();
}
```

### Problems
If all of the buffers 0 through 4 are filled, and IN = 5, then IN + 1 mod 6 = OUT (since OUT is still 0), then the last buffer (Buffer 5) remains unfilled until consumer consumes. 

### Producer (Counter Version)
Repeat:
```
next_product = produceAnTtem();

// Wait while buffer is full
while (Counter == N) {
  skip();
}

// Produce item into buffer
buffer[IN] = next_product;
IN = IN + 1;
Counter = Counter + 1;

// Repeat forever
if (false) {
 stop();
}
```

### Consumer (Counter Version)
Repeat:
```
// Wait while buffer is full
while (Counter == 0) {
  skip();
}

// Consume item in buffer
next_consumed = buffer[OUT];
OUT = OUT + IN mod N;
Counter = Counter - 1;

// Repeat forever
if (false) {
 stop();
}
```

### Counter Problem: 
Controller of CPU takes first command goes to IR register

Implementation by CPU into registers:

**Producer:**
```
a1: R1 <- Counter
a2: R2 <- Counter + 1
a3: Counter -> RAM
```

**Consumer:**
```
b1: R5 <- Counter
b2: R6 <- Counter - 1
b3: Counter -> RAM
```

#### Scenario
Suppose value of `counter = 5;`

Assume the order of parallel implementation of calculating counter is as follows:
```
a1 : R1 = 5
a2: R2 = 6
b1: R5 = 5
b2: R6 = 4
a3: In RAM, counter = 6
b3: In RAM, counter = 4
```
Then counter has an incorrect value.

### Solution: Critical Sections
When we have 2 processes in parallel, there is a part of code (# of lines) that must not ever be executed in parallel. 

Parts of the codes in producer and parts of codes in consumer must not be executed in parallel.

We call these codes: *Critical Section*.

**Critical Section**: If you have N processes that run in parallel. Every processes has one or more critical section. If a process is in its critical section, no other processes can be in their own critical sections. Enforced by blocking interruptions (and other ways). 

## Skeleton of Process
A process where somewhere we have a critical section
```
Process Start
==========================================================================
. (Previous Code)
.
.
--------------
Entry Section: Always proceeds critical section. Asks for permission to enter critical section
--------------
--------------
Critical Section
. (Critical Section codes)
.
.
--------------
--------------
Exit Section: Notifies that critical section is finished and another process can enter the critical section 
--------------
--------------
Remaining (Remaining Code)
--------------
==========================================================================
Process End
```

## Mutual Exclusion
If we have several processes and we have several processes that want to go to their critical section at the same time. To satisfy the mutual exclusion in time, we have 3 conditions. 
1. **Mutual Exclusion**: At any time only one process is in its critical section. 
2. **Progress**: At any given time, only the processes that are in their entry sections are eligible to compete for going to their critical section.
3. **Bounded Waiting**: Operating system cannot deny a process forever (deprive a process) from going to its critical section. 

If satisfied, then yes, concurrency is satisfied. 

### Examples
Variable in common between the two: `Turn`

#### Violate Condition 1. Mutual Exclusion Not Satisfied 
```
               Initialize Flag[i] = Flag[j] = false
Process i                                       Process J
Repeat _______                                  Repeat _______
While flag[i] do skip                           While flag[j] do skip;
flag[j] = true                                  flag[i] = true
~Critical Section~                              ~Critical Section~
flag[j] = false                                 flag[i] = false
```
#### Violate Condition 2. Progress Not Satisfied 
```
                    Initialize Turn = i;
Process i                                       Process J
Repeat _______                                  Repeat _______
While Turn != i do skip                         While Turn != j do skip;
Critical Section                                Critical Section
Turn = j                                        Turn = i
```

Assume Process i has large remainder section and J doesn't. Then J will finish and wait at loop (compete) with itself, thus invalidating Condition 2, Progress

#### Violate Condition 3. Bounded Waiting Not Satisfied 
```
               Initialize Flag[i] = Flag[j] = false
Process i                                       Process J
Repeat _______                                  Repeat _______
flag[j] = true                                  flag[i] = true
While flag[i] do skip                           While flag[j] do skip;
~Critical Section~                              ~Critical Section~
flag[j] = false                                 flag[i] = false
```
If flag[j] and flag[i] = True at same time, waiting occurs forever.
#### Satisfy All Three Conditions
```
               Initialize Flag[i] = Flag[j] = false
Process i                                       Process J
Repeat _______                                  Repeat _______
flag[j] = true;                                 flag[i] = true;
turn = i;                                       turn = j;
While flag[i] and turn = i do skip              While flag[j] and turn = j do skip;
~Critical Section~                              ~Critical Section~
flag[j] = false                                 flag[i] = false
turn = j;                                       turn = i;
```

### Semaphores
Next Session. 