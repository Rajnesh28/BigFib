/******************************************************************************/
/* BigFib.C:                                                     */
/* Copyright (C) 2022 Craig Scratchley    wcs (at) sfu (dot) ca  */
/******************************************************************************/

/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>  // for strerror()

#include "heapstats.h"
#include "asm_include.h"
#include "InitHw.h"
#include "BigFib.h"
#define MAX_SIZE_TEST 1000

void halt()
{
	while(0);
}

int main() {

	unsigned *fibResP = NULL;
	int rv;
	unsigned size;
	unsigned lsw;
	
	InitHw(); // Initialize the HW, including the UART for printf()
	printf("BigFib Testing Program\n"); // must write to stdout/printf before below line with __heapstats
	HEAPSTATS;
//
//	////////////////****************1*****************///////////////////

//	////////////////****************2*****************///////////////////
	rv = bigFib(1, 0, &fibResP);
	size = *((fibResP));
	printf("F1 requested. F%d was calculated with size %u.\n", rv, size); 
	if(!(rv==0x0 && size==0) )
			halt();
	free(fibResP);

//	////////////////*****************3****************///////////////////
	rv = bigFib(0, 0, &fibResP);
	lsw =  *((fibResP)+1);
	size = *((fibResP));
	printf("F0 requested. F%d was calculated with size %u.\n", rv, size); 
	if(!(rv==0x0 && size==0) )
		halt();
	free(fibResP);

//	 ////////////////*****************4****************///////////////////
	rv = bigFib(1, 1, &fibResP);
	lsw =  *((fibResP)+1);
	size = *((fibResP));
	printf("F1 requested. F%d was calculated as %u with size %u.\n", rv, lsw, size); 
	if(!(rv==0x1 && lsw==1 && size==1) )
		halt();
	free(fibResP);

//	////////////////****************5*****************///////////////////
	rv = bigFib(3, 1, &fibResP);
	lsw =  *((fibResP)+1);
	size = *((fibResP));
	printf("F3 requested. F%d was calculated as %u with size %u.\n", rv, lsw, size); 
	if(!(rv==0x3 && lsw==2 && size==1) )
		halt();
	free(fibResP);

//	////////////////****************5b*****************///////////////////
	rv = bigFib(3, 4, &fibResP);
	lsw =  *((fibResP)+1);
	size = *((fibResP));
	printf("F3 requested. F%d was calculated as %u with size %u.\n", rv, lsw, size); 
	if(!(rv==0x3 && lsw==2 && size==1) )
		halt();
	free(fibResP);

//	////////////////****************5c*****************///////////////////
	rv = bigFib(3, 0, &fibResP);
	size = *((fibResP));
	printf("F3 requested. F%d was calculated with size %u.\n", rv, size); 
	if(!(rv==0x0 && size==0) )
		halt();
	free(fibResP);

//	////////////////***************6******************///////////////////
	rv = bigFib(50, 1, &fibResP);
	lsw =  *((fibResP)+1);
	size = *((fibResP));
	printf("F50 requested. F%d was calculated as %u with size %u.\n", rv, lsw, size); 
	if(!(rv==0x2f && lsw==0xB11924E1 && size==1) ) // 0x2f = 47
		halt();
	free(fibResP);
	
//	////////////////***************7******************///////////////////

	rv = bigFib(-2, 1, &fibResP);
	printf("F-2 requested. \n"); 
	if(!(rv==-1 && errno==EINVAL) )  
		halt();
	else
		printf("Test 7: %s\n", strerror(errno));
	
//	////////////////***************8******************///////////////////

	rv = bigFib(1, Heap_Size*2, &fibResP);
	printf("Maxsize Heap_Size*2 requested. \n"); 
	if(!(rv==-1 && errno==ENOMEM) )  
		halt();
	else
		printf("Test 8: %s\n", strerror(errno));
	
//	////////////////****************9*****************///////////////////
	rv = bigFib(1, 0, NULL);
	if(!(rv==-1 && errno==EINVAL) ) {
		halt();
	}	
	else
		printf("Test 9: %s\n", strerror(errno));

// please add more testcases	
	
// and now ...	
	rv = bigFib(1000000, MAX_SIZE_TEST, &fibResP);
	lsw =  *((fibResP)+1);
	size = *((fibResP));
	printf("F1000000 requested. F%d was calculated with size %u.\n", rv, size); 
	halt();
	free(fibResP);
  HEAPSTATS;

	while(1);
//	return 0;
}

