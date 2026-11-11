#include <stdio.h>
#include "print_binary.h"

void printBinary(int n, int bits) {
    // Duyet tu bit cao nhat den bit thap nhat
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}
