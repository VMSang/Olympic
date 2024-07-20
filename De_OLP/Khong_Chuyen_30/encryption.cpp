#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l, r, a, k;
    cin >> l >> r >> a >> k;

    if (a % k == 0) {
        // Nếu a chia hết cho k, tất cả các số trong đoạn [l, r] đều thỏa mãn
        cout << (r - l) + 1 << '\n';
    } else {
        long long g = __gcd(a, k);
        // Tính B = K / gcd(A, K)
        long long b = k / g;
        
        // Đếm số lượng số chia hết cho B trong đoạn [l, r]
        long long count = (r / b) - ((l - 1) / b);
        cout << count << '\n';
    }

    return 0;
}
