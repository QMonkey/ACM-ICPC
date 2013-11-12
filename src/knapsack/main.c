#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "knapsack.h"

int main(int argc,char **argv)
{
	if((argc & 1) != 0 || argc < 4)
	{
		fprintf(stdout,"Error input.\n");
		exit(1);
	}

	uint32_t kweight = atoi(argv[1]);
	fprintf(stdout,"%u\n",kweight);
	uint32_t size = (argc - 2) >> 1;
	item_t *item_list = (item_t*)malloc(sizeof(item_t) * size);
	int i;
	for(i = 0; i < size; ++i)
	{
		item_t *item = item_list + i;
		item->weight = atoi(argv[(i<<1)+2]);
		item->value = atoi(argv[(i<<1)+3]);
		fprintf(stdout,"%u\t%u\n",item->weight,item->value);
	}
	fprintf(stdout,"%u\n",zero_one_knapsack(item_list,item_list+size,kweight));
	fprintf(stdout,"%u\n",dp_zero_one_knapsack(item_list,item_list+size,kweight));

	free(item_list);
	return 0;
}
