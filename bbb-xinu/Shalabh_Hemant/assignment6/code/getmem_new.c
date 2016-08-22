/* getmem_new.c - getmem */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  getmem_new  -  Allocate heap storage, returning lowest word address
 *------------------------------------------------------------------------
 */
char  	*getmem_new(
	  uint32	nbytes		/* Size of memory requested	*/
	)
{
		intmask	mask;			/* Saved interrupt mask		*/
	struct	memblk	*prev, *curr, *leftover;

	mask = disable();
	if (nbytes == 0) {
		restore(mask);
		return (char *)SYSERR;
	}

	nbytes = (uint32) roundmb(nbytes);	/* Use memblk multiples	*/

	prev = &memlist;
	curr = memlist.mnext;
	
	 if (curr->mlength >= nbytes) { /* Split big block	*/
			leftover = (struct memblk *)((uint32) curr +
					nbytes);
			prev->mnext = leftover;
			leftover->mnext = curr->mnext;
			leftover->mlength = curr->mlength - nbytes;
			memlist.mlength -= nbytes;
			kprintf("\nInside getmem_new Heap Memory being allocated is %d to process %d\n",nbytes,currpid);
			restore(mask);
			return (char *)(curr);
		} 
	restore(mask);
	return (char *)SYSERR;	
}
