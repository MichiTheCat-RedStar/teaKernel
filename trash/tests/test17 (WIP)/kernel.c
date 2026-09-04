#include <io/teavideo.h>
#include <system/teaio.h>
#include <system/teakeyboard.h>
#include <io/teainput.h>

// kernel.c teakmain - ядро всего проекта
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

#define KVERSION "v0.17a"

int strcmp(const char* a, const char* b) { // Вынести в отдельный модуль
	while (*a && *b && *a == *b) { a++; b++; } // + добавить в модуль
	return *a - *b; // функции для работы со строками, вроде strip
}

void teakmain() {
	clear_screen();
	print_colored_string(" MichiTheCat-RedStar (c) 2026 - GPL-3.0 \n", 0xF0);
	print_string("Version " KVERSION " | Write 'help':\n");
	
	while (1) {
		print_string("> ");
		char* user = input();
		
		if (strcmp(user, "help") == 0) { // Тут тест print_colored_string() - по идее это менее оптимизировано, так как вечно переключает цвет курсора, но удобнее и порой по скорости так же
			print_colored_string("\nhelp     ", 0x0E);
			print_string("- show this message");
			print_colored_string("\nclear    ", 0x0E);
			print_string("- clear screen");
			print_colored_string("\nlicense  ", 0x0E);
			print_string("- show license");
			print_colored_string("\nshutdown ", 0x0E);
			print_string("- shutdown QEMU emulation");
		} else if (strcmp(user, "clear") == 0) {
			clear_screen();
		} else if (strcmp(user, "license") == 0) {
			print_colored_string("\n MichiTheCat-RedStar (c) 2026 - GPL-3.0 ", 0xF0);
			print_colored_string("\n https://github.com/MichiTheCat-RedStar ", 0x0B);
		} else if (strcmp(user, "shutdown") == 0) {
			qemu_poweroff();
			print_colored_string("\n[!] If nothing happens, then the launch is not in QEMU.", 0x04);
		} else if (user[0] != '\0') {
			print_string("\nUnknown command: ");
			print_string(user);
		}
		
		print_char('\n');
	}
}
