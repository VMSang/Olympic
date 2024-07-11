#include <bits/stdc++.h>
using namespace std;

void search(int a[], int l, int r, int giatri) {
	int m = l + (l + r) / 2;

	if (l > r) return;

	if (a[m] == giatri) {
		cout << m;
		return;
	}
	else if (a[m] < giatri) {
		search(a, l, m, giatri);
	} else {
		search(a, m + 1, r, giatri);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int giatri; cin >> giatri; cout << endl;
	sort(a, a + (n - 1));
	search(a, 0, n - 1, giatri);
	return 0;
}