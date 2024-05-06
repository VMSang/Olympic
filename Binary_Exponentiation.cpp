/*
	username: Minh Sang
*/
#include <bits/stdc++.h>
//======================================
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz size
#define mp make_pair
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define vdb vector<double>
using namespace std;
//======================================
ll binMul(ll a, ll b){
	ll res = 0;
	while(b>0){
		if(b & 1) //b%2 == 1
			res += a;   	//%c
		a <<= 1; //a*2		//%c
		b >>= 1; //b/2
	}
	return res;
}

ll binPow(ll a, ll b){
	int res = 1;
	while(b>0){
		if(b & 1)
			res *= a;	//%c
		a *= a;			//%c
		b >>= 1;
	}
	return res;
}

int main(){ fast
	int a, b; cin >> a >> b;
	cout << "nhan nhi phan = " <<binMul(a,b) << endl;
	cout<< "mu nhi phan = " <<binPow(a,b);

	return 0;
}