#include "prodcons.h"

int future_cons(future *fut) {

 //printf("Inside future consumer\n");
  int i, status;
  status = future_get(fut, &i);
  if (status < 1) {
    printf("\nfuture_get failed\n");
    return -1;
  }
  //kprintf("con : consumed %d %d\n", i,fut->tid);
  kprintf("\ncon : consumed %d \n", i);
  return OK;
}
