#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "insertion_sort.h"

static void insertion_sort3(int32_t *sorted_begin,int32_t *unsorted_begin,int32_t *unsorted_end);

void insertion_sort3(int32_t *sorted_begin,int32_t *unsorted_begin,int32_t *unsorted_end)
{
	if(unsorted_begin != unsorted_end)
	{
		int32_t *scanner = NULL;
		int32_t value = *unsorted_begin;
		for(scanner = unsorted_begin - 1; scanner >= sorted_begin && 
				*scanner > value; --scanner)
		{
			*(scanner + 1) = *scanner;
		}
		*++scanner = value;
		insertion_sort3(sorted_begin,unsorted_begin + 1,unsorted_end);
	}
}

void insertion_sort(int32_t *begin,int32_t *end)
{
	insertion_sort3(begin,begin + 1,end);
}
