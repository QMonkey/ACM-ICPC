PROG = matrix_multiplication
OBJS = main.o matrix_multiplication.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -g -o $@

%.o: %.c
	$(CC) -g -c $< -I ../../include

clean:
	-rm -rf $(OBJS) $(PROG)
