#ifndef AES128_H
#define AES128_H

#include <stdint.h>

// Ma hoa mot khoi 16 byte voi khoa 16 byte va in cac buoc tinh.
void aes128_encrypt(const uint8_t plaintext[16], const uint8_t key[16],
                    uint8_t ciphertext[16]);

#endif
