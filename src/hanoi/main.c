#include <stdio.h>
#include <stdlib.h>

#include "hanoi.h"

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"No enough parameter.\n");
		exit(1);
	}
	hanoi(atoi(argv[1]),"a","b","c");
	return 0;
}
