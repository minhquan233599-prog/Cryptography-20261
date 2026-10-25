# Bài tập: Phép nhân trong GF(2⁴) và GF(2⁸)

## 1. Giới thiệu

Trịnh Minh Quân - 20233599

Bài tập này thực hiện cài đặt phép nhân trong hai trường hữu hạn GF(2⁴) và GF(2⁸) bằng ngôn ngữ C.

Chương trình sử dụng phép dịch bit và XOR để thực hiện phép nhân, sau đó lấy modulo theo đa thức bất khả quy tương ứng.

## 2. Nội dung thực hiện

- **GF(2⁴):** Sử dụng đa thức \(m(x)=x^4+x+1\).
- **GF(2⁸):** Sử dụng đa thức \(m(x)=x^8+x^4+x^3+x+1\).
- Cài đặt hai hàm `gf4_multiply()` và `gf8_multiply()`.
- Viết các bộ test để kiểm tra kết quả phép nhân.

## 3. Cấu trúc thư mục

```text
include/
    gf.h
src/
    gf.c
    main.c
tests/
    test_gf4.c
    test_gf8.c
```

## 4. Biên dịch và chạy

**Chương trình chính:**

```powershell
gcc -std=c11 -Iinclude src/main.c src/gf.c -o gf.exe
.\gf.exe
```

**Kiểm thử GF(2⁴):**

```powershell
gcc -std=c11 -Iinclude tests/test_gf4.c src/gf.c -o test_gf4.exe
.\test_gf4.exe
```

**Kiểm thử GF(2⁸):**

```powershell
gcc -std=c11 -Iinclude tests/test_gf8.c src/gf.c -o test_gf8.exe
.\test_gf8.exe
```

## 5. Kiểm thử

Mỗi trường sử dụng 12 bộ test với các giá trị đầu vào và kết quả mong đợi được xác định trước.

Chương trình so sánh kết quả tính toán với kết quả mong đợi và thông báo `PASS` hoặc `FAIL`.

Mục tiêu là kiểm tra tính đúng đắn của hai hàm nhân đã cài đặt.