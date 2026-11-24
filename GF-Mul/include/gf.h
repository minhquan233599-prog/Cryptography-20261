#ifndef GF_H
#define GF_H

#include <stdint.h>
#include <stdio.h>

// khai bao 2 ham nhan truong GF(2^4) va GF(2^8)
uint8_t gf4_multiply(uint8_t a, uint8_t b);
uint8_t gf8_multiply(uint8_t a, uint8_t b);

#endif