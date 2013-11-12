#include <stdint.h>

#include "heap.h"

static swap(uint32_t *first,uint32_t *second);

static swap(uint32_t *first,uint32_t *second)
{
	uint32_t temp = *first;
	*first = *second;
	*second = temp;
}

void build_heap(uint32_t *begin,uint32_t *end)
{
	if(begin < end)
	{
		heapify(begin,end,PARENT(begin,end - 1));
		build_heap(begin,end - 2);
	}
}

void heapify(uint32_t *begin,uint32_t *end,uint32_t *current)
{
	if(begin <= current)
	{
		uint32_t *lchild = LEFT_CHILD(begin,current);
		uint32_t *rchild = RIGHT_CHILD(begin,current);
		uint32_t *ptr = current;
		if(lchild < end && *lchild > *ptr)
		{
			ptr = lchild;
		}
		if(rchild < end && *rchild > *ptr)
		{
			ptr = rchild;
		}
		if(ptr != current)
		{
			swap(ptr,current);
			heapify(begin,end,PARENT(begin,current));
		}
	}
}
