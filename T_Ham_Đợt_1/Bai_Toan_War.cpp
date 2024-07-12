#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 1000, MAX_M = 1000;

int n, m, i, j;
int grid[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Thực hiện thuật toán loang (flood fill)
int floodFill(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int size = 1;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = curX + dx[k];
            int ny = curY + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == 0) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                size++;
            }
        }
    }

    return size;
}

// Đếm số lượng vùng an toàn
int countSafeRegions() {
    int count = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (!visited[x][y] && grid[x][y] == 0) {
                count++;
                floodFill(x, y);
            }
        }
    }
    return count;
}

// Tìm kích thước của vùng an toàn lớn nhất
int findLargestSafeRegion() {
    int maxSize = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (!visited[x][y] && grid[x][y] == 0) {
                int size = floodFill(x, y);
                maxSize = max(maxSize, size);
            }
        }
    }
    return maxSize;
}

// Tìm đường thoát ngắn nhất
int findShortestEscape(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                return steps;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        steps++;
    }

    return -1;
}

int main() {
    // Đọc dữ liệu từ file input
    freopen("TASK.inp", "r", stdin);
    cin >> n >> m >> i >> j;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> grid[x][y];
        }
    }

    // Tính toán kết quả
    int safeRegions = countSafeRegions();
    int largestSafeRegion = findLargestSafeRegion();
    int shortestEscape = findShortestEscape(i, j);

    // Ghi kết quả ra file output
    freopen("TASK.out", "w", stdout);
    cout << safeRegions << " " << largestSafeRegion << " " << shortestEscape << endl;
    if (shortestEscape != -1) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                cout << "(" << x << "," << y << ")" << endl;
                break;
            }
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    cout << "(" << nx << "," << ny << ")" << endl;
                }
            }
        }
    }
    return 0;
}