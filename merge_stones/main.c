#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "merge_stones.h"

static int isGreater(int32_t first,int32_t second)
{
	return first > second ? 1 : (first == second ? 0 : -1);
}

static int isLess(int32_t first,int32_t second)
{
	return first < second ? 1 : (first == second ? 0 : -1);
}

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"No enough parameters.\n");
		exit(1);
	}

	int32_t *array = (int32_t*)malloc(sizeof(int32_t)*argc);
	int i;
	for(i = 1; i < argc; ++i)
	{
		array[i] = atoi(argv[i]);
	}
	array[0] = array[argc-1];

	fprintf(stdout,"%d  %d\n",merge_stones(array+1,array+argc,isLess),
		merge_stones(array+1,array+argc,isGreater));
	fprintf(stdout,"%d  %d\n",merge_stones(array,array+argc,isLess),
		merge_stones(array,array+argc,isGreater));

	return 0;
}
