#include "memmontr.h"
/*#include <stdlib.h>
#include <string.h>*/
int n;   //Definition for global variable 'n'
pid32 receiverPID;  
               
/*Now global variable n will be on Heap so it is accessible all the processes i.e. consume and produce*/

shellcmd xsh_monitor(int nargs, char *args[])
{
      //Argument verifications and validations

      int count=0;
      int len=0;
      int i;
      if(2==nargs)
      {
        len=strlen(args[1]);
        if(strcmp(args[1], "--help", 7)==0)
          {
                printf("\nUsage: %s\n\n", args[0]);
		printf("\nDescription:");
		printf("\nType 1 to execute 9.1");
		printf("\nType 2 to execute 9.4");
                printf("\nType 3 to execute 9.7");
		
		return 0;
           }
         //printf("String Length %d",len);
         for(i=0;i<len;i++)
         {
           //printf("ascii value %d",(args[1])[i]);
           if((args[1])[i]>=48 && (args[1][i])<=57)
               {
                 
               }
              else
               {
                 printf("\n not a number \n");
                return 1;
               }

         }
        count=atoi(args[1]);
       
      }
      else if(nargs>2)
      {
        printf("\nToo many arguments : \n");
       return 1;
      }else
      {
        printf("\n Please refer help\n");
      }
      
      switch(count)
    {
       case 1 :
		{
       kprintf("\n executing 9.1");
	block_space();
	//list_free();

        break;};
     case 2 :
	{
        kprintf("\n executing 9.4");
	struct procent *prptr;
	kprintf("\nInside the main process having Process ID= %d\n",currpid);
	//for the parent process
	prptr= &proctab[currpid];
	prptr->free_flag=2;
	kprintf("\n Before calling the child process , space statistics are :- \n");
	block_space();
	resume(create(table, 1024, 20, "table",0));
	resume(create(table, 1024, 20, "table",0));
	getmem_new(2048);
	kprintf("\n Before exiting the main process , final space statistics are :- \n");
	block_space();
	//get_size_stack(prid);
        break;
	};
       case 3 :
       kprintf("\n executing 9.7");
	kprintf("\nInside the main process having Process ID= %d\n",currpid);
       kprintf("\n Before calling the process , space statistics are:-\n");
	block_space();
	//resume(create2(table2, 1024, 20, "table2", 1,5));
	  resume(create(table2, 1024, 20, "table2", 1,5));
	  kprintf("\n Before exiting the main process , final space statistics are:- \n");
	  block_space();	
        break;
    }      
} 
