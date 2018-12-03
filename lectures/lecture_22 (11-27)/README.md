# Lecture 22

### Announcements
Project Presentations - November 29th (Thursday)

Demo: Run each program

Optionally, we can go tomorrow (Weds) around 2pm to test run programs

# Lecture Notes
Distributed Systems (Listen to lecture)
1. Tightly Coupled (Parallel Processors)
2. Loosely Coupled (Distributed Systems)

## Names to refer to computer in distributed system
- Node
- Computer
- Machine
- Site: Location of computer
- Host: Computer itself

A site can have many computers

In a distributed system you have a host, called *server whose resources can be used by another node, called a *client. Thus distributed system considered a client-server system

Distributed systems can:
1. Share resources
2. Communicate with each other
3. Transferring data among themselves

Major difference between loosely and tightly coupled: When we say shared resources, for dist systems we share in the sense that we ask a favor of another host. We don't physical share a cpu, memory, etc.

## Two Types of OS for distributed Systems
1. Network OS: In addition to whatever OS provides, it support 2 items:
    1. Support logging into another host. Using command: **Telnet <name_of_host>** Example: **Telnet Jib.armstrong.edu**. 
    2. Transfer files or data: We use command **get** to get the file from the hose *after* we are logged in. Example **get abc.dat myabcdat**. If we want to transfer our file to a remote machine we call **put**:

2. Distributed OS:


--- (Recording for missed section)

Data Migration

Computation Migration: File must exist on remote machine
   1. Messaging: Process P sends a message to the remote which says, "I want routine A be applied on file abc.dat". Remote generates process Q and applies routine A (which already exists on remote) and give the results back to P. 
   2. CRC: Routine A is part of CRC
    
Processor Migration

