#include "teaprint.h"
#include "teavideo.h"
#include <stdint.h>

// Библиотека для вывода текста с буферизацией
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

#define BUFFER_SIZE 2000 // Изначально было 256, но я решил вынести

static char buffer[BUFFER_SIZE];
static uint32_t buffer_index = 0;


// Вывод символов из буфера и очищаем остальное
void printflush() {
	if (buffer_index == 0) return;
	clear_screen();
	buffer[buffer_index] = '\0';
	print_string(buffer);
	buffer_index = 0;
}


// Добавление символов в буфер
void print(const char* str) {
	while (*str) {
		buffer[buffer_index++] = *str++;
		if (buffer_index >= BUFFER_SIZE - 1) printflush();
	}
}
