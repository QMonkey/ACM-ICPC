#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "closest_point.h"

int main(int argc,char **argv)
{
	if(argc < 3)
	{
		fprintf(stderr,"No enough parameter.\n");
		exit(1);
	}
	uint32_t size = argc - 1;
	int32_t *array = (int32_t*)malloc(sizeof(int32_t) * size);
	int i;
	for(i = 0; i < size; ++i)
	{
		array[i] = atoi(argv[i + 1]);
		fprintf(stdout,"%d ",array[i]);
	}
	fprintf(stdout,"\n");
	fprintf(stdout,"%d\n",closest_point(array,array+size));
	free(array);
	return 0;
}
