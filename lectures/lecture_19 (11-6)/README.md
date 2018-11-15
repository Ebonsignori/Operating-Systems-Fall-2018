# Lecture 19

### Announcements


# Lecture Notes
Page Algorithms Continued 

## Page Classes
Every page has a class and 2 bits
(0, 0)
(0, 1)
(1, 0)
(1, 1)

First bit is called the reference bit, the second bit the dirty bit. 

Dirty bit: Something changing in that page

If the page has been referenced, 1st bit will be set to 1, if the page has been changed, the dirty bit will be set to 1. 

## LFU Least Frequently Used
You have a number of frames and want to replace, pick one that is least frequency used. Use counter for each time a page is used.

Minimum Number of Frames: The number of frames needed so that (slides)

**Threshing:** Process doing more page faults then it is executed

If you increase the degree of multiprogramming you take the CPU utilization (down?)

(Insert Image)

Vertical Line is the line where more page faults are happening and execution isn't optimized 

1. Locality 


## Threshing Prevention Algorithms
1. Working Set Model (?)

4. Piece of data that processes needs comes and sits inside a buffer. A page is already

## 

Page size: 

Internal Fragmentation?

