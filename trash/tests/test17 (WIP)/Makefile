# Makefile для ядра teaKernel
# MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

# Снизу написаны команды, либо напишите "make help"


# Настраиваю флаги
CFLAGS = -m32 -ffreestanding -nostdlib -Wall -Wextra -Itealibs -MMD -MP
LDFLAGS = -m elf_i386 -T linker.ld
NASMFLAGS = -f elf32


# Файлы
C_SOURCES = $(wildcard *.c) $(wildcard tealibs/*/*.c)
ASM_SOURCES = $(wildcard tealibs/*/*.S)
OBJECTS = boot.o $(C_SOURCES:.c=.o) $(ASM_SOURCES:.S=.o)
DEPFILES = $(C_SOURCES:.c=.d) $(ASM_SOURCES:.S=.d)


# Цель по умолчанию
all: teaKernel.elf


# Сборка всего ядра
teaKernel.elf: $(OBJECTS)
	ld $(LDFLAGS) -o $@ $^

%.o: %.asm
	nasm $(NASMFLAGS) $< -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

%.o: %.S
	nasm -f elf32 $< -o $@


# Сборка загрузочного ISO
ISO_DIR = iso
GRUB_DIR = $(ISO_DIR)/boot/grub
KERNEL_ELF = teaKernel.elf

iso: $(KERNEL_ELF)
	mkdir -p $(GRUB_DIR)
	cp $(KERNEL_ELF) $(ISO_DIR)/boot/teaKernel.elf
	echo 'set timeout=0' > $(GRUB_DIR)/grub.cfg
	echo 'set default=0' >> $(GRUB_DIR)/grub.cfg
	echo 'menuentry "teaKernel" {' >> $(GRUB_DIR)/grub.cfg
	echo '    multiboot /boot/teaKernel.elf' >> $(GRUB_DIR)/grub.cfg
	echo '    boot' >> $(GRUB_DIR)/grub.cfg
	echo '}' >> $(GRUB_DIR)/grub.cfg
	grub-mkrescue -o teaKernel.iso $(ISO_DIR)
	rm -rf $(ISO_DIR)


# Команды
# run - Запуск QEMU
run: teaKernel.elf
	qemu-system-i386 -kernel teaKernel.elf

# Запуск QEMU с ISO
run-iso: teaKernel.iso
	qemu-system-i386 -cdrom teaKernel.iso

# claen - удалить собранное
clean:
	rm -f *.o tealibs/*/*.o teaKernel.elf *.d tealibs/*/*.d
	rm -rf teaKernel.iso $(ISO_DIR)

# Очистка собранного ISO
clean-iso:
	rm -rf teaKernel.iso $(ISO_DIR)

# help - поомщь для вывода информации
help:
	@echo "	-= MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0 =-"
	@echo "Помощь:"
	@echo "	make           - для сборки"
	@echo "	make run       - для запуска QEMU"
	@echo "	make clean     - для удаления собранных файлов"
	@echo "	make help      - для вывода помощи"
	@echo "	make iso       - для сборки ISO"
	@echo "	make run-iso   - для запуска QEMU ISO образа"
	@echo "	make clean-iso - для удаления собранного ISO"


# Зависимости
-include $(DEPFILES)


# Команды в готовом виде:
# make			 - для сборки
# make run		 - для запуска QEMU
# make clean	 - для удаления собранных файлов
# make help		 - для вывода помощи
# make iso		 - для сборки ISO
# make run-iso	 - для запуска QEMU ISO образа
# make clean-iso - для удаления собранного ISO
