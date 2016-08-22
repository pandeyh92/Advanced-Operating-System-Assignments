#include <future.h>
#define OUT_MSG_LENGTH 40
#define IN_MSG_LENGTH 100
#define RCV_TIMEOUT 10000
void sendudppacket(int32 slot,char* message){
	
	if(slot==SYSERR){
		kprintf("\nFailed to register a udp slot. Exiting");
		return;					
	}
	int i=0;
       
	while(i<1){
                 
                if(strlen(message)>OUT_MSG_LENGTH)
                {
                   return SYSERR;
                }
		int status_send=udp_send(slot,message,strlen(message));
                kprintf("\n messgae sent to linux:");
		if(status_send==SYSERR){
			kprintf("\nFailed to send message");		
		}
		i++;
			
	}
	/*int released=udp_release(slot);
	if(released==SYSERR){
		kprintf("\nFailed to release the UDP slot");
	}*/
}
