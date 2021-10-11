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

.code
main PROC
    mov ecx, 5 ;makes ecx equal to 5 so that the loop happens 5 times (since we already have two numbers from the following two lines)

	mov eax, 1 ;makes eax equal to 1
	mov ebx, 1 ;makes ebx equal to 1

	;loop that goes until ecx is 0
	L1:
		add eax, ebx ;add ebx to eax
		add ebx, eax ;add eax to ebx

		Call WriteInt ;print the number in eax
	loop L1

    INVOKE ExitProcess,0
main ENDP

; (insert additional procedures here)
END main