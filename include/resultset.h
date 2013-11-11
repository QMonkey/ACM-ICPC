#ifndef RESULTSET_H
#define RESULTSET_H

#include <stdint.h>

typedef struct
{
	uint32_t *resultset;
	int *resultset_flag;
	uint32_t size;
} resultset_t;

#ifdef __cplusplus
extern "C"
{
#endif

extern resultset_t* create_resultset(uint32_t size);
extern void init_resultset(resultset_t *rs,int value);
extern int32_t index_resultset(resultset_t *rs,int32_t x,int32_t y);
extern uint32_t get_resultset(resultset_t *rs,int32_t x,int32_t y);
extern void set_resultset(resultset_t *rs,int32_t x,int32_t y,uint32_t value);
extern int isset_resultset(resultset_t *rs,int32_t x,int32_t y);
extern int destroy_resultset(resultset_t *rs);
extern uint32_t dp_min_matrix_multiplication4(uint32_t *m_chain,uint32_t *begin,uint32_t *end,resultset_t *rs);

#ifdef __cplusplus
}
#endif

#endif
