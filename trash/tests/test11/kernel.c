#include <teavideo.h>
#include <teaprint.h>
#include <teaio.h>
#include <teakeyboard.h>

// kernel main - ядро всего проекта :3
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

static char teabuffer[17];
static uint8_t teabuffer_arrow = 0;

int strcmp(const char* a, const char* b) {
	while (*a && *b && *a == *b) { a++; b++; }
	return *a - *b;
}

void kmain() {
	clear_screen();
	set_color(0xF0);
	print_string("MichiTheCat-RedStar (c) 2026 - GPL-3.0\n");
	set_color(0x0F);
	print_string("Write 'help':");
	
	char teabuffer[17]; // Буфер для команды
	int  teabuffer_arrow = 0;
	
	while (1) {
		print_string("\n> ");
		teabuffer_arrow = 0;
		
		while (1) {
			char ch = read_char();
			
			if (ch == '\n') {
				teabuffer[teabuffer_arrow] = '\0';
				break;
			} else if (teabuffer_arrow < 15) {
				teabuffer[teabuffer_arrow++] = ch;
				print_char(ch);
			}
		}
		
		// Обработка команды
		if (strcmp(teabuffer, "help") == 0) {
			print_string("\nhelp    - show this message");
			print_string("\nclear   - clear screen");
			print_string("\nlicense - show license");
		} else if (strcmp(teabuffer, "clear") == 0) {
			clear_screen();
		} else if (strcmp(teabuffer, "license") == 0) {
			set_color(0xF0);
			print_string("\nMichiTheCat-RedStar (c) 2026 - GPL-3.0\n");
			set_color(0x0F);
		} else if (teabuffer[0] != '\0') {
			print_string("\nUnknown command: ");
			print_string(teabuffer);
		}
	}
}
