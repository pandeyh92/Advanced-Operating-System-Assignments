#include "prodcons.h"

int n;
void producer(int count)
{
	int i;
        // printf("The default value of n in producer is =%d \n", n);
	for( i=1; i<=count ; i++ )
	{
		n=i;
		printf("The value of n produced is =%d \n", n);
	}

	
}
