#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> a;
int x[4] = { -1, 0, 1, 0}, y[4] = {0, 1, 0, -1};
int minDistance = INT_MAX;

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    a[i][j] = 1; // đánh dấu vị trí đang xét = 1

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;

        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) { // nếu đã đến cạnh của lưới
            minDistance = min(minDistance, a[i][j] - 1); // cập nhật khoảng cách nhỏ nhất
            return; // kết thúc hàm bfs
        }

        int tmp = a[i][j];
        for (int k = 0; k < 4; k++) {
            int dx = i + x[k], dy = j + y[k]; // kiểm tra vị trí xung quanh
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && a[dx][dy] == 1) { // nếu vị trí hợp lệ và chưa được xét
                q.push(make_pair(dx, dy));
                a[dx][dy] = tmp + 1;
            }
        }

        q.pop(); // xóa i, j khỏi hàng đợi
    }
}

int main() {
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);

    cin >> n >> m;
    a.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    bfs(2, 2);

    if (minDistance == INT_MAX) {
        cout << "Khong the thoat khoi me cung" << endl;
    } else {
        cout << "Khoang cach nho nhat de thoat khoi me cung: " << minDistance << endl;
    }

    return 0;
}