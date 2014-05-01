#include <stdio.h>
#include <stdlib.h>

#include "bitset.h"

int main()
{
	int n = 50;
	bitset_t *bset = bitset_create(n);

	int i;
	for(i = n - 1; i != -1; --i)
	{
		bitset_set(bset, i);
	}

	for(i = 0; i != 50; ++i)
	{
		if(bitset_isset(bset, i))
		{
			fprintf(stdout, "%d\n", i);
		}
	}

	bitset_destroy(bset);
	return 0;
}
