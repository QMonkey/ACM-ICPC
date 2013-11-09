#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "partition.h"

static int less(int32_t first,int32_t second)
{
	return first < second ? 1 : (first > second ? -1 : 0);
}

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"No enough parameter.\n");
		exit(1);
	}

	int32_t size = argc - 1;
	int32_t *array = (int32_t*)malloc(sizeof(int32_t) * size);
	int i;
	for(i = 0; i < size; ++i)
	{
		array[i] = atoi(argv[i + 1]);
		fprintf(stdout,"%d ",array[i]);
	}
	fprintf(stdout,"\n");

	partition(array,array+size,less);

	for(i = 0; i < size; ++i)
	{
		fprintf(stdout,"%d ",array[i]);
	}
	fprintf(stdout,"\n");
	
	free(array);
	return 0;
}
