#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra xem có thể chia các cặp vợ chồng thành số nhóm nhất định không
bool canDivideIntoGroups(vector<pair<int, int>>& couples, int groups) {
    vector<int> maxWifeHeight(groups, 0);  // Chiều cao tối đa của vợ trong mỗi nhóm
    for (const auto& couple : couples) {
        bool placed = false;
        for (int i = 0; i < groups; ++i) {
            if (maxWifeHeight[i] <= couple.second) {  // Nếu có thể xếp vào nhóm này
                maxWifeHeight[i] = couple.second;  // Cập nhật chiều cao tối đa của vợ trong nhóm
                placed = true;
                break;
            }
        }
        if (!placed) return false;  // Nếu không thể xếp cặp vợ chồng này vào bất kỳ nhóm nào
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> couples(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> couples[i].first >> couples[i].second;
    }

    sort(couples.begin(), couples.end());

    int left = 1, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (canDivideIntoGroups(couples, mid)) {
            right = mid;  // Có thể chia thành mid nhóm, thử với số nhóm ít hơn
        } else {
            left = mid + 1;  // Không thể chia thành mid nhóm, cần nhiều nhóm hơn
        }
    }

    cout << left << endl;  // Số
