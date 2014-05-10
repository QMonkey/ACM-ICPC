#include <stdint.h>
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
		int parent = BINARY_HEAP_PARENT(current);
		if(!heap->comparator(elements[parent], elements[current]))
		{
			int tmp = elements[parent];
			elements[parent] = elements[current];
			elements[current] = tmp;

			binary_heap_swim(heap, parent);
		}
	}
}

void binary_heap_sink(binary_heap_t *heap, int current)
{
	uint32_t end = heap->capacity >> 1;
	if(current <= end)
	{
		int *elements = heap->elements;
		uint32_t left = BINARY_HEAP_LEFT(current);
		uint32_t right = BINARY_HEAP_RIGHT(current);
		uint32_t idx = current;
		if(!heap->comparator(elements[idx], elements[left]))
		{
			idx = left;
		}
		if(right <= end && !heap->comparator(elements[idx], elements[right]))
		{
			idx = right;
		}
		if(idx != current)
		{
			int tmp = elements[idx];
			elements[idx] = elements[current];
			elements[current] = tmp;

			binary_heap_sink(heap, idx);
		}
	}
}

void binary_heap_push(binary_heap_t *heap, int elem)
{
	if(heap->capacity == heap->size)
	{
		binary_heap_resize(heap, heap->size << 1);
	}
	heap->elements[++heap->capacity] = elem;
	binary_heap_swim(heap, heap->capacity);
}

void binary_heap_pop(binary_heap_t *heap)
{
	if(heap->capacity > 0)
	{
		int *elements = heap->elements;
		elements[1] = elements[heap->capacity--];
		binary_heap_sink(heap, 1);
	}
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
