#include "teavideo.h"
#include <stdint.h>

// Библиотека для управления VGA MEMORY
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

static volatile uint16_t* video = (uint16_t*)0xB8000;
static unsigned int cursor_position = 0;
static uint8_t cursor_color = 0x0F;


// Очистка экрана (заполняет пробелами)
void clear_screen() {
	cursor_position = 0;
	
	int i;
	for (i = 0; i < 2000; i++) {
		video[i] = (uint16_t)' ' | ((uint16_t)0x0F << 8);
	}
}


// Вывести символ (очистка экрана если символы вышли за лимит в 2000)
void print_char(char c) {
	if (c == '\n') {
		cursor_position = (cursor_position / 80 + 1) * 80;
		
		if (cursor_position >= 2000) {
			clear_screen();
		}
		return;
	}

	video[cursor_position] = (uint16_t)c | ((uint16_t)cursor_color << 8);
	cursor_position++;
}


// Вывести строку по символам
void print_string(const char* str) {
	while (*str) {
		print_char(*str);
		str++;
	}
}


// Задать цвет байтом (старший ниббл - фон, младший - текст)
void set_color(uint8_t color) {
	cursor_color = color;
}


// Вывести шестнадцатеричное значение
void print_hex(uint32_t value) {
	if (value == 0) {
		print_char('0');
		return;
	}
	int started = 0;
	for (int i = 28; i >= 0; i -= 4) { // 4 байта на ниббл (2^4=16 log?)
		uint8_t nibble = (value >> i) & 0xF;
		if (nibble != 0 || started) {
			started = 1;
			char c = (nibble < 10) ? ('0' + nibble) : ('A' + nibble - 10);
			print_char(c);
		}
	}
}


// Вывести двоичное значение с ведущими нулями
void print_32bin(uint32_t value) {
	for (int i = 31; i >= 0; i--) {
		print_char((value >> i) & 1 ? '1' : '0');
	}
}


// Вывести двоичное значение без ведущих нулей
void print_bin(uint32_t value) {
	if (value == 0) {
		print_char('0');
		return;
	}
	int started = 0;
	for (int i = 31; i >= 0; i--) {
		if ((value >> i) & 1) {
			started = 1;
		}
		if (started) {
			print_char((value >> i) & 1 ? '1' : '0');
		}
	}
}


// Вывести беззнаковое десятичное число
void print_dec(uint32_t value) {
	if (value == 0) {
		print_char('0');
		return;
	}
	char buffer[12];
	int idx = 0;
	while (value > 0) {
		buffer[idx++] = '0' + (value % 10);
		value /= 10;
	}
	while (idx > 0) {
		print_char(buffer[--idx]);
	}
}


// Вывести знаковое число
void print_int(int32_t value) {
	if (value < 0) {
		print_char('-');
		uint32_t abs_value = (uint32_t)(-value);
		print_dec(abs_value);
	} else {
		print_dec((uint32_t)value);
	}
}
