/* future_alloc.c - close */

#include "prodcons.h"
future *future_alloc(int future_flag)
{
  if(future_flag != FUTURE_EXCLUSIVE)
       {
		return NULL;
       } 
   future *alloc=getmem(sizeof(future));
   alloc->state=FUTURE_EMPTY;
   alloc->flag=future_flag;
   alloc->value=0;
   return alloc;
}
