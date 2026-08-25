#include <teavideo.h>
#include <teaprint.h>

// kernel main - ядро всего проекта :3
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

void kmain() {
	
	clear_screen();
	print_string("MichiTheCat-RedStar (c) 2026 - GPL-3.0\n");
	set_color(0x01);
	print_hex(0xE60C0C);
	print_char('\n');
	set_color(0x04);
	print_bin(0b000111000);
	set_color(0x0F);
	print_string(" <- bin | 32bin -> ");
	set_color(0x04);
	print_32bin(0b000111000);
	print_char('\n');
	set_color(0x02);
	print_int(-3);
	set_color(0xF0);
	print_string("\nEOF!");
	
	while (1) {}
}
