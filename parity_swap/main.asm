section	.data
	errmsg	db	'No enough parameters.',0x0A
	len	equ	$-errmsg

section	.text
	global	_start
	extern	atoi

_start:
.intsize	equ	4
	mov	rsi,rsp
	mov	rcx,[rsi]
	dec	rcx
        test    rcx,rcx
        jnz     .endjudge

        mov     rax,1
        mov     rdi,2
        mov     rsi,errmsg
        mov     rdx,len
        syscall

        mov     rax,60
        mov     rdi,1
        syscall

.endjudge:
	mov	rax,.intsize
	imul	rax,rcx

	sub	rsp,rax
	mov	rbx,rsp
	add	rsi,16
.lp:
	mov	rdi,[rsi]
	call	atoi
	mov	[rbx],eax
	add	rbx,.intsize
	add	rsi,8
	loop	.lp

	mov	rax,60
	mov	rdi,1
	syscall
