; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example
INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.code
main proc
	mov	eax,-32780d	+0B0000h			
	add	eax,0B0000h
	add eax,37777400000o
	sub eax, 20000h
	call WriteHex				

	invoke ExitProcess,0
main endp
end main