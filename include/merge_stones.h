#ifndef MERGE_STONES
#define MERGE_STONES

#include <stdint.h>

#define DESC	0
#define ASC	1

#ifdef __cplusplus
extern "C"
{
#endif

extern int32_t merge_stones(int32_t*,int32_t*,int (*)(int32_t,int32_t));

#ifdef __cplusplus
}
#endif

#endif
