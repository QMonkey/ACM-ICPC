#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <stdint.h>

typedef struct
{
	int32_t x;
	int32_t y;
} Pos;

typedef struct
{
	Pos begin;
	int32_t size;
} Area;

extern void chess_board(Area area,Pos pos);

#endif
