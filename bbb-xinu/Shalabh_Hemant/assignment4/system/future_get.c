/* future_get.c - close */

#include "prodcons.h"

syscall	future_get(future *f,int *value)
{
	intmask		mask;		/* Saved interrupt mask		*/
	//mask=disable();
	//printf("\nInside future get");
          if(f->state == FUTURE_EMPTY)
		{
		  f->state=FUTURE_WAITING;
		  f->tid=getpid();
                  kprintf("get : b4r while %d\n",f->state);
		  while(1)
                  {
                     kprintf("");
                     if(f->state==FUTURE_VALID)
                     {
                       break;
                      }
                  }
                 // kprintf("get : after while\n");

                 if(f->state==FUTURE_WAITING)
		  {
		 //restore(mask);
		 return SYSERR;
		  }		 
	        else if(f->state==FUTURE_VALID)
		  {
		  f->state=FUTURE_EMPTY;
	          *value =f->value; 
                   //kprintf("get : value emp %d \n",*value);
		  } 
          
		}
	else if(f->state==FUTURE_WAITING)
		{
		 //restore(mask);
                 kprintf("get : invalid state to get");
		 return SYSERR;
		}		 
	else if(f->state==FUTURE_VALID)
		{
		  f->state=FUTURE_EMPTY;
	          *value =f->value; 
                 // kprintf("get : value val %d \n",*value);
		}
        //restore(mask);
	return OK;
	
}
