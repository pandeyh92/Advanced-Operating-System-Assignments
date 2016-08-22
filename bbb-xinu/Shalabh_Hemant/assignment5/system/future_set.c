/* future_set.c - close */

#include "future.h"

syscall	future_set(future *f,int *value)
{
	intmask mask;
	
	int32 i;
	mask = disable();
	
	
	struct procent *ptr;

	switch(f->flag){
	

	case FUTURE_EXCLUSIVE : {
				
				if(f->state == FUTURE_EMPTY)
						{
						  	f->value = *value;
							f->state = FUTURE_VALID;
							restore(mask);
							return OK;
						}
				else if(f->state == FUTURE_WAITING)
						{
							f->value = *value;
							f->state = FUTURE_VALID;
							
							ready(f->prid);
							restore(mask);
							return OK;
						}
				else 		{
							kprintf("\nInvalid State :: future is already set in FUTURE_EXCLUSIVE  mode");
							restore(mask);
							return SYSERR;
						}
				}; break;


	case FUTURE_SHARED : {
				if(f->state == FUTURE_EMPTY)
						{
							kprintf("\n S:B %d  %d ",f->value,*value); 
							f->value = *value;
                                                         kprintf("\n S:A %d  %d ",f->value,*value); 
							f->state = FUTURE_VALID;
							restore(mask);
							return OK;
						}
				else if(f->state == FUTURE_WAITING)
						{	
                                                      //kprintf("\n S:B %d  %d ",f->value,*value); 
							f->value = *value;
                                                        //  kprintf("\n S:A %d  %d ",f->value,*value); 
							f->state = FUTURE_VALID;
							resched_cntl(DEFER_START);
							for(i=0;i<f->get_queue.count;i++)
							//while(f->get_queue.count != 0)
							{
								
								//ipid = f->get_queue.futqueue[f->get_queue.tail++];

								//kprintf("\n S:L %d ",f->get_queue.count ); 
								//f->get_queue.count --;	
								ready(f->get_queue.futqueue[f->get_queue.tail++]);	
								
							}				
							resched_cntl(DEFER_STOP);
							restore(mask);
							return OK;							
						}
				else 		{
							kprintf("\nInvalid State :: future is already set, only One-to-many mapping suppoerted in FUTURE_SHARED  MODE");
							restore(mask);
							return SYSERR;
						}
				}; break;
	case FUTURE_QUEUE: {
				if(f->state == FUTURE_EMPTY || f->state == FUTURE_VALID)
						{	
							kprintf("\nS: E || V"); 
							if(f->set_queue.count == NMAX)
							{
								kprintf("\nERROR : QUEUE IS FULL , CANT'T ENQUEUE MORE GET PIDS"); 
								restore(mask);
								return SYSERR;
							}
							
							f->set_queue.head = (f->set_queue.head) % NMAX;

							f->set_queue.futqueue[f->set_queue.head++]=currpid;
							f->set_queue.count++;
							ptr = &proctab[currpid];
							ptr->prstate = PR_WAIT;
							
							resched();
							
						}
				if(f->state == FUTURE_WAITING)
						{	kprintf("\nf->get_queue.count %d",f->get_queue.count);
							kprintf("\nS: W "); 
							if(f->get_queue.count == 0)
							{
								kprintf("\nGET QUEUE UNDERFLOW , NO PID TO DEQUEUE");
							}
							kprintf("\n S: B %d %d",f->value,*value);
							f->value = *value;
							kprintf("\n S: A %d %d",f->value,*value);
							f->state = FUTURE_VALID;
							f->get_queue.count--;
							ready(f->get_queue.futqueue[f->get_queue.tail++]);
							
							//restore(mask);
							return OK;
						}
				};break;
	default: 		{
				kprintf("\nINVALID MODE INSIDE SET ");
				restore(mask);
				return SYSERR;
				};break;
	}
}


	

