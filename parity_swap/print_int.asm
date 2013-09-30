section	.text
	global	print_int

print_int:
	push	rbp
	mov	rbp,rsp

	push	rbx
	push	rcx
	push	rsi
	push	rdx

	mov	rbx,rsp
	mov	rsi,rbx
	sub	rsp,0x28

	mov	rax,rdi
	cmp	rax,0
	jge	.endjudge
	mov	BYTE [rsp],1
.endjudge:

	mov	rcx,10
.lp:
	xor	rdx,rdx
	idiv	rcx
	add	rdx,0x30
	dec	rsi
	mov	[rsi],dl
	cmp	rax,0
	jne	.lp
.endlp:
	cmp	BYTE [rsp],1
	jne	.notneg
	dec	rsi
	mov	BYTE [rsi],'-'
.notneg:
	sub	rbx,rsi
	mov	rax,1
	mov	rdi,1
	mov	rdx,rbx
	syscall

	pop	rdx
	pop	rsi
	pop	rcx
	pop	rbx

	leave
	ret
