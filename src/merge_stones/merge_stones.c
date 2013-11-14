#include <stdint.h>
#include <stdio.h>

#include "resultset.h"
#include "merge_stones.h"

static uint32_t sum(uint32_t *begin,uint32_t *end);
static uint32_t dp_sum(uint32_t *numbers,uint32_t *begin,uint32_t *end,resultset_t *srs);
static uint32_t dp_merge_stones4(uint32_t *stones,uint32_t *begin,uint32_t *end,
		resultset_t *rs,resultset_t *srs);

static uint32_t sum(uint32_t *begin,uint32_t *end)
{
	uint32_t res;
	if(begin == end)
	{
		res = 0;
	}
	else
	{
		res = *begin + sum(begin + 1,end);
	}
	return res;
}

uint32_t merge_stones(uint32_t *begin,uint32_t *end)
{
	uint32_t res;
	if(end - begin < 2)
	{
		res = 0;
	}
	else
	{
		res = 0;
		uint32_t *splitter = NULL;
		for(splitter = begin + 1; splitter != end; ++splitter)
		{
			uint32_t tmpres = merge_stones(begin,splitter) + 
				merge_stones(splitter,end) + sum(begin,end);
			if(res < tmpres)
			{
				res = tmpres;
			}
		}
	}
	return res;
}

static uint32_t dp_sum(uint32_t *numbers,uint32_t *begin,uint32_t *end,resultset_t *srs)
{
	int32_t x = begin - numbers;
	int32_t y = end - numbers - 1;
	uint32_t res;
	if(begin == end)
	{
		res = 0;
	}
	else
	{
		if(!isset_resultset(srs,x + 1,y))
		{
			dp_sum(numbers,begin + 1,end,srs);
		}
		res = *begin + get_resultset(srs,x + 1,y);
	}
	set_resultset(srs,x,y,res);
	return res;
}

static uint32_t dp_merge_stones4(uint32_t *stones,uint32_t *begin,uint32_t *end,
		resultset_t *rs,resultset_t *srs)
{
	int32_t x = begin - stones;
	int32_t y = end - stones - 1;
	uint32_t res;
	if(end - begin < 2)
	{
		res = 0;
	}
	else
	{
		res = 0;
		uint32_t *splitter = NULL;
		for(splitter = begin + 1; splitter != end; ++splitter)
		{
			int32_t splitter_index = splitter - stones - 1;
			if(!isset_resultset(rs,x,splitter_index))
			{
				dp_merge_stones4(stones,begin,splitter,rs,srs);
			}
			if(!isset_resultset(rs,splitter_index + 1,y))
			{
				dp_merge_stones4(stones,splitter,end,rs,srs);
			}
			uint32_t tmpres = get_resultset(rs,x,splitter_index) + 
				get_resultset(rs,splitter_index + 1,y) + dp_sum(stones,begin,end,srs);
			if(res < tmpres)
			{
				res = tmpres;
			}
		}
	}
	set_resultset(rs,x,y,res);
	return res;
}

uint32_t dp_merge_stones(uint32_t *begin,uint32_t *end)
{
	uint32_t size = end - begin;
	resultset_t *rs = create_resultset(size);
	resultset_t *srs = create_resultset(size);
	uint32_t res = dp_merge_stones4(begin,begin,end,rs,srs);
	destroy_resultset(rs);
	return res;
}
