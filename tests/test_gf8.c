
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "gf.h"

// Cau truc luu dau vao va ket qua mong doi
typedef struct {
    uint8_t a;
    uint8_t b;
    uint8_t expected;
} TestVector;

int main(void)
{
    // Cac bo kiem thu cho phep nhan trong GF(2^8)
    // Da thuc bat kha quy: x^8 + x^4 + x^3 + x + 1 (0x11B)
    const TestVector tests[] = {
        {0x00, 0x00, 0x00},
        {0x00, 0xFF, 0x00},
        {0x01, 0xA7, 0xA7},
        {0x02, 0x80, 0x1B},
        {0x57, 0x83, 0xC1},
        {0xFF, 0xFF, 0x13},
        {0x80, 0x80, 0x9A},
        {0x53, 0xCA, 0x01},
        {0x13, 0x11, 0x38},
        {0xF0, 0x0F, 0x27},
        {0xAE, 0x02, 0x47},
        {0x7B, 0xC4, 0xD7}
    };

    size_t total = sizeof(tests) / sizeof(tests[0]);
    size_t passed = 0;
    size_t failed = 0;

    printf("===== GF(2^8) TEST VECTORS =====\n");

    // Duyet qua tung bo kiem thu
    for (size_t i = 0; i < total; i++) {

        // Goi ham nhan can kiem thu
        uint8_t actual = gf8_multiply(tests[i].a, tests[i].b);

        // So sanh ket qua thuc te voi ket qua mong doi
        if (actual == tests[i].expected) {
            passed++;

            printf("[PASS] Test %02zu: %02X * %02X = %02X\n",
                   i + 1, tests[i].a, tests[i].b, actual);
        } else {
            failed++;

            printf("[FAIL] Test %02zu: %02X * %02X | Expected: %02X, Actual: %02X\n",
                   i + 1, tests[i].a, tests[i].b,
                   tests[i].expected, actual);
        }
    }

    // Thong ke ket qua kiem thu
    printf("\n===== GF(2^8) TEST RESULTS =====\n");
    printf("Total : %zu\n", total);
    printf("Passed: %zu\n", passed);
    printf("Failed: %zu\n", failed);

    // Tra ve 0 neu tat ca cac bo kiem thu deu thanh cong
    return failed == 0 ? 0 : 1;
}
