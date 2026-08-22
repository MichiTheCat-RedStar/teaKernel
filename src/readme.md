### Полый teaKernel

**Данное руководство о том, как писать код для полого teaKernel**

1. Откройте файл [`kernel.c`](kernel.c)
2. В нёс есть строка `// Вставьте Ваш код тут` - вместо этой строки пишите свой код
3. Так как это полая версия, она умеет только выводить текст, состоит из четырёх функций:
	1. `clear_screen();` - используйте для того, чтобы убрать текст с экрана
	2. `print_char(char c);` - используется для того, чтобы вывести один символ
	3. `print_string(char* str);` - используется для того, чтобы вывести строку
	4. ``set_color(uint8_t color);` - используется для смены цвета текста
	
#### Примеры:

Вы можете написать код, позволяющий вывести "Hello World!" в виде зелёного текста на чёрном фоне, для этого вам нужно:

1. Написать `set_color(0x02);`
2. Написать `print_string("Hello World!");`

**Итог:**

```c
set_color(0x02);
print_string("Hello World!");
```

или целиком:

```c
#include "tealibs/teavideo.h"

// Базовая "Полая" версия ядра teaKernel
// MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0

void kmain() {
	clear_screen();
	
	set_color(0x02);
	print_string("Hello World!");
	
	while (1) {}
}
```

set_color тут работает с одним байтом, где один ниббл указывает на цвет фона, а другой на цвет текста, подробнее можно увидеть в этой таблице:

| Dec | Hex | Color          |
|-----|-----|----------------|
| 0   | 0   | Black          |
| 1   | 1   | Blue           |
| 2   | 2   | Green          |
| 3   | 3   | Cyan           |
| 4   | 4   | Red            |
| 5   | 5   | Magenta        |
| 6   | 6   | Brown          |
| 7   | 7   | Light Gray     |
| 8   | 8   | Dark Gray      |
| 9   | 9   | Light Blue     |
| 10  | A   | Light Green    |
| 11  | B   | Light Cyan     |
| 12  | C   | Light Red      |
| 13  | D   | Light Magenta  |
| 14  | E   | Yellow         |
| 15  | F   | White          |

Здесь Hex - это значение в ниббле, а Color - это цвет, который его обозначает

#### Сборка:

```bash
nasm -f elf32 boot.asm -o boot.o
gcc -m32 -ffreestanding -nostdlib -Wall -Wextra -Itealibs -c kernel.c -o kernel.o
gcc -m32 -ffreestanding -nostdlib -Wall -Wextra -Itealibs -c tealibs/teavideo.c -o tealibs/teavideo.o
ld -m elf_i386 -T linker.ld -o kernel.elf boot.o kernel.o tealibs/teavideo.o
qemu-system-i386 -kernel kernel.elf
```

---

*Базовый пример работы.*

*MichiTheCat-RedStar (c) 2026 ☭ GPL-3.0.*