#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <stdint.h>

typedef struct
{
	uint32_t weight;
	uint32_t value;
} item_t;

#define ITEMWEIGHT(item) (item->weight)
#define ITEMVALUE(item) (item->value)

#ifdef __cplusplus
extern "C"
{
#endif

extern item_t* create_item(uint32_t weight,uint32_t value);
extern int destroy_item(item_t *item);
extern uint32_t zero_one_knapsack(item_t *begin,item_t *end,uint32_t kweight);
extern uint32_t dp_zero_one_knapsack(item_t *begin,item_t *end,uint32_t kweight);

#ifdef __cplusplus
}
#endif

#endif
