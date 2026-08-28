#ifndef TEAIO_H
#define TEAIO_H

#include <stdint.h>

// inb|outb -> 8 бит или один байт
// inw|outw -> 16 бит или два байта
// inl|outl -> 32 бит или четыре байта
// Реализовать в дальнейшем остальные вариации, если будут нужны, а пока:

static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

static inline void outb(uint16_t port, uint8_t val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

#endif
