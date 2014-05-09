#include <stdlib.h>
#include <string.h>

#include "binary_heap.h"

static void binary_heap_swim(binary_heap_t *heap, int current);
static void binary_heap_sink(binary_heap_t *heap, int current);

binary_heap_t* binary_heap_create(uint32_t size, int (*comparator)(int,int))
{
	binary_heap_t *heap = (binary_heap_t*)malloc(sizeof(binary_heap_t));
	heap->elements = (int*)malloc(sizeof(int) * size) - 1;
	heap->capacity = 0;
	heap->size = size;
	heap->comparator = comparator;
	return heap;
}

void binary_heap_resize(binary_heap_t *heap, uint32_t size)
{
	if(size > heap->size)
	{
		int *elements = (int*)malloc(sizeof(int) * size);
		++heap->elements;
		memcpy(elements, heap->elements, sizeof(int) * heap->capacity);
		free(heap->elements);
		heap->elements = elements - 1;
		heap->size = size;
	}
}

void binary_heap_swim(binary_heap_t *heap, int current)
{
	if(current > 1)
	{
		int *elements = heap->elements;
		int parent = current >> 1;
	}
}

void binary_heap_sink(binary_heap_t *heap, int current)
{
}

void binary_heap_push(binary_heap_t *heap, int elem)
{
}

void binary_heap_pop(binary_heap_t *heap)
{
}

int binary_heap_top(binary_heap_t *heap)
{
	return heap->elements[1];
}

void binary_heap_destroy(binary_heap_t *heap)
{
	if(heap != NULL)
	{
		free(heap->elements + 1);
		free(heap);
	}
}
