PROG = hanoi
OBJS = main.o hanoi.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $<

clean:
	-rm -rf $(OBJS) $(PROG)
