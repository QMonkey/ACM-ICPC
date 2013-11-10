#ifndef MERGE_STONES
#define MERGE_STONES

#include <stdint.h>

#define DESC	0
#define ASC	1

#ifdef __cplusplus
extern "C"
{
#endif

extern uint32_t merge_stones(uint32_t*,uint32_t*,int (*)(uint32_t,uint32_t));

#ifdef __cplusplus
}
#endif

#endif
