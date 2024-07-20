// Bài toán 1 : Tìm ước nguyên tố nhỏ nhất của các số từ 1 tới N
// coi ước nguyên tố nhỏ nhất của 1 là chính nó

#include <bits/stdc++.h>
using namespace std;

const int N = 10000001;
int min_prime[N];

void uoc_nho_nhat(int n) {
	// khởi tạo nó băng chính nó vì nếu là snt thì ước nhỏ nhất là chính nó 
	for (int i = 1; i <= n; i++) {
		min_prime[i] = i;
	}

	for (int i = 2; i * i <= n; i++) {
		if (min_prime[i] == i) {
			for (int j = i * i; j <= n; j += i) {
				//chưa được cập nhật lần nào 
				if (min_prime[j] == j) {
					min_prime[j] = i;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	uoc_nho_nhat(n);
	for (int i = 1; i <= n; i++) {
		cout << min_prime[i] << " ";
	}
	return 0;
}