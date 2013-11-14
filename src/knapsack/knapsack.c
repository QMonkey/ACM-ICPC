#include <stdint.h>
#include <stdio.h>

#include "resultset.h"
#include "knapsack.h"

static uint32_t dp_zero_one_knapsack5(item_t *items,item_t *begin,item_t *end,
		uint32_t kweight,resultset_t *rs);

item_t* create_item(uint32_t weight,uint32_t value)
{
	item_t *item = (item_t*)malloc(sizeof(item_t));
	item->weight = weight;
	item->value = value;
	return item;
}

int destroy_item(item_t *item)
{
	free(item);
}

uint32_t zero_one_knapsack(item_t *begin,item_t *end,uint32_t kweight)
{
	uint32_t res;
	if(begin == end || kweight == 0)
	{
		res = 0;
	}
	else
	{
		res = zero_one_knapsack(begin + 1,end,kweight);
		if(ITEMWEIGHT(begin) <= kweight)
		{
			uint32_t tmpres = ITEMVALUE(begin) + 
				zero_one_knapsack(begin + 1,end,kweight - ITEMWEIGHT(begin));
			if(res < tmpres)
			{
				res = tmpres;
			}
		}
	}
	return res;
}

static uint32_t dp_zero_one_knapsack5(item_t *items,item_t *begin,item_t *end,
		uint32_t kweight,resultset_t *rs)
{
	int32_t x = begin - items;
	int32_t y = kweight;
	uint32_t res;
	if(begin == end || kweight == 0)
	{
		res = 0;
	}
	else
	{
		if(!isset_resultset(rs,x + 1,y))
		{
			dp_zero_one_knapsack5(items,begin + 1,end,kweight,rs);
		}
		res = get_resultset(rs,x + 1,y);
		if(ITEMWEIGHT(begin) <= kweight)
		{
			if(!isset_resultset(rs,x + 1,y - ITEMWEIGHT(begin)))
			{
				dp_zero_one_knapsack5(items,begin + 1,end,kweight - ITEMWEIGHT(begin),rs);
			}
			uint32_t tmpres = ITEMVALUE(begin) + 
				get_resultset(rs,x + 1,y - ITEMWEIGHT(begin));
			if(res < tmpres)
			{
				res = tmpres;
			}
		}
	}
	set_resultset(rs,x,y,res);
	return res;
}

uint32_t dp_zero_one_knapsack(item_t *begin,item_t *end,uint32_t kweight)
{
	uint32_t size = end - begin;
	resultset_t *rs = create_resultset(size * kweight);
	uint32_t res = dp_zero_one_knapsack5(begin,begin,end,kweight,rs);
	destroy_resultset(rs);
	return res;
}

uint32_t knapsack(item_t *begin,item_t *end,uint32_t kweight)
{
}
