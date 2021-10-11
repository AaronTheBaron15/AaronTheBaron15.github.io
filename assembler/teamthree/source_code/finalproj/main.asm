;authors: Aaron Borjas and Caleb Grode
;date created: 4/27/2020
;last edited: 5/9/2020

INCLUDE Irvine32.inc
includelib irvine32.lib

.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD



.data



row BYTE ?
col BYTE ?

board BYTE 0,0,0 ;main board
Rowsize = ($ - board) ;row size of main board
	  BYTE 0,0,0
	  BYTE 0,0,0

boardValue BYTE ? ; holds value from board
xWin BYTE 0 ;bool for if x won
oWin BYTE 0 ;bool for is o won
winSum BYTE 0 ;sums the items in the board to check for win
currentPlayer BYTE ? ;the current player

prompt BYTE "enter a number 0-8 (0 is top left, 8 is bottom right): ",0 ; prompt for turn
wrongInput BYTE "enter a value that does not have an X or an O on it. >:O ",0 ; prompt if wrong input
playerString BYTE "The current player is : ",0 ; prompt for current player
xWon BYTE "X won!", 0 ; string for if X won
oWon BYTE "O won!", 0 ; string for if O won

oWinASCII byte "   ___   __    __  _____     __  __    _  ", 0
RowsizeO = ($ - oWinASCII) ;row size of main board
byte           "  /___\ / / /\ \ \ \_   \ /\ \ \/ _\  / \ ", 0
byte           " //  // \ \/  \/ /  / /\//  \/ /\ \  /  / ", 0
byte           "/ \_//   \  /\  //\/ /_ / /\  / _\ \/\_/  ", 0
byte           "\___/     \/  \/ \____/ \_\ \/  \__/\/    ", 0

xWinASCII byte  "____  __             _____              ______", 0
RowsizeX = ($ - xWinASCII) ;row size of main board
 byte           "__  |/ /   ___      ____(_)________________  /", 0
 byte           "__    /    __ | /| / /_  /__  __ \_  ___/_  / ", 0
 byte           "_    |     __ |/ |/ /_  / _  / / /(__  ) /_/  ", 0
 byte           "/_/|_|     ____/|__/ /_/  /_/ /_//____/ (_)   ", 0

 ; row 2 = 46*(size byte)
.code
main PROC 
		
		;mov eax, (white * 16)
		
		;call SetTextColor

		call printBoard 
		call Turn

	INVOKE ExitProcess, 0

main ENDP

AccessBoard PROC ; change row and col variables to access the board value at that location, returned in al
	
	pushad
	
	mov eax, 0 ;rest eax just in case
	mov ebx, 0 ;reset ebx just in case

	mov ebx,OFFSET board ;move the board's memory location to ebx
	mov al, row ;move the row value to al
	mov bl, RowSize ;move the size of the rows to bl
	mul bl ;access the row
		
	add ebx, eax ; add eax and ebx (al is a part of eax)
	movzx esi,col ;moves the col value to esi
	mov al,[ebx + esi - 1] ;moves the value at ebx+esi-1 to al (leave the minus one there no matter what)

	mov boardValue, al ;saves the value we are accessing

	popad

	ret 

AccessBoard ENDP

Turn PROC
	pushad
	
	mov currentPlayer, 1
	mov ecx, 9
	L1:
		call PlayerStatus ;gets the current player
		call Place ;places an item based on user input
		call printBoard ;prints the new board with an item on it
		call checkWin ;checks if there is a win
		call SwitchPlayer

		;if there is a win, exit loop
		mov al, 1
		cmp xWin, al
		jz finish

		cmp oWin, al ;if there is an owin exit loop
		jz finish
	loop L1

	finish:
		
	popad
	ret
Turn ENDP


SwitchPlayer PROC
	pushad
	mov al, currentPlayer
	cmp al, 1 ; switch to the next player
	je nowO ; switches based off the compare
	jnc nowX

	nowO:
		mov al, 7 ; mov the O value
		jmp finish
	nowX:
		mov al, 1 ; mov in the X value
		jmp finish
	finish:
		mov currentPlayer, al ; set the current player 

	popad
	ret
SwitchPlayer ENDP

PlayerStatus PROC
	pushad
	cmp currentPlayer, 1 ; compare the current player to 1 
			je isX  ; is 1
			jnc isO ; is 7
	isX:			
		mov eax, 'X'
		jmp done
	isO:
		mov eax, 'O'
		jmp done

	done:
		mov edx, OFFSET playerString
		call WriteString
		call WriteChar
		call Crlf
	popad
	ret
PlayerStatus ENDP

Place PROC
	pushad
	jmp top ;makes sure we start in top
	top:
		; need to check if can place
		; need to flip between X and O use currentPlayer var

		;says what to input
		mov edx, OFFSET prompt
		call WriteString
		call Crlf

		;gets user input
		call ReadInt
		mov col, al
		
		add col, 1 ; hmmmmmmm 


		mov row, 0 ;sets row to zero

		;gets the selected value
		mov ebx, OFFSET board
		; add ebx, RowSize * row
		mov al, RowSize
		mov bl, row
		mul bl
		add bx, ax
		movzx esi, col

		; check if the placement is valid
		mov bl, [ebx + esi + 1]
		cmp bl, 0 ; compare board value with 0
		jz finish ; if it is equal to 0 jump to finish
		jnz error ; if it is not zero then it is not a valid placement, jump to error

	error:
		;print that the user messed up
		mov edx, OFFSET wrongInput 
		call WriteString
		call Crlf
		jmp top ;restart

	finish:
		;the user didnt mess up so we place their thing at this row and column
		mov al, currentPlayer
		mov [ebx + esi + 1], al

	popad	
		
	ret
	
Place ENDP

printBoard PROC
	pushad
	mov row, 0 ;sets row and col to 0
	mov col, 0

	mov ecx, 3 ;moves 3 to ecx to loop 3 times
	outer:
		push ecx ; save loop counter
		call innerLoop ;prints the inner loop
		pop ecx ;gets back ecx for the outer loop
		mov col, 0 ;resets col to 0
		
		call Crlf ; endline
		
		cmp ecx, 1 ; if we are on the last loop we dont want to print the bottom hline
		je finish2

		
		push ecx	;saves ecx	
		mov ecx, 5 
		hLines: ; prints horizontal lines between rows of values on board
			mov eax, black + (white * 16)
			call SetTextColor
			mov eax, '-'
			call WriteChar
		loop hLines
		pop ecx		;retrieves ecx back for the outer loop

		finish2:

		call Crlf ;endl
		inc row ;increment row
	loop outer
	popad
	ret
printBoard ENDP

innerLoop PROC
	mov ecx, 3 ;# of things in board row
	inner:		
			call AccessBoard ;gets a value of the board at a specific value

		
			;(0 is empty spot, 1 is X, 7 is O)
			cmp boardValue, 1 ;compare boardValue to 1 
			jc empty ; is 0
			je isX; is 1
			jnc isO; is 7

			empty:
				mov eax, black + (white * 16)
				call SetTextColor
				mov eax, ' '
				call WriteChar
				jmp done
			isX:	
				mov eax, red + (white * 16)
				call SetTextColor
		
				mov eax, 'X'
				call WriteChar
				jmp done
			isO:
				mov eax, blue + (white * 16)
				call SetTextColor
				mov eax, 'O'
				call WriteChar
				jmp done
				
			done:		
				mov eax, black + (white * 16)
				call SetTextColor
				cmp ecx, 1 ;if the loop is 1 away from printing don't continue with this code
				je finish ;skip to the next label
				mov eax, '|'
				call WriteChar

				
			finish: ; skip printing line at last spot on board
					mov eax, white + (black * 16)
					call SetTextColor

			inc col ;increment the column
		loop inner
		
		ret

innerLoop ENDP

checkDiagWin PROC
	pushad
	;top left to bottom right
	mov row, 0 ;sets row to 0
	mov col, 0 ;sets col to 0 
	call AccessBoard ;accesses the board at row, col
	mov al, boardValue ;moves the accessed board value to al
	add winSum, al ;adds the board value to winSum (to calculate a win)

	;some process as last chunk of code, but with the item in the middle of the board
	mov row, 1
	mov col, 1
	call AccessBoard ;get value from 1,1,
	mov al, boardValue
	add winSum, al ; add that value to the winsum

	;same process as the previous two chunks of code, but with the item in the bottom right of the board
	mov row, 2 ;continue with 2,2
	mov col, 2
	call AccessBoard
	mov al, boardValue
	add winSum, al

	mov al, 3 ;moves 3 to al to compare
	cmp al, winSum ; check if winSum is equal to a sum that wins (3 in the case of x's)
	je Xwinner ;jump to xwin condition if al and winsum are equal

	mov al, 21 ;moves 21 to al to compare
	cmp al, winSum ;check if winSum is equal to a sum that wins (21 in the case of O's)
	je Owinner ;jump to owin condition if al and winSum are equal

	mov winSum, 0 ;resets winSum for top right to bottom left calculation

	;top right to bottom left
	;same process as top left to bottom right
	mov row, 0
	mov col, 2
	call AccessBoard
	mov al, boardValue
	add winSum, al
	
	mov row, 1
	mov col, 1
	call AccessBoard
	mov al, boardValue
	add winSum, al

	mov row, 2
	mov col, 0
	call AccessBoard
	mov al, boardValue
	add winSum, al

	mov al, 3
	cmp al, winSum
	je Xwinner 

	mov al, 21 ; new with 7
	cmp al, winSum
	je Owinner 
	
	; if we have not jumped to an x win or o win, then jump to the finish because the game is still afoot (or nonone won)
	jmp finish

	xWinner:
		mov xWin, 1 ; set bool value
		mov edx, OFFSET xWinASCII
		mov eax, red
		call SetTextColor

		mov ecx, 5
		writeWinX:
			call WriteString
			add edx, RowsizeX
			call Crlf
		loop writeWinX

		jmp finish
	oWinner:
		mov oWin, 1
		mov edx, OFFSET oWinASCII
		mov eax, blue
		call SetTextColor

		mov ecx, 5
		writeWinO:
			call WriteString
			add edx, RowsizeO
			call Crlf
		loop writeWinO

		jmp finish
	finish:
		
	popad
	ret
checkDiagWin ENDP

CheckWin PROC
	pushad
	mov winSum, 0
	mov row, 0
	mov col, 0

	mov ecx, 3 ;loop checkHorizontal 3 times (for 3 rows)
	checkHorizontal:
		push ecx ;saves ecx
		mov ecx, 3 ;checks the three columns inside the current row (3 columns)
		inner:
			call AccessBoard ;gets the value at the current row and col values
			mov al, boardValue ;saves our value from previous line
			add winSum, al ;adds the boardvalue to winsum to check for a win later
			inc col ;increment the column
		loop inner
		mov col, 0 ; reset the column
		pop ecx ;gets the saved value of ecx

		;resets eax, then compares 3 to winSum to check for a win for the X player
		mov eax, 0 
		mov al, 3
		cmp al, winSum
		je Xwinner

		;compares 21 to winsum to check for a win for the O player
		mov al, 21 ; new with 7
		cmp al, winSum
		je Owinner

		mov winSum, 0 ; reset the value for the next inner loop
		inc row
	loop checkHorizontal  

	mov row, 0
	mov col, 0
	mov ecx, 3
	checkVertical:; checks cases for a vertical win (mostly the same as checkHorizontal, but reversing row and col)
		push ecx
		mov ecx, 3
		inner2: ; checks a full column
			call AccessBoard
			mov al, boardValue
			add winSum, al
			inc row ;increment the row
		loop inner2
		mov row, 0 ; reset the row
		pop ecx

		mov eax, 0
		mov al, 3
		cmp al, winSum
		je Xwinner

		mov al, 6
		cmp al, winSum
		je Owinner

		mov winSum, 0 ; reset the value for the next inner loop
		inc col ; move to the next column
	loop checkVertical


	call checkDiagWin

	jmp finish ; if no winner yet

	xWinner:
		mov xWin, 1
		mov edx, OFFSET xWinASCII
		mov eax, red
		call SetTextColor

		mov ecx, 5
		writeWinX:
			call WriteString
			add edx, RowsizeX
			call Crlf
		loop writeWinX
		jmp finish
	oWinner:
		mov oWin, 1
		mov edx, OFFSET oWinASCII

		mov eax, blue
		call SetTextColor
		
		mov ecx, 5
		writeWinO:
			call WriteString
			add edx, RowsizeO
			call Crlf
		loop writeWinO
		jmp finish
	finish: ; prints the winner
		call Crlf

	popad
	ret
CheckWin ENDP

END main