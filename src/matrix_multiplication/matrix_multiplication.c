#include <stdint.h>
#include <stdio.h>

#include "matrix_multiplication.h"

#define INFINITY 0xFFFFFFFF

uint32_t min_matrix_multiplication(uint32_t *begin,uint32_t *end)
{
	if(end - begin < 3)
	{
		return 0;
	}

	uint32_t min = INFINITY;
	uint32_t *splitter = NULL;
	uint32_t *splitter_end = end - 1;
	for(splitter = begin + 1; splitter != splitter_end; ++splitter)
	{
		uint32_t times = min_matrix_multiplication(begin,splitter+1) + 
			min_matrix_multiplication(splitter,end) + *begin * *splitter * *(end-1);
		if(min > times)
		{
			min = times;
		}
	}

	return min;
}
