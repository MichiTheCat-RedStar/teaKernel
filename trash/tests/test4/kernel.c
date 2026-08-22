#include "tealibs/teavideo.h" // Вынес в отдельный модуль

// kernel main - ядро всего проекта :3
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

void kmain() {		// <- main тут
	clear_screen();
	
	print_string("Hello, teaKernel!\n");
	print_string("Test new line!");
	
	set_color(0x24); // Новая функция
	print_string("\nRed on Green TEST!");
	
	while (1) {}
}
