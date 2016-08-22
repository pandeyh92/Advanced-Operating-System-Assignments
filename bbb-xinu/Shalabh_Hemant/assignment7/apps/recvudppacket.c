#include <future.h>
#define OUT_MSG_LENGTH 40
#define IN_MSG_LENGTH 100
#define RCV_TIMEOUT 10000
int recvudppacket(int32 slot){
	
       
	if(slot==SYSERR){
		kprintf("\nFailed to register a udp slot. Exiting");
		return;					
	}
	int i=0;
      
	while(i<1){
                 
		
		char in_msg[IN_MSG_LENGTH]="";
		int status_rcv=udp_recv(slot,&in_msg,IN_MSG_LENGTH,RCV_TIMEOUT);
		if(status_rcv==TIMEOUT){
			kprintf("\nRcv timed out--");
		}
		else if(status_rcv==SYSERR){
				//kprintf("\nError occured while receiving msg %d",status_rcv);
		}			
		else{
			kprintf("\nrcvd msg:%s",in_msg);
                        return 	atoi(in_msg);
		}
		
		i++;	
			
	}
	
}
