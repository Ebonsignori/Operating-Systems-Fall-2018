# Lecture 16

### Announcements


# Lecture Notes
**NOTICE:** The slides are sufficient for this lecture, use them as a primary source and these notes for reference.

### Problems with use of semaphores: Dead Lock

When two are waiting forever

### Timing Error
If two processes arrive at exactly the same nanosecond, then we have a timing error. 

Solution is *Locking*. 

## Programmer Error
Suppose you have n programs each with structure (from slides)
```
Repeat
    P(mutex)
        Critical Section
    .. todo slides
```

3 cases: (slides)

## Use CRC (Critical Region Construct) when users have programming errors

For CRC we require a shared variable among processes with type T (i.e. integer, boolean)

Example: `Var u: shared T`

`Var u: shared T;`

Region u do A

**Abstract data types use CRC.** ADT (Class in Java). Has a name, set of variables, and a set of methods (procedures). 

# Integration of C.R.C> and ADT ex
You have a number of buffers or frames that we want to occupy. When we occupy it we change variable to false


# Nested Critical Region
x > y => x has greater priority than y

# Condition Critical Region Construct 
(Slides Rest)
