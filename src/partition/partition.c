#include <stdint.h>

#include "partition.h"

int32_t* partition(int32_t *begin,int32_t *end,int (*comparator)(int32_t,int32_t))
{
	int32_t key = *begin;
	--end;
	while(1)
	{
		while(begin != end && comparator(*end,key) < 0)
		{
			--end;
		}
		if(begin == end)
		{
			break;
		}
		*begin++ = *end;
		while(begin != end && comparator(*begin,key) > 0)
		{
			++begin;
		}
		if(begin == end)
		{
			break;
		}
		*end-- = *begin;
	}
	*begin = key;
	return begin;
}
