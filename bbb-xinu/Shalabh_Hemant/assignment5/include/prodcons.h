
#include "future.h"



extern int n;

extern sid32 consumed, produced;

//void consumer(sid32 , sid32 , int);
//void producer(sid32 , sid32 , int);

void consumer(int);
void producer(int);
int future_prod(future *fut);
int future_cons(future *fut);
