#include <stdint.h>

#include "integer_division.h"

uint32_t integer_division(uint32_t number,uint32_t max)
{
	uint32_t result = 0;
	if(number == 1 || max == 1)
	{
		result = 1;
	}
	else if(max > number)
	{
		result = integer_division(number,number);
	}
	else if(max == number)
	{
		result = 1 + integer_division(number,number-1);
	}
	else
	{
		result = integer_division(number-max,max) + integer_division(number,max-1);
	}
	return result;
}
