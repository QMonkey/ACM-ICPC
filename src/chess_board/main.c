#include <stdio.h>
#include "chess_board.h"

int main()
{
	Area area = {0,0,4};
	Pos pos = {1,1};
	chess_board(area,pos);
	return 0;
}
