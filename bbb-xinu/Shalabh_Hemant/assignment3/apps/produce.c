#include "prodcons.h"

int n;
//void producer(sid32 consumed , sid32 produced , int count)
void producer(int count)
{
	int i;
        // printf("The default value of n in producer is =%d \n", n);
	for( i=1; i<=count ; i++ )
	{
		wait(consumed);
		n=i;
		signal(produced);
		printf("The value of n produced is =%d \n", n);
	}

	
}
