void clear_screen() {
	char *video = (char*)0xB8000;
	int i;
	for (i = 0; i < 80 * 25; i++) {
		video[i * 2] = ' ';
		video[i * 2 + 1] = 0x0F;
	}
}

void kmain() {
	clear_screen();
	
	char *video = (char*)0xB8000;
	int n = 0;
	
	while(1) {
		video[n++]++;
		if (n > 4000) n = 0;
	}
}
