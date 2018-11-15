# Lecture 13

### Announcements
Assignment 1 due this Thursday (Next Class)

Do (ungraded) exercise handed out in class

### Handouts
- [Fork Join Practice Handout](./handout_fork_join.pdf)
- [Fork Join Practice Handout Solution](./handout_fork_join_solution.pdf)

# Lecture Notes
**NOTICE**: For this lecture, refer to the [slides](./slides_13.pdf) for the "how-to" of the concept. 
# Process Synchronization
"This is the heart of the entire course. This is my favorite subject, which means be very good at it"
- Dr. Hashemi

**Process Synchronization:** If you have several processes, how can you run these processes in parallel?
Concurrency happens in two levels:

1. Intra-concurrency: Concurrency/Parallelism within a process
2. Inter-concurrency: Concurrency/Parallelism among several processes

Precedence graph: A directed acyclic graph made of edges and nodes. Each node represents 1 statement of a process, each edge represents order of the statements execution. 

## Intra-concurrency
Goal: Achieving parallelism *within* a process. 

(See [slides](./slides_13.pdf) picture for example)

### Implementation
**Read variables:** Variables that we read data from to calculate the left side (write variable). Variables whose value is changed (write into).


**Write variable:** Variables whose values are needed (read from).

If we have: `S7: g = c + y + z;`

Then the read variables are represented as the set:

`R(S7) = {c, y, z}`

And the write variable(s) are represented as the set:

`W(S7) = {g}`

### Concurrency Condition
Three statements S_i and S_j can concurrently be executed if:
1. R(S_i) intersect W(S_j) = Empty set
2. W(S_i) intersect R(S_j) = Empty set
3. W(S_i) intersect W(S_j) = Empty set

## Fork .. Join Construct
`Fork <label>`

All statements after Fork L1 and L1 are executed in parallel (slides image)

In example with L2, we need Join or L1 will go to L2 and L2 needs L1 and Fork L1

`<label> Join <counter>`

If the counter is 0, it continues. If counter > 0, it loops/waits doesn't go anywhere. 

In example, when L2 is reached, count is decremented. Count starts at 2, and execution of L2 continues when count - 1 - 1 = 0;

**tldr:** Set `Count` to number of parallel processes that need to be joined/waited for

### Example
Set up a counter for *each* place that multiple arrows join. 

```
Counter_S7 = 3;

See slides

S7 Join Count
```

## Parbegin .. parend Construct
S_0 (Start with 0)
Parbegin S1, S2, ... Sn parend (All processes goes and counter ticks down and reaches 0 when all are completed)
S_n+1 (End after all S_n are executed and counter is 0)

### Example
S_0
Parbegin
    S_1;
    S_2;
    S_n;
Parend
S_n+1

### Parbegin Insufficiency 
Cannot handle any precedence graph

However, we can represent parbegin .. parend using fork joins.