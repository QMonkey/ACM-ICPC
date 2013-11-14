#include <stdint.h>

#include "heap.h"

static void swap(int32_t *first,int32_t *second);
static void backtrack(int32_t *begin,int32_t *end,int32_t *current);
static void build_heap3(int32_t *begin,int32_t *end,int32_t *current);

void swap(int32_t *first,int32_t *second)
{
	int32_t temp = *first;
	*first = *second;
	*second = temp;
}

void build_heap3(int32_t *begin,int32_t *end,int32_t *current)
{
	if(begin <= current)
	{
		heapify(begin,end,current);
		build_heap3(begin,end,current - 1);
	}
}

void build_heap(int32_t *begin,int32_t *end)
{
	build_heap3(begin,end,PARENT(begin,end-1));
}

void heapify(int32_t *begin,int32_t *end,int32_t *current)
{
	int32_t *lchild = LEFT_CHILD(begin,current);
	int32_t *rchild = RIGHT_CHILD(begin,current);
	int32_t *ptr = current;
	if(lchild < end && *ptr < *lchild)
	{
		ptr = lchild;
	}
	if(rchild < end && *ptr < *rchild)
	{
		ptr = rchild;
	}
	if(ptr != current)
	{
		swap(ptr,current);
		heapify(begin,end,ptr);
	}
}

int32_t heap_top(int32_t *begin,int32_t *end)
{
	return *begin;
}

void heap_pop(int32_t *begin,int32_t *end)
{
	*begin = *--end;
	heapify(begin,end,begin);
}

void backtrack(int32_t *begin,int32_t *end,int32_t *current)
{
	if(begin != current)
	{
		int32_t *parent = PARENT(begin,current);
		if(*parent < *current)
		{
			swap(parent,current);
			backtrack(begin,end,parent);
		}
	}
}

void heap_push(int32_t *begin,int32_t *end,int32_t value)
{
	*end++ = value;
	backtrack(begin,end,end - 1);
}
