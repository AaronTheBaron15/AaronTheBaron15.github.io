04
; Program Name:           Template.asm

; Program Description:
; Author: Aaron Borjas and Caleb Grode
; Date: 4/16/2020

INCLUDE Irvine32.inc
includelib irvine32.lib

.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD



.data
grade DWORD ?

.code



main PROC

        ; code here!

        mov ecx, 10



        L1:

        mov eax, 100h
        call Randomize ; reset the seed

        call RandomRange ; get a random integer

        mov grade, eax

        call CalcGrade

        call WriteChar

        mov eax, ' '

        call WriteChar

        loop L1

        call DumpRegs

    INVOKE ExitProcess, 0

main ENDP

CalcGrade PROC

        ; push pointer to array, then push size of array
        push ebp 
        push ebx



         ; 41 = A, 42 = B, 43 = C, 44 = D, 46 = F in hex

         mov eax, grade ; grade is now in eax

         mov ebx, 89h
         CMP ebx, eax
         JC above89

         mov ebx, 79h
         CMP ebx, eax
         JC above79

         mov ebx, 69h
         CMP ebx, eax
         JC above69

         mov ebx, 59h
         CMP ebx, eax
         JC above59

         mov ebx, 0h
         CMP ebx, eax
         JC above0

         above89:
            mov eax, 0
            mov AL, 41h
            jmp restore 

         above79:
            mov eax, 0
            mov AL, 42h
            jmp restore

         above69:
            mov eax, 0
            mov AL, 43h
            jmp restore

         above59:
            mov eax, 0
            mov AL, 44h
            jmp restore

         above0:
            mov eax, 0
            mov AL, 46h
            jmp restore



     restore:
        pop ebx
        pop ebp ; restore the old bottom pointer 
        ret 8



CalcGrade ENDP
END main