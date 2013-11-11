#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resultset.h"

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
