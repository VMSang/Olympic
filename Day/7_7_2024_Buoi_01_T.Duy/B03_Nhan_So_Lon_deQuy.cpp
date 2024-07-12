//chung minh cong thuc: (ab)%c = ((a%c)(b%c))%c
/*
Biểu diễn a và b:
a = k₁c + r₁, trong đó r₁ = a%c (0 ≤ r₁ < c)
b = k₂c + r₂, trong đó r₂ = b%c (0 ≤ r₂ < c)
Khai triển ab:
ab = (k₁c + r₁) * (k₂c + r₂)
= k₁k₂c² + k₁r₂c + k₂r₁c + r₁r₂
Lấy phần dư khi chia cho c:
(a*b) % c = (k₁k₂c² + k₁r₂c + k₂r₁c + r₁r₂) % c
Phân tích từng thành phần:
k₁k₂c² % c = 0 (vì k₁k₂c² = c * (k₁k₂c), luôn chia hết cho c)
k₁r₂c % c = 0 (vì k₁r₂c = c * (k₁r₂), luôn chia hết cho c)
k₂r₁c % c = 0 (vì k₂r₁c = c * (k₂r₁), luôn chia hết cho c)

Áp dụng tính chất của phép chia lấy dư:
(a*b) % c = (0 + 0 + 0 + r₁r₂) % c = r₁r₂ % c
Thay r₁ và r₂:
(a*b) % c = ((a%c) * (b%c)) % c
*/

/*
các giai đoạn cải thiện thuật toán:
gđ1: áp dụng trực tiếp (ab)%c = ((a%c)(b%c))%c   => tràn số khi phần dư quá lớn
gđ2: biểu diễn b dạng nhị phân:
    b = 2^k1 + 2^k2 + ... + 2^kn (biểu diễn nhị phân của b)
    Khi đó: a*b  = a*(2^k1 + 2^k2 + ... + 2^kn)
                = a*2^k1 + a*2^k2 + ... + a*2^kn
    (a*b)%c = ( (a*2^k1)%c + (a*2^k2)%c + ... + (a2^kn)%c ) % c
            ...(a%c * (2^k1)%c)%c...
            ...a%c * bit 1 == (2^k1)%c
                     bit 2 == 0
*/

#include <bits/stdc++.h>
using namespace std;
using long long = long long;

// nhược điểm [(𝑎 % 10^18)×(b % 10^18)] ≤ 10^36
long long nhan_CongThucNguyenBan(long long a, long long b, long long c) {
    return ((a % c) * (b % c)) % c;
}


/* cải tiến của phép nhân ấn độ
(a*b) = a*b/2 + a*b/2 (b chẵn)
      = a*b/2 * a + a*b/2 * a (b lẻ)
*/

long long nhan_nhi_Phan(long long a, long long b, long long c) {
    long long res = 0;
    a %= c; //đảm bảo rằng giá trị của a luôn nhỏ hơn c, tránh tràn số
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % c; //phần dư a khi b lẻ
        }
        //a nhân 2 thì b chia đảm bảo khi triệt tiêu nhau là đúng
        //chỉ chia dư ở a vì chỉ có a tăng lên, b giảm mãi
        a *= 2 % c;
        b /= 2; // bỏ bit cuối
    }
    return res;
}

//có thể tràn ở chỗ a*2 với lần gọi đầu tiên với a rất lớn nhân 2
long long nhan_dequy(long long a, long long b, long long c) {
    if (b == 0)
        return 0;
    long long res = 0;
    if (b % 2 == 0)
        res = a % c;
    return (res + nhan_dequy((a * 2) % c, b / 2, c)) % c;
}

//khắc phục chỉ cần giảm b và nhân 2 vào a khi cần
long long multiply_modulo(long long a, long long b, long long M) {
    if (b == 0)
        return 0;
    long long t = multiply_modulo(a, b / 2, M) % M;
    if (b & 1)
        return ((t + t) % M + a % M) % M;
    else
        return (t + t) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUlong long);

    long long a, b, c;
    cin >> a >> b >> c;
    cout << nhan_dequy(a, b, c);
    return 0;
}
