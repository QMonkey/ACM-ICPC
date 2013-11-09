PROG = integer_division
OBJS = main.o integer_division.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $<

clean:
	-rm -rf $(OBJS) $(PROG)
