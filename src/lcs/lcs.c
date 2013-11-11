#include <stdint.h>

#include "lcs.h"
#include "resultset.h"

static uint32_t dp_lcs7(char *x_sequence,char *begin_x,char *end_x,
		char *y_sequence,char *begin_y,char *end_y,resultset_t *rs);

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
	int32_t x = begin_x - x_sequence;
	int32_t y = begin_y - y_sequence;
	uint32_t res;
	if(begin_x == end_x || begin_y == end_y)
	{
		res = 0;
	}
	else if(*begin_x == *begin_y)
	{
		if(!isset_resultset(rs,x+1,y+1))
		{
			dp_lcs7(x_sequence,begin_x + 1,end_x,y_sequence,begin_y + 1,end_y,rs);
		}
		res = 1 + get_resultset(rs,x+1,y+1);
	}
	else
	{
		if(!isset_resultset(rs,x+1,y))
		{
			dp_lcs7(x_sequence,begin_x + 1,end_x,y_sequence,begin_y,end_y,rs);
		}
		if(!isset_resultset(rs,x,y+1))
		{
			dp_lcs7(x_sequence,begin_x,end_x,y_sequence,begin_y + 1,end_y,rs);
		}
		uint32_t xcs_size = get_resultset(rs,x+1,y);
		uint32_t ycs_size = get_resultset(rs,x,y+1);
		res = xcs_size > ycs_size ? xcs_size : ycs_size;
	}
	set_resultset(rs,x,y,res);
	return res;
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
