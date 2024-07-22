#include <bits/stdc++.h>
using namespace std;

int check(vector<int> v, int mid){
    int Ve = 1;
    for(int i=0; i<v.size() - 1; i++){
        if(v[i].second == -1)
            continue;
        else if(v[i+1].second > v[i].second){
            v[i].second = -1;
        } else {
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &x : v) {
        cin >> x.first >> x.second;
    }

    sort(v.begin(), v.end());

    int left = 1, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(v, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}