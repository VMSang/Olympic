#include <bits/stdc++.h>
using namespace std;

// int main(){
// 	string s;
// 	cin>>s;
// 	int dem = 0;
// 	stack<char> st;
// 	for(int x : s){
// 		if(x == '(')
// 			st.push('(');
// 		else{
// 			if(st.empty())
// 				continue;
// 			else{
// 				st.pop();
// 				dem++;
// 			}
// 		}
// 	}
// 	cout<<dem*2;
// 	return 0;
// }

int main(){
	string s;
	cin>>s;
	int b = 1; //defaut max value of substring
	int currCnt = 0; //current count
	int max = 0;
	stack<char> st;
	for(int x : s){
		if(x == '('){
			st.push('('); //push in stack
		}
		else{
			if(st.empty())
				if(currCnt == max)
					b++;
			else{
				st.pop();
				currCnt++;
				if (currCnt > max)
					max = currCnt;
			}
		}
	}
	cout<<currCnt<<' '<<b;
}