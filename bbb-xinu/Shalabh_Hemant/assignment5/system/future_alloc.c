/* future_alloc.c - close */

#include "future.h"
future *future_alloc(int future_flag)
{
  intmask mask;
  mask=disable();
  if(future_flag == FUTURE_EXCLUSIVE || future_flag == FUTURE_SHARED || future_flag == FUTURE_QUEUE)
       {
   	future *alloc=getmem(sizeof(future));
   	alloc->state=FUTURE_EMPTY;
   	alloc->flag=future_flag;
   	alloc->value=0;
   	alloc->set_queue.head=0;
	alloc->set_queue.tail=0;
	alloc->set_queue.count=0;
	alloc->get_queue.head=0;
	alloc->get_queue.tail=0;
	alloc->get_queue.count=0;
	restore(mask);	
	return alloc ; 
       }
else
	{
	  printf("\n Invalid flag");
	  restore(mask);
	  return SYSERR;
	}	
}
