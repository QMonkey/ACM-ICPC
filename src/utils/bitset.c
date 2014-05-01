#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bitset.h"

bitset_t* bitset_create(uint32_t bsize)
{
	bitset_t *bset = (bitset_t*)malloc(sizeof(bitset_t));
	bset->size = CEIL(bsize, 8) >> 3;
	bset->data = (char*)malloc(sizeof(char) * bset->size);
	memset(bset->data, 0, sizeof(char) * bset->size);
	return bset;
}

void bitset_resize(bitset_t *bset, uint32_t size)
{
	if(bset->size < size)
	{
		char *tmp = (char*)malloc(sizeof(char) * size);
		memcpy(tmp, bset->data, bset->size);
		free(bset->data);
		bset->data = tmp;
		bset->size = size;
	}
}

void bitset_set(bitset_t *bset, uint32_t bidx)
{
	uint32_t idx = bidx >> 3;
	if(bset->size <= idx)
	{
		bitset_resize(bset, bset->size << 1);
	}
	uint32_t offset = bidx & 7;
	uint8_t mask = 1 << offset;
	bset->data[idx] |= mask;
}

int bitset_isset(bitset_t *bset, uint32_t bidx)
{
	uint32_t idx = bidx >> 3;
	uint32_t offset = bidx & 7;
	uint8_t mask = 1 << offset;
	mask &= bset->data[idx];
	return mask;
}

void bitset_destroy(bitset_t *bset)
{
	if(bset != NULL)
	{
		free(bset->data);
		free(bset);
	}
}
