#ifndef BITSET_H
#define BITSET_H

#include <stdint.h>

typedef struct bitset_s bitset_t;

struct bitset_s
{
	char *data;
	uint32_t size;
};

#define CEIL(number, base) ((number + base - 1) & ~(base - 1))

#ifdef __cplusplus
extern "C"
{
#endif

extern bitset_t* bitset_create(uint32_t size);
extern void bitset_set(bitset_t *bset, uint32_t bidx);
extern int bitset_isset(bitset_t *bset, uint32_t bidx);
extern void bitset_resize(bitset_t *bset, uint32_t size);
extern void bitset_destroy(bitset_t *bset);

#ifdef __cplusplus
}
#endif

#endif
