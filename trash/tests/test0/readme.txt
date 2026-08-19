Проверка 0xB8000 под:
nasm -f bin boot.asm -o boot.bin
qemu-system-x86_64 -drive format=raw,file=boot.bin

Итог:
Всё работает, было запущено окно эмулятора с выведенным HELLO
