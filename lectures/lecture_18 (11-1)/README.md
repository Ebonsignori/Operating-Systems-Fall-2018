# Lecture 18

### Announcements


# Lecture Notes
## Memory Management 
**Virtual Memory**: You bring in part of the process (that is absolutely needed for execution of process), you bring those into the frame. 

## Virtual Memory Adoption
1. Overlay: The size of the page table is not important. How many frames you give the processes from the RAM is important. Degree of multiprogramming goes up when you shrink the number of frames for each process. 

2. Dynamic Loading: Only difference, but in the case of dynamic you load only the main part (module). If you have enough frames to accomidate the main and a couple of other pages, you are ok.

### Demand Paging System
(? Recording)

Made up of two parts:
1. Paging System
2. Swapping System: Take a page from the backing store, bring it to the RAM or vise versa.
 - Lazy Swapping (a.k.a *pager*): Because it brings only the pages that the process needs. Generally speaking (non-lazy) a regular swapper brings in extra pages that may not be needed. 
 
0 in page table just means that the page isn't in, instead of there being an error as in (?)


Page demanded not in the RAM, page fault happens

Internal Table in charge of checking the valid bit. 

Dirty Bit: Add a bit to the page table.
If bit = 1: The corresponding page has been modified (it is dirty)
If bit = 0: Then nothing changed (at the time of swap)