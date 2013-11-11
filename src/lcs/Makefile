PROG = lcs
OBJS = main.o lcs.o
CC = gcc

all: $(PROG)

$(PROG): $(OBJS)
	make -C ../utils
	$(CC) $(OBJS) -g -o $@ ../utils/resultset.o

%.o: %.c
	$(CC) -g -c $< -I ../../include

clean:
	make clean -C ../utils
	-rm -rf $(OBJS) $(PROG)
