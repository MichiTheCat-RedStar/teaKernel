ENTRY(start)          /* указываю start, вместо _start */

SECTIONS {
    /* ядро будет загружено по адресу 1 МБ */
    . = 1M;

    /* секция multiboot должна быть самой первой */
    .multiboot : {
        *(.multiboot)
    }

    .text : {
        *(.text)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }
}
