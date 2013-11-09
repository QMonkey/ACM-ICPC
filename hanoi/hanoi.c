#include <stdint.h>
#include <stdio.h>

#include "hanoi.h"

void hanoi(int32_t level,int src,int auxiliary,int dest)
{
	if(level > 0)
	{
		hanoi(level-1,src,dest,auxiliary);
		fprintf(stdout,"(%d,%d)\n",src,dest);
		hanoi(level-1,auxiliary,src,dest);
	}
}
