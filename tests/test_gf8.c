#include <stdio.h>
#include "gf.h"
#include "print_binary.h"

void runTest(int a, int b, int expected) {
    int actual = gf8_multiply(a, b);

    printf("Actual:   ");
    printBinary(actual, 8);

    printf("\nExpected: ");
    printBinary(expected, 8);

    printf("\n");

    if (actual == expected) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }

    printf("\n");
}

int main() {
    // Test 1: Nhan voi 0
    runTest(0x00, 0xFF, 0x00);

    // Test 2: Nhan voi 1
    runTest(0x01, 0xA7, 0xA7);

    // Test 3: Phep nhan can rut gon da thuc
    runTest(0x02, 0x80, 0x1B);

    // Test 4: Phep nhan cho ket qua bang 1
    runTest(0x53, 0xCA, 0x01);

    return 0;
}
