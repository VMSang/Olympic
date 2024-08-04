#include <bits/stdc++.h>
using namespace std;

void check(vector<int> v, int n, int c, int mid) {
	int crrCow = v[0], containCow = c - 1;
	for(int i=1; i < n; i++){
		if(v[i] - crrCow >= mid){
			crrCow = v[i];
			containCow--;
			if(containCow == 0)
				break;
		}
	}

	return containCow <= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c; cin >> n >> c;
	vector<int> v(n);
	for (int &x : v)
		cin >> x;

	sort(v.begin(), v.end());
	
	int mid = l+r >> 2;
	while(l < r){
		if(check(v, n, c, mid)){
			//nếu khoảng giả định này đủ cho C con bò
			//tăng mid xem còn cách nào cách xa hơn không
			
		}
	}	


	return 0;
}