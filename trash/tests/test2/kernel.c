void clear_screen() {
    char *video = (char*)0xB8000;
    int i;
    for (i = 0; i < 80 * 25; i++) {
        video[i * 2] = ' ';
        video[i * 2 + 1] = 0x0F;
    }
}

void kmain() {
    clear_screen(); // Добавлено из примечания, подробнее в readme.txt

    char *video = (char*)0xB8000;
    video[0] = 'H';
    video[1] = 0x0F;
    video[2] = 'i';
    video[3] = 0x0F;
    while(1) {}
}

// Пробую писать Hi
