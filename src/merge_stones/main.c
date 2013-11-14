#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "merge_stones.h"

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"No enough parameter.\n");
		exit(1);
	}

	uint32_t size = argc - 1;
	uint32_t *array = (uint32_t*)malloc(sizeof(uint32_t) * size);
	int i;
	for(i = 0; i < size; ++i)
	{
		array[i] = atoi(argv[i + 1]);
		fprintf(stdout,"%d ",array[i]);
	}
	fprintf(stdout,"\n");

	fprintf(stdout,"%d\n",merge_stones(array,array+size));
	
	free(array);
	return 0;
}
