#include "prodcons.h"

int n;
//void consumer(sid32 consumed , sid32 produced , int count)
void consumer(int count)
{
	int i;
	for( i=1; i<=count ; i++ )
	{
		wait(produced);
		//n=i;
		printf("The value of n consumed is =%d \n", n);
		signal(consumed);
		
	}

//printf("\n Value of semaphore produced before deletion is %d", produced);
//printf("\n Value of semaphores consumed before deletion is %d", consumed);
//semdelete(produced);
//semdelete(consumed);
//printf("\n Value of semaphore produced after deletion is %d", produced);
//printf("\n Value of semaphores consumed after deletionis %d", consumed);
//printf("\n semphores deleted");

	
}
