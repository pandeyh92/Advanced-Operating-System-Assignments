#include <future.h>

syscall future_get(future *f, int* value)
{

	intmask mask;
	pid32 ipid;
	umsg32 word;
	mask = disable();
	struct procent *cpid;	
	word =OK;

	switch(f->flag){
	

	case FUTURE_EXCLUSIVE : {
				
				
				if(f->state == FUTURE_EMPTY)
						{
						
							f->state = FUTURE_WAITING;
							f->tid   = currpid;
							cpid = &proctab[currpid];
							cpid->prstate = PR_WAIT;
							resched();	
							
						}
				 if(f->state == FUTURE_WAITING)
						{
							kprintf("\nInvalid State :: future is already in waiting state in FUTURE_EXCLUSIVE  mode");
							restore(mask);
							return SYSERR;
						}
				if(f->state == FUTURE_VALID)
						{
							
                                                         f->value=recvudppacket(slot);
                                                        // kprintf("\n EX:G %d",f->value);
                                                          *value = f->value;
							restore(mask);
							return OK;
						}
				}; break;


	case FUTURE_SHARED : {
				if(f->state == FUTURE_EMPTY)
						{
							if(f->get_queue.count == NFQ)
								{
									kprintf("\n SET QUEUE IS FULL , CAN'T ENQUEUE MORE PROCESS");
									restore(mask);
									return SYSERR;
								}
							f->get_queue.head = (f->get_queue.head) % NFQ;
							f->get_queue.fpid[f->get_queue.head++] = currpid;
							f->get_queue.count++;
							f->state = FUTURE_WAITING;
						  //	f->tid = currpid;
							cpid = &proctab[currpid];
							cpid->prstate = PR_WAIT;
							resched();

						//	restore(mask);
						//	return OK;
						}
				 if(f->state == FUTURE_WAITING)
						{	
						
							if(f->get_queue.count == NFQ)
								{
									kprintf("\n SET QUEUE IS FULL , CAN'T ENQUEUE MORE PROCESS");
									restore(mask);
									return SYSERR;
								}
							f->get_queue.head = (f->get_queue.head) % NFQ;
							f->get_queue.fpid[f->get_queue.head++] = currpid;
							f->get_queue.count++;
							f->state == FUTURE_WAITING;
						  	//f->tid = currpid;
							cpid = &proctab[currpid];
							cpid->prstate = PR_WAIT;
							resched();

							//restore(mask);
							//return OK;

													
						}
				if(f->state == FUTURE_VALID)
						{
                                                   //     kprintf("\n G:B %d  %d %d ",f->value,*value,value); 
							//*value = f->value;
                                                         f->value=recvudppacket(slot);
                                                         *value = f->value;
                                                  //    kprintf("\n G:A %d  %d %d ",f->value,*value,value); 
							f->get_queue.count--;
						if(f->get_queue.count ==0)
							{
								f->state = FUTURE_EMPTY;
							}
						}
						restore(mask);
						return OK;
				
				}; break;
	case FUTURE_QUEUE: {
				if(f->state == FUTURE_EMPTY)
									
						{
							//kprintf("\nG: FM");
							if(f->get_queue.count == NFQ)
							{
								kprintf("\nERROR : QUEUE IS FULL , CANT'T ENQUEUE MORE GET PIDS"); 
								restore(mask);
								return SYSERR;
							}
							if(f->set_queue.count > 0)
								{
                                                                     //kprintf("\n G:SW");
									f->get_queue.head = (f->get_queue.head) % NFQ;
									f->get_queue.fpid[f->get_queue.head++] = currpid;
									f->get_queue.count++;
									f->state = FUTURE_WAITING;
									//kprintf("\nf->get_queue.count %d",f->get_queue.count);
									cpid = &proctab[currpid];
									cpid->prstate = PR_WAIT;
									f->set_queue.count--;
									ready(f->set_queue.fpid[f->set_queue.tail++]);
									

									if(f->state == FUTURE_VALID)
									{
                                                                                  // kprintf("\n G: B %d %d",f->value,*value);
                                                                                  f->value=recvudppacket(slot);
										*value = f->value;
										//kprintf("\n G: A %d %d",f->value,*value);
										if(f->get_queue.count > 0)
											{
												f->state = FUTURE_WAITING;
											}
										else    {
												f->state = FUTURE_EMPTY;
											}								
 										restore(mask);
										return OK;
									}
							
														
								}

							else 
							{	
							//kprintf("S: FE c<0");
							f->get_queue.head = (f->get_queue.head) % NFQ;							
							f->get_queue.fpid[f->get_queue.head++] = currpid;
							f->get_queue.count++;
							f->state = FUTURE_WAITING;
								

							cpid = &proctab[currpid];
							cpid->prstate = PR_WAIT;	
							resched();
								if(f->state == FUTURE_VALID)
									{
                                                                                  // kprintf("\n G: B %d %d",f->value,*value);
										//*value = f->value;
                                                                               f->value=recvudppacket(slot);
                                                                                *value = f->value;
										//kprintf("\n G: A %d %d",f->value,*value);
										if(f->get_queue.count > 0)
											{
												f->state = FUTURE_WAITING;
											}
										else    {
												f->state = FUTURE_EMPTY;
											}								
 										restore(mask);
										return OK;
									}
							restore(mask);
							return OK;
							}
						}
				 if(f->state == FUTURE_WAITING)
						{
							
							//kprintf("\nG: W"); 
							if(f->get_queue.count == NFQ)
							{
								kprintf("\nERROR : QUEUE IS FULL , CANT'T ENQUEUE MORE GET PIDS"); 
								restore(mask);
								return SYSERR;
							}
							f->get_queue.head = (f->get_queue.head) % NFQ;
							
							f->get_queue.fpid[f->get_queue.head++] = currpid;
							f->get_queue.count++;
							f->state = FUTURE_WAITING;
							
						  	
							cpid = &proctab[currpid];
							cpid->prstate = PR_WAIT;	
							resched();



						

						}
				 if(f->state == FUTURE_VALID)
						{

							kprintf("\nG: V"); 
							//kprintf("\n G: B %d %d",f->value,*value);
							//*value = f->value;
                                                        f->value=recvudppacket(slot);
                                                        *value = f->value;
							f->state = FUTURE_VALID;
							kprintf("\n G: A %d %d",f->value,*value);							
 							
						}
							restore(mask);
							return OK;
				
				};break;
	default: 		{
				kprintf("\nINVALID MODE");
				restore(mask);
				return SYSERR;
				};break;
	}
}

