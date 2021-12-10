;;5 variantas
;;Lauke nėra 'X' ir 'Z' simbolių
;;Trečio, ketvirto ir penkto laukų suma yra iš aibės {35, 45, 55, 67, 101, 201}.	

%include 'yasmmac.inc'
org 100h

section .text

start:  

	macPutString 'Skaitoma is: $'
    mov bx, 82h
    mov si, 0
    jmp s

    s:
    mov cl, [bx+si]
    cmp cl, 20h
    jl x
    inc si
    jmp s
    int 21h
    
    x :
    mov byte [bx+si], '$'
    mov ah, 09
    mov dx, bx
    int 21h
	macNewLine
	
	macPutString 'Laurynas Gailius, 1 kursas, 2 grupe', crlf, '$'
	macPutString '5 uzduotis', crlf, '$'
	macPutString 'Iveskite isvedamu duomenu failo varda', crlf, '$'

	mov al, 255
	mov dx, oName
	call procGetStr
	macNewLine
	
	mov ah, 0x3C
	mov al, 1
	int 0x21
	mov bx, ax
	mov [outputHandle], bx
	
	mov dx, 82h
	call procFOpenForReading
	mov [inputHandle], bx
	
	mov di, 0 ;;inputBuffer
	mov bx, 0 ;;outputBuffer
	mov cx, 0 ;;dabartinis laukas
	mov ch, 1 ;;x ir z skaicius
	
	l
		mov ah, 0x3F
		push bx
		push cx
		mov bx, [inputHandle]
		mov cx, 1
		mov dx, inputBuffer
		add dx, di
		int 0x21
		
		pop cx
		pop bx
		
		mov dl, [inputBuffer + di]
		mov [outputBuffer + bx], dl
		
		cmp dl, ";"
		je nextField
		
		cmp dl, 0xA
		je nextLine
		
		cmp cl, 1
		jg cont
		
		cmp dl, 0x58
		je XorZ
		
		cmp dl, 0x5A
		je XorZ
		
		cont
		
		inc di
		inc bx
		
		contNextLoop
		
	cmp ax, 0
	jne l
	
	mov ah, 0x3E
	mov bx, [inputHandle]
	int 0x21
	
	mov ah, 0x3E
	mov bx, [outputHandle]
	int 0x21
	
	exit
	
	isZ
	mov cx, 0
	mov di, 0
	mov bx, 0
		
	jmp contNextLoop
		
	XorZ
		inc ch
		jmp cont
	
	nextField
		cmp cl, 2
		jge getIntegerFieldSum
		
		contNextField
		
		mov bx, 0
		inc cl
		inc di
		
		jmp contNextLoop
		
	nextLine
		jmp getIntegerFieldSum
		
		contNextLine
		
		mov dx, [lineSum]
		push cx
		mov cl, "$"
		mov [inputBuffer + di], cl
		pop cx
		
		mov bx, 0

		cmp ch, 1	
		mov cx, 0
		mov [lineSum], cx
		jge isZ
		
		mov cx, 6
		lNextLine
			dec cx
			mov bx, cx
			push ax
			mov ax, 0
			mov al, [arr + bx]
			cmp dx, ax
			pop ax
			je printLine
			inc cx
		loop lNextLine
		
		mov di, 0
		mov cx, 0
		mov bx, 0
		
		jmp contNextLoop
		
	printLine
		mov dx, inputBuffer
		push ax
		mov cx, di
		mov bx, [outputHandle]
		mov ah, 0x40
		int 0x21
		pop ax
		
		mov cx, 0
		mov di, 0
		mov bx, 0
		
		jmp contNextLoop

	getIntegerFieldSum
		push cx
		mov cl, "$"
		mov [outputBuffer + bx], cl
		
		push ax
		push bx
		mov dx, outputBuffer
		call procParseInt16
		mov cx, [lineSum]
		add cx, ax
		mov [lineSum], cx
		
		pop bx
		pop ax
		
		pop cx
		
		cmp cl, 4
		jne contNextField
		
		jmp contNextLine
		
%include 'yasmlib.asm'
section .data

	inputHandle
		dw 0
		
	oName
		times 20 db "*"
		
	outputHandle 
		dw 0
		
	inputBuffer
		times 100 db "*"
		
	outputBuffer
		times 100 db "*"
		
	lineSum
		dw 0
		
	arr
		db 35, 45, 55, 67, 101, 201

section .bss