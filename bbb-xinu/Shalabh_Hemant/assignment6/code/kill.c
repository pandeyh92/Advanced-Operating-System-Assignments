/* kill.c - kill */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  kill  -  Kill a process and remove it from the system
 *------------------------------------------------------------------------
 */
syscall	kill(
	  pid32		pid		/* ID of process to kill	*/
	)
{
	intmask	mask;			/* Saved interrupt mask		*/
	struct	procent *prptr;		/* Ptr to process' table entry	*/
	int32	i;			/* Index into descriptors	*/
	uint32 *base,len;
	mask = disable();
	if (isbadpid(pid) || (pid == NULLPROC)
	    || ((prptr = &proctab[pid])->prstate) == PR_FREE) {
		restore(mask);
		return SYSERR;
	}

	if (--prcount <= 1) {		/* Last user process completes	*/
		xdone();
	}

	send(prptr->prparent, pid);
	for (i=0; i<3; i++) {
		close(prptr->prdesc[i]);
	}

	//code added for 9.7
	base=(uint32)prptr->prstkbase;
	//kprintf("\n----Inside Kill----\n");
	//kprintf("\n---Current Pid : %d\n",getpid());
	//kprintf("\nStack  base address: %u\n",base);
	len=(uint32)prptr->prstklen;
	while(*base != -99)
	{
	base--;
	}
	kprintf("\nMax Stack position used in memory for process %d till: %u\n",currpid,base);	
	kprintf("\nMax memory space used for process is %d %u\n",currpid,(((uint32*)prptr->prstkbase)-base));
	//code added for 9.7 ends



	//code added for 9.4
	if(prptr->free_flag == 2)
	{
	kprintf("\nStack Memory not released for Process %d\n",currpid );
	kprintf("\nExiting the process having Process ID %d\n",currpid);
	}
	else 
	{
	freestk(prptr->prstkbase, prptr->prstklen);
	}//code added for 9.4 ends
	//freestk(prptr->prstkbase, prptr->prstklen);

	switch (prptr->prstate) {
	case PR_CURR:
		prptr->prstate = PR_FREE;	/* Suicide */
		resched();

	case PR_SLEEP:
	case PR_RECTIM:
		unsleep(pid);
		prptr->prstate = PR_FREE;
		break;

	case PR_WAIT:
		semtab[prptr->prsem].scount++;
		/* Fall through */

	case PR_READY:
		getitem(pid);		/* Remove from queue */
		/* Fall through */

	default:
		prptr->prstate = PR_FREE;
	}

	restore(mask);
	return OK;
}
