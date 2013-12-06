#ifndef HANOI_H
#define HANOI_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern void hanoi(uint32_t level,char *src,char *auxiliary,char *dest);

#ifdef __cplusplus
}
#endif

#endif
