@echo off
nasm -f elf32 boot.asm -o boot.o
i686-elf-gcc -m32 -ffreestanding -nostdlib -Wall -Wextra -I. -c kernel.c -o kernel.o
i686-elf-gcc -m32 -ffreestanding -nostdlib -Wall -Wextra -I. -c tealibs/teavideo.c -o tealibs/teavideo.o
i686-elf-ld -m elf_i386 -T linker.ld -o kernel.elf boot.o kernel.o tealibs/teavideo.o
qemu-system-i386 -kernel kernel.elf
