#include "prodcons.h"

int n;
sid32 consumed, produced;

shellcmd xsh_prodcons(int nargs, char *args[])
{



	int count,j,k,flag=0,curr=3;
/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\t To view Future implementations via system calls please provide -f option.\n");
		printf("\t Parameter:  The future value and the mode of the future are passed as parameters.\n");
		printf("\t Default: A default value of 2000 is used when no parameter is passed and all the values aare printed till 2000.\n");
		return 0;
	}
	else if (nargs == 2 && (strcmp(args[1], "-f") == 0))
	{
		curr=4;
	}
if (nargs > 2) {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		return 1;
		}
	else{ 
		if (nargs < 2) 
				{
		 		count =2000;
			        }
		else if (nargs == 2) {
					count=atoi(args[1]);
					for(j=0;j<strlen(args[1]);j++)
					{
	  				k=args[1][j];
	   				if((k>=48)&&(k<=57))
					  {
					  }
	   				else
						flag=1;		

					}
        				if ((flag == 1)&&(curr == 3)) 
					  {
		  			   printf("The current input is =%s and is an invalid input . Please provide only an integer as input or an integer greater than 0.\n\n", args[1]);
		  			   return 1;
					  }
					else if ((flag == 0)&&(curr == 3))
					{
 						if (count == 0) 
						{
		  				printf("The current input is =%s and is an invalid input . Please provide only an integer as input which is greater than 0.\n\n", args[1]);
		  				return 1;
						}
		 			}

				    }



		}
if(curr == 3)
	{
	consumed=semcreate(0);
	produced=semcreate(1);
	resume(create(producer, 1024, 20, "producer", 1, count));
	resume(create(consumer, 1024, 20, "consumer", 1, count));
	}
else if(curr == 4)
	{
		future *f1, *f2, *f3;
   		f1 = future_alloc(FUTURE_EXCLUSIVE);
		
  		f2 = future_alloc(1);
  		f3 = future_alloc(1);
 		
  		resume( create(future_prod, 1024, 20, "fprod1", 1, f1) );
                resume( create(future_cons, 1024, 20, "fcons1", 1, f1) );
                 resume( create(future_cons, 1024, 20, "fcons1", 1, f1) );
                resume( create(future_cons, 1024, 20, "fcons1", 1, f1) );

  		resume( create(future_cons, 1024, 20, "fcons2", 1, f2) );
  		resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );
  		resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );
                resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );

  		resume( create(future_prod, 1024, 20, "fprod3", 1, f3) );
                resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );







	}


}
