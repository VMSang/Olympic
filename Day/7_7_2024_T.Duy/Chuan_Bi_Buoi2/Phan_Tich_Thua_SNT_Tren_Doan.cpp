// Bài toán 2 : Phân tích thừa số nguyên tố kết hợp sàng số nguyên tố
// phương pháp này hiệu quả khi cần phân tích nhiều số nguyên tố trong đoạn cho trước
// Còn nếu chỉ phân tích 1 số thì nên làm theo phương pháp thông thường.

#include <bits/stdc++.h>
using namespace std;

const int N = 10000001;
int prime[N];

void sang() {
	for (int i = 1; i <= N ; i++) {
		prime[i] = i;
	}

	for (int i = 2; i * i <= N; i++) {
		for (int j = i * i; j <= N; j += i) {
			if (prime[j] == j ) {
				prime[j] = i;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	sang();
	for (int i = a; i <= b; i++) {
		int num = i;
		cout << num << " = ";
		while (num != 1) {
			cout << prime[num] << " ";
			num /= prime[num];
		}

		cout << endl;
	}

	return 0;
}
