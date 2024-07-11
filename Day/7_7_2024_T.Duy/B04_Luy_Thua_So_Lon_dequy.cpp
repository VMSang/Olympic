#include <bits/stdc++.h>
using namespace std;

long long luythua(long long a, long long b, long long c){
	if(b <= 0) 
        return 1; 
    long long res = 1;
    if(b % 2 == 1)
        res = a % c;
    return (res * luythua((a * a) % c, b / 2, c)) % c; 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c; cin>>a>>b>>c;
    cout<<luythua(a, b, c);
    return 0;
}