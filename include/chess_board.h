#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <stdint.h>

typedef struct
{
	uint32_t x;
	uint32_t y;
} Pos;

typedef struct
{
	Pos begin;
	uint32_t size;
} Area;

extern void chess_board(Area area,Pos pos);

#endif
