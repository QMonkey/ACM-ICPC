#include <stdint.h>

#include "heap.h"

static void swap(uint32_t *first,uint32_t *second);
static void backtrack(uint32_t *begin,uint32_t *end,uint32_t *current);
static void backtrack2(uint32_t *begin,uint32_t *end,uint32_t *current);

void swap(uint32_t *first,uint32_t *second)
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

uint32_t heap_top(uint32_t *begin,uint32_t *end)
{
	return *begin;
}

void backtrack2(uint32_t *begin,uint32_t *end,uint32_t *current)
{
	if(current <= PARENT(begin,end-1))
	{
		uint32_t *lchild = LEFT_CHILD(begin,lchild);
		uint32_t *rchild = RIGHT_CHILD(begin,rchild);
		uint32_t *ptr = current;
		if(lchild < end && *lchild > *current)
		{
			current = lchild;
		}
		if(rchild < end && *rchild > *current)
		{
			current = rchild;
		}
		if(ptr != current)
		{
			swap(ptr,current);
			backtrack2(begin,end,ptr);
		}
	}
}

void heap_pop(uint32_t *begin,uint32_t *end)
{
	*begin = *--end;
	backtrack2(begin,end,begin);
}

void backtrack(uint32_t *begin,uint32_t *end,uint32_t *current)
{
	if(begin != current)
	{
		uint32_t *parent = PARENT(begin,current);
		if(*parent < *current)
		{
			swap(parent,current);
			backtrack(begin,end,parent);
		}
	}
}

void heap_push(uint32_t *begin,uint32_t *end,uint32_t value)
{
	*end++ = value;
	backtrack(begin,end,end - 1);
}
