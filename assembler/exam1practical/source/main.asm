TITLE MASM Template         (main.asm)
;description: number value program
;author: Aaron Borjas
;Date: 2/26/2020
INCLUDE Irvine32.inc
;TODO PLACE SYMBOLIC INTEGER CONSTANTS HERE
;
UNO = 1
DOS = 2
TRES = 3
QUATRO = 4
CINCO = 5
SEIS = 6
SIETE = 7
OCHO = 8
NUEVE = 9
DIES = 10
ONCE = 11
DOCE = 12
TRECE = 13
.data
;TODO: MAKE A LABEL numeros THAT LOCATES MEMORY FOR ALL THE DWORD NUMBER VALUES
; USE THE INTEGER CONSTANTS SPECIFIED ABOVE OT INITIALIZE ALL 13 DWORD VALUES
; PROGRAM MATCHES THAT SHOWN BELOW

numeros DWORD TRECE, DOCE, ONCe, DIES, NUEVE, OCHO, SIETE, SEIS, CINCO, QUATRO, TRES, DOS, UNO 

.code
main proc
    ;The code for main has already been written for you...
    ; setup a lopo that will run 13 times and outup all the DWORD number VALUES
    mov ecx, 13
    mov esi, 0

    label1:
        ;this writes out each dword from the array "numeros" to the screen
        mov eax, numeros[esi*TYPE DWORD]
        call WriteInt
        ; This increments the array index counter
        inc esi
    LOOP label1 ;loop 13 times (based on value in ECX)
    invoke ExitProcess,0

main endp
end main