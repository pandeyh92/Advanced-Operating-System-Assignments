/* future_free.c - close */

#include "prodcons.h"

syscall	future_free(future *f)
{
	intmask		mask;		/* Saved interrupt mask		*/
	mask=disable();
	if(freemem(f,sizeof(future)) == SYSERR)
	   {
	       restore(mask);
	       return SYSERR;		
	   }
	else
	   {
		restore(mask);
	       return OK;	
	   } 
}
