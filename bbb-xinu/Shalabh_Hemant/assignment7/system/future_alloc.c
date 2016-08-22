#include "future.h"

future* future_alloc(int future_flag)
{	
	intmask mask;
	mask = disable();
	/* uint32 remip;
        char ipAdress[]="192.168.1.100";
        dot2ip(ipAdress,&remip);*/
	
	if(future_flag == FUTURE_EXCLUSIVE || future_flag == FUTURE_SHARED || future_flag == FUTURE_QUEUE){
		
	
 future *f= (struct futent*)getmem(sizeof(struct futent));
		//f = getmem(sizeof(future));  
		//allocate memory for f
	
		f->value =0;
		f->flag	= future_flag;
		f->state = FUTURE_EMPTY;
		f->get_queue.head = 0;
		f->get_queue.tail = 0;
		f->get_queue.count = 0;
		f->set_queue.head = 0;
		f->set_queue.tail = 0;
		f->set_queue.count = 0;
               
                // f->slot=udp_register(remip,50410,50410);
                  
                
		restore(mask);	
	        return (struct futent*)f;
	}
	else {
		
		kprintf("\n INVALID FLAG \n");
		restore(mask);		
		return SYSERR;
	}
	
}
