#include <bits/stdc++.h>
using namespace std;

long long binaryPower(long long a, long long b, long long c){
	if(b == 0)
		return 1;
	long long res = 1;
	while(b){
		if(b & 1)
			res = res * a % c;

		a = a * a % c;
		b /= 2;
	}
	return res;
}

bool isProbalyPrime(long long n){
	if(n <= 10)
		return n == 2 || n == 3 || n == 5 || n == 7;
	int k = 10;
	for(int i=0; i<k; i++){
		long long a = rand()%(n-3) + 2; //0->n-4
		if(binaryPower(a, n-1, n) != 1)
			return false;
	}
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; cin>>n;
    if(isProbalyPrime(n))
    	cout<<"YES";
    else
    	cout<<"NO";
    return 0;
}