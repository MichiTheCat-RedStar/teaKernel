Все встроенные функции (tealibs), рекомендуется использовать именно их:


	<teavideo.h>

// Работа с выводом на экран

clear_screen(); - очистка всего экрана

print_char(char c); - вывод одного символа

print_string(const char* str); - вывод строки

set_color(uint8_t color); - изменение цвета по палитре VGA

print_hex(uint32_t value); - вывод hex значения

print_32bin(uint32_t value); - вывод бинарного значения с ведущими нулями

print_bin(uint32_t value); - вывод банарного значения без ведущих нулей

print_dec(uint32_t value); - вывод беззнакового десятичного числа

print_int(int32_t value); - вывод знакового десятичного числа


	<teaprint.h>

// Работа с выводом через буфер

print(const char* str); - добавить строку в буфер

printflush(); - обнуление буфера и очистка экрана с выводом буфера


	<teakeyboard.h>

// Работа с вводом с клавиатуры

char read_char(); - читать символ с клавиатуры (блокирующий опрос, в будущем прерывания)



Всё что не входит сюда не рекомендуется к использованию, поэтому выведено ниже:


	<teakeyboard.h>

char scancode_to_ascii(uint8_t sc); - перевод сканкода 0x60 в ASCII


	<teaio.h>

uint8_t inb(uint16_t port); - inb ассемблера

outb(uint16_t port, uint8_t val); - outb ассемблера

uint16_t inw(uint16_t port); - inw ассемблера

outw(uint16_t port, uint16_t val); - outw ассемблера

qemu_poweroff(); - выключение QEMU
