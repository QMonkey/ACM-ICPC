#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern uint32_t min_matrix_multiplication(uint32_t *begin,uint32_t *end);
extern uint32_t dp_min_matrix_multiplication(uint32_t *begin,uint32_t *end);

#ifdef __cplusplus
}
#endif

#endif
