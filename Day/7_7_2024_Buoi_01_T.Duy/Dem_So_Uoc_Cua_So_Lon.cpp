#include <bits/stdc++.h>
using namespace std;

long long binaryPower(long long a, long long b, long long c) {
	if (b == 0)
		return 1;
	long long res = 1;
	while (b) {
		if (b & 1)
			res = res * a % c;

		a = a * a % c;
		b /= 2;
	}
	return res;
}

bool isProbalyPrime(long long n) {
	if (n <= 10)
		return n == 2 || n == 3 || n == 5 || n == 7;
	int k = 10;
	for (int i = 0; i < k; i++) {
		long long a = rand() % (n - 3) + 2; //0->n-4
		if (binaryPower(a, n - 1, n) != 1)
			return false;
	}
	return true;
}

vector<pair<long long, long long>> pttsnt(long long n) {
	vector<pair<long long, long long>> v;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			long long cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			v.push_back({i, cnt});
		}
	}
	if (n != 1)
		v.push_back({n, 1});
	return v;
}

long long uoc(vector<pair<long long, long long>> v) {
	long long cnt = 1;
	for (auto x : v) {
		cnt *= (x.second + 1);
	}
	return cnt;
}

long long uocSNT(vector<pair<long long, long long>> v) {
	long long cnt = 0;
	for (auto x : v) {
		if (isProbalyPrime(x.first))
			cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n; cin >> n;
	auto tsnt = pttsnt(n);
	cout << uocSNT(tsnt) << " " << uoc(tsnt);

	return 0;
}