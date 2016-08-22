#include "prodcons.h"

int n;
void consumer(int count)
{
	int i;
	for( i=1; i<=count ; i++ )
	{
		printf("The value of n consumed is =%d \n", n);
	}

	
}
