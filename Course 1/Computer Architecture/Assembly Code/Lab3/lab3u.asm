%include 'yasmmac.inc'

org 100h

section .text

	start:
	
	mov dx, string
	
	mov bx, 7
	mov ah, 0x9
	int 0x21

	exit
	
%include 'yasmlib.asm'

section .data
	string
		db "1234567890ABCDEFGHJKLMNOPRSTU$"

section .bss