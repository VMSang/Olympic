// #include <bits/stdc++.h>
// using namespace std;


// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	//sai:
// 	//tìm độ dài nhỏ nhất
// 	//tong = trừ abs đi các que khac do dai voi que nho nhat

// 	//y tuong:
// 	/*
// 	tim khoang giua => sum == Min
// 	*/
// 	int n; cin >> n;
// 	vector<int> v(n);
// 	for (int &x : v)
// 		cin >> x;

// 	sort(v.begin(), v.end());

// 	int sum = 0, median = v[n/2];

// 	for(int x : v){
// 		sum+=abs(x - median);
// 	}
// 	cout << sum;

// 	return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// long long calculate_cost(const vector<int>& sticks, int length) {
//     long long cost = 0;
//     for (int stick : sticks) {
//         cost += abs(stick - length);
//     }
//     return cost;
// }

// int main() {
//     int n;
//     cin >> n;
    
//     vector<int> sticks(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> sticks[i];
//     }
    
//     int left = 1, right = 1e9;
//     long long min_cost = LLONG_MAX;
    
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
        
//         long long cost_mid = calculate_cost(sticks, mid);
//         long long cost_mid_minus_1 = (mid > 1) ? calculate_cost(sticks, mid - 1) : LLONG_MAX;
//         long long cost_mid_plus_1 = calculate_cost(sticks, mid + 1);
        
//         min_cost = min({min_cost, cost_mid, cost_mid_minus_1, cost_mid_plus_1});
        
//         if (cost_mid_minus_1 < cost_mid) {
//             right = mid - 1;
//         } else if (cost_mid_plus_1 < cost_mid) {
//             left = mid + 1;
//         } else {
//             break;
//         }
//     }
    
//     cout << min_cost << endl;
    
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

int Cost(vector<int> v, int length){
	int sumCost = 0;
	for(int x : v){
		sumCost+= abs(x - length);
	}

	return sumCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<int> v(n);
    for(int &x : v){
    	cin>>x;
    }
    sort(v.begin(), v.end());

    int l = 0, r = n - 1;
    int Cost_mid;
    while(l <= r){
    	int midLength = (l+r) >> 2;

    	Cost_mid = Cost(v, midLength);
    	int Cost_mid_mius_1 = Cost(v, midLength - 1);
    	int Cost_mid_plus_1 = Cost(v, midLength + 1);
    	int min_cost = min({Cost_mid, Cost_mid_mius_1, Cost_mid_plus_1});

    	if(Cost_mid_mius_1 < ){
    		r = midLength - 1;
    	} else if(Cost_mid_plus_1 > Cost_mid){
    		l = midLength + 1;
    	} else {
    		break;
    	}
    }

    cout<<Cost_mid;

    return 0;
}