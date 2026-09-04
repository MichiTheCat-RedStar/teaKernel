#include <io/teavideo.h>
#include <system/teaio.h>
#include <system/teakeyboard.h>
#include <io/teainput.h>

// kernel.c teakmain - ядро всего проекта
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

int strcmp(const char* a, const char* b) { // Вынести в отдельный модуль
	while (*a && *b && *a == *b) { a++; b++; } // + добавить в модуль
	return *a - *b; // функции для работы со строками, вроде strip
}

void teakmain() {
	clear_screen();
	set_color(0xF0);
	print_string(" MichiTheCat-RedStar (c) 2026 - GPL-3.0 \n");
	set_color(0x0F);
	print_string("Version v0.16a\nWrite 'help':\n");
	
	while (1) {
		print_string("> ");
		char* user = input();
		
		if (strcmp(user, "help") == 0) {
			set_color(0x0E);
			print_string("\nhelp     - show this message");
			print_string("\nclear    - clear screen");
			print_string("\nlicense  - show license");
			print_string("\nshutdown - shutdown QEMU emulation");
			set_color(0x0F);
		} else if (strcmp(user, "clear") == 0) {
			clear_screen();
		} else if (strcmp(user, "license") == 0) {
			set_color(0xF0);
			print_string("\n MichiTheCat-RedStar (c) 2026 - GPL-3.0 ");
			set_color(0x01);
			print_string("\n https://github.com/MichiTheCat-RedStar ");
			set_color(0x0F);
		} else if (strcmp(user, "shutdown") == 0) {
			qemu_poweroff();
			set_color(0x04);
			print_string("\nIf nothing happens, then the launch is not in QEMU.");
			set_color(0x0F);
		} else if (user[0] != '\0') {
			print_string("\nUnknown command: ");
			print_string(user);
		}
		
		print_char('\n');
	}
}
