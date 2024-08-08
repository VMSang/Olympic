#include <bits/stdc++.h>
using namespace std;
//sai voi test: 1 3 2 5 7 1
int main() {
	int n; cin >> n;
	int a[n];
	for(int &x : a) cin>>x;

	int result = INT_MIN;
	int max_pair = INT_MIN;
	int max_a = INT_MIN;

	for (int i = 1; i < n; ++i) {
		// cout << " max_a = "<< max_a <<endl;
		if (i >= 2) {
			max_pair = max(max_pair, max_a + a[i]);
			result = max(result, max_pair - a[i]);
		}
		//để ở đây vì sẽ cập nhật sau khi đã dùng ở trên
		//max [0, i-1]
		max_a = max(max_a, a[i - 1]);

		// cout << " " << "max_pair = " << max_pair << " " << "result = " << result << "\n";
	}

	cout << result;
	return 0;
}
