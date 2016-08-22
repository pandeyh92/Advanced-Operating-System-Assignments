#include<xinu.h>

void table()
{
intmask mask;
mask = disable();
struct procent *prptr;
kprintf("\nInside the child process having Process ID= %d\n",currpid);
block_space();
//for the child process
prptr= &proctab[currpid];
prptr->free_flag=2;
//kprintf("\nExiting the child process having Process ID= %d\n",currpid);
restore(mask);
}
