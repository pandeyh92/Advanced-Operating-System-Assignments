#include <xinu.h>

#ifndef NFQ
#define NFQ 	20
#endif

struct fentry{

	pid32 fpid[NFQ];
	int32 head;
	int32 tail;
	int32 count;
};



