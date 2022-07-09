/******************************************************************************
;@
;@ Student Name 1: student1
;@ Student 1 #: 123456781
;@ Student 1 userid (email): stu1 (stu1@sfu.ca)
;@
;@ Student Name 2: student2
;@ Student 2 #: 123456782
;@ Student 2 userid (email): stu2 (stu2@sfu.ca)
;@
;@ Below, edit to list any people who helped you with the code in this file,
;@      or put ‘none’ if nobody helped (the two of) you.
;@
;@ Helpers: _everybody helped us/me with the assignment (list names or put ‘none’)__
;@
;@ Also, reference resources beyond the course textbooks and the course pages on Canvas
;@ that you used in making your submission.
;@
;@ Resources:  ___________
;@
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

#include "heapstats.h"

typedef unsigned int bigNumN[];

int bigAdd(bigNumN bigN0P, const bigNumN bigN1P, unsigned int maxN0Size);

int bigFib(int n, int maxSize, unsigned **bNP) {
	// ... you can modify any code in this function ****
	unsigned* bNa = malloc(4*(1 + maxSize));
	// check for null pointer being returned or not
	if (bNa)
		*bNa = 0;	

	unsigned* bNb = malloc(4*(1 + maxSize));
	// check for null pointer being returned or not

	HEAPSTATS;

	// ... fill in code here for sure ****
	
	// The following two lines of code are just examples.
	// You might not always want to do them.
	*bNP = bNa; // don't forget to free the other allocated memory
	return 0;
}

