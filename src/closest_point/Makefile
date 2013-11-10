PROG = closest_point
OBJS = main.o closest_point.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	make -C ../select_kth
	$(CC) $(OBJS) -o $@ ../select_kth/select_kth.o ../partition/partition.o

%.o: %.c
	$(CC) -c $< -I ../../include

clean:
	make clean -C ../select_kth
	-rm -rf $(OBJS) $(PROG)
