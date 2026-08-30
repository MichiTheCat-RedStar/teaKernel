#include <teavideo.h>
#include <teaprint.h>
#include <teaio.h>
#include <teakeyboard.h>
#include <teainput.h>

// kernel main - ядро всего проекта :3
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

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
	
	while (1) {
		print_string("\n> ");
		char* user = input();
		
		// Обработка команды
		if (strcmp(user, "help") == 0) {
			print_string("\nhelp     - show this message");
			print_string("\nclear    - clear screen");
			print_string("\nlicense  - show license");
			print_string("\nshutdown - shutdown QEMU emulation");
		} else if (strcmp(user, "clear") == 0) {
			clear_screen();
		} else if (strcmp(user, "license") == 0) {
			set_color(0xF0);
			print_string("\nMichiTheCat-RedStar (c) 2026 - GPL-3.0");
			set_color(0x0F);
		} else if (strcmp(user, "shutdown") == 0) {
			qemu_poweroff();
		} else if (user[0] != '\0') {
			print_string("\nUnknown command: ");
			print_string(user);
		}
	}
}
