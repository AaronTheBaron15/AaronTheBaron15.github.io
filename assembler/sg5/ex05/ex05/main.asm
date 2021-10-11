; Program Name:           Template.asm

; Program Description:
; Author:
; Date:

INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
    myArr DWORD 10,20,30,40
	arrType DWORD TYPE myArr
	newArr DWORD LENGTHOF myArr DUP(?)
	lastElement DWORD ?

.code
main PROC
    mov esi, OFFSET myArr ;first element from array into esi

	;gets address of the next element
	mov edi, OFFSET newArr
	add edi, TYPE newArr

	mov ecx, LENGTHOF myArr ;loop counter
	
	L1:
		mov eax, [esi]
		mov [edi], eax

	loop L1

	;moves last element from myArr into first position in newArr
	mov edi, OFFSET newArr
	mov eax, [esi]
	mov [edi], eax

	call WriteInt

    INVOKE ExitProcess,0
main ENDP

; (insert additional procedures here)
END main