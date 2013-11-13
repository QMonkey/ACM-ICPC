#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>

#define NTH(begin,current) ((current)-(begin) + 1)
#define INDEX_PARENT(begin,current) ((NTH(begin,current) >> 1) - 1)
#define INDEX_LEFT(begin,current) ((NTH(begin,current) << 1) - 1)
#define PARENT(begin,current) (INDEX_PARENT(begin,current) + (begin))
#define LEFT_CHILD(begin,current) (INDEX_LEFT(begin,current) + (begin))
#define RIGHT_CHILD(begin,current) (LEFT_CHILD(begin,current) + 1)

#ifdef __cplusplus
extern "C"
{
#endif

extern void build_heap(uint32_t *begin,uint32_t *end);
extern void heapify(uint32_t *begin,uint32_t *end,uint32_t *current);
extern uint32_t heap_top(uint32_t *begin,uint32_t *end);
extern void heap_pop(uint32_t *begin,uint32_t *end);
extern void heap_push(uint32_t *begin,uint32_t *end,uint32_t value);

#ifdef __cplusplus
}
#endif

#endif
