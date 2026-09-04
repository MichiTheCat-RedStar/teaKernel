#include "../system/teakeyboard.h"
#include "teavideo.h"
#include <stdint.h>

// Библиотека для возможности ввода текста
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

static char buffer[256]; // 256 - 0xFF -> uint8_t для указателя
static uint8_t buffer_arrow = 0; // Я вообще правильно делаю, что указываю указатель как отдельную переменную, а не buffer*? Я всё ещё плох в C :(


// Ввод с клавиатуры с обработкой \t и \b, а так же ENTER как ОТПРАВИТЬ
char* input(void) {
	while (1) {
		set_color(0x07);
		print_char('_');
		set_color(0x0F);
		print_char('\b');
		char ch = read_char();
		
		if (buffer_arrow < 255) {
			if (ch == '\n') {
				goto ret;
			} else if (ch == '\t') {
				buffer[buffer_arrow] = ' '; // Чтобы не ломать пробелами
				print_char(' '); // в будущем заменить на \t, но надо добавить учёт %4 и сравнения позиций
			} else if (ch == '\b') {
				if (buffer_arrow > 0) {
					buffer[buffer_arrow] = '\0'; // ноль, чтобы не было лишего подсчёта пробелов в парсере
					print_char(' ');
					print_char('\b');
					print_char('\b');
					print_char(' ');
					print_char('\b');
					buffer_arrow--;
				}
				continue;
			} else {
				buffer[buffer_arrow] = ch;
				print_char(ch);
			}
		} else {
			if (ch == '\b') { // Не даю печатать символы при переполнении, если это не \b для удаления
				buffer[buffer_arrow] = '\0'; // ноль, чтобы не было лишего подсчёта пробелов в парсере
				print_char(' ');
				print_char('\b');
				print_char('\b');
				print_char(' ');
				print_char('\b');
				buffer_arrow--;
				continue;
			} else if (ch == '\n') {
				goto ret;
			} else {
				continue;
			}
		}
		
		buffer_arrow++;
		continue;
		ret:
		buffer[buffer_arrow] = '\0';
		buffer_arrow = 0;
		print_char(' ');
		return buffer;
	}
}
