#include<xinu.h>
void send_rcv(char *remip_dot,uint32 remport,uint16 locport);

shellcmd xsh_sendrecv (int nargs , char *args[]){
	send_rcv("192.168.1.100",55555,55555);
}
