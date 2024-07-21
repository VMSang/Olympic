#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &x : v)
        cin >> x.first >> x.second;

    sort(v.begin(), v.end());
    // for (auto x : v) {
    //     cout << x.first << " " << x.second << "\n";
    // } cout << endl;

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].second == -1)
            continue;
        //khi gặp cái không thỏa mãn
        if ( v[i].second < v[i - 1].second) {
            // cout<<"check = "<<i<<endl;
            cnt++;
            int MAX = v[i - 1].second;
            // cout<<"Max = "<<MAX<<endl;
            //đánh dấu các cặp phía sau có thể đi chung với cặp này
            for (int j = i + 1; j < n; j++) {
                if (v[j].second >= MAX) {
                    // cout<<"co vao day "<<j<<endl;
                    MAX = v[j].second;
                    v[j].second = -1;
                }
            }
        }
        if(i == n-1 && v[i-1].second == -1)
            cnt++;
        // cout << "check cnt : " << i << " " << cnt << endl;
    }

    // for (auto x : v) {
    //     cout << x.first << " " << x.second << "\n";
    // } cout << endl;
    cout << cnt;

    return 0;
}
