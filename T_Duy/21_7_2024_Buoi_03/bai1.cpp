// #include <bits/stdc++.h>
// using namespace std;

// long long cal(vector<int>& v, int x, int k) {
//     long long low = x - k;
//     long long high = x + k;
//     long long sum = 0;

//     // Tính tổng các phần tử nhỏ hơn low
//     auto lowIdx = lower_bound(v.begin(), v.end(), low);
//     sum += accumulate(v.begin(), lowIdx, 0LL);

//     // Xóa các phần tử nhỏ hơn low
//     v.erase(v.begin(), lowIdx);

//     // Cập nhật highIdx sau khi xóa phần tử
//     auto highIdx = upper_bound(v.begin(), v.end(), high);
//     sum += accumulate(highIdx, v.end(), 0LL);

//     // Xóa các phần tử lớn hơn high
//     v.erase(highIdx, v.end());

//     return sum;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m; cin >> n >> m;
//     vector<int> v(n);
//     for (int &x : v) cin >> x;
//     sort(v.begin(), v.end());

//     while (m--) {
//         int x, k; cin >> x >> k;
//         cout << cal(v, x, k) << "\n";
//     }

//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

int bienTrai, bienPhai;

int funcLow(int a[], int n, int x) {
    int l = bienTrai, r = bienPhai, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int funcHeight(int a[], int n, int x) {
    int l = bienTrai, r = bienPhai, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] > x) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    bienTrai = 0; bienPhai = n;
    int a[n];
    for (int &x : a)
        cin >> x;
    sort(a, a + n);

    int prefix[n];
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int x : prefix)
        cout << x << " ";
    cout << endl;
    while (m--) {
        int x, k; cin >> x >> k;

        long long sum = 0;
        int check1 = funcLow(a, n, x - k);
        int check2 = funcHeight(a, n, x + k);

        if (check1) {
            sum += prefix[check1];
            prefix[check1 + 1] = a[check1 + 1];
            bienTrai = check1;
        }
        if (check2) {
            sum += prefix[bienPhai - 1] - prefix[check2 - 1];
            prefix[check2 + 1] = a[check2 + 1];
            bienPhai = check2;
        }

        // cout << sum << "\n";
        for (int x : prefix)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}