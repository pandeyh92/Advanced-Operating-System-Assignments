#include<xinu.h>

#ifndef NMAX
#define NMAX 10
#endif

struct futque{
int head;
int tail;
int count;
pid32 futqueue[NMAX];
};
