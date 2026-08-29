Забиваю видеопасять по циклу

'''
nasm -f elf32 boot.asm -o boot.o
gcc -m32 -ffreestanding -nostdlib -c kernel.c -o kernel.o
ld -m elf_i386 -T linker.ld -o kernel.elf boot.o kernel.o
qemu-system-i386 -kernel kernel.elf
'''
