; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example
INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.code
main proc
	mov	eax,10000h			
	add	eax,40000h
	sub eax,20000h
	call DumpRegs				

	invoke ExitProcess,0
main endp
end main