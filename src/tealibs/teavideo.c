#include "teavideo.h"
#include <stdint.h>

// Библиотека для управления VGA MEMORY
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

static volatile uint16_t* video = (uint16_t*)0xB8000;
static unsigned int cursor_position = 0;
static uint8_t cursor_color = 0x0F;


void clear_screen() {
	cursor_position = 0;
	
	int i;
	for (i = 0; i < 2000; i++) {
		video[i] = (uint16_t)' ' | ((uint16_t)0x0F << 8);
	}
}


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


void print_string(const char* str) {
	while (*str) {
		print_char(*str);
		str++;
	}
}


void set_color(uint8_t color) {
	cursor_color = color;
}
