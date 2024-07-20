#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<int> v(n);
    int start; cin>>start;
    v[0] = start;
    for(int i=1; i<n; i++){
    	cin>>v[i];
    	if(v[i] > v[i-1]){
    		dem++;
    		if(dem > Max){
    			p.first = dem - i;
    			p.second = dem;
    			Max = dem; 
    		}
    	}
    }


    return 0;
}