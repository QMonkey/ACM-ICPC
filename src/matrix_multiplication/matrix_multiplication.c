#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix_multiplication.h"

typedef struct
{
	uint32_t *resultset;
	int *resultset_flag;
	uint32_t size;
} resultset_t;

static resultset_t* create_resultset(uint32_t size);
static void init_resultset(resultset_t *rs,int value);
static int32_t index_resultset(resultset_t *rs,int32_t x,int32_t y);
static uint32_t get_resultset(resultset_t *rs,int32_t x,int32_t y);
static void set_resultset(resultset_t *rs,int32_t x,int32_t y,uint32_t value);
static int isset_resultset(resultset_t *rs,int32_t x,int32_t y);
static int destroy_resultset(resultset_t *rs);
static uint32_t dp_min_matrix_multiplication4(uint32_t *m_chain,uint32_t *begin,uint32_t *end,resultset_t *rs);

resultset_t* create_resultset(uint32_t size)
{
	uint32_t psize = size * size;
	resultset_t *rs = (resultset_t*)malloc(sizeof(resultset_t));
	rs->resultset = (uint32_t*)malloc(sizeof(uint32_t) * psize);
	rs->resultset_flag = (int*)malloc(sizeof(int) * psize);
	init_resultset(rs,0);
	rs->size = size;
	return rs;
}

void init_resultset(resultset_t *rs,int value)
{
	uint32_t size = rs->size;
	memset(rs->resultset_flag,value,sizeof(int) * size * size);
}

int32_t index_resultset(resultset_t *rs,int32_t x,int32_t y)
{
	return x * rs->size + y;
}

uint32_t get_resultset(resultset_t *rs,int32_t x,int32_t y)
{
	return rs->resultset[index_resultset(rs,x,y)];
}

void set_resultset(resultset_t *rs,int32_t x,int32_t y,uint32_t value)
{
	int32_t index = index_resultset(rs,x,y);
	rs->resultset[index] = value;
	rs->resultset_flag[index] = 1;
}

int isset_resultset(resultset_t *rs,int32_t x,int32_t y)
{
	return rs->resultset_flag[index_resultset(rs,x,y)];
}

int destroy_resultset(resultset_t *rs)
{
	if(rs == NULL)
	{
		return -1;
	}
	free(rs->resultset);
	free(rs->resultset_flag);
	free(rs);
	return 0;
}

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
	if(end - begin < 3)
	{
		int32_t x = begin - m_chain;
		int32_t y = end - m_chain - 1;
		if(!isset_resultset(rs,x,y))
		{
			set_resultset(rs,x,y,0);
		}
		return get_resultset(rs,x,y);
	}

	uint32_t min = UINT32_MAX;
	uint32_t *splitter = NULL;
	uint32_t *splitter_end = end - 1;
	for(splitter = begin + 1; splitter != splitter_end; ++splitter)
	{
		int32_t left_x = begin - m_chain;
		int32_t left_y = splitter - m_chain;
		int32_t right_x = left_y;
		int32_t right_y = end - m_chain - 1;
		if(!isset_resultset(rs,left_x,left_y))
		{
			set_resultset(rs,left_x,left_y,dp_min_matrix_multiplication4(m_chain,begin,splitter + 1,rs));
		}
		if(!isset_resultset(rs,right_x,right_y))
		{
			set_resultset(rs,right_x,right_y,dp_min_matrix_multiplication4(m_chain,splitter,end,rs));
		}
		if(!isset_resultset(rs,left_x,right_y))
		{
			set_resultset(rs,left_x,right_y,*begin * *splitter * *(end - 1));
		}
		uint32_t left_times = get_resultset(rs,left_x,left_y);
		uint32_t right_times = get_resultset(rs,right_x,right_y);
		uint32_t last_times = get_resultset(rs,left_x,right_y);
		uint32_t times = left_times + right_times + last_times;
		if(min > times)
		{
			min = times;
		}
	}

	return min;
}

uint32_t dp_min_matrix_multiplication(uint32_t *begin,uint32_t *end)
{
	resultset_t *rs = create_resultset(end - begin);
	uint32_t res = dp_min_matrix_multiplication4(begin,begin,end,rs);
	destroy_resultset(rs);
	return res;
}
