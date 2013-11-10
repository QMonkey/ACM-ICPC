#include <stdint.h>
#include <stdio.h>

#include "chess_board.h"

static uint32_t point_pos(Area *area,Pos *pos)
{
	uint32_t offset = area->size >> 1;
	Pos middle = {area->begin.x + offset,area->begin.y + offset};
	uint32_t less = pos->y < middle.y;

	return pos->x < middle.x ? (less ? 0 : 3) : (less ? 1 : 3);
}

static void center_pos(Area *area,uint32_t direct,Pos *pos)
{
	pos->x = area->begin.x + (area->size >> 1);
	pos->y = area->begin.y + (area->size >> 1);

	switch(direct)
	{
	case 0:
		--pos->x;
		--pos->y;
		break;
	case 1:
		--pos->y;
		break;
	case 2:
		--pos->x;
		break;
	default:
		break;
	}
}

static void subarea(Area *src,uint32_t direct,Area *dest)
{
	dest->size = src->size >> 1;
	switch(direct)
	{
	case 0:
		dest->begin = src->begin;
		break;
	case 1:
		dest->begin.x = src->begin.x + dest->size;
		dest->begin.y = src->begin.y;
		break;
	case 2:
		dest->begin.x = src->begin.x;
		dest->begin.y = src->begin.y + dest->size;
		break;
	case 3:
		dest->begin.x = src->begin.x + dest->size;
		dest->begin.y = src->begin.y + dest->size;
		break;
	default:
		break;
	}
}

static void print_pos(Pos *pos)
{
	fprintf(stdout,"(%d,%d)",pos->x,pos->y);
}

void chess_board(Area area,Pos pos)
{
	if(area.size == 1)
	{
		return;
	}

	Pos poslt,posrt,poslb,posrb;
	center_pos(&area,0,&poslt);
	center_pos(&area,1,&posrt);
	center_pos(&area,2,&poslb);
	center_pos(&area,3,&posrb);

	uint32_t pnum = point_pos(&area,&pos);

	switch(pnum)
	{
	case 0:
		print_pos(&posrt);
		print_pos(&poslb);
		print_pos(&posrb);
		fprintf(stdout,"\n");
		break;
	case 1:
		print_pos(&poslt);
		print_pos(&poslb);
		print_pos(&posrb);
		fprintf(stdout,"\n");
		break;
	case 2:
		print_pos(&poslt);
		print_pos(&posrt);
		print_pos(&posrb);
		fprintf(stdout,"\n");
		break;
	case 3:
		print_pos(&poslt);
		print_pos(&posrt);
		print_pos(&poslb);
		fprintf(stdout,"\n");
		break;
	default:
		break;
	}

	Area arealt,areart,arealb,arearb;
	subarea(&area,0,&arealt);
	subarea(&area,1,&areart);
	subarea(&area,2,&arealb);
	subarea(&area,3,&arearb);

	switch(pnum)
	{
	case 0:
		chess_board(arealt,pos);
		chess_board(areart,posrt);
		chess_board(arealb,poslb);
		chess_board(arearb,posrb);
		break;
	case 1:
		chess_board(arealt,poslt);
		chess_board(areart,pos);
		chess_board(arealb,poslb);
		chess_board(arearb,posrb);
		break;
	case 2:
		chess_board(arealt,poslt);
		chess_board(areart,posrt);
		chess_board(arealb,pos);
		chess_board(arearb,posrb);
		break;
	case 3:
		chess_board(arealt,poslt);
		chess_board(areart,posrt);
		chess_board(arealb,poslb);
		chess_board(arearb,pos);
		break;
	default:
		break;
	}
}
