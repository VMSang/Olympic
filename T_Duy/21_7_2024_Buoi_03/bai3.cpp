#include <bits/stdc++.h>
using namespace std;

long long SumMoney(vector<pair<long long, long long>>& phai, vector<pair<long long, long long>>& trai, long long m, long long n, long long R, long long dv) {
	long long sum = 0;
	for (long long i = 0; i < m; i++) {
		if (phai[i].first >= dv) {
			sum += phai[i].second;
		}
	}
	for (long long i = 0; i < n; i++) {
		if (trai[i].first >= R - dv) {
			sum += trai[i].second;
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long R, m, n;
	cin >> R >> m >> n;
	vector<pair<long long, long long>> phai(m), trai(n);

	for (auto &x : phai)
		cin >> x.first;
	for (auto &x : phai)
		cin >> x.second;
	for (auto &x : trai)
		cin >> x.first;
	for (auto &x : trai)
		cin >> x.second;

	long long l = 0, r = R + 1;
	// long long MAX = 0;

	// while (l <= r) {
	// 	long long mid = (l + r) / 2;
	// 	long long moneyMid = SumMoney(phai, trai, m, n, R, mid);

	// 	MAX = max(MAX, moneyMid);

	// 	if (SumMoney(phai, trai, m, n, R, mid + 1) > moneyMid) {
	// 		l = mid + 1;
	// 	} else {
	// 		r = mid - 1;
	// 	}
	// }
	long long MAX = 0;
	for (long long pos = 0; pos <= R; pos++) {
		long long currentMoney = SumMoney(phai, trai, m, n, R, pos);
		MAX = max(MAX, currentMoney);
	}
	cout << MAX << "\n";
	return 0;
}