section	.data
	format	db	'%s',0x0A,0
	newline	db	0x0A,0

section	.text
	global	_start
	extern	atoi
	extern	printf
	extern	exit
	extern	parity_swap

_start:
	mov	rdx,[rsp]
	lea	rbx,[rsp+8]
;	dec	rcx
;	mov	rax,rcx
;	mov	rdx,4
;	imul	rdx
;	sub	rsp,rax

.lp:
	mov	rdi,format
	mov	rsi,[rbx]
	call	printf
	add	rbx,8
	cmp	rdx,0
	jle	.endlp
	dec	rdx
	jmp	.lp
.endlp:

	mov	rdi,0
	call	exit
