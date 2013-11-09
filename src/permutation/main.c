#include <stdio.h>
#include <stdlib.h>
#include "permutation.h"

int main(int argc,char *argv[])
{
	char str[] = "abc";
	permutation(str,str+sizeof(str)-1);
	return 0;
}
