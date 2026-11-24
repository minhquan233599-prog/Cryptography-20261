#include "aes128.h"

#include <stdio.h>

int main(void)
{
    // Du lieu mau va ban ma dung de so sanh.
    const uint8_t plaintext[16] = {
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x11, 0x11
    };

    const uint8_t key[16] = {0};

    const uint8_t expected[16] = {
        0x44, 0x27, 0x58, 0xDF,
        0x6D, 0xDA, 0x9E, 0xDB,
        0x6B, 0xF1, 0x46, 0x8A,
        0x17, 0xB9, 0x3F, 0xE5
    };

    uint8_t ciphertext[16];
    aes128_encrypt(plaintext, key, ciphertext);

    // In va kiem tra tung byte cua ban ma.
    int passed = 1;
    printf("Ban ma C = ");
    for (int i = 0; i < 16; i++) {
        printf("%02X", (unsigned)ciphertext[i]);
        if (ciphertext[i] != expected[i]) {
            passed = 0;
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
