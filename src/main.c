
#include <stdio.h>
#include "gf.h"

int main(void)
{
    // GF(2^4)
    uint8_t a4 = 0b1010;
    uint8_t b4 = 0b1101;
    uint8_t result4 = gf4_multiply(a4, b4);

    printf("GF(2^4): 1010 * 1101 = ");

    for (int i = 3; i >= 0; i--)
    {
        printf("%u", (unsigned)((result4 >> i) & 1u));
    }

    printf("\n");

    // GF(2^8)
    uint8_t a8 = 0b10000000;
    uint8_t b8 = 0b00000010;
    uint8_t result8 = gf8_multiply(a8, b8);

    printf("GF(2^8): 10000000 * 00000010 = ");

    for (int i = 7; i >= 0; i--)
    {
        printf("%u", (unsigned)((result8 >> i) & 1u));
    }

    printf("\n");

    return 0;
}
