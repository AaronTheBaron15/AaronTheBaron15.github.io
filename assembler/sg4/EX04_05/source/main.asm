
Include Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword


string1 TEXTEQU <"hey">
string2 TEXTEQU <"there">
string3 TEXTEQU <"friend :)">

.data 
myVar BYTE string1
myVar2 BYTE string2
myVar3 BYTE string3

.code
main PROC
    invoke exitProcess,0
    
main endp
end main