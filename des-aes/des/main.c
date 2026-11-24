#include "des.h"

#include <stdio.h>

int main(void)
{
    // Bo du lieu mau va ban ma dung de so sanh.
    const uint8_t plaintext[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    const uint8_t key[8] = {0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF, 0xF1};
    const uint8_t expected[8] = {0x85, 0xE8, 0x13, 0x54, 0x0F, 0x0A, 0xB4, 0x05};
    uint8_t ciphertext[8];

    des_encrypt(plaintext, key, ciphertext, true);

    // In va kiem tra tung byte cua ban ma.
    bool passed = true;
    printf("Ban ma C = ");
    for (int i = 0; i < 8; i++) {
        printf("%02X", (unsigned)ciphertext[i]);
        if (ciphertext[i] != expected[i]) {
            passed = false;
        }
    }
    printf("\n");

    if (passed) {
        printf("Kiem tra ban ma: PASS\n");
        return 0;
    }

    printf("Kiem tra ban ma: FAIL\n");
    return 1;
}
