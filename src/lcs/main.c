#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lcs.h"

int main(int argc,char **argv)
{
	if(argc < 3)
	{
		fprintf(stderr,"No enough parameter.\n");
		exit(1);
	}

	fprintf(stdout,"%s\t%s\n",argv[1],argv[2]);
	fprintf(stdout,"%u\n",lcs(argv[1],argv[1] + strlen(argv[1]),argv[2],argv[2] + strlen(argv[2])));
	fprintf(stdout,"%u\n",dp_lcs(argv[1],argv[1] + strlen(argv[1]),argv[2],argv[2] + strlen(argv[2])));
	return 0;
}
