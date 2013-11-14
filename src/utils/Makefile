OBJS = resultset.o heap.o insertion_sort.o
CC = gcc

all: $(OBJS)

%.o: %.c
	$(CC) -g -c $< -I ../../include

clean:
	-rm -rf $(OBJS) $(PROG)
