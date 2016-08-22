#include "fqueue.h"

#ifndef _FUTURE_H
#define _FUTURE_H
 
/* define states */
#define FUTURE_EMPTY	  0
#define FUTURE_WAITING 	  1         
#define FUTURE_VALID 	  2         

/* modes of operation for future*/
#define FUTURE_EXCLUSIVE  1	
#define FUTURE_SHARED     2	    
#define FUTURE_QUEUE      3  	

typedef struct futent{
   int value;		
   int flag;		
   int state;         	
   pid32 tid;
   //int32 slot;
   struct fentry set_queue;
   struct fentry get_queue;
} future;

/* Interface for system call */
future* future_alloc(int future_flags);
syscall future_free(future*);
syscall future_get(future*, int*);
syscall future_set(future*, int*);
 
#endif /* _FUTURE_H_ */


extern pid32 receiverPID;
extern int32 slot;
int future_cons(future *);
int future_prod(future *);
int recvudppacket(int32 slot);
void sendudppacket(int32 slot,char* message);

