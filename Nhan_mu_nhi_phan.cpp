#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binMul(ll a, ll b) {
	ll res = 0;
	while (b > 0) {
		if (b & 1) //b%2 == 1
			res += a;   	//%c
		a <<= 1; //a*2		//%c
		b >>= 1; //b/2
	}
	return res;
}

ll binPow(ll a, ll b) {
	int res = 1;
	while (b > 0) {
		if (b & 1)
			res *= a;	//%c
		a *= a;			//%c
		b >>= 1;
	}
	return res;
}

int main() {
	int a, b; cin >> a >> b;
	cout << "nhan nhi phan = " << binMul(a, b) << endl;
	cout << "mu nhi phan = " << binPow(a, b);

	return 0;
}