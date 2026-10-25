
#include "gf.h"

uint8_t gf4_multiply(uint8_t a, uint8_t b)
{
    uint8_t result = 0b0000;

    uint8_t mask = 0b1111; // giu lai 4 bit
    uint8_t reduction = 0b0011;

    a = a & mask; // chi giu lai 4 bit thap
    b = b & mask;

    for (int i = 0; i < 4; i++)
    {
        if (b & 0b0001)
        {
            result = result ^ a; 
        }

        uint8_t carry = a & 0b1000;   // check he so x^3

        a = (a << 1) & mask; // x.a(x)

        if (carry)
        {
            a = a ^ reduction;      // mod
        }

        b = b >> 1;
    }

    return result;
}


uint8_t gf8_multiply(uint8_t a, uint8_t b)
{
    uint8_t result = 0b00000000;

    uint8_t mask = 0b11111111;
    uint8_t reduction = 0b00011011;

    for (int i = 0; i < 8; i++)
    {
        if (b & 0b00000001)
        {
            result = result ^ a;
        }

        uint8_t carry = a & 0b10000000;

        a = (a << 1) & mask;

        if (carry)
        {
            a = a ^ reduction;
        }

        b = b >> 1;
    }

    return result;
}
