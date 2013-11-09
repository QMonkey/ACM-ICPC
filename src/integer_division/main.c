#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "integer_division.h"

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"No enough parameter.\n");
		exit(1);
	}

	int32_t number = atoi(argv[1]);
	fprintf(stdout,"%d\n",integer_division(number,number));
	return 0;
}
