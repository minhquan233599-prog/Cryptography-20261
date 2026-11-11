#include <stdio.h>
#include "gf.h"
#include "print_binary.h"

void runTest(int a, int b, int expected){
    int actual = gf4_multiply(a, b);
    printf("Actual:   ");
    printBinary(actual, 4);
    printf("\nExpected: ");
    printBinary(expected, 4);
    if (actual == expected) {
        printf("\nPASS\n");
    } else {
       printf("\nFAIL\n");
    }
    printf("\n");
}

int main(){
    // Test 1: Nhan voi 0
    runTest(0x0, 0xF, 0x0);

    // Test 2: Nhan voi 1
    runTest(0x1, 0xA, 0xA);

    // Test 3: Phep nhan can rut gon da thuc
    runTest(0x2, 0x8, 0x3);

    // Test 4: Hai gia tri lon nhat trong GF(2^4)
    runTest(0xF, 0xF, 0xA);

    return 0;
}
