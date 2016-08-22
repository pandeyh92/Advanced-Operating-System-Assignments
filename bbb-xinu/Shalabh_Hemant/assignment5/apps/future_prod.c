#include "future.h"

int future_prod(future *fut) 
{
  int i, j=7;
  printf("\nprod : item produced and being sent =%d \n ",j);
  if(future_set(fut, &j)!=SYSERR)
 {
   //kprintf("prod : item produced %d \n ",j,fut->tid);
   kprintf("\nprod : item produced= %d \n ",j);
 }
 else
{
  return SYSERR;
}
  return OK;
}
