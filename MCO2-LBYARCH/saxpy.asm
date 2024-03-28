section .data
A dq 2.0
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
	movsd xmm14, [rdx+r10*8];
	vmulsd xmm15, xmm14, [A]
	
	; add Y[i]
	addsd xmm15, [r8+r10*8]

	; store into Z[i]
	movsd [r9+r10*8], xmm15

	; move to next value
	inc r10
	jmp saxpy_loop

done:
	pop rbp
	ret