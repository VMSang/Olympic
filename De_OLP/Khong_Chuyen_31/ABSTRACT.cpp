#include <bits/stdc++.h>
using namespace std;

int h[1005][1005];
int nhinThay[1005][1005] = {false};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//nhap
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> h[i][j];
		}
	}

	//xu ly
	//trai sang phai
	for (int i = 0; i < n; i++) {
		int maxH = INT_MIN;
		for (int j = 0; j < m; j++) {
			if (h[i][j] > maxH) {
				maxH = h[i][j];
				nhinThay[i][j] = true;
			}
		}
	}
	//phai sang trai
	for (int i = 0; i < n; i++) {
		int maxH = INT_MIN;
		for (int j = m - 1; j >= 0; j--) {
			if (h[i][j] > maxH) {
				maxH = h[i][j];
				nhinThay[i][j] = true;
			}
		}
	}
	//sau ra truoc
	for(int i=0; i<m; i++){
		int maxH = INT_MIN;
		for(int j=0; j<n; j++){
			if(h[j][i] > maxH){
				maxH = h[j][i];
				nhinThay[j][i] = true;
			}
		}
	}
	//truoc ra sau
	for(int i=0; i<m; i++){
		int maxH = INT_MIN;
		for(int j=n-1; j>=0; j--){
			if(h[j][i] > maxH){
				maxH = h[j][i];
				nhinThay[j][i] = true;
			}
		}
	}

	//tong cot nhin thay
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(nhinThay[i][j] == true){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}