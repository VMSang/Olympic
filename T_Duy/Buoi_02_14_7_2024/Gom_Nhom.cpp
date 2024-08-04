#include <bits/stdc++.h>
using namespace std;

int parent[1000000];
int sz[1000000];
int cnt[1000000];

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
}

int find_set(int v) {
	if (v == parent[v]) return v; // Trả về đỉnh v nếu như đỉnh v là gốc của cây
	int p = find_set(parent[v]); // Đệ quy lên cha của đỉnh v
	parent[v] = p;
	return p;
}

void union_set(int a, int b, set<int> &se) {
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if (sz[a] < sz[b])
			swap(a, b);
		cnt[sz[a]]--;
		cnt[sz[b]]--;
		if (cnt[sz[a]] == 0)
			se.erase(sz[a]);
		if (cnt[sz[b]] == 0)
			se.erase(sz[b]);
		parent[b] = a; //cha là vị trí trước
		sz[a] += sz[b];

		cnt[sz[a]]++;
		if (cnt[sz[a]] == 1) {
			se.insert(sz[a]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	set<int> se = {1};
	cnt[1] = n;
	for (int i = 1; i <= n; i++) {
		make_set(i);
	}

	int q; cin >> q;
	while (q--) {
		int loai; cin >> loai;
		if (loai == 1) {
			int a, b; cin >> a >> b;
			union_set(a, b, se);
		} else if (loai == 2) {
			int u; cin >> u;
			cout << sz[find_set(u)] << "\n";
		} else {
			if (se.size() == 1) {
				cout << "-1" << "\n";
			} else {
				auto it = se.end();
				it--;
				it--;
				cout << *it << "\n";
			}
		}
	}
	return 0;
}