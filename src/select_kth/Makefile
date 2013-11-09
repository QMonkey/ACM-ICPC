PROG = select_kth
OBJS = main.o select_kth.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	make -C ../partition
	$(CC) $(OBJS) -g -o $@ ../partition/partition.o

%.o: %.c
	$(CC) -g -c $< -I ../../include

clean:
	make clean -C ../partition
	-rm -rf $(OBJS) $(PROG)
