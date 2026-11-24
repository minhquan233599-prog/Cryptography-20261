#include "gf.h"

uint8_t gf4_multiply(uint8_t a, uint8_t b){
    uint8_t result = 0;
    a = a & 0x0F; // chi giu lai 4 bit thap
    b = b & 0x0F; // chi giu lai 4 bit thap

    for (int i = 0; i < 4; i++) {
        if (b & 1) {
            result = result ^ a; 
        }
        int carry = a & 0x08;   // kiem tra bit cao nhat, tuc la he so cua x^3        
        a = (a << 1) & 0x0F;  // x.a(x)
        if (carry){
            a = a ^ 0x03;     // mod a theo da thuc sinh x^4 + x + 1
        }
        b = b >> 1;
    }
    return result;
}


uint8_t gf8_multiply(uint8_t a, uint8_t b){
    uint8_t result = 0;
    for (int i = 0; i < 8; i++)
    {
        if (b & 1){
            result = result ^ a;
        }
        // kiem tra bit cao nhat cua a
        int carry = a & 0x80;
        a = a << 1;
        if (carry){
            a = a ^ 0x1B; // da thuc sinh x^8 + x^4 + x^3 + x + 1
        }
        b = b >> 1;
    }
    return result;
}
