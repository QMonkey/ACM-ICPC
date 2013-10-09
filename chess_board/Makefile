PROG = chess_board
OBJS = main.o chess_board.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $<

clean:
	-rm -rf $(OBJS) $(PROG)
