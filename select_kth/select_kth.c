#include <stdint.h>

#include "partition.h"
#include "select_kth.h"

int32_t* select_kth(int32_t *begin,int32_t *end,int32_t k,int (*comparator)(int32_t,int32_t))
{
	int32_t *pivot = partition(begin,end,comparator);
	int32_t distance = pivot - begin;
	int32_t *result = NULL;
	if(distance == k)
	{
		result = pivot;
	}
	else if(distance > k)
	{
		result = select_kth(begin,pivot,k,comparator);
	}
	else
	{
		result = select_kth(pivot + 1,end,k - distance,comparator);
	}
	return result;
}
