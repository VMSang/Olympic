#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }

    vector<bool> stolen(n, false);
    vector<int> targets(m);
    for (int i = 0; i < m; i++) {
        cin >> targets[i];
        targets[i]--;  // Chuyển từ 1-indexed sang 0-indexed
    }

    for (int i = 0; i < m; i++) {
        int target = targets[i];

        // Nếu nhà đã bị trộm, tìm nhà gần nhất chưa bị trộm
        if (stolen[target]) {
            int left = target, right = target;
            while (left >= 0 && stolen[left]) {
                left--;
            }
            while (right < n && stolen[right]) {
                right++;
            }

            if (left < 0) {
                target = right;
            } else if (right >= n) {
                target = left;
            } else if (houses[left] > houses[right]) {
                target = left;
            } else {
                target = right;
            }
        }

        // Đánh dấu nhà đã bị trộm
        stolen[target] = true;

        // Tính tổng tài sản của các nhà liên tiếp bị trộm
        int left = target, right = target;
        int total = houses[target];
        while (left > 0 && stolen[left - 1]) {
            left--;
            total += houses[left];
        }
        while (right < n - 1 && stolen[right + 1]) {
            right++;
            total += houses[right];
        }

        cout << total << endl;
    }

    return 0;
}