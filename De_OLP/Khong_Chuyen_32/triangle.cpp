/*
các tam giác trong hình vuông là tam giác vuông cân (1/2 hai cgv)
nên chỉ có thể tính diện tích hcn MNPQ (cạnh bình)
đúng bằng cạnh huyền tính được từ pytago với u và v
sau đó chia 4 vì 4 tam giác băng nhau

link full đề: https://oj.vnoi.info/contest/olp_kc23
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long double u, v;
	cin >> u >> v;
	cout << fixed << setprecision(2) <<(u * u + v * v) / 4.0;

	return 0;
}