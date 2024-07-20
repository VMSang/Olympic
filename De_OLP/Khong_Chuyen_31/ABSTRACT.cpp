//đọc kĩ đề bài, vì cột có thể bằng 0, nên không khởi tạo INT_MIN được
//vì nó sẽ đếm luôn cái 0 này 
#include <bits/stdc++.h>
using namespace std;

int h[1005][1005];
bool nhinThay[1005][1005] = {false};

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
		if (h[i][0] > 0)
			nhinThay[i][0] = true;
		int maxH = 0;
		for (int j = 0; j < m; j++) {
			if (h[i][j] > maxH) {
				maxH = h[i][j];
				nhinThay[i][j] = true;
			}
		}
	}
	//phai sang trai
	for (int i = 0; i < n; i++) {
		if (h[i][m - 1] > 0)
			nhinThay[i][m - 1] = true;
		int maxH = 0;
		for (int j = m - 1; j >= 0; j--) {
			if (h[i][j] > maxH) {
				maxH = h[i][j];
				nhinThay[i][j] = true;
			}
		}
	}
	//sau ra truoc
	for (int j = 0; j < m; j++) {
		if (h[0][j] > 0)
			nhinThay[0][j] = true;
		int maxH = 0;
		for (int i = 0; i < n; i++) {
			if (h[i][j] > maxH) {
				maxH = h[i][j];
				nhinThay[i][j] = true;
			}
		}
	}
	//truoc ra sau
	for (int j = 0; j < m; j++) {
		if (h[n - 1][j] > 0)
			nhinThay[n - 1][j] = true;
		int maxH = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (h[i][j] > maxH) {
				maxH = h[i][j];
				nhinThay[i][j] = true;
			}
		}
	}

	//tong cot nhin thay
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (nhinThay[i][j] == true) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}