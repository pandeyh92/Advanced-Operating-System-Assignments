/* getstk_new.c - getstk */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  getstk  -  Allocate stack memory, returning highest word address
 *------------------------------------------------------------------------
 */
char  	*getstk_new(
	  uint32	nbytes		/* Size of memory requested	*/
	)
{
	intmask	mask;			/* Saved interrupt mask		*/
	struct	memblk *curr;		/* Walk through memory list	*/

	mask = disable();

	if (nbytes == 0) {
		restore(mask);
		return (char *)SYSERR;
	}

	nbytes = (uint32) roundmb(nbytes);	/* Use mblock multiples	*/

	curr = &memlist;
	curr = memlist.mnext;


 	if (curr->mlength >= nbytes)
	{
		curr->mlength -= nbytes;
		curr = (struct memblk *)((uint32)curr + curr->mlength);
	        memlist.mlength -= nbytes;
		restore(mask);
		return (char *)((uint32) curr + nbytes - sizeof(uint32));
	}
	else
	{			/* No block was found	*/
		restore(mask);
		return (char *)SYSERR;
	}
}
