PROG = partition
OBJS = main.o partition.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $< -I ../../include

clean:
	-rm -rf $(OBJS) $(PROG)
