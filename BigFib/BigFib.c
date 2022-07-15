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

//Desc: Find the nth fibonacci number, or the one prior to overflow
//Pre:  N>0, maxSize>0, and bNP must point to a valid space in memory
//Post: Return the nth fibonacci number
int bigFib(int n, int maxSize, unsigned **bNP) {

	//Check if the parameters are valid
	if (n < 0 || maxSize < 0 || bNP == NULL){
		errno = EINVAL;
		return -1;
	}
	
	// Allocated space for a pointer (bNa) to a memory address
	unsigned* bNa = malloc(4*(1 + maxSize));
	
	//Check if the space was properly allocated
	if (!bNa){
		errno = ENOMEM;
		return -1;
	}
	
	// Allocated space for a pointer (bNb) to a memory address
	unsigned* bNb = malloc(4*(1 + maxSize));

	//Check if the space was properly allocated
	if (!bNb){
		errno = ENOMEM;
		free(bNa);
		return -1;
	}
	
	//If maxsize is zero, just return 0
	if (maxSize == 0){	
		*bNa = 0;
		*bNP = bNa;
		return 0;
	}	
	
	//If bNa exists then begin computation using recursive bigAdd
	if (bNa) { 

		//Allocate the bNa and bNb memory spaces at the first position to the
		//respective fibonnaci values of F0, and F1
		*bNa = 1;	
		*(bNa+1) = 0;

		*bNb = 1;
		*(bNb+1) = 1;			
			
		//If we want 0th term, return 0
		if(n==0){
			*bNP = bNa;	
			free(bNb);
			return 0;
		}
		
		//If we want 1st term, return 1
		if(n==1){
			*bNP = bNb;	
			free(bNa);
			return 1;
		}		
		
		//Fibonacci function variable
		int f;
		
		//First two, n=0,1 are taken care of
		for(int i=0; i <= n-2; ++i){
			
				f = bigAdd(bNa, bNb, maxSize);
			
				//If f = 1 return the number prior to overflow
				if (f){
					free(bNa);
					return i+1;
				}
				
				//If f = 0 continue to recurisively bigAdd
				else if (!f){
					*bNP = bNa;	
					bNa = bNb;
					bNb = *bNP;
					continue;
				}
				
				//If f = -1 error occurred, return -1
				else if (f==-1){
					errno = ENOMEM;
					return -1;
				}

			}

		}

	//Free space and return
	//This is from original code template from Professor Craig
	free(bNa);
	return n;
}
	

 	
	



