#include <stdint.h>

#include "lcs.h"
#include "resultset.h"

uint32_t lcs(char *begin_x,char *end_x,char *begin_y,char *end_y)
{
	uint32_t res;
	if(begin_x == end_x || begin_y == end_y)
	{
		res = 0;
	}
	else if(*begin_x == *begin_y)
	{
		res = 1 + lcs(begin_x + 1,end_x,begin_y + 1,end_y);
	}
	else
	{
		uint32_t xcs_size = lcs(begin_x + 1,end_x,begin_y,end_y); 
		uint32_t ycs_size = lcs(begin_x,end_x,begin_y + 1,end_y); 
		res = xcs_size > ycs_size ? xcs_size: ycs_size;
	}
	return res;
}

uint32_t dp_lcs7(char *x_sequence,char *begin_x,char *end_x,
		char *y_sequence,char *begin_y,char *end_y,resultset_t *rs)
{
	if(begin_x == end_x || begin_y == end_y)
	{
		return 0;
	}
}

uint32_t dp_lcs(char *begin_x,char *end_x,char *begin_y,char *end_y)
{
	uint32_t xsize = end_x - begin_x;
	uint32_t ysize = end_y - begin_y;
	resultset_t *rs = create_resultset(xsize * ysize);
	uint32_t res = dp_lcs7(begin_x,begin_x,end_x,begin_y,begin_y,end_y,rs);
	destroy_resultset(rs);
	return res;
}
