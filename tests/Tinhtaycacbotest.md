# TÍNH TAY KIỂM THỬ GF(2^4) VÀ GF(2^8)

## Kiểm thử GF(2^4)

Đa thức sinh:

P(x) = x^4 + x + 1 = 10011

Ta có: x^4 = x + 1

### Test 1: 0000 × 1111

0 × 1111 = 0

Kết quả: 0000 (PASS)

### Test 2: 0001 × 1010

1 × 1010 = 1010

Kết quả: 1010 (PASS)

### Test 3: 0010 × 1000

0010 = x
1000 = x^3

x × x^3 = x^4

Do x^4 = x + 1

Kết quả: 0011 (PASS)

### Test 4: 1010 × 1101

1010 = x^3 + x
1101 = x^3 + x^2 + 1

Nhân:

(x^3 + x)(x^3 + x^2 + 1)
= x^6 + x^5 + x^4 + x

Rút gọn theo đa thức sinh:

x^6 + x^5 + x^4 + x
= x^5 + x^4 + x^3 + x^2 + x
= x^4 + x^3
= x^3 + x + 1

Kết quả: 1011 (PASS)

### Test 5: 1111 × 1111

1111 = x^3 + x^2 + x + 1

Nhân:

(x^3 + x^2 + x + 1)^2
= x^6 + x^4 + x^2 + 1

Rút gọn:

x^6 + x^4 + x^2 + 1
= x^4 + x^3 + 1
= x^3 + x

Kết quả: 1010 (PASS)

## Kiểm thử GF(2^8)

Đa thức sinh:

P(x) = x^8 + x^4 + x^3 + x + 1

Dạng nhị phân: 100011011

Ta có:

x^8 = x^4 + x^3 + x + 1

### Test 1: 00000000 × 11111111

0 × 11111111 = 0

Kết quả: 00000000 (PASS)

### Test 2: 00000001 × 10100111

1 × 10100111 = 10100111

Kết quả: 10100111 (PASS)

### Test 3: 00000010 × 10000000

00000010 = x
10000000 = x^7

x × x^7 = x^8

Rút gọn theo đa thức sinh:

x^8 = x^4 + x^3 + x + 1

Kết quả: 00011011 (PASS)

### Test 4: 01010111 × 10000011
01010111 = x^6 + x^4 + x^2 + x + 1
10000011 = x^7 + x + 1

A(x) × B(x)
= x^13 + x^11 + x^9 + x^8 + x^6
+ x^5 + x^4 + x^3 + 1

Đổi sang hệ 16: 0x2B79

Rút gọn theo đa thức sinh 0x11B:

0x2B79 XOR 0x2360 = 0x0819
0x0819 XOR 0x08D8 = 0x00C1

Kết quả: 11000001 (PASS)

### Test 5: 01010011 × 11001010

01010011 = x^6 + x^4 + x + 1
11001010 = x^7 + x^6 + x^3 + x

A(x) × B(x)
= x^13 + x^12 + x^11 + x^10 + x^9
+ x^8 + x^6 + x^5 + x^4 + x^3
+ x^2 + x

Đổi sang hệ 16: 0x3F7E

Rút gọn theo đa thức sinh 0x11B:

0x3F7E XOR 0x2360 = 0x1C1E
0x1C1E XOR 0x11B0 = 0x0DAE
0x0DAE XOR 0x08D8 = 0x0576
0x0576 XOR 0x046C = 0x011A
0x011A XOR 0x011B = 0x0001

Kết quả: 00000001 (PASS)

