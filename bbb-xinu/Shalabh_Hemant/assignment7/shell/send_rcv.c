#include<xinu.h>
#define OUT_MSG_LENGTH 40
#define IN_MSG_LENGTH 100
#define RCV_TIMEOUT 10000
void send_rcv(char *remip_dot,uint32 remport,uint16 locport){
	uint32 remip;
        char *arr[][20]={"192.168.1.102","192.168.1.103","192.168.1.104","192.168.1.105","192.168.1.106","192.168.1.107","192.168.1.108","192.168.1.109","192.168.1.1010","192.168.1.111"};
        char *portArr[][20]={"50411","50412","50413","50414","50415","50416","50417","50418","50419","50420"};
	dot2ip(remip_dot,&remip);
	int32 slot1=udp_register(remip,remport,locport);
        
        int count=0;
      /*
        while(count<10)
      {
        sleep(2);
        dot2ip(arr[count],&remip);
        udp_register(remip,portArr[count],portArr[count]);
       count++;
      }*/
        
	if(slot1==SYSERR){
		kprintf("\nFailed to register a udp slot. Exiting");
		return;					
	}
	int i=0;
	while(i<1){
                 
		char out_msg[OUT_MSG_LENGTH]="message from xinu";
		int status_send=udp_send(slot1,out_msg,OUT_MSG_LENGTH);
		if(status_send==SYSERR){
			kprintf("\nFailed to send message");		
		}
		else{
		char in_msg[IN_MSG_LENGTH]="";
		int status_rcv=udp_recv(slot1,&in_msg,IN_MSG_LENGTH,RCV_TIMEOUT);
		if(status_rcv==TIMEOUT){
			kprintf("\nRcv timed out--");
		}
		else if(status_rcv==SYSERR){
				kprintf("\nError occured while receiving msg");
		}			
		else{
			kprintf("\nrcvd msg:%s",in_msg);		
		}
                  
		}
		i++;	
			
	}
	int released=udp_release(slot1);
    

	if(released==SYSERR){
		kprintf("\nFailed to release the UDP slot");
	}
}
