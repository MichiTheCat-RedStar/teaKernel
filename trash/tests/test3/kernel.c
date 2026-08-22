#include <stdint.h>		// Как я понял, должно быть доступно даже там

static volatile uint16_t* video = (uint16_t*)0xB8000;	// VGA вместо 0xB8000
static unsigned int cursor_position = 0;				// Позиция коретки
static uint8_t cursor_color = 0x0F;						// Цвет коретки


void clear_screen() {	// Изменил функцию под актуальный стандарт
	cursor_position = 0; // Обнуляю позицию курсора
	
	int i; // Так же в цикле просто закрашиваю пробелами экран
	for (i = 0; i < 2000; i++) { // 80 * 25 = 2000 символов (хардкод не мой)
		video[i] = (uint16_t)' ' | ((uint16_t)0x0F << 8);
	}
}


void print_char(char c) { // Создаю функцию для вывода символа
	if (c == '\n') { // Проверяю на '\n'
		cursor_position = (cursor_position / 80 + 1) * 80;
		// Переход на новую строку
		
		if (cursor_position >= 2000) {
			// Если вылезло за 80 столбцов и 25 строк
			clear_screen();
		}
		return; // Выхожу, чтобы символ не печатать
	}

	video[cursor_position] = (uint16_t)c | ((uint16_t)cursor_color << 8);
	cursor_position++;
}


void print_string(const char* str) {
	while (*str) {
		print_char(*str); // Господи Боже, хоть бы работало так, как я думаю
		str++;			  // Я питонист и болят глазки в C документацию
	}					  // нырять, лучше бы на Nim писал...
}


void kmain() {
	clear_screen();
	
	print_string("Hello, teaKernel!\n");
	print_string("Test new line!");

	while (1) {}
}
