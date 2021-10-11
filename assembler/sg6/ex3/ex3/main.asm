; Program Name:           Template.asm

; Program Description:
; Author: Aaron Borjas and Caleb Grode
; Date: 4/16/2020

INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
    myColor DWORD ?
    myText BYTE "This is my message! ", 0

.code
main PROC
    call Randomize ;seed for randomrange
    mov ecx, 20 ;moves 20 to ecx to loop 20 times

    L1:
        ;random number between 0 and 9
        mov eax, 10 
        call RandomRange

        ;call WriteInt

        CMP eax, 3 ;compare eax to 3
        JC colorWhite ;if eax is less than 3 jump to colorWhite label
        JE colorBlue ;if eax is equal to 3 jump to colorBlue label
        JNC colorGreen ;if eax is greater than 3 jump to colorGreen label

        colorWhite:
            mov myColor, white
            jmp finish
        colorBlue:
            mov myColor, blue
            jmp finish
        colorGreen:
            mov myColor, green
            jmp finish

        finish:
            mov eax, myColor
    

            mov edx, OFFSET myText
            call SetTextColor ;sets text color to the color based on the random generation
            call WriteString ;prints the string

            ; new line
            mov eax, 10
            call WriteChar
      
    loop L1

    INVOKE ExitProcess,0
main ENDP

; (insert additional procedures here)
END main