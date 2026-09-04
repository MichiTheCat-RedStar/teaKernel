#ifndef TEAVIDEO_H
#define TEAVIDEO_H

#include <stdint.h>

void clear_screen(void);
void print_char(char c);
void print_string(const char* str);
void set_color(uint8_t color);
void print_hex(uint32_t value);
void print_32bin(uint32_t value);
void print_bin(uint32_t value);
void print_dec(uint32_t value);
void print_int(int32_t value);
void print_colored_string(const char* str, uint8_t color);

#endif
