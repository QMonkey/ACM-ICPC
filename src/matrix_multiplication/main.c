#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix_multiplication.h"

int main(int argc,char **argv)
{
	if(argc < 3)
	{
		fprintf(stderr,"No enough parameters.\n");
		exit(1);
	}

	uint32_t size = argc - 1;
	uint32_t *array = (uint32_t*)malloc(sizeof(uint32_t) * size);
	uint32_t i;
	for(i = 0; i < size; ++i)
	{
		array[i] = atoi(argv[i + 1]);
		fprintf(stdout,"%u ",array[i]);
	}
	fprintf(stdout,"\n");

	fprintf(stdout,"%u\n",min_matrix_multiplication(array,array+size));

	free(array);
	return 0;
}
