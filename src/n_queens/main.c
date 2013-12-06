#include <stdio.h>
#include <stdlib.h>

#include "n_queens.h"

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"No enough parameter.\n");
		exit(1);
	}

	n_queens(atoi(argv[1]));
	return 0;
}
