#ifndef PARTITION_H
#define PARTITION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern int32_t* partition(int32_t *begin,int32_t *end,int (*comparator)(int32_t,int32_t));

#ifdef __cplusplus
}
#endif

#endif
