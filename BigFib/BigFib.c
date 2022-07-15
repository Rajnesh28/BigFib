/******************************************************************************
;@
;@ Student Name 1: Rajnesh Joshi
;@ Student 1 #: 301390046
;@ Student 1 userid (email): rajneshj@sfu.ca
;@
;@ Student Name 2: Gabriel Manansala
;@ Student 2 #: 301411776
;@ Student 2 userid (email): gmanansa@sfu.ca
;@
;@ Below, edit to list any people who helped you with the code in this file,
;@      or put ‘none’ if nobody helped (the two of) you.
;@
;@ Helpers: _everybody helped us/me with the assignment (list names or put ‘none’)__
;@
;@ Also, reference resources beyond the course textbooks and the course pages on Canvas
;@ that you used in making your submission.
;@
;@ Resources:  https://developer.arm.com/documentation/dui0492/c/the-c-and-c---libraries/--heapstats--
;@						 Piazza
;@% Instructions:
;@ * Put your name(s), student number(s), userid(s) in the above section.
;@ * Edit the "Helpers" line and "Resources" line.
;@ * Your group name should be "HW5_<userid1>_<userid2>" (eg. HW5_stu1_stu2)
;@ * Form groups as described at:  https://courses.cs.sfu.ca/docs/students
;@ * Submit your file to courses.cs.sfu.ca
;@
;@ Name        : BigFib.c
;@ Description : bigFib subroutine for HW5.
******************************************************************************/


#include <stdlib.h>
#include <errno.h>

typedef unsigned int bigNumN[];

int bigAdd(bigNumN bigN0P, const bigNumN bigN1P, unsigned int maxN0Size);

int bigFib(int n, int maxSize, unsigned **bNP) {

	//Invalid argument check
	if (n < 0 || maxSize < 0 || bNP == NULL){
		errno = EINVAL;
		return -1;
	}
	

	
	// Allocated space for a pointer to a memory address
	unsigned* bNa = malloc(4*(1 + maxSize));
	if (!bNa){
		errno = ENOMEM;
		return -1;
	}
	
	unsigned* bNb = malloc(4*(1 + maxSize));

	if (!bNb){
		errno = ENOMEM;
		free(bNa);
		return -1;
	}
	
	if (maxSize == 0){	
		*bNa = 0;
		*bNP = bNa;
		return 0;
	}	
	
	if (bNa) { 

		*bNa = 1;	
		*(bNa+1) = 0;

		*bNb = 1;
		*(bNb+1) = 1;			

		if(n==0){
			*bNP = bNa;	//return F0
			free(bNb);
			return 0;
		}
		if(n==1){
			*bNP = bNb;	//return F1
			free(bNa);
			return 1;
		}			
			
		int f;
		
		for(int i=2; i <= n; ++i){
			
				f = bigAdd(bNa, bNb, maxSize);
				if (f){
					free(bNa);
					return i-1;
				}
				else if (!f){
					*bNP = bNa;	
					bNa = bNb;
					bNb = *bNP;
					continue;
				}
				
				else if (f==-1){
					errno = ENOMEM;
					return -1;
				}

			}

		}

	free(bNa);
	return n;
}
	

 	
	



