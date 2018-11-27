# Lecture 21

### Announcements
Quiz #2 - November 15th (Thursday)
Demo Day for first 3 projects: November 29th
Assignment #4: Due November 27th'

# Lecture Notes
Everything in a computer is a resource. A computer system is made up of resources.


A resource has 
1. Type
2. Instance


A process may use a resource in only the following sequence:
1. Request: (slides)
2. Use: 
3. Release:  

A set of processes are in a deadlock state when every process in the set is wawiting for an event (releaseing a resource) that can take place only by another process in the set.

Example : (slides)
Deadlocks. Process P1 is using resource R1 and it needs resource resource R2. P2 is using resource R2, but needs resource R1. 

```
P1    R1    Uses
      R2    Needs

P2    R2    Uses
      R1    Needs
```

## Deadlock Facts
All four must be true for a deadlock to occur: 

1. Circular Wait:  Circular waiting in deadlock. Every process holds a resource and waiting on a resource held by the next process. {P1, P2, P3} is a circular wait that we denote with the triangle dot symbol. Every deadlock has a circular wait.

2. Mutual Exclusion (of resources):  Resources are not sharable. 

3. No preemption (of resources): Any of the resources held by a process can not be preempted.  

4. Hold and wait: It is clear that a process in the set is holding a resource (slides)

## Resource Allocation Graph
Resources are rectangles

Processes are circles

Dots in rectangles: Number of instances you have for a resource
Ex. Two copies of a same file, 3 disks, 1 printer, etc.

Edges: {P1 -> R1} means "P1 requesting R1" and we draw an arrow in that direction. 

{R1 -> P2} R1 is given to P2. 

If graph has no cycle: Then there is no deadlock

For deadlock: Cycle and each resource has only one instance.

If cycle and multiple instances *may* not have a deadlock.

## Deadlock Handling Methods
In deadlock prevention we get rid of one of four conditions.

Methods for handling deadlocks:
1. Deadlock Prevention: (slides)
2. Deadlock Avoidance: (slides)
3. Deadlock Ignoring: You have a deadlock and you ignore all processes that have a deadlock. You reboot system and resubmit process.
4. Deadlock Detection and Recovery: Detect a deadlock, and then you do something to get rid of the deadlock. 

### Deadlock Prevention
1. Circular Wait: Assign a precedence to the resources' types and use the following protocol. Each process can request resources only in an increasing order of precedence. 

### Mutual Exclusion
(Slides)

### No Preemptive Condition
One of the following protocols does the job:
1.
2. 

### Hold and Wait
1. Release before request: If asking for a new resource, only get if you don't have any. (slides). As soon as you ask for something else you release whatever you were holding. 

2. All or none: Each process has to request and be allocated all of its requested resources before it begins execution. It gives either all or none. 

## Advantages and Disadvantages of Preventing Deadlocks
Advantage: 
1. Preventing Deadlock

Disadvantages: 
1. Low resource utilization
2. Low system throughput
3. (Slides)

### Deadlock Avoidance
(slides)

.
.
.
(slides)
Process Termination or Resource Terminaltion

Decide Process Termination using a number of factors: THe number of resources it has used, how long it has been running, etc. (slides)



