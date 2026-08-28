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
		char ch = read_char();
		print_char(ch);
	}
}
