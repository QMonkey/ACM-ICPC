#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "n_queens.h"

static void swap(uint32_t *first,uint32_t *second);
static int is_conflict(uint32_t *begin,uint32_t *current);
static void n_queens3(uint32_t *begin,uint32_t *current,uint32_t *end);

void swap(uint32_t *first,uint32_t *second)
{
	uint32_t tmp = *first;
	*first = *second;
	*second = tmp;
}

void n_queens(uint32_t n)
{
	uint32_t *position = (uint32_t*)malloc(sizeof(uint32_t) * n);
	int i;
	for(i = 0; i < n; ++i)
	{
		position[i] = i;
	}
	n_queens3(position,position,position + n);
}

int is_conflict(uint32_t *begin,uint32_t *current)
{
	int res = 0;
	uint32_t offset = current - begin;
	while(begin != current)
	{
		if(*begin + offset == *current || *begin - offset == *current)
		{
			res = 1;
			break;
		}
		++begin;
		--offset;
	}
	return res;
}

void n_queens3(uint32_t *begin,uint32_t *current,uint32_t *end)
{
	if(current == end)
	{
		int i = 0;
		while(begin != end)
		{
			fprintf(stdout,"(%d,%u)",i++,*begin++);
		}
		fprintf(stdout,"\n");
	}
	else
	{
		uint32_t *scanner = NULL;
		for(scanner = current; scanner != end; ++scanner)
		{
			swap(current,scanner);
			if(!is_conflict(begin,current))
			{
				n_queens3(begin,current + 1,end);
			}
			swap(current,scanner);
		}
	}
}
