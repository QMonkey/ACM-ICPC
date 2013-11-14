PROG = merge_stones
OBJS = main.o merge_stones.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	make -C ../utils
	$(CC) $(OBJS) -o $@ ../utils/resultset.o

%.o: %.c
	$(CC) -c $< -I ../../include

clean:
	make clean -C ../utils
	-rm -rf $(OBJS) $(PROG)
