#include <stdint.h>

#include "closest_point.h"

static int32_t most(int32_t *begin,int32_t *end,int (*comparator)(int32_t,int32_t))
{
	int32_t result = *begin++;
	while(begin != end)
	{
		if(comparator(*begin,result) > 0)
		{
			result = *begin;
		}
		++begin;
	}
	return result;
}

static int greater(int32_t first,int32_t second)
{
	return first > second ? 1 : (first < second ? -1 : 0);
}

static int less(int32_t first,int32_t second)
{
	return first < second ? 1 : (first > second ? -1 : 0);
}

int32_t closest_point(int32_t *begin,int32_t *end)
{
	int32_t *middle = begin + ((end-begin) >> 1);
}
