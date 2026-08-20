; boot.asm - оно нужно будет для того, чтобы вызвать C код скомпилированный... Если всё получится, то я уже смогу писать на C

section .multiboot
align 4
dd 0x1BADB002           ; магическое число
dd 0x03                 ; флаги (выравнивание, видеорежим)
dd -(0x1BADB002 + 0x03) ; контрольная сумма

section .text
extern kmain
global start
start:
    mov esp, stack_top
    push eax            ; передаём магическое число (GRUB)
    push ebx            ; передаём указатель на структуру
    call kmain
    cli
    hlt

section .bss
align 16
stack_bottom:
    resb 16384          ; 16 КБ стека
stack_top:
