#ifndef SELECT_KTH_H
#define SELECT_KTH_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern int32_t* select_kth(int32_t *begin,int32_t *end,int32_t k,int (*comparator)(int32_t,int32_t));

#ifdef __cplusplus
}
#endif

#endif
