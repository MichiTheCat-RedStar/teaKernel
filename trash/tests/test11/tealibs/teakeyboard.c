#include "teaio.h"
#include <stdint.h>

// Библиотека для общения с legacy keyboard
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

static const char scancode_ascii[128] = { // Таблица скан-кодов ASCII (set 1)
//	'0'  '1'  '2'  '3'  '4'  '5'  '6'  '7'  '8'  '9'  'A'  'B'  'C'  'D'  'E'  'F'	// сканкоды:
	 0,   0,  '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',  0,   0,	// 0x00–0x0F
	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',  0,   0,  'a', 's',	// 0x10–0x1F
	'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'','`',  0,  '\\','z', 'x', 'c', 'v',	// 0x20–0x2F
	'b', 'n', 'm', ',', '.', '/',  0,  '*',  0,  ' ',  0,   0,   0,   0,   0,   0,	// 0x30–0x3F
	 0,   0,   0,   0,   0,   0,   0,  '7', '8', '9', '-', '4', '5', '6', '+', '1',	// 0x40–0x4F
	'2', '3', '0', '.',  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,	// 0x50–0x5F
};


// Перевод по таблице сканкода в ASCII
char scancode_to_ascii(uint8_t sc) {
	if (sc >= 128) return 0;
	return scancode_ascii[sc];
}


// Получение символа ASCII
char read_char(void) {
	uint8_t sc;	// scancode
	char ch;	// char
	while (1) { // В будущем заменить надо на прерывания вместо цикла	(или вообще убрать, сейчас всегда ожидается символ и ничего не выполняется, пока ждётся)
		while (!(inb(0x64) & 1)) {}
		sc = inb(0x60);
		if (sc & 0x80) continue;
		ch = scancode_to_ascii(sc);
		
		// Спецсимволы:
		if (sc == 0x1C) return '\n'; // 0x1C -> Enter
		
		if (ch != 0) return ch;
	}
}
