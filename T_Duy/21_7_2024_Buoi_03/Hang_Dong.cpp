#include <bits/stdc++.h>
using namespace std;

void cnt(vector<int> v, int )

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h; cin >> n >> h;
	vector<int> duoi;
	vector<int> tren;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (i % 2 == 0) {
			duoi.push_back(x);
		} else {
			tren.push_back(x);
		}
	}
	sort(duoi.begin(), duoi.end());
	sort(tren.begin(), tren.end());

	for(int x : duoi){
		cout<<x<<" ";
	}
	cout<<endl;
	for(int x : tren){
		cout<<x<<" ";
	}

	for(int i=1; i<)

	return 0;
}