OBJS = resultset.o heap.o
CC = gcc

all: $(OBJS)

%.o: %.c
	$(CC) -c $< -I ../../include

clean:
	-rm -rf $(OBJS) $(PROG)
