#include <teavideo.h>
#include <teaprint.h>
#include <teaio.h>

// kernel main - ядро всего проекта :3
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

void kmain() {
	clear_screen();
	print_string("Test teaio.h:\n");
	
	while (1) {
		if (inb(0x64) & 0x01) { // Проверяю бит 0
			uint8_t scancode = inb(0x60);
			
			if ((scancode & 0x80) == 0) { // Игнорируем отпускания
				print_hex(scancode);
				print_char(' ');
			}
		}
	}
}
