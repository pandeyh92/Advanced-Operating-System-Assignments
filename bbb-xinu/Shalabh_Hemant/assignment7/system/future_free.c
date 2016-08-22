#include "future.h"

syscall future_free(future* f)
{

     intmask mask;
     int released;
     mask=disable();
    char* buff;
      if(f->state!=FUTURE_EMPTY)
     {
       kprintf("\nfree : Killing all waiting process !");
        while(f->get_queue.count--!=0)
      {
        //released=udp_release(f->slot);
	if(released==SYSERR){
		kprintf("\nFailed to release the UDP slot");
	}
        kill(f->get_queue.fpid[f->get_queue.tail++]);
      }

     while(f->set_queue.count--!=0)
      {
        //released=udp_release(f->slot);
	if(released==SYSERR){
		kprintf("\nFailed to release the UDP slot");
	}
        kill(f->set_queue.fpid[f->set_queue.tail++]);
      }
        
      }

        released=udp_release(slot);
	if(released==SYSERR){
		kprintf("\nFailed to release the UDP slot");
	}
                f->value =0;
		f->state = FUTURE_EMPTY;
		f->get_queue.head = 0;
		f->get_queue.tail = 0;
		f->get_queue.count = 0;
		f->set_queue.head = 0;
		f->set_queue.tail = 0;
		f->set_queue.count = 0;

    buff=freemem((char *)f,sizeof(struct futent));
    if((int32)buff==SYSERR)
{
 restore(mask);
 return SYSERR;
}
         restore(mask);
    return OK;
    
}
