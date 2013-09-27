PROGS = parity_swap_c parity_swap_nasm
COBJS = main_c.o parity_swap_c.o
NASMOBJS = main_nasm.o parity_swap_nasm.o atoi.o

all: $(PROGS)

parity_swap_c: $(COBJS)
	gcc $(COBJS) -o $@

parity_swap_nasm: $(NASMOBJS)
	ld $(NASMOBJS) -o $@

parity_swap_c.o: parity_swap.c
	gcc -c $< -o $@

main_c.o: main.c
	gcc -c $< -o $@

atoi.o: atoi.asm
	nasm -f elf64 $< -o $@ -l $*.lst

parity_swap_nasm.o: parity_swap.asm
	nasm -f elf64 $< -o $@ -l $*.lst

main_nasm.o: main.asm
	nasm -f elf64 $< -o $@ -l $*.lst

clean:
	-rm $(COBJS) $(NASMOBJS) $(PROGS) *lst
