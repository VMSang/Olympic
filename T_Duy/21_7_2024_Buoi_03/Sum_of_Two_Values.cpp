#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x; cin >> n >> x;
	vector<pair<int, int>> v(n);

	for (int i = 1; i <= n; i++) {
		int value; cin >> value;
		v[i - 1].first = value;
		v[i - 1].second = i;
	}

	sort(v.begin(), v.end());

	// (a < x)  +  (b == x-a)

	//all a<x;

	int idxA;
	for(int i=0; i<n; i++){
		if(v[i].first < x){
			idxA = v[i].second;
			break;
		}
	}

	int valueA = v[idxA].first; 
	int idxB;
	for(int i=0; i<n; i++){
		if(valueA + v[i].first){
			idxB= v[i].second;
		}
	}

	//print
	cout<<idxA<<" "<<idxB;
	return 0;
}