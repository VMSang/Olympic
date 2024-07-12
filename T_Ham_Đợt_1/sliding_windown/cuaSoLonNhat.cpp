//use:	tong/trung binh lon nhat/ nho nhat
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {    
 	int t; cin>>t;
 	while(t--){
 		int n; cin>>n; int a[1001]; int k; cin>>k;
 		for(int i=0; i<n; i++){
 			cin>>a[i];
 		}
 		long long sum = 0;
 		//first sum
 		for(int i=0; i<k; i++) sum+=a[i];
 		long long res = sum; int idx = 0;
 		//continue sum
 		for(int i=k; i<n; i++){
 			sum = sum - a[i-k] + a[i];
 			if(sum > res){
 				res = sum;
 				idx = i - k + 1;
 			}
 		}
 		cout<<res<<endl;
 		for(int i=0; i<k; i++){
 			cout<<a[idx + i]<<" ";
 		}
 	}   
    return 0;
}