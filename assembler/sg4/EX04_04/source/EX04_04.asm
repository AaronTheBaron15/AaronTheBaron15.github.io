; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

varA SDWORD 10
varB SDWORD 20
varC SDWORD 30
varD SDWORD 40

.code
main proc
	mov	eax, varA 
	mov ebx, varB 
	mov ecx, varC 
	mov edx, varD

	add eax, ebx
	add ecx, edx

	sub eax, ecx
	mov varA, eax
	
	call WriteInt		

	invoke ExitProcess,0
main endp
end main