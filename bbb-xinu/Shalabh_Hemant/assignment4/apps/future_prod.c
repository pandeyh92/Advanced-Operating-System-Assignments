#include "prodcons.h"

int future_prod(future *fut) 
{
  int i, j=0;
  for (i=0; i<100; i++) 
  {
    j += i;
  }
  if(future_set(fut, &j)!=SYSERR)
 {
   //kprintf("prod : item produced %d \n ",j,fut->tid);
   kprintf("\nprod : item produced %d \n ",j);
 }
 else
{
  return SYSERR;
}
  return OK;
}
