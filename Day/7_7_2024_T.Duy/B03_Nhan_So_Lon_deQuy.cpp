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
using ll = long long;

ll nhan_CongThucNguyenBan(ll a, ll b, ll c) {
    return (a * b) % c = ((a % c) * (b % c)) % c;
}

ll nhan_Loop(ll a, ll b, ll c) {
    ll res = 0;
    a %= c; //đảm bảo không tràn khi a là chẵn (bit cuối == 0)
    while (b > 0) { //mỗi lần bỏ đi 1 bit, khi b == 0 tương đương bit 0 thì dừng
        if (b & 1) { //bit 1 thì tính
            res = (res + a) % c;
        }
        a*=2;
        b /= 2; // bỏ bit cuối
    }
}

long long nhan_dequy(long long a, long long b, long long c) {
    if (b <= 0)
        return 0;
    long long res = 0;
    if (b % 2 == 1)
        res = a % c;
    return (res + nhan_dequy((a * 2) % c, b / 2, c)) % c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;
    cout << nhan_dequy(a, b, c);
    return 0;
}
