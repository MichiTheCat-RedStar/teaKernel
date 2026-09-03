section .multiboot
align 4
dd 0x1BADB002
dd 0x03
dd -(0x1BADB002 + 0x03)

section .text
extern teakmain
global start
start:
	mov esp, stack_top
	push eax
	push ebx
	call teakmain
	cli
	hlt

section .bss
align 16
stack_bottom:
	resb 16384
stack_top:
