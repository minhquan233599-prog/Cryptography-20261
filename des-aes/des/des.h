#ifndef DES_H
#define DES_H

#include <stdbool.h>
#include <stdint.h>

// Ma hoa mot khoi 8 byte voi khoa 8 byte (gom ca 8 bit kiem tra).
// Truyen true vao trace de in cac buoc tinh.
void des_encrypt(const uint8_t plaintext[8], const uint8_t key[8],
                 uint8_t ciphertext[8], bool trace);

#endif
