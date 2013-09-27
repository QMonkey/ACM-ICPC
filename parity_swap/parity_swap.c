#include "stdint.h"
#include "parity_swap.h"

void parity_swap(int32_t *start,int32_t *end)
{
	--end;
	while(1)
	{
		while(start != end && (*start & 1) == 1)
		{
			++start;
		}
		while(start != end && (*end & 1) == 0)
		{
			--end;
		}
		if(start == end)
		{
			break;
		}
		int32_t tmp = *start;
		*start = *end;
		*end = tmp;
	}
}
