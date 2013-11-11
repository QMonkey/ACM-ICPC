#ifndef LCS_H
#define LCS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern uint32_t lcs(char *begin_x,char *end_x,char *begin_y,char *end_y);
extern uint32_t dp_lcs(char *begin_x,char *end_x,char *begin_y,char *end_y);

#ifdef __cplusplus
}
#endif

#endif
