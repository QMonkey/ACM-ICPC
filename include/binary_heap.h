#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stdint.h>

typedef struct binary_heap_s
{
	int *elements;
	uint32_t capacity;
	uint32_t size;
	int (*comparator)(int,int);
} binary_heap_t;

#define BINARY_HEAP_PARENT(idx) (idx >> 1)
#define BINARY_HEAP_LEFT(idx) (idx << 1)
#define BINARY_HEAP_RIGHT(idx) (BINARY_HEAP_LEFT(idx) + 1)

#ifdef __cplusplus
extern "C"
{
#endif

extern binary_heap_t* binary_heap_create(uint32_t size, int (*comparator)(int,int));
extern void binary_heap_resize(binary_heap_t *heap, uint32_t size);
extern void binary_heap_push(binary_heap_t *heap, int elem);
extern void binary_heap_pop(binary_heap_t *heap);
extern int binary_heap_top(binary_heap_t *heap);
extern void binary_heap_destroy(binary_heap_t *heap);

#ifdef __cplusplus
}
#endif

#endif
