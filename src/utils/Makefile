OBJS = resultset.o heap.o insertion_sort.o bitset.o
CC = gcc

all: $(OBJS)

%.o: %.c
	$(CC) -g -c $< -I ../../include

clean:
	-rm -rf $(OBJS) $(PROG)
