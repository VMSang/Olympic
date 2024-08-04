#include <bits/stdc++.h>
using namespace std;

// kiểm tra xem với giá trị R, có thể đào hết các thỏi vàng với tối đa K lần đào không
bool canDigAllGold(vector<int>& positions, int n, int k, int r) {
    int count = 0;
    int i = 0;
    while (i < n) {
        count++;
        int rangeEnd = positions[i] + 2 * r;
        while (i < n && positions[i] <= rangeEnd) {
            i++;
        }
        if (count > k) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    // Tìm kiếm nhị phân để tìm R nhỏ nhất
    int left = 0, right = 1000000000, result = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canDigAllGold(positions, n, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
