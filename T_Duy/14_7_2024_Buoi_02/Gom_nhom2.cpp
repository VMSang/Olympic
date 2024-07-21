#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000000;
int n, q;

int parent[MAX_N], sz[MAX_N];

void make_set(int n){
	for(int i=1; i<=n; i++){
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int x) {
	if (parent[x] != x) parent[x] = find(parent[x]);
	return parent[x];
}

void Union_set(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (sz[x] < sz[y]) swap(x, y);
		parent[y] = x;
		sz[x] += sz[y];
	}
}

int main() {
	cin >> n >> q;

	set<int> se[MAX_N];
	int pos[MAX_N];

	for(int i=1; i<=n; i++){
		se[i].insert(i);
		pos[i] = i;
	}


	while (q--) {
		int type, u, v;
		cin >> type;

		if (type == 1) {
			cin >> u >> v;
			Union_set(u, v);

		} else if (type == 2) {
			cin >> u;
			cout << sz[find(u)] << endl;
		} else if (type == 3) {
			cin >> u;

		}
	}
	
	return 0;
}