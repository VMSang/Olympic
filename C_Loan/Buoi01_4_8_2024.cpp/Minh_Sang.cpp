#include <bits/stdc++.h>
using namespace std;

bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ifstream infile("LUYENTAP.INP");
	ofstream outfile("LUYENTAP.OUT");

	int n, c; cin >> n >> c;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v[i] = {x, y};
	}

	sort(v.begin(), v.end(), customComparator);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (c >= v[i].first) {
			c += v[i].second;
			cnt++;
		}
		else {
			break;
		}
	}
	cout<<cnt;

	return 0;
}