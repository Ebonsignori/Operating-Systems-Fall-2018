# Lecture 15

### Announcements


# Lecture Notes
**NOTICE:** The slides are sufficient for this lecture, use them as a primary source and these notes for reference.

**Semaphore:** Is an integer variable.

Two operations can be performed on this variable. These operations are atmoic: meaning when one operation is being performed, the other cannot be performed. 

P: wait

V(S) 

## Example
Two processes: S_1, S_2 that need to be excuted at the same time with shared variable, sync.

```
                sync = 0
S_1;                            P(sync);
V(sync);                        S_2;
```

## Slide Semaphore Example
a = b = c = d = e = f = g = 0

```
Parbegin
    S1; V(a); V(b);
    P(a); S2; S4; V(c); V(d);
    P(b); S3; V(e);
    P(d); P(e); S6; V(0);
    P(c); S5; V(f);
    P(f); P(g); S7;
```

## 
Solutuion for problem #3:

However all processes can be waiting at `P(mutex)` leading to starvation. 

### Implementation Problem
- Busy Waiting: When looping, we are taking away CPU time. We solve this by 

Blocking process: Instead of looping, we add waiting process to a queue, then when the semaphore permits we go and wake up the process. 

##
3 Problems to solve for concurrency 

1. Bounded Buffer: Producer/Consume: Producer keeps producing and consumer keeps producing. If producer produces faster, the buffer fills up and producer must wait for consumer to consume buffer. 
2. Reading/Writers: You have a data object (file, record, piece of data). You have n users who want to read data. You have w writers who can/want to change the state of the data. They all go in parallel. 
3. Dining Philosopher: You have 5 philosophers. They either [A. Eat] or they [B. Think]. There are 5 chopsticks. Solution 1: Only let 1 eat a time. Solution 2: Half go for right chopstick first, the other half go for right half, only 1 gets at time. 


## Semaphore buffer example 
2 buffers
empty = 2
full = 0
mutex = 1

P1
C1
P3

```
P1: empty = 2 -> empty = 1
    mutex = 1 -> mutex = 0 (Continues)
C1: full = 0 -> full = -1 (Consumer waits at P(full))
P1: finished -> mutex = 1, full = 0
```


## Reader Writer solution
1. Give priority to readers - Allow as many readers read the data who want to, as long as not writers are writing. (writers must wait)
2. Give priority to writers - whenever writers are writing, don't let anyone read. (readers must wait)

### R-W Ex
readcount = 0 // # of readers 
wrt = 1 // 
mutex = 1;

Arriving (slide typo): W1, R1, R2, R3, R4, W2, [W1 is finished]

```
W1 arrives: wrt = 1 -> wrt = 0 (since s.valu ! < 0, then no blocking occurs)
R1 arrives: mutex = 1 -> mutex = 0 | readcount = 1
            wrt = 0 -> wrt = -1 (Since < 0, we block R1 in the queue for wrt)
R2 arrives: mutex = 0 -> mutex = -1 (Since < 0, we block R2 in the queue for mutex)
R3 arrives: mutex = -1 -> mutex = -2 (Since < 0 we block R3 in the queue for mutex)
R4 arrives: mutex = -2 -> mutex = -3 (Since < 0 we block R4 in the queue for mutes)
W2 arrives: wrt = -1 -> wrt = -2 (Since < 0 we block w2 in the queue of wrt)
W1 is finished: wrt = -2 -> wrt = -1 (Since < 0, we remove first item in wrt queue which is R1)
R1 is free: mutex = -3 -> mutex = -2
R2 is free: readcount = 1 -> readcount = 2 | mutex = -2 -> mutex = -1
R3 is free: readcount = 2 -> readcount = 3 | mutex = -1 -> mutex = 0
R4 is free: readcount = 3 -> readcount = 4 | mutex = 0 -> mutex = 1 
--------------
R1 is finioshed reading: mutex = 1 -> mutex = 0 | readcount = 4 -> 3
R2 is finioshed reading: mutex = 1 -> mutex = 0 | readcount = 3 -> 2


```

If n readers come while the first writer is not finished, then 1 reader is in the queue for `wrt`, the rest `(n-1)` are in the queue for `mutex`.

## Dining Philosopher Solution
In the first problem they all go for chopstick at the same time and reach a deadlock1   