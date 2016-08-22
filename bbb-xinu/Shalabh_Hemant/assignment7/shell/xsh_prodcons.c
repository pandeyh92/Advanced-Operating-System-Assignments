#include "future.h"
#include <stdlib.h>
#include <string.h>
int n;
pid32 receiverPID;
int32 slot;                  //Definition for global variable 'n'
/*Now global variable n will be on Heap so it is accessible all the processes i.e. consume and produce*/

shellcmd xsh_prodcons(int nargs, char *args[])
{
     
      int count = 2000;             //local varible to hold count
      int flag=0;
      int len=0;
      int i;
      future *f1, *f2, *f3, *f4;
      
      if(nargs==2)
      {
     	   len=strlen(args[1]);
        	if(strcmp(args[1], "--help", 7)==0)
        	  {
                printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tProducer will produce N values and consumer will consume N values\n");
		printf("\nParameters : one parameter to be pased which has to be a number\n");
                printf("\nDefault : If no argument is passed then a default value of 2000 will get assigned to count\n");
		
		return OK;
        	   }
      		   //printf("String Length %d",len);

      		   if(strcmp(args[1],"-f")==0)
      		  {
      		    //kprintf("it is a future call %s \n",args[1]);
      		    flag=1;
      		  }else
      		  {
      		   for(i=0;i<len;i++)
      		   {
      		     //printf("ascii value %d",(args[1])[i]);
      		     if((args[1])[i]>=48 && (args[1][i])<=57)
      		         {
                 
      		         }
      		        else
      		         {
      		           printf("\n not a number \n");
      		          return SYSERR;
      		         }
		
      		   }
        count=atoi(args[1]);
        printf("\nInitializing Producer and Consumer. Count Passed %d \n",count);

      }
      }
      else if(nargs>2)
      {
        printf("\nToo many arguments : \n");
       return SYSERR;
      }else
      {
        printf("\n Setting default count to 2000\n");
      }
      
      //check args[1] if present assign value to count

      //create the process producer and consumer and put them in ready queue.
      //Look at the definations of function create and resume in exinu/system folder for reference. 

    if(0==flag)
     {     
   	kprintf("\nInvalid input");
  }
     else
    {
      
        
        uint32 remip;
        char ipAdress[]="192.168.1.100";
        dot2ip(ipAdress,&remip);
        slot=udp_register(remip,55555,55555);
        // f1 = future_alloc(FUTURE_EXCLUSIVE);
        f2 = future_alloc(FUTURE_SHARED);
      // f3 = future_alloc(FUTURE_QUEUE);
       receiverPID=currpid;


/* MODE FUTURE_EXCLUSIVE */ 



         
       /*resume( create(future_prod, 1024, 20, "fprod1", 1, f1) );
       resume( create(future_cons, 1024, 20, "fcons1", 1, f1) );
       
        receive();
        future_free(f1);*/
/* MODE FUTURE_SHARED */
        
	resume( create(future_prod, 1024, 20, "fprod1", 1, f2) );
        resume( create(future_cons, 1024, 20, "fcons2", 1, f2) );
        resume( create(future_cons, 1024, 20, "fcons2", 1, f2) );
        resume( create(future_cons, 1024, 20, "fcons3", 1, f2) );
       
	
	receive();
        future_free(f2);

/* MODE FUTURE_QUEUE */

	/*resume( create(future_cons, 1024, 20, "fcons2", 1, f3) );
	resume( create(future_cons, 1024, 20, "fcons2", 1, f3) );	
	resume( create(future_prod, 1024, 20, "fprod1", 1, f3) );
     
	resume( create(future_prod, 1024, 20, "fprod1", 1, f3) );*/
	//resume( create(future_prod, 1024, 20, "fprod1", 1, f3) );
	//resume( create(future_cons, 1024, 20, "fcons2", 1, f3) );
	
        //receive();
        //future_free(f3);
   
        
        /*receive();
        future_free(f1);*/
       //resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );
       //resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );
      //resume( create(future_cons, 1024, 20, "fcons2", 1, f2) ); 
        //receive();
        //future_free(f2);
       
        // resume( create(future_prod, 1024, 20, "fprod3", 1, f3) );
         //resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );
         //resume( create(future_prod, 1024, 20, "fprod3", 1, f3) );
       // resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );
      //  resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );
       // resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );
     //  receive();
      // future_free(f3);

       //resume( create(future_cons, 1024, 20, "fcons1", 1, f4) );
    //   resume( create(future_prod, 1024, 20, "fprod1", 1, f4) );
      // receive();
       //future_free(f4);
    }
      
}





 
