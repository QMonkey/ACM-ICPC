PROG = select_kth_heap
OBJS = main.o select_kth_heap.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	make -C ../utils
	$(CC) $(OBJS) -g -o $@ ../utils/heap.o

%.o: %.c
	$(CC) -g -c $< -I ../../include

clean:
	make clean -C ../utils
	-rm -rf $(OBJS) $(PROG)
