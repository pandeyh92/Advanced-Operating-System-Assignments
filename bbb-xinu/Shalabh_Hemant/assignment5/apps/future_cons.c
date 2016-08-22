#include "future.h"

int future_cons(future *fut) {
intmask mask;
mask=disable();
 //printf("Inside future consumer\n");
  int i, status;
  status = future_get(fut, &i);
  if (status < 1) {
    printf("\nfuture_get failed\n");
    restore(mask); 	
    return -1;
  }
  //kprintf("con : consumed %d %d\n", i,fut->tid);
  kprintf("\ncon : consumed %d \n", i);
  restore(mask);
  return OK;
}
