section	.text
	global	parity_swap

parity_swap:
.intsize	equ	4
	push	rbp
	mov	rbp,rsp

	push	rsi
	push	rdx
	push	rcx

	sub	rsi,.intsize
.forever:
.oddlp:
	cmp	rdi,rsi
	je	.endoddlp
	test	DWORD [rdi],1
	jz	.endoddlp
	add	rdi,.intsize
	jmp	.oddlp
.endoddlp:

.evenlp:
	cmp	rdi,rsi
	je	.endevenlp
	test	DWORD [rsi],1
	jnz	.endevenlp
	sub	rsi,.intsize
	jmp	.evenlp
.endevenlp:

	cmp	rdi,rsi
	je	.endforeverlp

	mov	edx,[rdi]
	mov	ecx,[rsi]
	mov	[rdi],ecx
	mov	[rsi],edx
.endforeverlp:

	pop	rcx
	pop	rdx
	pop	rsi

	leave
	ret
