#include <stdint.h>
#include <stdio.h>

#include "merge_stones.h"

#define RESULTSET_LENGTH(number) (number*(number+1)>>1)

static int32_t* create_resultset(int32_t number)
{
	return (int32_t*)malloc(sizeof(int32_t) * RESULTSET_LENGTH(number));
}

static void init_resultset(int32_t *resultset,int32_t *begin,int32_t *end)
{
	memcpy(resultset,begin,sizeof(int32_t) * (end - begin));
}

static int32_t index_resultset(int32_t row,int32_t column,int32_t number)
{
	return row * ((number << 1) - row + 1) >> 1;
}

static void destroy_resultset(int32_t *resultset)
{
	free(resultset);
}

int32_t merge_stones(int32_t *begin,int32_t *end,int (*comparator)(int32_t,int32_t))
{
	int32_t number = end - begin;
	int32_t *resultset = create_resultset(number);
	init_resultset(resultset,begin,end);

	int sum = 0;
	while(--number)
	{
	}

	destroy_resultset(resultset);
	return sum;
}
