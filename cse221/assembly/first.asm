section .data
	welcome db "welcome to assembly language",10,0
	len equ $-welcome
section .text
	global _start

_start:
	mov eax,4
	mov ebx,1
	mov ecx,welcome
	mov edx,len
	int 80h

	mov eax,1
	mov ebx,0
	int 0x80
