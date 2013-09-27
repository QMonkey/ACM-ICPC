section	.text
	global	atoi

atoi:
	push	rbp
	mov	rbp,rsp

	push	rsi
	push	rcx
	push	rdx

	mov	rsi,1
	xor	rax,rax
	mov	rcx,rdi

.scan:
	mov	dl,BYTE [rdi]
	cmp	dl,0
	je	.endscan
	inc	rdi
	jmp	.scan
.endscan:
	sub	rcx,rdi
	neg	rcx
	dec	rdi

.lp:
	xor	rdx,rdx
	mov	dl,BYTE [rdi]
	sub	dl,0x30
	imul	rdx,rsi
	add	rax,rdx
	imul	rsi,10
	dec	rdi
	loop	.lp

	pop	rdx
	pop	rcx
	pop	rsi

	leave
	ret
