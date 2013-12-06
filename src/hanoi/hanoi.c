#include <stdint.h>
#include <stdio.h>

#include "hanoi.h"

void hanoi(uint32_t level,char *src,char *auxiliary,char *dest)
{
	if(level > 0)
	{
		hanoi(level-1,src,dest,auxiliary);
		fprintf(stdout,"(%s,%s)\n",src,dest);
		hanoi(level-1,auxiliary,src,dest);
	}
}
