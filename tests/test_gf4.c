
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
    // Cac bo kiem thu cho phep nhan trong GF(2^4)
    // Da thuc bat kha quy: x^4 + x + 1 (0x13)
    const TestVector tests[] = {
        {0x0, 0x0, 0x0},
        {0x0, 0xF, 0x0},
        {0x1, 0xA, 0xA},
        {0x2, 0x8, 0x3},
        {0xA, 0xD, 0xB},
        {0xF, 0xF, 0xA},
        {0x8, 0x2, 0x3},
        {0x7, 0x9, 0xA},
        {0x3, 0x5, 0xF},
        {0xC, 0xB, 0xD},
        {0x8, 0x8, 0xC},
        {0xE, 0x7, 0xC}
    };

    size_t total = sizeof(tests) / sizeof(tests[0]);
    size_t passed = 0;
    size_t failed = 0;

    printf("===== GF(2^4) TEST VECTORS =====\n");

    // Duyet qua tung bo kiem thu
    for (size_t i = 0; i < total; i++) {

        // Goi ham nhan can kiem thu
        uint8_t actual = gf4_multiply(tests[i].a, tests[i].b);

        // So sanh ket qua thuc te voi ket qua mong doi
        if (actual == tests[i].expected) {
            passed++;

            printf("[PASS] Test %02zu: %X * %X = %X\n",
                   i + 1, tests[i].a, tests[i].b, actual);
        } else {
            failed++;

            printf("[FAIL] Test %02zu: %X * %X | Expected: %X, Actual: %X\n",
                   i + 1, tests[i].a, tests[i].b,
                   tests[i].expected, actual);
        }
    }

    // Thong ke ket qua kiem thu
    printf("\n===== GF(2^4) TEST RESULTS =====\n");
    printf("Total : %zu\n", total);
    printf("Passed: %zu\n", passed);
    printf("Failed: %zu\n", failed);

    // Tra ve 0 neu tat ca cac bo kiem thu deu thanh cong
    return failed == 0 ? 0 : 1;
}
