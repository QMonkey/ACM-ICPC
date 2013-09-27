#include <stdio.h>
#include <stdlib.h>
#include "parity_swap.h"

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"No enough parameters.");
		exit(1);
	}

	int32_t *array = (int32_t*)malloc(sizeof(int32_t)*(--argc));
	int32_t i;
	for(i = 0; i < argc; ++i)
	{
		array[i] = atoi(argv[i+1]);
	}

	parity_swap(array,array+argc);

	for(i = 0; i < argc; ++i)
	{
		fprintf(stdout,"%d ",array[i]);
	}
	fprintf(stdout,"\n");

	return 0;
}
