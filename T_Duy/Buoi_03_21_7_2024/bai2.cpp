#include <bits/stdc++.h>
using namespace std;

bool check(pair<int, int> a[], int n, int mid) {
    vector<int> group(mid, 0); // Chiều cao max ban đầu của các nhóm
    
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < mid; ++j) {
            if (a[i].second >= group[j]) {
                group[j] = a[i].second;
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;
    pair<int, int> a[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    
    sort(a, a + n); // Sắp xếp theo chiều cao của chồng
    
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(a, n, mid)) {
            r = mid; // Giảm số nhóm
        } else {
            l = mid + 1; // Tăng số nhóm
        }
    }
    cout << l;
    return 0;
}
