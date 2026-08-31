# Makefile для ядра teaKernel v86
# MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0


CC = gcc
AS = nasm
LD = ld

CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra -I. -Itealibs
LDFLAGS = -m elf_i386 -T linker.ld -nostdlib

SRCS_C = kernel.c tealibs/teavideo.c tealibs/teaprint.c tealibs/teakeyboard.c tealibs/teainput.c
OBJS = boot.o $(SRCS_C:.c=.o)

all: kernel.bin

boot.o: boot.asm
	$(AS) -f elf32 boot.asm -o boot.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o tealibs/*.o kernel.bin
