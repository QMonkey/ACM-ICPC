PROG = select_kth
OBJS = main.o select_kth.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $<

clean:
	-rm -rf $(OBJS) $(PROG)
