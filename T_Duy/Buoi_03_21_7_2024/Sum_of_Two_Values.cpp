#include <bits/stdc++.h>
using namespace std;

long long Search(vector<pair<long long, long long>> &b, int n, int y, int idxX) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (b[mid].first == y && b[mid].second != idxX)
			return b[mid].second;
		else if (b[mid].first > y)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, value; cin >> n >> value;
	vector<long long> a(n);
	for (long long &x : a)
		cin >> x;
	vector<pair<long long, long long>> b(n); //first: value, second: idx (0->n-1)
	for (long long i = 0; i < n; i++) {
		b[i] = {a[i], i};
	}
	sort(b.begin(), b.end());

	for (long long i = 0; i < n; i++) {
		long long y = value - a[i];

		long long check = Search(b, n, y, i);
		if (check != -1) {
			cout << i + 1 <<" "<< check + 1;
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}