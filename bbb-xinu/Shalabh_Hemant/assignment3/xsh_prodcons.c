#include "prodcons.h"

int n;
sid32 consumed, produced;

shellcmd xsh_prodcons(int nargs, char *args[])
{

	int count,j,k,flag=0;
/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\t n is used as a global variable by both producer and consumer to create & use N values.\n");
		printf("\t Parameter:  a single integer for the value of n is passed as parameter.\n");
		printf("\t Default: A default value of 2000 is used when no parameter is passed.\n");
		return 0;
	}
	
if (nargs > 2) {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		return 1;
	}
	else{ 
		consumed=semcreate(0);
		produced=semcreate(1);
		if (nargs < 2) {
		 		count =2000;
			       }
		else if (nargs == 2) {
		
					count=atoi(args[1]);
					//printf("Without conversion args[1]=%s\n\n", args[1]);
					//printf("after conversion from string to number=%d\n\n", count);
					//printf("initial value of flag=%d\n\n", flag);
        				//printf("length of string %s is=%d for %c\n\n", args[1],strlen(args[1]) );
					for(j=0;j<strlen(args[1]);j++)
					{
	  				k=args[1][j];
	   				//printf(" value of k=%d for %c\n\n", k,args[1][j] );
	  				if((k>=48)&&(k<=57))
					{
					}
	   				else
						flag=1;		

					}
        				//printf("final value of flag=%d\n\n", flag);
					if (flag == 1) 
					{
		  			printf("The current input is =%s and is an invalid input . Please provide only an integer as input or an integer greater than 0.\n\n", args[1]);
		  			return 1;
					}
					else if (flag == 0) 
					{
 						if (count == 0) 
						{
		  				printf("The current input is =%s and is an invalid input . Please provide only an integer as input which is greater than 0.\n\n", args[1]);
		  				return 1;
						}
		 			// resume(create(producer, 1024, 20, "producer", 1, count));
		  			//resume(create(consumer, 1024, 20, "consumer", 1, count));
		  
					}

				    }

		}

//resume(create(producer, 1024, 20, "producer", 3, consumed , produced , count));
//resume(create(consumer, 1024, 20, "consumer", 3, consumed , produced , count));

resume(create(producer, 1024, 20, "producer", 1, count));
resume(create(consumer, 1024, 20, "consumer", 1, count));
//

}
