#include <bits/stdc++.h>
using namespace std;

int a[30001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ifstream infile("SN.INP");
    ofstream outfile("SN.OUT"); 

 	int n; cin>>n;
 	for(int i=0; i<n; i++){
 		int x; cin>>x;
 		a[x] = 1;
 	}
 	for(int i=0; i<1000000001; i++){
 		if(a[i] == 0){
 			cout<<i;
 			break; 
 		}
 	}

    return 0;
}