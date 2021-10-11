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
    source BYTE "This is the source string", 0
	target BYTE SIZEOF source DUP('#')

.code
main PROC
    mov esi, 0 ;move 0 to esi
	mov edi, lengthof source-1 ; moves the length of source (minus one) to edi
	mov ecx, sizeof source ;moves the size of source (1*lengthof) to ecx

	L1:
		mov eax, 0 ;moves 0 to eax
		mov al, source[esi] ;moves the data from source at esi to al (indirect addressing)
		mov target[edi], al ;moves the stuff that was moved into al from the previous line into target at edi (indirect addressing)

		inc esi ;increments esi
		dec edi ;decrements edi
	loop L1

	mov edx, OFFSET source ;moves the offset of source to edx
	call WriteString ;calls writestring, outputs stuff in edx
	mov edx, offset target ;moves the offset of target to edx
	call WriteString ;calls writestring, outputs stuff in edx

    INVOKE ExitProcess,0
main ENDP

; (insert additional procedures here)
END main