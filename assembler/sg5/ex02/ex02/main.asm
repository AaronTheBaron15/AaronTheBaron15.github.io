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
    ; declare variables here
    myArr BYTE 12h,34h,56h,78h
	arrLength = ($-myArr)
	lengthMinusOne DWORD ?
.code
main PROC
    ; write your code here

    mov ecx, arrLength
	dec ecx
	mov lengthMinusOne, ecx
	mov ecx, 0

	L1:
		;makes sure it isnt the end of the loop
		cmp ecx, lengthMinusOne 
		je exitL1

		mov ebx, ecx 
		inc ebx ;finds the what i+1 is

		mov dh, [myArr+ecx] ;myArr[i]
		mov dl, [myArr+ebx] ;myArr[i+1]

		mov [myArr+ebx], dh ;moves myArr[i+1] to myArr[i]
		mov [myArr+ecx], dl ;moves myArr[i] to myArr[i+1]

		inc ecx
		inc ecx
	jmp L1

	exitL1:
		mov eax, 0
		mov ecx, 0
		L2: 
			cmp ecx, arrLength
			je quit

			mov al, [myArr+ecx]
			call WriteInt
			inc ecx
		jmp L2
	quit:
	exit
	mov ah, myArr

	call DumpRegs

    INVOKE ExitProcess,0
main ENDP

; (insert additional procedures here)
END main