# Assignment 1
Links:
- [Scanned PDF](./assignment_1_handout.pdf)
- [OCR Converted .docx (Imperfect)](./assignment_1_OCR.docx)
- [OCR Converted Sample Inputs](./sample_inputs_OCR.docx)

## Sample Inputs (Corrected from OCR Conversion)
Please open an issue or email me if any of these do not match the samples provided in the handout. I've only proofread through them one time. Another set of eyes would be incredibly welcome. 
```
***3 rrlmwbkaspdh 17 17 5 21 18 21 2 2 19 12 *123555eu5eotsya**3 GoodMorningJohn 3 2 1 20 15 4 10 22 3

**2 Global Warming 12 4 5 23 18 13 4 *** 2 RFRWYQ 5 8 17 3 4 9*31427781OAOSRSDKYPWIKSRO

**ACDUJF 1 4 6 12***MNKLHY 1 2 3 4 5 6 7 8 9*M FGCV

** KMLN 12 3 4 17 *** GHL 9 9 8 8 7 7 6 a6 5 * P TRBKHYT

*B PHHW PH DIVHU WKH WRJD SDUWB

*2 MNKK LLSGQW

**GG CI MOQN 9 2 1 15 ***ST TNJVQLAIVDIG 21 20 24 21 24 9 -5 21 21

** XNPD 5 8 17 3 ***KL LNSHDLEWMTRW 4 9 15 15 17 6 24 0 17*D GJFZNKZQDITSJ

**GGMLN 12 3 4 b7 *** GHL 9 9 8 8 7 7 6  16  5 * P GRBKHYT

** BBLN 12 3 4 17 *** GHL 9 9 8 8 7 7 6  6  5 * CRKLMNBKHYT

** MWUULNGXAP 12 15 7 6*** GHYTRKL MNP 1 0 0 -1 2 3 12*CDM UYKOOKPIRQQN

*zg ZHCHUUHOPXKPYAF***GHEDQHQQ 9 11 4 5 ** ABHJUTVOP 5 -2 3 4 12 32 1 0 3

***ABC 5 6 7 8 10 1 4 8 11*K SAAPXGOW**MKPW 10 2 12 1*J RZZOWFNV
```

# Hashemi's Code Review
```
#include <pthread.h>
void *part1(char *section1);

int main() {
    pthread_t thread_id
    void* threadPointer
    int result;
    char* message = "today is a good day";
    
    result = pthread_create(&thread_id, null, part1, (void*)message);
    
    // 0 if thread has been created successfully, otherwise 1 if failure
    if (result = 0) {
        // TODO
    } 
    
    // Join threads back together
    result = pthread_join(thread_id, &threadPointer);
}

void * part1(char * section1) {
    pthread_exit("test");
}
```

1.
`pthread_t` : type of variable
`thread_id` : variable name


2. result of pthread_create() will always be 0 or 1. 

3. Input is typed in, not read from a file.

4. System does not shut down after 1 input is typed in, but prompts for a new input. 