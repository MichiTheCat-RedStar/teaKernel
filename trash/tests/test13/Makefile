# Makefile для ядра teaKernel
# MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0


# Настраиваю флаги
CFLAGS = -m32 -ffreestanding -nostdlib -Wall -Wextra -Itealibs -MMD -MP
LDFLAGS = -m elf_i386 -T linker.ld
NASMFLAGS = -f elf32


# Файлы
C_SOURCES = $(wildcard *.c) $(wildcard tealibs/*.c)
OBJECTS = boot.o $(C_SOURCES:.c=.o)
DEPFILES  = $(C_SOURCES:.c=.d)


# Цель по умолчанию
all: kernel.elf


# Сборка всего ядра
kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) -o $@ $^

%.o: %.asm
	nasm $(NASMFLAGS) $< -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@


# Команды
# run - Запуск QEMU
run: kernel.elf
	qemu-system-i386 -kernel kernel.elf

# claen - удалить собранное
clean:
	rm -f *.o tealibs/*.o kernel.elf *.d tealibs/*.d

# help - поомщь для вывода информации
help:
	@echo "MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0"
	@echo "Помощь:"
	@echo "	make       - для сборки"
	@echo "	make run   - для запуска QEMU"
	@echo "	make clean - для удаления собранных файлов"
	@echo "	make help  - для вывода помощи"


# Зависимости
-include $(DEPFILES)


# Команды в готовом виде:
# make 		 - для сборки
# make run	 - для запуска QEMU
# make clean - для удаления собранных файлов
# make help	 - для вывода помощи
