#include <bits/stdc++.h>
using namespace std;

// Tính a^b % M khử đệ quy.
long long power_modulo_non_recur(long long a, long long b, long long M) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % M;

        a = (a * a) % M; //tăng a^2   a^4   a^8   a^16 ...
        b /= 2;
    }

    return res;
}

long long luythua(long long a, long long b, long long c) {
    if (b <= 0)
        return 1;
    long long res = 1;
    if (b % 2 == 1)
        res = a % c;
    return (res * luythua((a * a) % c, b / 2, c)) % c;
}

// Tính a^b mod M.
long long power_modulo(long long a, long long b, long long M) {
    if (b == 0)
        return 1LL;

    long long half = power_modulo(a, b / 2, M) % M;

    if (b & 1)
        return (((half * half) % M) * (a % M)) % M;
    else
        return (half * half) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c; cin >> a >> b >> c;
    cout << luythua(a, b, c);
    return 0;
}