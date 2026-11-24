#include "des.h"

#include <stdio.h>

// Cac bang DES dem bit tu trai sang phai, bat dau tu 1.
static const uint8_t IP[64] = {
    58, 50, 42, 34, 26, 18, 10,  2,
    60, 52, 44, 36, 28, 20, 12,  4,
    62, 54, 46, 38, 30, 22, 14,  6,
    64, 56, 48, 40, 32, 24, 16,  8,
    57, 49, 41, 33, 25, 17,  9,  1,
    59, 51, 43, 35, 27, 19, 11,  3,
    61, 53, 45, 37, 29, 21, 13,  5,
    63, 55, 47, 39, 31, 23, 15,  7
};

static const uint8_t IP_INVERSE[64] = {
    40,  8, 48, 16, 56, 24, 64, 32,
    39,  7, 47, 15, 55, 23, 63, 31,
    38,  6, 46, 14, 54, 22, 62, 30,
    37,  5, 45, 13, 53, 21, 61, 29,
    36,  4, 44, 12, 52, 20, 60, 28,
    35,  3, 43, 11, 51, 19, 59, 27,
    34,  2, 42, 10, 50, 18, 58, 26,
    33,  1, 41,  9, 49, 17, 57, 25
};

static const uint8_t E[48] = {
    32,  1,  2,  3,  4,  5,
     4,  5,  6,  7,  8,  9,
     8,  9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32,  1
};

static const uint8_t P[32] = {
    16,  7, 20, 21, 29, 12, 28, 17,
     1, 15, 23, 26,  5, 18, 31, 10,
     2,  8, 24, 14, 32, 27,  3,  9,
    19, 13, 30,  6, 22, 11,  4, 25
};

static const uint8_t PC1[56] = {
    57, 49, 41, 33, 25, 17,  9,
     1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
     7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4
};

static const uint8_t PC2[48] = {
    14, 17, 11, 24,  1,  5,
     3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

static const uint8_t KEY_SHIFTS[16] = {
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

static const uint8_t SBOX[8][4][16] = {
    {
        {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
        { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
        { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
        {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13}
    },
    {
        {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
        { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
        { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
        {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9}
    },
    {
        {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
        {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
        {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
        { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12}
    },
    {
        { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
        {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
        {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
        { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14}
    },
    {
        { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
        {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
        { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
        {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3}
    },
    {
        {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
        {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
        { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
        { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13}
    },
    {
        { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
        {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
        { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
        { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12}
    },
    {
        {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
        { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
        { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
        { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11}
    }
};

// Lay tung bit theo thu tu trong bang roi ghep vao ket qua.
static unsigned long long permute(unsigned long long input, int input_bits,
                                  const uint8_t table[], int output_bits)
{
    unsigned long long result = 0;

    for (int i = 0; i < output_bits; i++) {
        unsigned bit = (input >> (input_bits - table[i])) & 1;
        result = (result << 1) | bit;
    }
    return result;
}

// Xoay trai, dua cac bit bi day ra ve ben phai.
static uint32_t rotate_left_28(uint32_t value, int shift)
{
    return ((value << shift) | (value >> (28 - shift))) & 0x0FFFFFFF;
}

void des_encrypt(const uint8_t plaintext[8], const uint8_t key[8],
                 uint8_t ciphertext[8], bool trace)
{
    unsigned long long block = 0;
    unsigned long long key_bits = 0;

    // Ghep 8 byte thanh mot so, byte dau nam ben trai.
    for (int i = 0; i < 8; i++) {
        block = (block << 8) | plaintext[i];
        key_bits = (key_bits << 8) | key[i];
    }

    // Hoan vi IP roi chia ban ro thanh hai nua 32 bit.
    block = permute(block, 64, IP, 64);
    uint32_t left = (uint32_t)(block >> 32);
    uint32_t right = (uint32_t)block;

    if (trace) {
        printf("=== Sau IP ===\nL0 = %08lX, R0 = %08lX\n\n",
               (unsigned long)left, (unsigned long)right);
    }

    // PC-1 bo 8 bit kiem tra. Chia 56 bit con lai thanh C va D.
    key_bits = permute(key_bits, 64, PC1, 56);
    uint32_t c = (uint32_t)(key_bits >> 28);
    uint32_t d = (uint32_t)(key_bits & 0x0FFFFFFF);

    for (int round = 1; round <= 16; round++) {
        // Xoay C va D, sau do dung PC-2 de lay khoa vong 48 bit.
        c = rotate_left_28(c, KEY_SHIFTS[round - 1]);
        d = rotate_left_28(d, KEY_SHIFTS[round - 1]);
        unsigned long long combined_key = ((unsigned long long)c << 28) | d;
        unsigned long long round_key = permute(combined_key, 56, PC2, 48);

        // Mo rong R tu 32 len 48 bit roi XOR voi khoa vong.
        unsigned long long expanded = permute(right, 32, E, 48);
        unsigned long long mixed = expanded ^ round_key;
        uint32_t substituted = 0;
        for (int box = 0; box < 8; box++) {
            int group = (mixed >> (42 - 6 * box)) & 0x3F;
            // Lay 2 bit ngoai lam hang, 4 bit giua lam cot.
            int row = 2 * (group >> 5) + (group & 1);
            int col = (group >> 1) & 0x0F;
            substituted = (substituted << 4) | SBOX[box][row][col];
        }

        // L moi la R cu. R moi la L cu XOR ket qua ham F.
        uint32_t f = (uint32_t)permute(substituted, 32, P, 32);
        uint32_t next_right = left ^ f;
        left = right;
        right = next_right;

        if (trace) {
            printf("=== Vong %d ===\nKhoa vong  = %012llX\n", round, round_key);
            printf("E(R)       = %012llX\nE(R) XOR K = %012llX\n", expanded, mixed);
            printf("Sau S-box  = %08lX\nSau P      = %08lX\n",
                   (unsigned long)substituted, (unsigned long)f);
            printf("L%d = %08lX, R%d = %08lX\n\n",
                   round, (unsigned long)left, round, (unsigned long)right);
        }
    }

    // Ghep R16 truoc L16, hoan vi nguoc roi tach ra 8 byte.
    unsigned long long swapped = ((unsigned long long)right << 32) | left;
    unsigned long long result = permute(swapped, 64, IP_INVERSE, 64);
    if (trace) {
        printf("Truoc IP^-1 = %016llX\nSau IP^-1   = %016llX\n", swapped, result);
    }
    for (int i = 0; i < 8; i++) {
        ciphertext[i] = (uint8_t)(result >> (56 - 8 * i));
    }
}
