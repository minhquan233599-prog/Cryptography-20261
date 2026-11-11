Bài tập này thực hiện cài đặt phép nhân trong hai trường hữu hạn GF(2⁴) và GF(2⁸) bằng ngôn ngữ C.

Chương trình sử dụng phép dịch bit và XOR để thực hiện phép nhân, sau đó lấy modulo theo đa thức sinh tương ứng.

## Nội dung thực hiện

- **GF(2⁴):** Sử dụng đa thức \(m(x)=x^4+x+1\).
- **GF(2⁸):** Sử dụng đa thức \(m(x)=x^8+x^4+x^3+x+1\).
- Cài đặt hai hàm `gf4_multiply()` và `gf8_multiply()`.
- Viết các bộ test để kiểm tra kết quả phép nhân.
