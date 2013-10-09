#include <stdio.h>

static void swap(char *first,char *second)
{
	char ch = *first;
	*first = *second;
	*second = ch;
}

extern void permutation(char *begin,char *end)
{
	if(begin == end)
	{
		begin -= 3;
		fprintf(stdout,"%s\n",begin);
		return;
	}

	char *current = begin;
	for( ; current != end; ++current)
	{
		swap(begin,current);
//		fprintf(stdout,"%c",*current);
		permutation(begin+1,end);
		swap(begin,current);
	}
}
