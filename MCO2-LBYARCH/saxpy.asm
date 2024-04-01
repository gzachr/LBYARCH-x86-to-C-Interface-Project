section .data
A dd 2.0 ; declare scalar value
section .text
bits 64
default rel

global saxpy_x86_64:
saxpy_x86_64:
	push rbp
	mov rbp, rsp
    add rbp, 16
    
	; rcx contains 2^N
	; rdx contains vectorX
	; r8 contains vectorY
	; r9 contains vectorZ
	
	; setup counter
	xor r10, r10

saxpy_loop:
	; check if iterated over entire vector
	cmp r10, rcx
	jae done

	xorps xmm15, xmm15
	xorps xmm14, xmm14
	
	; A*X[i]
	movss xmm14, [rdx+r10*4]
	vmulss xmm15, xmm14, [A]
	
	; add Y[i]
	addss xmm15, [r8+r10*4]

	; store into Z[i]
	movss [r9+r10*4], xmm15

	; move to next value
	inc r10
	jmp saxpy_loop

done:
	pop rbp
	ret