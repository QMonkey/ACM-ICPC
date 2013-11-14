#ifndef MERGE_STONES
#define MERGE_STONES

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern uint32_t merge_stones(uint32_t *begin,uint32_t *end);
extern uint32_t dp_merge_stones(uint32_t *begin,uint32_t *end);

#ifdef __cplusplus
}
#endif

#endif
