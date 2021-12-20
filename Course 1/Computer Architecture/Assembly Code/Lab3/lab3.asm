%include 'yasmmac.inc'

org 100h

section .text

	start:
		jmp initialize
		
	originalInterrupt:
		dw 0, 0
		
	myInterrupt:
	
		macPushAll
		
		cmp ah, 0x9
		jne useOriginalInterrupt
		
		mov cx, bx
		mov bx, dx
		mov di, 0
		
		cmp cx, 0
		jle outOfBounds
		
		keistasCiklas:
		mov dl, [bx + di]

		mov ah, 0x2
		push cx
		push bx
		push di
		int 21h
		pop di
		pop bx
		pop cx
		
		inc di

		loop keistasCiklas
		
	outOfBounds:
		macPopAll
		iret
		
	useOriginalInterrupt:
		pushf
		call far [cs:originalInterrupt]
		macPopAll
		iret
		
	initialize:
	
		mov ah, 0x35
		mov al, 0x21
		int 0x21
		
		mov [cs:originalInterrupt], bx
		mov [cs:originalInterrupt + 2], es
		
		mov dx, myInterrupt
		mov ah, 0x25
		mov al, 0x21
		int 0x21
		
		mov dx, initialize + 1
		int 0x27
	
%include 'yasmlib.asm'
	
section .bss