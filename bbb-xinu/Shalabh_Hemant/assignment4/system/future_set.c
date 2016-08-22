/* future_set.c - close */

#include "prodcons.h"

syscall	future_set(future *f,int *value)
{
	intmask		mask;		/* Saved interrupt mask		*/
	mask=disable();
	//printf("\nInside future set");
        if(f->state == FUTURE_EMPTY)
		{
		  f->value=*value;
		  f->state=FUTURE_VALID;
                 // kprintf("set : empty %d \n",f->value);
		}
	else if(f->state==FUTURE_WAITING)
		{
		 f->value=*value;
		 f->state=FUTURE_VALID;
                //kprintf("set : wait %d %d\n",f->value,f->state);
		}		 
	else if(f->state==FUTURE_VALID)
		{
                  kprintf("set : invalid state for set\n");
		  restore(mask);
		 return SYSERR;
		}
        restore(mask);
	return OK;
}
