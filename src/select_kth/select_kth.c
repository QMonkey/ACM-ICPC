#include <stdint.h>
#include <stdio.h>

#include "partition.h"
#include "select_kth.h"

int32_t* select_kth(int32_t *begin,int32_t *end,int32_t kth,int (*comparator)(int32_t,int32_t))
{
	int32_t *pivot = partition(begin,end,comparator);
	int32_t nth = pivot - begin + 1;
	int32_t *result = NULL;
	if(nth == kth)
	{
		result = pivot;
	}
	else if(nth > kth)
	{
		result = select_kth(begin,pivot,kth,comparator);
	}
	else
	{
		result = select_kth(pivot + 1,end,kth - nth,comparator);
	}
	return result;
}
