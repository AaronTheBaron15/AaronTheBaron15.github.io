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
    bigEndian BYTE 12h, 34h, 56h, 78h ;creates an array for a big endian number
	littleEndian DWORD ? ;similar to doing "int littleEndian;" in c++
.code
main PROC
    mov al,[bigEndian] ;moves the first byte of bigEndian (12) to al
    mov BYTE PTR [littleEndian], al ;puts the first byte of bigEndian at the end of littleEndian
 
    mov al,[bigEndian+1] ;moves the second byte of bigEndian (34) to al
    mov BYTE PTR [littleEndian+1],al ;moves the second byte of bigEndian to the end of littleEndian
 
    mov al,[bigEndian+2] ;moves the third byte of bigEndian (56) to al
    mov BYTE PTR [littleEndian+2],al ;moves the third byte of bigEndian to the end of littleEndian
 
    mov al,[bigEndian+3] ;moves the fourth byte of bigEndian (78) to al
    mov BYTE PTR [littleEndian+3],al ;moves the fourth byte of bigEndian to the end of littleEndian

    mov eax, littleEndian ;gets the little endian version of bigEndian into eax for examination
    call WriteInt

    INVOKE ExitProcess,0
main ENDP

; (insert additional procedures here)
END main