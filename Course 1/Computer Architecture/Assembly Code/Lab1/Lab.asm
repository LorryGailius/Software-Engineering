%include 'yasmmac.inc'

org 100h

section .text

start:

; Išveda Vardą Pavardę Kursą Grupę:
mov ah, 09
mov dx, Class
int 0x21

; Išveda pranešimą įvesti simbolių eilutę:
mov ah, 09
mov dx, String1
int 0x21

; Įveda ascii simbolius:
mov ah, 0Ah
mov dx, Buffer
int 0x21
macNewLine

; Išveda pranešimą įvesti kintamuosius:
mov ah, 09
mov dx, String2
int 0x21

; Įveda kintamuosius:
call procGetInt16
mov [Skc1], ax
macNewLine
call procGetInt16
mov [Skc2], ax
macNewLine
call procGetInt16
mov [Skc3], ax
macNewLine

; -Pirma užduotis-
xor bx,bx
xor cx,cx

mov cl,[Buffer+1]

l1: ;Kopijuoja vartotojo įvesta simbolių eilutę
xor ax,ax
mov al,[Buffer+bx+2]
mov [Copy+bx],al
inc bx
loop l1

xor ax,ax
mov al, [Copy+3] ; Apkeičia 5 ir 4 simbolius
mov ah, [Copy+2]
mov [Copy+3], ah
mov [Copy+2], al

xor bx,bx
mov bl,[Buffer+1] ;Kiek simbolių buvo įvesta
mov byte [Copy+bx], 0x7C ;Prie eilutės pridedamas simbolis '|'
mov byte [Copy+bx+1], 0x0D ;Pridedama eilutės pabaiga
mov byte [Copy+bx+2], 0x0A
mov byte [Copy+bx+3], '$'

mov ah, 09 ;Išveda apkeista eilute
mov dx, Copy
int 0x21

; -Antra užduotis-

xor ax,ax ;Priskiriamos nulinės reikšmės registrams
xor cx,cx

mov cl, [Buffer+1] ;Ciklas vykdomas įvestų simboliu kartų
xor bx,bx ;BX = Simbolio indexas

l2:
xor dx,dx
mov word [Sk1], 0x0 ;'1' bitų skaičiui baite priskiriame nulinė reikšmė
mov dl, [Buffer + bx + 2];Į registrą DX įdedamas simbolis

push dx
and dx, 0x0004 ;Tikrinama ar 2 bitas turi reikšmę '1'
shr dx, 2
add word [Sk1], dx

pop dx
push dx
and dx, 0x0008 ;Tikrinama ar 3 bitas turi reikšmę '1'
shr dx, 3
add word [Sk1], dx

pop dx
and dx, 0x0040 ;Tikrinama ar priešpaskutinis bitas turi reikšmę '1'
shr dx, 6
add word [Sk1], dx

mov ax, [Sk1] ;Išvedamas '1' reikšmę turinčių bitų skaičius baite
call procPutInt16
macPutString ' $' 
inc bl
loop l2


macNewLine

;-Trečia uzduotis-				----> Programa apskaičiuoja ir išspausdina reiškinio min( (1000 / a), (b % c), max(a / 2 + 1, 23) ) reikšmę.

mov ax,03E8h ;Atliekamas veiksmas (1000 / a)
mov bx,[Skc1]
xor dx,dx
div bx
mov [Value1],ax


mov ax,[Skc2] ;Atliekamas veiksmas (b % c)
mov bx,[Skc3]
xor dx,dx
div bx
mov [Value2],dx


mov ax,[Skc1] ;Atliekamas veiksmas max(a / 2 + 1, 23)
xor bx,bx
mov bl,0x02
xor dx,dx
div bx
add ax,1
mov bx,0x17
cmp ax,bx
jg didesnis

mov [Value3],bx
jmp continue

didesnis:
mov [Value3],ax

continue:

mov ax, [Value1] ;Lyginami trijų užduočių atsakymai
mov bx, [Value2]
call Sort
;;mov bx, [Value3]
;;call Sort

mov [Ats],ax ;Išsaugomas atsakymas į kintamąjį
call procPutInt16

; -------------------------------- Pabaiga -----------------------------------
exit

Sort:
   ; išdėsto registrus mažėjančia tvarka:
   cmp ax, bx
   jb .end
   xchg ax, bx
   .end:
   ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include 'yasmlib.asm'
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

section .data ;duomenys

Sk1:
dw 00

Skc1:
dw 00

Skc2:
dw 00

Skc3:
dw 00

Value1:
dw 00

Value2:
dw 00

Value3:
dw 00

Ats:
dw 40

Class:
db 'Laurynas Gailius 1 kursas 2 grupe', 0x0D, 0x0A, '$'

String1:
db "Iveskite teksta nuo 10 iki 80 simboliu:", 0x0D, 0x0A, '$'

String2:
db "Iveskite tris teigiamus sveikuosius skaicius:", 0x0D, 0x0A, '$'

Buffer:
db 0x50, 0x00, "****************************************************************************************"

Copy:
db "****************************************************************************************"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
section .bss                    ; neinicializuoti duomenys  
