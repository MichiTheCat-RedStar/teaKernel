Попытка встроить C код и уйти от Nasm

Компиляция и линковка через:
'''
nasm -f elf32 boot.asm -o boot.o
gcc -m32 -ffreestanding -nostdlib -c kernel.c -o kernel.o
ld -m elf_i386 -Ttext 0x100000 -o kernel.elf boot.o kernel.o
'''

Запуск через:
'''
qemu-system-x86_64 -kernel kernel.elf
'''

Итог:
'''
ld: предупреждение: невозможно найти символ входа _start; используем значение по умолчанию 0000000000100000

qemu-system-x86_64: Error loading uncompressed kernel without PVH ELF Note
'''


Попытка 2 встроить C код и уйти от Nasm

Создаю linker.ld

Теперь пересобираю:

'''
nasm -f elf32 boot.asm -o boot.o
gcc -m32 -ffreestanding -nostdlib -c kernel.c -o kernel.o
ld -m elf_i386 -T linker.ld -o kernel.elf boot.o kernel.o
'''

И тест:

'''
qemu-system-i386 -kernel kernel.elf
'''


Итог:
Всё работает! Правда наслаивается на текст QEMU, потому что я не заполнил пробелами... Так же в будущем для автоматизации надо научиться создавать Makefile и ISO


Примечание:
Добавил функцию для забивки экрана пробелами, теперь нет надписи от QUME, а только Hi на чёрном фоне
