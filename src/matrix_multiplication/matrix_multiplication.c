#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resultset.h"
#include "matrix_multiplication.h"

uint32_t min_matrix_multiplication(uint32_t *begin,uint32_t *end)
{
	if(end - begin < 3)
	{
		return 0;
	}

	uint32_t min = UINT32_MAX;
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

uint32_t dp_min_matrix_multiplication4(uint32_t *m_chain,uint32_t *begin,uint32_t *end,resultset_t *rs)
{
	int32_t x = begin - m_chain;
	int32_t y = end - m_chain - 1;
	if(y - x < 2)
	{
		return 0;
	}

	uint32_t min = UINT32_MAX;
	uint32_t *splitter = NULL;
	uint32_t *splitter_end = end - 1;
	for(splitter = begin + 1; splitter != splitter_end; ++splitter)
	{
		int32_t splitter_index = splitter - m_chain;
		if(!isset_resultset(rs,x,splitter_index))
		{
			dp_min_matrix_multiplication4(m_chain,begin,splitter + 1,rs);
		}
		if(!isset_resultset(rs,splitter_index,y))
		{
			dp_min_matrix_multiplication4(m_chain,splitter,end,rs);
		}
		uint32_t left_times = get_resultset(rs,x,splitter_index);
		uint32_t right_times = get_resultset(rs,splitter_index,y);
		uint32_t times = left_times + right_times + *begin * *splitter * *(end - 1);
		if(min > times)
		{
			min = times;
		}
	}
	set_resultset(rs,x,y,min);

	return min;
}

uint32_t dp_min_matrix_multiplication(uint32_t *begin,uint32_t *end)
{
	resultset_t *rs = create_resultset(end - begin);
	uint32_t res = dp_min_matrix_multiplication4(begin,begin,end,rs);
	destroy_resultset(rs);
	return res;
}
