#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Công thức tính số Fibonacci thứ n bằng ma trận:
// [ F(n)   ] = Q^(n-1) * [ 1 ]
// [ F(n-1) ]             [ 0 ]
// Trong đó Q là ma trận chuyển đổi:
// Q = [ 1 1 ]
//     [ 1 0 ]

long long a, b, M;

// Hàm nhân hai số với mô-đun M
long long mul(const long long &a, const long long &b) {
    if (b <= 1000000) {
        return (a * b) % M; 
    }
    long long d = b / 1000000;
    long long r = b % 1000000; 
    long long ret = mul(a, d);
    (ret *= 1000000) %= M; 
    (ret += (a * r) % M) %= M;
    return ret; 
}

// Nhân hai ma trận
void matrixMultiply(long long A[2][2], long long B[2][2], long long result[2][2]) {
    long long temp[2][2] = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                temp[i][j] = (temp[i][j] + mul(A[i][k], B[k][j])) % M;
            }
        }
    }
    // Sao chép kết quả vào ma trận kết quả
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = temp[i][j];
        }
    }
}

// Tính lũy thừa của ma trận bằng phương pháp chia nửa
void matrixPower(long long base[2][2], long long n, long long result[2][2]) {
    // Khởi tạo ma trận kết quả là ma trận đơn vị
    result[0][0] = 1;
    result[0][1] = 0;
    result[1][0] = 0;
    result[1][1] = 1;

    long long temp[2][2];
    while (n > 0) {
        if (n % 2 == 1) {
            matrixMultiply(result, base, temp);
            // Cập nhật ma trận kết quả
            result[0][0] = temp[0][0];
            result[0][1] = temp[0][1];
            result[1][0] = temp[1][0];
            result[1][1] = temp[1][1];
        }
        matrixMultiply(base, base, temp);
        // Cập nhật ma trận cơ sở
        base[0][0] = temp[0][0];
        base[0][1] = temp[0][1];
        base[1][0] = temp[1][0];
        base[1][1] = temp[1][1];
        n /= 2;
    }
}

int main() {
    cin >> a >> b >> M;

    long long n = __gcd(a, b);
    if (n <= 1) {
        cout << n % M;
        return 0;
    }

    // Ma trận cơ sở cho dãy Fibonacci
    long long base[2][2] = {{1, 1}, {1, 0}};
    // Ma trận kết quả
    long long result[2][2];

    // Tính lũy thừa ma trận
    matrixPower(base, n - 1, result);

    // Ma trận đơn vị cho dãy Fibonacci
    long long fib[2] = {0, 1};
    long long F_n = (result[0][0] * fib[1] + result[0][1] * fib[0]) % M;

    cout << F_n;
    return 0;
}
