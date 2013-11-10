#include <stdint.h>

#include "select_kth.h"
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

uint32_t closest_point(int32_t *begin,int32_t *end)
{
	if(end - begin < 2)
	{
		return UINT32_MAX;
	}

	int32_t *middle = begin + ((end-begin) >> 1);
	int32_t *kth = select_kth(begin,end,middle - begin + 1,less);

	uint32_t middle_min = most(kth,end,less) - most(begin,kth,greater);
	uint32_t left_min = closest_point(begin,kth);
	uint32_t right_min = closest_point(kth,end);

	return middle_min < left_min ? 
		(middle_min < right_min ? middle_min : right_min) : 
		(left_min < right_min ? left_min : right_min);
}
