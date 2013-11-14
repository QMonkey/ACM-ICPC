#include <stdint.h>
#include <stdio.h>

#include "heap.h"
#include "select_kth_heap.h"

void adjust(int32_t *begin,int32_t *heap_end,int32_t *current,int32_t *end)
{
	if(current != end)
	{
		if(*current < heap_top(begin,heap_end))
		{
			heap_pop(begin,heap_end);
			heap_push(begin,heap_end-1,*current);
		}
		adjust(begin,heap_end,current + 1,end);
	}
}

int32_t select_kth_heap(int32_t *begin,int32_t *end,uint32_t kth)
{
	int32_t *heap_end = begin + kth;
	build_heap(begin,heap_end);
	adjust(begin,heap_end,heap_end,end);
	return heap_top(begin,heap_end);
}
