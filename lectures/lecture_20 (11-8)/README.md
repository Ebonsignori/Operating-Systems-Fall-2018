# Lecture 20

### Announcements
Quiz #2 - November 15th (Thursday)

On materials after Midterm exam up to today (Not including next Tuesday's lecture November 13)

# Lecture Notes
### Disk System
Suppose CPU while executing a process hits a case where data must be read in or writen from/to disk.

A disk system is in charge of:
1. Mechanical Part. OS tells disk you must do the reading operation. Disk needs to perform IO operation. You have read and write head that moves in and out of the disk. The movement of read and write stay on the same track. 
2. Implementing an IO operation: Reading into buffer.

`Process 1 -> Request an I/O Operation`

CPU sends following data to Disk System:
1. Type of operation read/write
2. Where data is located on disk (key or index)
3. Where should it go in buffer (address of buffer)
4. Size of information to be transfered.

Disk Queue holds I/O operations when multiple I/O operations are sent to slower disk. To decide order of queue we use one of size disk scheduling algorithms. 

### Six Disk Scheduling Algorithms 
(Slides for how to calculate optimal algo)

1. FCFS Sheduling
2. SSTF (Shortest Seek Time First)
- Advantage: Better total head movement
- Disadvantages: 
    1. Starvation
    2. Total head movement is not optimal 
3. SCAN (or Elevator)
    
4. Look
Similar to SCAN, but looks ahead for if there is a higher/lower value, and only move up to/down to the highest or lowest track number. 

5. C-SCAN (Circular Scan)
Goes up to highest value, then rather than going down, goes to 0 and then climbs up.
*Include the jump from highest value to 0*

6. C-Look (Scan)

### RAID
(See slides)
Mirroring: Multiple copy of files, but you have a very sophisticated algorithm to make sure that deletions are propagated to all mirrored versions 

Stripping: You have one record or file for example and want to read because CPU needs it. Break it downt to 10 pieces and put each piece on a different disk. Then when reading, you can read all 10 in parallel. Instead of reading record from 1 disk, you read in parallel from 10.

## File Management System
**Field:** is a named piece of data. Example student ID is a name for an ID that is `907111`
    - Name: Type 
    - Data: Instance (many instances of 1 type)

**Record:**  A named set of fields. Also name and collection of data
    - Name: Type 
    - Data: Instance (many instances of 1 type)
   
1 record type can have many instances. 

**File:** A named collection of one record type's instances. File may carry programs or data (numeric, alphabetic, alphanumeric, and binary). 

### File Attributes
1. Name (Only attribute that human being has a say): That user calls it
2. Identifier: A name that file management system chooses/calls it
3. Type
4. Location
5. Size
6. Protection
7. Time, date, user identification

### File Structure
An internal file structure used by OS to handle a file. We want the minimal number of internal structures of file.

Internal Structure: Way that OS looks at a file. 

In Unix: A file is a sequence of 8-bit bytes. Reads a file byte-by-byte
In Mac: File has two parts: A resource fork and a data fork.
In DEC VMS: 3 different file structures.

**Access Method:** The way by which the content of a file may be accessed. 
1. Sequential: Start from beginning and read record by record
2. Direct: Each record has a unique key and you can jump to any record that you want. 
3. Indexed