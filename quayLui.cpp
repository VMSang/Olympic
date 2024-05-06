#include <bits/stdc++.h>
using namespace std;

int value[20], pos[19];
int n; 
void print(){
	for(int j=1; j<=n; j++){
		cout<<value[j] << ' ';
	}
	cout<<endl;
}
void backtrack(int i){
	if(i>n)
		print();
	for(int j=1; j<=n; j++){
		if(pos[j] == 0){
			pos[j] = 1;
			value[i] = j;
			backtrack(i+1);
			pos[j] = 0; 
		}
	}
	
}
int main(){ 
	fast
	cin>>n;
	memset(pos, 0, sizeof(pos));
	backtrack(1);
	return 0;
}