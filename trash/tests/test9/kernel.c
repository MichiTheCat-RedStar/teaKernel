#include <teavideo.h>
#include <teaprint.h>
#include <teaio.h>
#include <teakeyboard.h>

// kernel main - ядро всего проекта :3
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

void kmain() {
	clear_screen();
	print_string("Test teaio.h and teakeyboard.h:\n> ");
	
	while (1) {
		if (inb(0x64) & 0x01) { // Проверяю бит 0
			uint8_t scancode = inb(0x60);
			
			if ((scancode & 0x80) == 0) { // Игнорируем отпускания
				char ch = scancode_to_ascii(scancode); // Перевожу в ASCII
				if (ch) { // Если не спецсимвол, то не 0				(сомтрите teakeyboard.h)
					print_char(ch);
				} else { // Обработка специальных клавиш или символов
					if (scancode == 0x1C) { // Сканкод Enter
						print_char('\n');
					}
				}
			}
		}
	}
}
