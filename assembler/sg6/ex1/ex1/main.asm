; Program Name:           Template.asm

; Program Description:
; Author:
; Date:

INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

;j equ 10d
;k equ 20d

.data
    j DWORD 10
    k DWORD 20
    arraySize = 5
    array DWORD arraySize DUP(?)

.code
main PROC

    
    push OFFSET array
    push ArraySize
    call Phil

    mov j, 0
    mov k, 10
    arraySize = 10
    push OFFSET array
    push ArraySize
    call Phil

    call DumpRegs

    INVOKE ExitProcess,0
main ENDP

Phil PROC
    ; push pointer to array, then push size of array

    push ebp 
    mov ebp, esp ; move bottom pointer to the top

    pushad ; save registers

    mov ebx, [ebp+12] ; points to the array
    mov ecx, [ebp+8] ; points to the arraySize

    cmp ecx, 0 ; if(arraySize == 0)
    je restore ; do not fill array and restore values by jumping ahead to the restore section

    ; else do fill loop

    L1:
        mov eax, k-j ; range 0 to FFFFh
        call RandomRange ; get a random range
        add eax, j
        mov [ebx], DWORD PTR eax ;mov value into array
        add ebx, TYPE DWORD ; i++

    loop L1



    restore:
        popad ; restore register values
        pop ebp ; restore the old bottom pointer 
        ret 8

Phil ENDP

END main