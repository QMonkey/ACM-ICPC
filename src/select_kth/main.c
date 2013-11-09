#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "select_kth.h"

static int greater(int32_t first,int32_t second)
{
	return first > second ? 1 : (first < second ? -1 : 0);
}

int main(int argc,char **argv)
{
	if(argc < 3)
	{
		fprintf(stderr,"No enough parameter.\n");
		exit(1);
	}
	int32_t size = argc - 2;
	int32_t *array = (int32_t*)malloc(sizeof(int32_t) * (size));
	int i;
	for(i = 0; i < size; ++i)
	{
		array[i] = atoi(argv[i + 2]);
	}
	int k = atoi(argv[i + 1]);
	fprintf(stdout,"%d\n",*select_kth(array,array + size,k,greater));
	free(array);
	return 0;
}
