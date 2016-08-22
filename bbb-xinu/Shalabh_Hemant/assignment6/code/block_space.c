/* block_space.c - close */

#include<xinu.h>

syscall	block_space()
{
intmask mask;
struct memblk *prev;
char *addr;
mask = disable();
prev = &memlist; /* Walk along free list */
prev = memlist.mnext;
int i=0;
if (prev == NULL)
     		{
		   printf("The free list is empty");
		   restore(mask);
		   return SYSERR;
		}
else
		{
		  while (prev != NULL)
		  {
		  i=i+1; 
		  //addr = getmem(sizeof(struct memblk));
		  printf("\nThe address of block %d is %u and the size of the block is %d\n",i,prev,prev->mlength);
		  prev = prev->mnext;
		  }
		  restore(mask);
		  return OK; 	
		}

}

